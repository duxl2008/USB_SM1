// +FHDR -----------------------------------------------------------------------
// Copyright (c) 2016, Hongsi.
// Hongsi Confidential Proprietary
// 2016/04/14 
//
// -----------------------------------------------------------------------------
// File Name: bcae_func.c
// Type: C Language 
//
// -----------------------------------------------------------------------------
// Description:
// This code is the functions for BCAE.
//
// -----------------------------------------------------------------------------
// Detailed Func Description:
// 1. Initailize BCAE
// 2. Run BCAE in register mode
// 3. Run BACE in RAM mode
//
// -----------------------------------------------------------------------------
// Revision History
// DATE         AUTHOR          DESCRIPTION
// 2016/04/14 					V1.0
// -FHDR -----------------------------------------------------------------------
 
// ---------------------------------------------------------------------  
// Include File Declarations 
// ---------------------------------------------------------------------  

#include "HSC32EU_cgm.h"
#include "HSC32EU_registers.h"
#include "bcae.h"

unsigned int Run_DES;
// ---------------------------------------------------------------------  
// Function Declarations 
// ---------------------------------------------------------------------  

// ---------------------------------------------------------------------  
// Func : BCAE_Init()
// Description : Initialize BCAE
// ---------------------------------------------------------------------  
// Input
//
//-----------------------------------------------------------------
// Output
// No
void BCAE_Init (unsigned int algorithm,
				unsigned int decrypt, unsigned int cbc_mode,
				unsigned char *key, unsigned char *iv)
{
	unsigned int i, n;
	unsigned int tmp[6];
	
	// Enable BCAE work
	MCGCR |= BCAE_ON;

	BCAE_Soft_Reset;
	BCAE_CSR = algorithm;
	if(decrypt) BCAE_CSR |= BCAE_DECRYPT;

	
	switch(algorithm)
	{
		case DES_64: n = 2; break;
		case DES_192: n = 6; break;	
		default: n = 4;	
	}
	memcpy(tmp, key, n*4);
	for(i=0;i<n;i++) 
	{
		BCAE_KINR = tmp[i];
	}	
	
	if((algorithm == SM4) && (decrypt!=0)) 
	{
		BCAE_CSR |= SM4_KEY_EXP;
		while(BCAE_CSR & BCAE_KEY_BUSY);
	}
	
	if(cbc_mode) 
	{
		BCAE_CSR |= CBC_MODE;
		switch(algorithm)
		{
			case SM1:
			case SM4:
				n = 4;
				break;
			default:
				n = 2;
		}
		memcpy((unsigned char*)tmp, iv, n*4);
		for(i=0;i<n;i++) BCAE_IVINR = tmp[i];
	}	
	
	Run_DES = (algorithm < 0x0800)?1:0;
}

int BCAE_Run(unsigned char *in, unsigned char *out, unsigned int len)
{
	unsigned int i, n, tmp[4], remain, offset=0;
	
	n = (Run_DES==0)?16:8;	
	if(len & (n-1)) return -1;
	
	remain = len;
	offset = 0;
	
	while(remain)
	{
		memcpy(tmp, in+offset, n);
		for(i=0;i<(n>>2);i++) BCAE_DATR = tmp[i];
	
		BCAE_CSR |= BCAE_RUN;
		while(BCAE_CSR & BCAE_BUSY);
		
		for(i=0;i<(n>>2);i++) tmp[i] = BCAE_DATR;
		memcpy(out+offset, tmp, n);
		
		remain -= n;
		offset += n;
	}
	return 0;
}

int BCAE_Run_RAM(unsigned int addr, unsigned int len)
{
	unsigned int n;
	
	n = (Run_DES==0)?16:8;	
	if(len & (n-1)) return -1;	
	if((len + addr) > 8192) return -2; 
	
	BCAE_ADDR = ((addr & 0x1fff)<<16)|(addr & 0x1fff);
	
	BCAE_LENR = len;
		
	Start_BCAE_RAM_Operation;
	
	while(BCAE_CSR & BCAE_BUSY);
	
	return 0;
}

int BCAE_Run_RAM_2(unsigned int in_addr, unsigned int out_addr, unsigned int len)
{
	unsigned int n;
	
	n = (Run_DES==0)?16:8;	
	if(len & (n-1)) return -1;	
	if(((len + in_addr) > 8192) || ((len + out_addr) > 8192)) return -2; 
	
	BCAE_ADDR = ((out_addr & 0x1fff)<<16)|(in_addr & 0x1fff);
	
	BCAE_LENR = len;
		
	Start_BCAE_RAM_Operation;
	
	while(BCAE_CSR & BCAE_BUSY);
	
	return 0;
}