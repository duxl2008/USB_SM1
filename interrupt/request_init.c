#include "interrupt.h"

void request_init()
{
	void isr_USB_IRQ();

	
	// ---------------------------------------------------------------------  
	// Initializes the INTC module
	// ---------------------------------------------------------------------  
	Disable_Interrupts;
	//Clear_VBR;
	INTC_ISCR = 0x00000000;
	INTC_NIER |= 0x00000002;
	INTC_PLSR32_35 = 0x00000001;
	
	// Set USB Interrupt
	Init_Int(0x80FC00, isr_USB_IRQ, 33);

	Enable_Interrupts;
}