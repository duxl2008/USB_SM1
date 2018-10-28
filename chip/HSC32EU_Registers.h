// +FHDR -----------------------------------------------------------------------
// Copyright (c) 2014, Hongsi.
// Hongsi Confidential Proprietary
// 2016/04/14 
//
// -----------------------------------------------------------------------------
// File Name: HSC32EU_Registers.h
// Type: C Language 
//
// -----------------------------------------------------------------------------
// Description:
// This code is the header file for HSC32EU registers.
//
// -----------------------------------------------------------------------------
// Revision History
// DATE         AUTHOR          DESCRIPTION
// 2016/04/14 					V1.0
// -FHDR -----------------------------------------------------------------------

// ---------------------------------------------------------------------  
// Register Definitions
// ---------------------------------------------------------------------

// for RCM
#define RCR   	 		(* (volatile unsigned char * )0x00C00000) 
#define RSR   			(* (volatile unsigned char * )0x00C00001)

// for CGM
#define MCGCR    		(* (volatile unsigned int * )0x00C10000) 
#define CGCSR    		(* (volatile unsigned int * )0x00C10004) 
#define CGCSR_1    		(* (volatile unsigned char * )0x00C10004)
#define CKDVR  	 		(* (volatile unsigned int * )0x00C10008)
#define PREDVR   		(* (volatile unsigned short * )0x00C1000C)

// for INTC
#define ICR   			(* (volatile unsigned short * )0x00C20000)
#define ISR   			(* (volatile unsigned short * )0x00C20002)
#define IFRL   			(* (volatile unsigned int * )0x00C20008)
#define IPR   			(* (volatile unsigned int * )0x00C2000C)
#define NIER   			(* (volatile unsigned int * )0x00C20010)
#define NIPR   			(* (volatile unsigned int * )0x00C20014)
#define FIER   			(* (volatile unsigned int * )0x00C20018)
#define FIPR   			(* (volatile unsigned int * )0x00C2001C)
#define PLSR0_3 		(* (volatile unsigned int * )0x00C20040)		//
#define PLSR4_7 		(* (volatile unsigned int * )0x00C20044)		//
#define PLSR8_11 		(* (volatile unsigned int * )0x00C20048)		//
#define PLSR12_15 		(* (volatile unsigned int * )0x00C2004C)		//
#define PLSR16_19 		(* (volatile unsigned int * )0x00C20050)		//
#define PLSR20_23 		(* (volatile unsigned int * )0x00C20054)		//
#define PLSR24_27 		(* (volatile unsigned int * )0x00C20058)		//
#define PLSR28_31 		(* (volatile unsigned int * )0x00C2005C)		//
#define PLSR32_35 		(* (volatile unsigned int * )0x00C20060)		//
#define PLSR36_39 		(* (volatile unsigned int * )0x00C20064)		//

//----------------------------------------------------------------------

// for WDT
#define WCR	   			(* (volatile unsigned char * )0x00C30001)
#define WMR   			(* (volatile unsigned short * )0x00C30002)
#define WCNTR   		(* (volatile unsigned short * )0x00C30004)
#define WSR		   		(* (volatile unsigned short * )0x00C30006)

// for PIT0
#define PCSR0   		(* (volatile unsigned short * )0x00C40000)
#define PMR0   			(* (volatile unsigned short * )0x00C40002)
#define PCNTR0   		(* (volatile unsigned short * )0x00C40004)

// for PIT1
#define PCSR1   		(* (volatile unsigned short * )0x00C50000)
#define PMR1   			(* (volatile unsigned short * )0x00C50002)
#define PCNTR1   		(* (volatile unsigned short * )0x00C50004)

// for PIT2
#define PCSR2   		(* (volatile unsigned short * )0x00C60000)
#define PMR2   			(* (volatile unsigned short * )0x00C60002)
#define PCNTR2   		(* (volatile unsigned short * )0x00C60004)

// ----------------------------------------------------------------------

// for TRNG
#define TRNG_CSR		(* (volatile unsigned short * )0x00900002) 
#define TRNG_SDR		(* (volatile unsigned int * )0x00900004) 
#define TRNG_DR			(* (volatile unsigned int * )0x00900008)
#define RNG_COUT0       (* (volatile unsigned int * )0x0090000c)
#define RNG_COUT1       (* (volatile unsigned int * )0x00900010)
#define RNG_COUT2       (* (volatile unsigned int * )0x00900014)
#define RNG_COUT3       (* (volatile unsigned int * )0x00900018)
#define RNG_COUT4       (* (volatile unsigned int * )0x0090001c)
#define RNG_COUT5       (* (volatile unsigned int * )0x00900020)
#define RNG_COUT6       (* (volatile unsigned int * )0x00900024)
#define RNG_COUT7       (* (volatile unsigned int * )0x00900028)
#define TRNG_EXP_CSR    (* (volatile unsigned int * )0x0090002c)
#define TRNG_OT_EDR     (* (volatile unsigned int * )0x00900030)
#define TRNG_FIFO_DR    (* (volatile unsigned int * )0x00900034)

// for BCAE
#define BCAE_CSR		(* (volatile unsigned int * )0x00910000)
#define BCAE_DATR		(* (volatile unsigned int * )0x00910004)
#define BCAE_KINR		(* (volatile unsigned int * )0x00910008)
#define BCAE_IVINR		(* (volatile unsigned int * )0x0091000C)
#define BCAE_ADDR		(* (volatile unsigned int * )0x00910010)
#define BCAE_LENR		(* (volatile unsigned int * )0x00910014)
#define BCAE_DR0		(* (volatile unsigned int * )0x00910020)
#define BCAE_DR1		(* (volatile unsigned int * )0x00910024)
#define BCAE_DR2		(* (volatile unsigned int * )0x00910028)
#define BCAE_DR3		(* (volatile unsigned int * )0x0091002C)
#define BCAE_KR0		(* (volatile unsigned int * )0x00910030)
#define BCAE_KR1		(* (volatile unsigned int * )0x00910034)
#define BCAE_KR2		(* (volatile unsigned int * )0x00910038)
#define BCAE_KR3		(* (volatile unsigned int * )0x0091003C)
#define BCAE_KR4		(* (volatile unsigned int * )0x00910040)
#define BCAE_KR5		(* (volatile unsigned int * )0x00910044)
#define BCAE_KR6		(* (volatile unsigned int * )0x00910048)
#define BCAE_KR7		(* (volatile unsigned int * )0x0091004C)
#define BCAE_IVR0		(* (volatile unsigned int * )0x00910050)
#define BCAE_IVR1		(* (volatile unsigned int * )0x00910054)
#define BCAE_IVR2		(* (volatile unsigned int * )0x00910058)
#define BCAE_IVR3		(* (volatile unsigned int * )0x0091005C)

// for SHAE
#define SHAE_CSR		(* (volatile unsigned int * )0x00920000)
#define SHAE_DIGDR0		(* (volatile unsigned int * )0x00920004)
#define SHAE_DIGDR1		(* (volatile unsigned int * )0x00920008)
#define SHAE_DIGDR2		(* (volatile unsigned int * )0x0092000C)
#define SHAE_DIGDR3		(* (volatile unsigned int * )0x00920010)
#define SHAE_DIGDR4		(* (volatile unsigned int * )0x00920014)
#define SHAE_DIGDR5		(* (volatile unsigned int * )0x00920018)
#define SHAE_DIGDR6		(* (volatile unsigned int * )0x0092001C)
#define SHAE_DIGDR7		(* (volatile unsigned int * )0x00920020)
#define SHAE_MESSDR		(* (volatile unsigned int * )0x00920024)
#define SHAE_LAR		(* (volatile unsigned int * )0x00920028)

// for REAE
#define REAE_CSR		(* (volatile unsigned int * )0x00930000)
#define REAE_SEG		(* (volatile unsigned int * )0x00930004)
#define REAE_PAR0		(* (volatile unsigned int * )0x00930008)
#define REAE_PAR1		(* (volatile unsigned int * )0x0093000C)
#define REAE_CMD		(* (volatile unsigned int * )0x00930010)
#define REAE_NOISE      (* (volatile unsigned int * )0x0093001C)

// for SDAE
#define SDAE_CSR		(* (volatile unsigned int * )0x00940000)
#define SDAE_DATR		(* (volatile unsigned int * )0x00940004)
#define SDAE_ADDR		(* (volatile unsigned int * )0x00940008)
#define SDAE_LENR		(* (volatile unsigned int * )0x0094000C)

// for AAE
#define AAE_CSR      	(* (volatile unsigned char * )0x00950000)
#define AAE_DATA_IN0    (* (volatile unsigned int * )0x00950004)
#define AAE_DATA_IN1    (* (volatile unsigned int * )0x00950008)
#define AAE_DATA_IN2    (* (volatile unsigned int * )0x0095000C)
#define AAE_DATA_IN3    (* (volatile unsigned int * )0x00950010)
#define AAE_KEY_IN0     (* (volatile unsigned int * )0x00950014)
#define AAE_KEY_IN1     (* (volatile unsigned int * )0x00950018)
#define AAE_KEY_IN2     (* (volatile unsigned int * )0x0095001C)
#define AAE_KEY_IN3     (* (volatile unsigned int * )0x00950020)
#define AAE_KEY_IN4     (* (volatile unsigned int * )0x00950024)
#define AAE_KEY_IN5     (* (volatile unsigned int * )0x00950028)
#define AAE_KEY_IN6     (* (volatile unsigned int * )0x0095002C)
#define AAE_KEY_IN7     (* (volatile unsigned int * )0x00950030)
#define AAE_DATA_OUT0   (* (volatile unsigned int * )0x00950034)
#define AAE_DATA_OUT1   (* (volatile unsigned int * )0x00950038)
#define AAE_DATA_OUT2   (* (volatile unsigned int * )0x0095003C)
#define AAE_DATA_OUT3   (* (volatile unsigned int * )0x00950040)
#define AAE_IV0         (* (volatile unsigned int * )0x00950044)
#define AAE_IV1         (* (volatile unsigned int * )0x00950048)
#define AAE_IV2         (* (volatile unsigned int * )0x0095004C)
#define AAE_IV3         (* (volatile unsigned int * )0x00950050)
#define AAE_ADDR        (* (volatile unsigned int * )0x00950054)
#define AAE_LENR        (* (volatile unsigned int * )0x00950058)

// for FAE
#define FAE_CSR			(* (volatile unsigned int * )0x00960000)
#define FAE_DATR		(* (volatile unsigned int * )0x00960004)
#define FAE_KINR		(* (volatile unsigned int * )0x00960008)
#define FAE_IVINR		(* (volatile unsigned int * )0x0096000C)
#define FAE_DR0			(* (volatile unsigned int * )0x00960020)
#define FAE_DR1			(* (volatile unsigned int * )0x00960024)
#define FAE_DR2			(* (volatile unsigned int * )0x00960028)
#define FAE_DR3			(* (volatile unsigned int * )0x0096002C)
#define FAE_KR0			(* (volatile unsigned int * )0x00960030)
#define FAE_KR1			(* (volatile unsigned int * )0x00960034)
#define FAE_KR2			(* (volatile unsigned int * )0x00960038)
#define FAE_KR3			(* (volatile unsigned int * )0x0096003C)
#define FAE_IVR0		(* (volatile unsigned int * )0x00960040)
#define FAE_IVR1		(* (volatile unsigned int * )0x00960044)
#define FAE_IVR2		(* (volatile unsigned int * )0x00960048)
#define FAE_IVR3		(* (volatile unsigned int * )0x0096004C)

// for CSM
#define SCM_FLCSR      	(* (volatile unsigned int * )0x00970000)
#define SCM_TVCSR      	(* (volatile unsigned int * )0x00970004)
#define SCM_SMCR       	(* (volatile unsigned int * )0x00970008)
#define SCM_SK         	(* (volatile unsigned int * )0x0097000C)
#define SCM_SDPOR      	(* (volatile unsigned int * )0x00970010)
#define SCM_SDER       	(* (volatile unsigned int * )0x00970014)
#define SCM_SDSR       	(* (volatile unsigned int * )0x00970018)
#define SCM_TD_PRE      (* (volatile unsigned int * )0x0097001C)
#define SCM_VD_PRE      (* (volatile unsigned int * )0x00970020)
#define SCM_FD_PRE      (* (volatile unsigned int * )0x00970024)
#define SCM_LDSD_PRE    (* (volatile unsigned int * )0x00970028)

// for EFM
#define EFM_CR   		(* (volatile unsigned char * )0x00980000) 
#define EFM_CMDR1  		(* (volatile unsigned short * )0x00980018)
#define EFM_CMDR2   	(* (volatile unsigned char * )0x0098001b)

// for EDCU
#define DEC_CCR         (*(volatile  unsigned short *)0x00990000)
#define DEC_CCR_1       (*(volatile  unsigned char *)0x00990000)
#define DEC_CCR_2       (*(volatile  unsigned char *)0x00990001)
#define EEC_CCR         (*(volatile  unsigned short *)0x00990002)
#define EEC_CSR         (*(volatile  unsigned short *)0x00990002)
#define ECC_SR          (*(volatile  unsigned short *)0x00990006)
#define DECM            (*(volatile  unsigned short *)0x00990008)
#define ENCM            (*(volatile  unsigned short *)0x0099000A)
#define ERRCNT          (*(volatile  unsigned char *)0x0099016C)
#define ECCPCNT         (*(volatile  unsigned char *)0x0099016D)
#define CONT            (*(volatile  unsigned char *)0x0099016E)

#define EBYTEA0         ((volatile  unsigned short *)0x00990090)
#define EBITA0          ((volatile  unsigned char *)0x00990120)
#define ECCP0           ((volatile   unsigned char *)0x00990010)

// ----------------------------------------------------------------------

// for USBI
// Common USB registers
#define	USB_FADDR 		(*(volatile unsigned char *)0x00A00000)
#define USB_POWER 		(*(volatile unsigned char *)0x00A00001)
#define USB_INTRTX 		(*(volatile unsigned short *)0x00A00002)
#define USB_INTRRX 		(*(volatile unsigned short *)0x00A00004)
#define USB_INTRTXE 	(*(volatile unsigned short *)0x00A00006)
#define USB_INTRRXE 	(*(volatile unsigned short *)0x00A00008)
#define USB_INTRUSB 	(*(volatile unsigned char *)0x00A0000A)
#define USB_INTRUSBE 	(*(volatile unsigned char *)0x00A0000B)
#define USB_FRAME 		(*(volatile unsigned short *)0x00A0000C)
#define USB_INDEX 		(*(volatile unsigned char *)0x00A0000E)

// Indexed registers - Peripheral mode
#define USB_CSR0 		(*(volatile unsigned short *)0x00A00012)
#define USB_COUNT0 		(*(volatile unsigned char *)0x00A00018)

#define USB_TXMAXP 		(*(volatile unsigned short *)0x00A00010)
#define USB_TXCSR 		(*(volatile unsigned short *)0x00A00012)
#define USB_RXMAXP 		(*(volatile unsigned short *)0x00A00014)
#define USB_RXCSR 		(*(volatile unsigned short *)0x00A00016)
#define USB_RXCOUNT 	(*(volatile unsigned short *)0x00A00018)

// FIFOs
#define USB_EP0_FIFO_8 	(*(volatile unsigned char *)0x00A00020)
#define USB_EP0_FIFO_16 (*(volatile unsigned short *)0x00A00020)
#define USB_EP0_FIFO_32 (*(volatile unsigned int *)0x00A00020)

#define USB_EP1_FIFO_8 	(*(volatile unsigned char *)0x00A00024)
#define USB_EP1_FIFO_16 (*(volatile unsigned short *)0x00A00024)
#define USB_EP1_FIFO_32 (*(volatile unsigned int *)0x00A00024)

#define USB_EP2_FIFO_8 	(*(volatile unsigned char *)0x00A00028)
#define USB_EP2_FIFO_16 (*(volatile unsigned short *)0x00A00028)
#define USB_EP2_FIFO_32 (*(volatile unsigned int *)0x00A00028)

#define USB_EP3_FIFO_8 	(*(volatile unsigned char *)0x00A0002C)
#define USB_EP3_FIFO_16 (*(volatile unsigned short *)0x00A0002C)
#define USB_EP3_FIFO_32 (*(volatile unsigned int *)0x00A0002C)

#define USB_EP4_FIFO_8 	(*(volatile unsigned char *)0x00A00030)
#define USB_EP4_FIFO_16 (*(volatile unsigned short *)0x00A00030)
#define USB_EP4_FIFO_32 (*(volatile unsigned int *)0x00A00030)

#define USB_EP5_FIFO_8 	(*(volatile unsigned char *)0x00A00034)
#define USB_EP5_FIFO_16 (*(volatile unsigned short *)0x00A00034)
#define USB_EP5_FIFO_32 (*(volatile unsigned int *)0x00A00034)

#define USB_EP6_FIFO_8 	(*(volatile unsigned char *)0x00A00038)
#define USB_EP6_FIFO_16 (*(volatile unsigned short *)0x00A00038)
#define USB_EP6_FIFO_32 (*(volatile unsigned int *)0x00A00038)

#define USB_EP7_FIFO_8 	(*(volatile unsigned char *)0x00A0003C)
#define USB_EP7_FIFO_16 (*(volatile unsigned short *)0x00A0003C)
#define USB_EP7_FIFO_32 (*(volatile unsigned int *)0x00A0003C)

#define USB_EP8_FIFO_8 	(*(volatile unsigned char *)0x00A00040)
#define USB_EP8_FIFO_16 (*(volatile unsigned short *)0x00A00040)
#define USB_EP8_FIFO_32 (*(volatile unsigned int *)0x00A00040)

// USBI extern registers	
#define USBICR 			(*(volatile unsigned int *)0x00A00400)
#define RAM_DATALEN		(*(volatile unsigned int *)0x00A0040C)

// DYNAMIC FIFO SIZING
#define USB_TxFIFOsz 	(*(volatile unsigned char *)0x00A00062)
#define USB_RxFIFOsz 	(*(volatile unsigned char *)0x00A00063)
#define USB_TxFIFOadd 	(*(volatile unsigned short *)0x00A00064)
#define USB_RxFIFOadd 	(*(volatile unsigned short *)0x00A00066)

//-------------------------------------------------------------------------

// for SPI1
#define SPI1_CR1 		(* (volatile unsigned char * )0x00A10000)
#define SPI1_CR2 		(* (volatile unsigned char * )0x00A10001)
#define SPI1_CR3 		(* (volatile unsigned char * )0x00A10002)
#define SPI1_CR4 		(* (volatile unsigned char * )0x00A10003)
#define SPI1_FLCR 		(* (volatile unsigned char * )0x00A10004)
#define SPI1_SR			(* (volatile unsigned char * )0x00A10005)
#define SPI1_IER		(* (volatile unsigned char * )0x00A10006)
#define SPI1_BR			(* (volatile unsigned char * )0x00A10007)
#define SPI1_RADDR		(* (volatile unsigned short * )0x00A10008)
#define SPI1_RLENR		(* (volatile unsigned short * )0x00A1000A)
#define SPI1_CRC		(* (volatile unsigned short * )0x00A1000C)
#define SPI1_DR			(* (volatile unsigned char * )0x00A1000E)

// for SPI2
#define SPI2_CR1 		(* (volatile unsigned char * )0x00A20000)
#define SPI2_CR2 		(* (volatile unsigned char * )0x00A20001)
#define SPI2_CR3 		(* (volatile unsigned char * )0x00A20002)
#define SPI2_CR4 		(* (volatile unsigned char * )0x00A20003)
#define SPI2_FLCR 		(* (volatile unsigned char * )0x00A20004)
#define SPI2_SR			(* (volatile unsigned char * )0x00A20005)
#define SPI2_IER		(* (volatile unsigned char * )0x00A20006)
#define SPI2_BR			(* (volatile unsigned char * )0x00A20007)
#define SPI2_RADDR		(* (volatile unsigned short * )0x00A20008)
#define SPI2_RLENR		(* (volatile unsigned short * )0x00A2000A)
#define SPI2_CRC		(* (volatile unsigned short * )0x00A2000C)
#define SPI2_DR			(* (volatile unsigned char * )0x00A2000E)

//-------------------------------------------------------------------------

// for USI1
#define USI1_CR   		(* (volatile unsigned short * )0x00A30000)
#define USI1_IER   		(* (volatile unsigned short * )0x00A30002)
#define USI1_SR   		(* (volatile unsigned short * )0x00A30004)
#define USI1_BR   		(* (volatile unsigned short * )0x00A30006)
#define USI1_RADDR  	(* (volatile unsigned short * )0x00A30008)
#define USI1_RLENR   	(* (volatile unsigned short * )0x00A3000A)
#define USI1_DRH   		(* (volatile unsigned char * )0x00A3000C)
#define USI1_DRL   		(* (volatile unsigned char * )0x00A3000D)

// for USI2
#define USI2_CR   		(* (volatile unsigned short * )0x00A40000)
#define USI2_IER   		(* (volatile unsigned short * )0x00A40002)
#define USI2_SR   		(* (volatile unsigned short * )0x00A40004)
#define USI2_BR   		(* (volatile unsigned short * )0x00A40006)
#define USI2_RADDR  	(* (volatile unsigned short * )0x00A40008)
#define USI2_RLENR   	(* (volatile unsigned short * )0x00A4000A)
#define USI2_DRH   		(* (volatile unsigned char * )0x00A4000C)
#define USI2_DRL   		(* (volatile unsigned char * )0x00A4000D)

// for USI3
#define USI3_CR   		(* (volatile unsigned short * )0x00A50000)
#define USI3_IER   		(* (volatile unsigned short * )0x00A50002)
#define USI3_SR   		(* (volatile unsigned short * )0x00A50004)
#define USI3_BR   		(* (volatile unsigned short * )0x00A50006)
#define USI3_RADDR  	(* (volatile unsigned short * )0x00A50008)
#define USI3_RLENR   	(* (volatile unsigned short * )0x00A5000A)
#define USI3_DRH   		(* (volatile unsigned char * )0x00A5000C)
#define USI3_DRL   		(* (volatile unsigned char * )0x00A5000D)

//-------------------------------------------------------------------------

// for STI1
#define STI1_CR1   		(* (volatile unsigned char * )0x00A60000)
#define STI1_CR2   		(* (volatile unsigned char * )0x00A60001)
#define STI1_CR3   		(* (volatile unsigned char * )0x00A60002)
#define STI1_SR   		(* (volatile unsigned char * )0x00A60003)
#define STI1_IER   		(* (volatile unsigned char * )0x00A60004)
#define STI1_DR   		(* (volatile unsigned char * )0x00A60005)
#define STI1_GTR   		(* (volatile unsigned short * )0x00A60006)
#define STI1_RADDR   	(* (volatile unsigned short * )0x00A60008)
#define STI1_RLENR   	(* (volatile unsigned short * )0x00A6000A)
#define STI1_CWTR   	(* (volatile unsigned int * )0x00A6000C)
#define STI1_BWTR   	(* (volatile unsigned int * )0x00A60010)
#define STI1_COR   		(* (volatile unsigned int * )0x00A60014)
#define STI1_ECR   		(* (volatile unsigned short * )0x00A60018)
#define STI1_RCR   		(* (volatile unsigned short * )0x00A6001A)

// for STI2
#define STI2_CR1   		(* (volatile unsigned char * )0x00A70000)
#define STI2_CR2   		(* (volatile unsigned char * )0x00A70001)
#define STI2_CR3   		(* (volatile unsigned char * )0x00A70002)
#define STI2_SR   		(* (volatile unsigned char * )0x00A70003)
#define STI2_IER   		(* (volatile unsigned char * )0x00A70004)
#define STI2_DR   		(* (volatile unsigned char * )0x00A70005)
#define STI2_GTR   		(* (volatile unsigned short * )0x00A70006)
#define STI2_RADDR   	(* (volatile unsigned short * )0x00A70008)
#define STI2_RLENR   	(* (volatile unsigned short * )0x00A7000A)
#define STI2_CWTR   	(* (volatile unsigned int * )0x00A7000C)
#define STI2_BWTR   	(* (volatile unsigned int * )0x00A70010)
#define STI2_COR   		(* (volatile unsigned int * )0x00A70014)
#define STI2_ECR   		(* (volatile unsigned short * )0x00A70018)
#define STI2_RCR   		(* (volatile unsigned short * )0x00A7001A)

//-------------------------------------------------------------------------

// for EMMC
#define EMMCI_RSPCR   	(* (volatile unsigned char * )0x00A80000)
#define EMMCI_CTO_CNTR  (* (volatile unsigned char * )0x00A80001)
#define EMMCI_IDXR      (* (volatile unsigned char * )0x00A80002)
#define EMMCI_CLKCR     (* (volatile unsigned char * )0x00A80003)
#define EMMCI_ARGR1     (* (volatile unsigned int * )0x00A80004)
#define EMMCI_ARGR2     (* (volatile unsigned int * )0x00A80008)
#define EMMCI_ARGR3     (* (volatile unsigned int * )0x00A8000C)
#define EMMCI_ARGR4     (* (volatile unsigned int * )0x00A80010)
#define EMMCI_DATCR     (* (volatile unsigned short * )0x00A80014)
#define EMMCI_DATSR     (* (volatile unsigned short * )0x00A80016)
#define EMMCI_BOOT_ACK_CNTR     (* (volatile unsigned int * )0x00A80018)
#define EMMCI_DTOR     	(* (volatile unsigned int * )0x00A8001C)
#define EMMCI_ADDR	    (* (volatile unsigned short * )0x00A80020)
#define EMMCI_BL_NUMR  	(* (volatile unsigned char * )0x00A80022)
#define EMMCI_IER	  	(* (volatile unsigned char * )0x00A80023)

// for NFCI
#define NFC_CSCR0   	(* (volatile unsigned int * )0x00A90000)
#define NFC_CSCR1   	(* (volatile unsigned int * )0x00A90004)
#define NFC_CSCR2   	(* (volatile unsigned int * )0x00A90008)
#define NFC_CSCR3   	(* (volatile unsigned int * )0x00A9000C)
#define NFC_RSADDR   	(* (volatile unsigned short * )0x00A90010)
#define NFC_RSDLEN   	(* (volatile unsigned short * )0x00A90012)
#define NFC_WSADDR   	(* (volatile unsigned short * )0x00A90014)
#define NFC_WSDLEN   	(* (volatile unsigned short * )0x00A90016)
#define NFC_WFADDR   	(* (volatile unsigned int * )0x00A90018)
#define NFC_RFADDR   	(* (volatile unsigned int * )0x00A9001C)
#define NFC_RAMCSR   	(* (volatile unsigned int * )0x00A90020)
#define NFC_INFOCR   	(* (volatile unsigned int * )0x00A90024)
#define NFC_ECCCR   	(* (volatile unsigned int * )0x00A90028)
#define NFC_RAM_INFO0  	(* (volatile unsigned int * )0x00A90040)
#define NFC_RAM_INFO1  	(* (volatile unsigned int * )0x00A90044)
#define NFC_RAM_INFO2  	(* (volatile unsigned int * )0x00A90048)
#define NFC_RAM_INFO3  	(* (volatile unsigned int * )0x00A9004C)
#define NFC_RAM_INFO4  	(* (volatile unsigned int * )0x00A90050)
#define NFC_RAM_INFO5  	(* (volatile unsigned int * )0x00A90054)
#define NFC_RAM_INFO6  	(* (volatile unsigned int * )0x00A90058)
#define NFC_RAM_INFO7  	(* (volatile unsigned int * )0x00A9005C)

#define NAND_FLASH_CLE_CS0       (* (volatile unsigned char * )0x90000004)
#define NAND_FLASH_ALE_CS0       (* (volatile unsigned char * )0x90000008)
#define NAND_FLASH_DATA_CS0      (* (volatile unsigned char * )0x90000000)
#define NAND_FLASH_DATA_ECC_CS0  (* (volatile unsigned char * )0x90000010)

#define NAND_FLASH_CLE_CS1       (* (volatile unsigned char * )0x90800004)
#define NAND_FLASH_ALE_CS1       (* (volatile unsigned char * )0x90800008)
#define NAND_FLASH_DATA_CS1      (* (volatile unsigned char * )0x90800000)
#define NAND_FLASH_DATA_ECC_CS1  (* (volatile unsigned char * )0x90800010)

#define NAND_FLASH_CLE_CS2       (* (volatile unsigned char * )0x91000004)
#define NAND_FLASH_ALE_CS2       (* (volatile unsigned char * )0x91000008)
#define NAND_FLASH_DATA_CS2      (* (volatile unsigned char * )0x91000000)
#define NAND_FLASH_DATA_ECC_CS2  (* (volatile unsigned char * )0x91000010)

#define NAND_FLASH_CLE_CS3       (* (volatile unsigned char * )0x91800004)
#define NAND_FLASH_ALE_CS3       (* (volatile unsigned char * )0x91800008)
#define NAND_FLASH_DATA_CS3      (* (volatile unsigned char * )0x91800000)
#define NAND_FLASH_DATA_ECC_CS3  (* (volatile unsigned char * )0x91800010)

// for I2CI
#define I2CI_SR			(* (volatile unsigned char *)0x00AA0000)
#define I2CI_CR			(* (volatile unsigned char *)0x00AA0001)
#define I2CI_CMDR		(* (volatile unsigned char *)0x00AA0002)
#define I2CI_IER		(* (volatile unsigned char *)0x00AA0003)
#define I2CI_PRER		(* (volatile unsigned short *)0x00AA0004)
#define I2CI_SNDDR		(* (volatile unsigned char *)0x00AA0006)
#define I2CI_RCVDR		(* (volatile unsigned char *)0x00AA0007)
#define I2CI_LENR		(* (volatile unsigned short *)0x00AA0008)

// for GPCM

#define GP_PORT0   		(* (volatile unsigned int * )0x00AB0000)
#define GP_PORT1   		(* (volatile unsigned int * )0x00AB0004)
#define GP_DIR0   		(* (volatile unsigned int * )0x00AB0008)
#define GP_DIR1   		(* (volatile unsigned int * )0x00AB000C)
#define GP_CR0   		(* (volatile unsigned int * )0x00AB0010)
#define GP_CR1   		(* (volatile unsigned int * )0x00AB0014)

#define EINT_CR0   		(* (volatile unsigned int * )0x00AB0018)
#define EINT_CR1   		(* (volatile unsigned int * )0x00AB001C)
#define EINT_CR2   		(* (volatile unsigned int * )0x00AB0020)
#define EINT_CR3   		(* (volatile unsigned int * )0x00AB0024)
#define EINT_IER0  		(* (volatile unsigned int * )0x00AB0028)
#define EINT_IER1  		(* (volatile unsigned int * )0x00AB002C)
#define EINT_SR0   		(* (volatile unsigned int * )0x00AB0030)
#define EINT_SR1   		(* (volatile unsigned int * )0x00AB0034)

#define NEPCR   		(* (volatile unsigned char * )0x00AC001A)

// DMAC
#define DMAC_SAR        (*(volatile unsigned int *)(0x00AD0000))
#define DMAC_DAR        (*(volatile unsigned int *)(0x00AD0004))
#define DMAC_TCR        (*(volatile unsigned int *)(0x00AD0008))
#define DMAC_CSR        (*(volatile unsigned int *)(0x00AD000C))