
#include "HSC32EU_registers.h"
#include "types.h"
#include "HSC32EU_Flash_Func.h"

extern T_U8    State;
extern T_U8    CbwC;
extern T_U32 Rxcs;
extern unsigned int key[2][4];


#define KEY_ADDR 0x00005000
#pragma interrupt on

void isr_USB_IRQ()
{
	unsigned short usb_csr0;
	unsigned char usb_count0;
	unsigned int i;
	unsigned int cmd_buf[8];
	unsigned char len;
	
	static unsigned char DeviceDescriptor[18] =   
	{					
		0x12, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x09, 0x23, 
		0x06, 0x06, 0x01, 0x00, 0x01, 0x02, 0x03, 0x01           
	}; 
//500mA 0xfa	
	static unsigned char ConfigurationDescriptor[32] = 
	{
		0x09, 0x02, 0x20, 0x00, 0x01, 0x01, 0x00, 0x80, 0xfa,
		0x09, 0x04, 0x00, 0x00, 0x02, 0x08, 0x06, 0x50, 0x00,
		0x07, 0x05, 0x01, 0x02, 0x00, 0x02, 0x00,
		0x07, 0x05, 0x82, 0x02, 0x00, 0x02, 0x00
	};
												 
	static unsigned char StringDescriptor_langID[4] = {0x04, 0x03, 0x09, 0x04};
	
	static unsigned char StringDescriptor[22] =									
	{
		0x16, 0x03, 'H', 0x00, 'L', 0x00, 'J', 0x00, 'U', 0x00, 0x20, 0x00, 
		'U', 0x00, 'D', 0x00, 'I', 0x00, 'S', 0x00, 'K', 0x00
	};
	static unsigned char QqID[] =									
    {
      'Q','Q',':','2','4','3','6','0','7','7','1','9'   
    };	
	if(USB_INTRUSB & 0x04)
	{
		USB_INTRTXE = 0x0001;   // ep0 ÖÐ¶ÏÊ¹ÄÜ

		USB_INTRRXE = 0x0000; 
	
		USB_INTRUSBE = 0x00;
	}
	
	USB_INDEX = 0x0;									 
	usb_csr0 = USB_CSR0;
	
	if((USB_INTRTX & 0x0001) && (usb_csr0 & 0x0100))
	{
		usb_count0 = USB_COUNT0;
		
		for(i = 0; i < (usb_count0 >> 2); i++)
		{
			cmd_buf[i] = USB_EP0_FIFO_32;
		}
		
		if(cmd_buf[0] == 0x80060001)        // GetDescriptor (Device)
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
			
			for(i = 0; i < 18; i++)
			{
				USB_EP0_FIFO_8 = DeviceDescriptor[i];
			}
			
			USB_CSR0 = USB_CSR0 | 0x0A00;
		}
		else if((cmd_buf[0] & 0xFFFF0000) == 0x00050000)  // SetAddress
		{		
			USB_CSR0 = USB_CSR0 | 0x4800;
			
			while(!(USB_INTRTX & 0x0001));
			
			USB_FADDR = (unsigned char)(cmd_buf[0] >> 8);	
		}
		else if(cmd_buf[0] == 0x80060002)       // GetDescriptor (Configuration)
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
			
			len = (unsigned char)(cmd_buf[1] >> 8);
			
			len = (len > 32) ? 32 : len;
			
			for(i = 0; i < len; i++)
			{
				USB_EP0_FIFO_8 = ConfigurationDescriptor[i];
			}
			
			USB_CSR0 = USB_CSR0 | 0x0A00;
		}
		else if(cmd_buf[0] == 0x80060003)       // GetDescriptor (String lang IDs)
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
			
			len = (unsigned char)(cmd_buf[1] >> 8);
			
			len = (len > 4) ? 4 : len;
			
			for(i = 0; i < len; i++)
			{
				USB_EP0_FIFO_8 = StringDescriptor_langID[i];
			}
			
			USB_CSR0 = USB_CSR0 | 0x0A00;
		}
		else if(cmd_buf[0] == 0x80060303)      // GetDescriptor (String iSerialNumber)	
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
			
			len = (unsigned char)(cmd_buf[1] >> 8);
			
			len = (len > 22) ? 22 : len;
			
			for(i = 0; i < len; i++)
			{
				USB_EP0_FIFO_8 = StringDescriptor[i];
			}
			
			USB_CSR0 = USB_CSR0 | 0x0A00;	
		}
		else if(cmd_buf[0] == 0x80060203)      // GetDescriptor (String iProduct)	
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
			
			len = (unsigned char)(cmd_buf[1] >> 8);
			
			len = (len > 22) ? 22 : len;
			
			for(i = 0; i < len; i++)
			{
				USB_EP0_FIFO_8 = StringDescriptor[i];
			}
			
			USB_CSR0 = USB_CSR0 | 0x0A00;	
		}
		else if((cmd_buf[0] & 0xFFFF0000) == 0x00090000)    // SetConfiguration
		{
			USB_INDEX = 0x1;   // out rx
			USB_RXMAXP = 0x0200;
			USB_RXCSR = 0x0000;
											
			USB_INDEX = 0x2;  // in  tx
			USB_TXMAXP = 0x3a00;
			USB_TXCSR = 0x0020;
			
			USB_INDEX = 0x0;
			
			USB_CSR0 = USB_CSR0 | 0x4800;	
		}
		else if(cmd_buf[0] == 0xA1FE0000)     // Get Max LUN
		{
			USB_CSR0 = USB_CSR0 | 0x4000;			
		
			USB_EP0_FIFO_8 = 0x00;		
			
			USB_CSR0 = USB_CSR0 | 0x0A00;			
		}
		else if(cmd_buf[0] == 0x0a0b0c0d)     //update key 
		{
			
			for(i = 0; i < 4; i++)
			{
				if(*(U8*)(cmd_buf+1)%2)			
				  key[0][i]=cmd_buf[i+2];
				else 
				  key[1][i]=cmd_buf[i+2];
				FlashWrite(KEY_ADDR,(U8*)(key),32);
			}                      
			USB_CSR0 = USB_CSR0 | 0x4000;
			USB_CSR0 = USB_CSR0 | 0x0A00;			
		
		}
		else if(cmd_buf[0] == 0xC0010000)     //User Command 
		{
			
			
			USB_CSR0 = USB_CSR0 | 0x4000;
            USB_EP0_FIFO_8=0xfa;
			for(i = 0; i < 12; i++)
			{
				USB_EP0_FIFO_8 = QqID[i];
			}           
			for(i = 0; i < 32; i++)
			{
				USB_EP0_FIFO_8 = *((unsigned char *)key+i);
			}                      
	        USB_EP0_FIFO_8=State;
	        USB_EP0_FIFO_8=CbwC;
	        USB_EP0_FIFO_32=Rxcs;
			USB_CSR0 = USB_CSR0 | 0x0A00;			
		}
		else if(cmd_buf[0] == 0xC0020000)     //User erase program 
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
            USB_EP0_FIFO_8=0xfb;
            USB_EP0_FIFO_8=0x02;
	        USB_EP0_FIFO_8='O';
	        USB_EP0_FIFO_8='k';
			USB_CSR0 = USB_CSR0 | 0x0A00;
			FlashSectorErase(0x2000);
		}
		else if(cmd_buf[0] == 0xC0030000)     
		{
			USB_CSR0 = USB_CSR0 | 0x4000;
            USB_EP0_FIFO_8=0xfb;
            USB_EP0_FIFO_8=0x03;
	        USB_EP0_FIFO_8='O';
	        USB_EP0_FIFO_8='k';
			USB_CSR0 = USB_CSR0 | 0x0A00;
		}	
		else
		{
			USB_CSR0 = USB_CSR0 | 0x4000;					
		}
		
	}   // end if((usb_csr0 & 0x0100) && (USB_INTRTX & 0x0100))
	
	
}
#pragma interrupt off