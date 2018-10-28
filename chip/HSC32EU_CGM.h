// +FHDR -----------------------------------------------------------------------
// Copyright (c) 2016, Hongsi.
// Hongsi Confidential Proprietary
// 2016/04/14 
//
// -----------------------------------------------------------------------------
// File Name: HSC32EU_cgm.h
// Type: C Language 
//
// -----------------------------------------------------------------------------
// Description:
// This code is the header file for CGM.
//
// -----------------------------------------------------------------------------
// Revision History
// DATE         AUTHOR          DESCRIPTION
// 2016/04/14 					V1.0
// -FHDR -----------------------------------------------------------------------

// ---------------------------------------------------------------------  
// Constant Definitions 
// ---------------------------------------------------------------------  
// 1. Clock Frequency Multiplier
// ---------------------------------------------------------------------  
#define EXT_CLOCK 		0x04000000
#define PLL_MODE 		0x10000000

// for input clock <= 12 MHz
#define CLOCK_24MHz 	0x00002b12
#define PLL_LOCKED		0x80000000
#define OSC_EN			0x20000000

// ---------------------------------------------------------------------  
// 2. Module Clock Switch
// ---------------------------------------------------------------------  
// for settings of MCSCR
#define DMAC_ON		0x20000000
#define USI3_ON		0x10000000
#define UART3_ON	USI3_ON
#define I2C_ON		0x08000000
#define GPCM_ON		0x02000000
#define NFCI_ON		0x01000000

#define STI2_ON		0x00800000
#define STI1_ON		0x00400000
#define EMMC_ON		0x00200000
#define USI2_ON		0x00100000
#define UART2_ON	USI2_ON
#define USI1_ON		0x00080000
#define UART1_ON	USI1_ON
#define SPI2_ON		0x00040000
#define SPI1_ON		0x00020000
#define USBI_ON		0x00010000

#define EDCU_ON		0x00001000
#define WDT_ON		0x00000800
#define PIT2_ON		0x00000400
#define PIT1_ON		0x00000200
#define PIT0_ON		0x00000100

#define BEAE_ON		0x00000080
#define TRNG_ON		0x00000040
#define AAE_ON		0x00000020
#define AES_ON		AAE_ON
#define FAE_ON		0x00000010
#define SSF33_ON	FAE_ON
#define SHAE_ON		0x00000008
#define SDAE_ON		0x00000004
#define BCAE_ON		0x00000002
#define SM1_ON		BCAE_ON
#define SM4_ON		BCAE_ON
#define DES_ON		BCAE_ON
#define REAE_ON		0x00000001
#define PK_RSA_ON	(SDAE_ON | REAE_ON)
#define PK_ECC_ON	(SDAE_ON | REAE_ON)
#define SM2_ON		(SHAE_ON | SDAE_ON | REAE_ON)

#define CLKOUT_ON	0x08000000

#define CLOSE_ALL	0x00000000

void Clock_Setting();

void set_flash_for_50MHz();		//for 40~50 MHz
void set_flash_for_60MHz();		//for 49~60 MHz
void set_flash_for_80MHz();		//for 64~80 MHz