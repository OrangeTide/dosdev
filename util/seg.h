#ifndef SEG_H_
#define SEG_H_
#include <util/dos.h>

static inline void
set_es(WORD seg)
{
	asm volatile("movw %0, %%es" : : "r" (seg) : );
}

static inline void
es_write8(BYTE value, WORD ofs)
{
	asm volatile("movb %0, %%es:%1"
		     : : "r" (value), "m" (*(void**)(ofs)) : );
}

static inline void
es_write16(WORD value, WORD ofs)
{
	asm volatile("movw %0, %%es:%1"
		     : : "r" (value), "m" (*(void**)(ofs)) : );
}

#endif
