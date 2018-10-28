// +FHDR -----------------------------------------------------------------------
// Copyright (c) 2016, Hongsi.
// Hongsi Confidential Proprietary
// 2016/04/14 
//
// -----------------------------------------------------------------------------
// File Name: bcae.h
// Type: C Language 
//
// -----------------------------------------------------------------------------
// Description:
// This code is the header file for BCAE.
//
// -----------------------------------------------------------------------------
// Revision History
// DATE         AUTHOR          DESCRIPTION
// 2016/04/14 					V1.0
// -FHDR -----------------------------------------------------------------------

#ifndef __HS_BCAE_H__
#define __HS_BCAE_H__
// -----------------------------------------------------------------------------
// Constant Definition 
// -----------------------------------------------------------------------------
#define DES_64		0x00000000
#define DES_128		0x00000010
#define DES_192		0x00000018
#define SM1			0x00000800
#define SM4			0x00000C00
#define SM4_KEY_EXP	0x00000100

#define Start_BCAE_RAM_Operation	(BCAE_CSR |= 0x0080)
#define Enable_BCAE_Int		(BCAE_CSR |= 0x0040)
#define Disable_BCAE_Int	(BCAE_CSR &= 0xFFBF)
#define BCAE_Soft_Reset		(BCAE_CSR |= 0x0200)
#define Enable_BCAE_Secu	(BCAE_CSR |= 0x0020)
#define Disable_BCAE_Secu	(BCAE_CSR &= 0xFFDF)

#define BCAE_KEY_BUSY		0x0100

#define ECB_MODE			0x0000
#define CBC_MODE			0x0004
#define BCAE_ENCRYPT		0x0000
#define BCAE_DECRYPT		0x0002

#define BCAE_RUN			0x0001
#define BCAE_BUSY			0x0001

#define OPER_ENC			0
#define OPER_DEC			1
#define MODE_ECB			0
#define MODE_CBC			1

void BCAE_Init(unsigned int, unsigned int, unsigned int, unsigned char *, unsigned char *);
int BCAE_Run(unsigned char *, unsigned char *, unsigned int);
int BCAE_Run_RAM(unsigned int, unsigned int);

#endif