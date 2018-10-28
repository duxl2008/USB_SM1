#include "types.h"

void memcpy(U8 *dst, U8 *src, U32 len)
{
	U32 i;
	
	for(i=0; i<len; i++) dst[i] = src[i];
}