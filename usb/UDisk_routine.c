
#include "HSC32EU_Registers.h"

unsigned char *P_addr_2 = (unsigned char *)0x00810840;
void UDisk_routine(unsigned char *CBW_B)
{
	unsigned int i;
	
	unsigned char SCSI_Inquiry_Data[36] =
	{
		0x00, 0x80, 0x02, 0x02, 0x1f, 0x00, 0x00, 0x00,
		'H', 'L', 'J', 'U', 0x20, 0x20, 0x20, 0x20,
		'U', 'S', 'B', 'K', 'E', 'Y', 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		'1','.','0','0'
	};

	unsigned char SCSI_Read_Format_Capacity_Data[12] =
	{	
		0x00, 0x00, 0x00, 0x08,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00
	};
	
	unsigned char SCSI_Read_Capacity_Data[8] = 
	{	
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00
	};
	
	switch (CBW_B[15])
	{
		case 0x12:       // inquiry
		{
			usb_send(SCSI_Inquiry_Data, 36);			
		}		
		break;
		
		case 0x23:      // read format capacity
		{
			usb_send(SCSI_Read_Format_Capacity_Data, 12);					
		}
		break;
		
		case 0x25:      // read capacity
		{
			usb_send(SCSI_Read_Capacity_Data, 8);					
		}
		break;
		
		case 0x28:      // read
		{	
			
			for(i = 0; i < 128; i++)
			{
				USB_EP2_FIFO_32 = 0xFFFFFFFF;
			}
						
			USB_INDEX = 0x2;
			USB_TXCSR = 0x0120;
						
			while(USB_TXCSR & 0x0100);		
		}
		break;
		
		case 0x1A:     // MODE SENSE(6)
		{
			USB_EP2_FIFO_32 = 0x03000000;
				
			USB_INDEX = 0x2;
			USB_TXCSR = 0x0120;				
			while(USB_TXCSR & 0x0100);			
		}
		break;
		
		default:
		break;
		
	}   // end switch (CBW[15])

}