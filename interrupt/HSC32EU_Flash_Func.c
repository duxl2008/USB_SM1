#include "HSC32EU_Flash_Func.h"
#include "HSC32EU_registers.h"
#include "interrupt.h"
#include "types.h"

unsigned int sram_write[24];
unsigned int sram_erase[10];

void (*Page_Write)(unsigned char*, unsigned char *, unsigned int);
void (*Sector_Erase)(unsigned char*);

void EraseCode(unsigned char *addr)
{
		
	EFM_CMDR1 = ERASE_COMMAND;	
	(*(volatile unsigned char*)addr) = 0xff;	
	
}

void WriteCode(unsigned char *addr, unsigned char *buff, unsigned int len)
{
	unsigned int i;
	
	
	EFM_CMDR1 = WRITE_COMMAND;
	
	for(i = 0; i < len; i++, *addr++)
	{
	 	(*(volatile unsigned char*)addr) = buff[i];
	}

	EFM_CMDR2 = FINISH_WRITE_COMMAND;
	
}

void FlashInit()
{	
	memcpy(sram_erase, EraseCode, 36);
	Sector_Erase = (void (*)(unsigned char*))sram_erase;
	
	memcpy(sram_write, WriteCode, 96);	
	Page_Write = (void (*)(unsigned char*, unsigned char*, unsigned int))sram_write;
}

/*---------------------------------------------------------------
result:
0 - same, don't need writing
1 - same or flash room clean, need writing only
2 - need erase for writing
---------------------------------------------------------------*/
U32 sector_compare(U32 addr, U8 *data, U32 len)
{
	U8 *p;
	U32 result = 0, i;
	
	p = (U8*)addr;
	for(i = 0; i < len; i++)
	{
		if(p[i] != data[i])
		{
			if(p[i] != 0xff) return 2;
			else result = 1;
		}
	}
	
	return result;
}

U32 sector_write_only(U32 addr, U8 *data, U32 len)
{
	U8 *p;
	U32 page_border, first_page_len, ret;

	if((addr + len) >= FLASH_SIZE) return 1;
	if(((addr & 0xff) + len) > SECTOR_SIZE) return 2;
	
	
	p = (U8*)data;
	page_border = (addr & 0xfffffe00) + PAGE_SIZE;
	
	if(page_border > addr)
	{
		first_page_len = page_border - addr;
		if(first_page_len > len) first_page_len = len;
		
		Disable_Interrupts;
		Page_Write((unsigned char*)addr, p, first_page_len);
		Enable_Interrupts;
		
		addr += first_page_len;
		p += first_page_len;
		len -= first_page_len;
	}
	
	if(len) 
	{
		Disable_Interrupts;
		Page_Write((unsigned char*)addr, p, len);
		Enable_Interrupts;
	}
	return 0;		
}

U32 sector_write(U32 addr, U8 *data, U32 len)
{
	U32 ret;
	
	ret = sector_compare(addr, data,len);
	
	if(ret == 0) return ret;
	else if(ret == 1)
	{
		ret = sector_write_only(addr, data, len);
	}
	else
	{
		U32 *p, *d;
		U32 sector_begin, sector_end, i, n1 = 0, n2 = 0, n, offset;
		U8 tmp[512];
		
		sector_begin = addr & 0xfffffe00;
		sector_end = sector_begin + SECTOR_SIZE;
		
		if(addr > sector_begin)
		{
			n1 = (addr - sector_begin);
			n = n1 >> 2;
			if(n1 & 3) n++;
			
			p = (U32*)sector_begin;
			d = (U32*)tmp;
			
			for(i = 0; i < n; i++, p++, d++) *d = *p;
		}
		
		if((addr + len) < sector_end)
		{
			n2 = (sector_end - addr - len);
			n =  n2 >> 2;
			p = (U32*)((addr + len) & 0xfffffffc);
			offset = ((U32)p & 0x01fc);
			d = (U32*)&tmp[offset];
			
			for(i = 0; i < n; i++, p++, d++) *d = *p;			
		}
		Disable_Interrupts;
		Sector_Erase((unsigned char*)addr);
		Enable_Interrupts;
		if(n1) ret = sector_write_only(sector_begin, tmp, n1);
		ret = sector_write_only(addr, data, len);
		if(n2) ret = sector_write_only(addr + len, tmp + (addr & 0x1ff) + len, n2);
	}
	
	return ret;	
}

U32 FlashRead(unsigned int addr, unsigned char *buff, unsigned int len)
{
	unsigned int i;
	
	if((addr + len) >= FLASH_SIZE) return 1;
	
	for(i = 0; i < len; i++, addr++)
	{
		buff[i] = (*(U8*)addr);
	}
	
	return 0;
}

U32 FlashWrite(unsigned int addr, unsigned char *buff, unsigned int len)
{
	unsigned int sector_length, offset = 0, ret;
	
	if((addr + len) >= FLASH_SIZE) return 1;
	
	sector_length = SECTOR_SIZE - (addr & 0x1ff);
	if(sector_length > len) sector_length = len;
	while(len)
	{
		ret = sector_write(addr, buff + offset, sector_length);
		if(ret) break;
		
		addr += sector_length;
		offset += sector_length;
		len -= sector_length;
		
		if(len > SECTOR_SIZE) sector_length = SECTOR_SIZE;	
		else sector_length = len;	
	}
	
	return ret;	
};

U32 FlashWriteOnly(unsigned int addr, unsigned char *buff, unsigned int len)
{
	unsigned int sector_length, offset = 0, ret;
	
	if((addr + len) >= FLASH_SIZE) return 1;
	
	sector_length = SECTOR_SIZE - (addr & 0x1ff);
	if(sector_length > len) sector_length = len;
	while(len)
	{
		ret = sector_write_only(addr, buff + offset, sector_length);
		if(ret) break;
		
		addr += sector_length;
		offset += sector_length;
		len -= sector_length;
		
		if(len > SECTOR_SIZE) sector_length = SECTOR_SIZE;	
		else sector_length = len;	
	}
	
	return ret;
};

U32 FlashSectorErase(unsigned int addr)
{
	if(addr >= FLASH_SIZE) return 1;
	
	Disable_Interrupts;
	Sector_Erase((unsigned char*)(addr & 0x7fe00));
	Enable_Interrupts;
	return 0;
}