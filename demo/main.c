#include "HSC32EU_Registers.h"
#include "HSC32EU_cgm.h"
#include "types.h"
#include "bcae.h"

#define KEY_ADDR 0x00005000

unsigned int key[2][4] = 
	{{
		0x40bb12dd,0x6a827386,0x7f3529d3,0x54b4a026
	},{
		0x40bb12dd,0x6a827386,0x7f3529d3,0x54b4a026
	}};
	
static unsigned int iv[4] = 
	{
		0x4dd5660e,0x5b9b4b64,0x73c3c52d,0x5f2661f6
	};

#define PREDVR_1   		(* (volatile unsigned char * )0x00C1000C)	

void EDCU_Init()
{
	MCGCR |= EDCU_ON;	
//设置每1024B最大纠错18bit
    ENCM=0x03ff;  
    DECM=0x041f;
    DEC_CCR=0x1100;
    EEC_CCR=0x1100; 
 
  	NFC_ECCCR = 0x00001120; //硬件(RAM)实现ECC纠错的话，需要配置此寄存器  11=纠错能力减1   20=校验码长度
}

void chip_init()
{
	MCGCR |= GPCM_ON;       	//open GPCM  CLK
	MCGCR |= PIT0_ON;       	//open Timer0 CLK
	MCGCR |= DMAC_ON;            //open DMAC CLK
	MCGCR |= NFCI_ON;	         //open NFCI CLK
	
	NFC_CSCR0 = 0x11110201;      //setup time hold time

	GP_CR0 |= 0x00080000;   	//GP0 EN
	GP_PORT0 |= 0x00080000; 	//GP0 1
	GP_DIR0 |= 0x00080000;  	//GP0 out
	GP_PORT0 &= ~0x00080000; 	//GP0 0
	//----------------------------------------------------
	//定时器设置为定时1s
	PCSR0 = 0x0f12;
	PMR0  = 0x0989;         
	PCSR0 |= 0x0001; 
	EDCU_Init();
	
	FlashRead(KEY_ADDR,(unsigned char*)key,32);
}

T_U8    State=0;
T_U8    CbwC=0;


T_VOID main()
{
	T_U8	CBW[32];
	T_U32	*pCBW_W = (T_U32*)CBW;
	T_U8	*pCBWCB = &(CBW[15]);
	T_U32	len;
	T_U32	i = 0,j=0;

	
	unsigned char *p;
	p =  (unsigned char * )0x00810840;


	// 80MHz
	Clock_Setting();
	MCGCR = USBI_ON | BCAE_ON;

	chip_init();
	request_init();      			//注册中断处理程序	
	usb_init();
	FlashInit();	

	if((RSR&0x80)==1) //soft reset;
	{

    	GP_DIR0 |= 0x00080000;  	//1s的闪烁
        RSR&=0x7f;
	}
	
	while(1)
	{
        if(PCSR0 & 0x0004)
		{
		   PCSR0 |= 0x0004;
		   GP_DIR0 ^= 0x00080000;  	//1s的闪烁
		}
        State=0;
		usb_receive_cbw(CBW, 31);
		State=1;
		len = CBW[8] + (CBW[9] << 8) + (CBW[10] << 16) + (CBW[11] << 24);

		CbwC=CBW[15];
		switch (CBW[15])
		{
			case 0xFD:                 // receive OUT
			{
				switch (CBW[17])
				{
                    case 0xa1:
                    {
						usb_receive(len);
						usb_send_CSW_ep2(pCBW_W[1], 00);                                      
                    
                    }
                    break;

					case 0x00:             //普通
					{
					    State=3;
						usb_receive(len);
						usb_send_CSW_ep2(pCBW_W[1], 00);
						write_data_to_nandflash(len);						
					}
					break;	
					
					case 0xc2:            // SM1 Encrypt
					{
					
					    State=4;
						usb_receive(len);
						
						usb_send_CSW_ep2(pCBW_W[1], 00);
						
						if(CBW[18]) BCAE_Init(SM1, BCAE_ENCRYPT, CBC_MODE, (T_U8*)key[CBW[19]%2], (T_U8*)iv);
						else BCAE_Init(SM1, BCAE_ENCRYPT, ECB_MODE, (T_U8*)key[CBW[19]%2], (T_U8*)iv);
						
						BCAE_Run_RAM(0x1000, len);

					}
					break;
											
					case 0xc4:            // SM1 Decrypt
					{
						usb_receive(len);
						
						usb_send_CSW_ep2(pCBW_W[1], 00);
						
						if(CBW[18]) BCAE_Init(SM1, BCAE_DECRYPT, CBC_MODE, (T_U8*)key[CBW[19]%2], (T_U8*)iv);
						else BCAE_Init(SM1, BCAE_DECRYPT, ECB_MODE, (T_U8*)key[CBW[19]%2], (T_U8*)iv);
						
						BCAE_Run_RAM(0x1000, len);
					}
					break;						
				}			
			}
			break;
			
			case 0xFE:               // send IN
			{
				switch (CBW[17])
				{
					case 0x00:             //普通
					{
						usb_data_send_ram(len);
						usb_send_CSW_ep2(pCBW_W[1], 00);					
					}
					break;
					
					case 0xc2:            // SM1
					case 0xc4: 					
					{
						usb_data_send_ram(len);
						usb_send_CSW_ep2(pCBW_W[1], 00);						
					}
					break;
				}							
			}
			break;
			  
			default:
			{
			    State=5;
				UDisk_routine(CBW);
				usb_send_CSW_ep2(pCBW_W[1], 00);
			}
		}		
	}
}