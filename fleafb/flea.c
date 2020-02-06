#include "fleafb.h"
#include <stdio.h>

#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define PATCH_VERSION 0
#define VERSION_ID(maj,min) ( \
	((unsigned)(maj) << 8) | \
	(unsigned)(min))

unsigned char old_mode = 0x03;

unsigned flea_version(void) { return VERSION_ID(MAJOR_VERSION, MINOR_VERSION); }

static void
save_mode(void)
{
	asm volatile(
		"movb $0x0f, %%ah\n"
		"int $0x10\n"
		: "=al" (old_mode)
		: /* no inputs */
		: "ah", "sp", "si", "di");
}

static void
set_mode(unsigned char mode)
{
	asm volatile(
		"xorb %%ah, %%ah\n"
		"int $0x10\n"
		: /* no outputs */
		: "al" (mode)
		: "ax", "sp", "si", "di");
}

int
flea_init(void)
{
	save_mode();
	set_mode(0x13); /* MCGA/VGA */

	return 0;
}

void
flea_done(void)
{
	set_mode(old_mode);
}
