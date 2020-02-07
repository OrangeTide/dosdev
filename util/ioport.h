#ifndef IOPORT_H_
#define IOPORT_H_

static inline void
outb(unsigned char value, int port)
{
	asm volatile("outb %b0, %w1" : : "a" (value), "Nd" (port));
}

static inline void
outw(unsigned short value, int port)
{
	asm volatile("outw %w0, %w1" : : "a" (value), "Nd" (port));
}

static inline unsigned char
inb(int port)
{
	unsigned char value;
	asm volatile("inb %w1, %b0" : "=a" (value) : "Nd" (port));
	return value;
}

static inline unsigned short
inw(int port)
{
	unsigned short value;
	asm volatile("inw %w1, %w0" : "=a" (value) : "Nd" (port));
	return value;
}

#endif
