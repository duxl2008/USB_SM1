// -----------------------------------------------------------------------------
// File Name: hs32eu_flash_func.h
// Type: C Language 
//
// -----------------------------------------------------------------------------
// Header:
// Definitions for FLASH Function of HS32EU.
//
// -----------------------------------------------------------------------------
// Detailed Func Description:
// 1. Constant Definitions.
// 2. Register Definitions.
// 3. Function Declarations.
//
// -----------------------------------------------------------------------------
// Revision History
// DATE         AUTHOR          DESCRIPTION
// 2016/3/31 					V1.0
// -----------------------------------------------------------------------------

typedef unsigned int			U32;			
typedef unsigned short			U16;			
typedef unsigned char			U8;			

// ---------------------------------------------------------------------  
// Constant Definitions
// ---------------------------------------------------------------------  

#define WRITE_COMMAND			0x2233
#define ERASE_COMMAND			0x4455
#define FINISH_WRITE_COMMAND	0xAA
#define FLASH_SIZE				0x00080000
#define PAGE_SIZE				256
#define SECTOR_SIZE				512

// ---------------------------------------------------------------------  
// Function Declarations
// ---------------------------------------------------------------------  

void EraseCode(U8 *);

void WriteCode(U8 *, U8 *, U32);

void FlashInit();

U32 FlashRead(U32, U8 *, U32);

U32 FlashWrite(U32, U8 *, U32);

U32 FlashWriteOnly(U32, U8 *, U32);