/*
* Copyright (c) 2009 北京宏思电子技术有限责任公司
* All rights reserved.
*
* 文件名称：usb_func.c
* 摘要：USB底层函数
*
* 当前版本：2.0
* 作者：
* 完成日期：2009年5月27日
*
* 取代版本：
* 原作者：
* 完成日期：
*/

#include "HSC32EU_Registers.h"
#include "types.h"

extern unsigned int CBW_W[7];
#define RAM_BASE  		0x00810000
#define CBW_RCV_ADDR  		0x0100
#define CSW_SND_ADDR  		0x0140
#define DATA_WRK_ADDR		0x0200

extern T_U8    State;
extern T_U8    CbwC;
T_U32 Rxcs;

//-------------------------------------------------------------------------------
void usb_init()
{
	//usbi_in_reg = 0x01060013;

	USB_FADDR = 0x00;	

	USB_INTRTXE = 0x0001;   // ep0 中断使能  0x0100

	USB_INTRRXE = 0x0000;  
	
	USB_INTRUSBE = 0x00; 
	
	USB_INDEX = 0x0; 
	
	USB_CSR0 = 0x0000;	
	
	USB_INDEX = 0x1;
	USB_RxFIFOsz = 0x09;
	USB_RxFIFOadd = CBW_RCV_ADDR;
	
	USB_INDEX = 0x2;
	USB_TXMAXP = 0x3a00;
	USB_TxFIFOsz = 0x06;
	USB_TxFIFOadd = CSW_SND_ADDR;	 
	
	USB_INDEX = 0x0;
	
	USB_POWER = 0x60; 	
}

//----------------------------------------------------------------------------------
void usb_receive_package(unsigned char *data_buf, unsigned int len)
{
	unsigned int i;


	while(1)
	{
		USB_INDEX = 0x1;
		Rxcs=USB_RXCOUNT;		
		if(USB_RXCSR & 0x0100)
		{
			for(i = 0; i < len; i++)
			{
				data_buf[i] = USB_EP1_FIFO_8;
			}
			
			USB_RXCSR = USB_RXCSR & 0xFEFF;	
			
			return;			
		}				
	}
}

void usb_receive(unsigned int len)
{
	unsigned int i;
	unsigned int j;
	unsigned int tmp;
	
	USB_INDEX = 0x1;
	USB_RxFIFOadd = 0x0200;
	
	for(i = 0; i < (len >> 9); i++)
	{
		while(1)
		{
		    State=0x41;
			if(USB_INTRRX & 0x0002)    // ep1 routine
			{
				USB_INDEX = 0x1;
				Rxcs=USB_RXCOUNT;
				if(USB_RXCSR & 0x0100)
				{
					USB_RxFIFOadd += 0x40;
					USB_RXCSR = USB_RXCSR & 0xfeff;
					break;
				}
			}          // end if(USB_INTRRX & 0x0200)
		}        // end while(1)
	}
	
	if(len & 0x000001FF)
	{
		while(1)
		{
		    State=0x42;
			if(USB_INTRRX & 0x0002)    // ep1 routine
			{
				USB_INDEX = 0x1;
				if(USB_RXCSR & 0x0100)
				{
					USB_RxFIFOadd += 0x40;
					USB_RXCSR = USB_RXCSR & 0xfeff;
					break;
				}
			}        // end if(USB_INTRRX & 0x0200)
		}    // end while(1)
	}   // end if(len & 0x00000200)
}

void usb_receive_cbw(unsigned char *data_buf)
{
	unsigned int j;

	while(1)	
	{
		State=0x40;
		{
			USB_INDEX = 0x1;
			Rxcs=USB_RXCOUNT;		
		    if(USB_RXCSR & 0x0100)
			{
				for(j = 0; j < 31; j++)
				{
					data_buf[j] = USB_EP1_FIFO_8;
				}

				if(data_buf[15]==0xFD) USB_RxFIFOadd = DATA_WRK_ADDR;
				
				USB_RXCSR = USB_RXCSR & 0xfeff;	
				break;
			}
		}
	}
}

void usb_send(unsigned char *data_buf, unsigned int len)
{
	unsigned int i;
	unsigned int j;
	
	for(i = 0; i < (len >> 9); i++)
	{
		for(j = 0; j < 512; j++)
		{
			USB_EP2_FIFO_8 = data_buf[j + (i << 9)];
		}
		
		USB_INDEX = 0x2;
		USB_TXCSR = 0x0120;		
		while(USB_TXCSR & 0x0100);
	}
	
	if(len & 0x000001FF)
	{
		for(j = 0; j < (len & 0x000001FF); j++)
		{
			USB_EP2_FIFO_8 = data_buf[j + (i << 9)];
		}
		
		USB_INDEX = 0x2;
		USB_TXCSR = 0x0120;		
		while(USB_TXCSR & 0x0100);
	}
}

void write_data_to_nandflash(unsigned int len)
{
   char *pchar;
   int i=0;
   int DATALEN=len;
   int Ramaddr=DATA_WRK_ADDR;

//   pchar=(char *)DATA_WRK_ADDR;
/*   for(i=0;i<len;i++)
     NAND_FLASH_ALE_CS0=i;//*(pchar++);
*/

//	for(i=0;i<2;i++)
	{
	  EEC_CCR |= 0x0001;  //
      NFC_RSADDR = Ramaddr+i*DATALEN;
      NFC_RSDLEN = DATALEN;
      NFC_WFADDR = 0x90000010;

  	  NFC_RAMCSR |= 0x00000009;  //Write EN
  	  while(!(NFC_RAMCSR & 0x00008000));
	}      
}

void usb_data_send_ram(unsigned int len)
{
	USB_INDEX = 0x2;
	USB_TxFIFOadd = DATA_WRK_ADDR;
	USB_TxFIFOsz = 0x09;

    RAM_DATALEN = len;
    RAM_DATALEN |= 0x80000000;
  	USB_TXCSR = 0x0120;		
  	while(USB_TXCSR & 0x0100);
  	
  	USB_TxFIFOadd = CSW_SND_ADDR;
  	USB_TxFIFOsz = 0x06;
}

void usb_send_CSW_ep2(unsigned int dCSWTag, unsigned char status)
{
	USB_INDEX = 0x01;
	USB_RxFIFOadd = CBW_RCV_ADDR;

	USB_EP2_FIFO_32 = 0x55534253;
	USB_EP2_FIFO_32 = dCSWTag;
	USB_EP2_FIFO_32 = 0x00000000;
	USB_EP2_FIFO_8 = status;

	USB_INDEX = 0x2;
	USB_TXCSR = 0x0120;
		
	while(USB_TXCSR & 0x0100);
}