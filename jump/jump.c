#include <stdio.h>
#include <stdint.h>
#include <fleafb/fleafb.h>
#include <util/dos.h>
#include <util/seg.h>

static void
draw(void)
{
	WORD row;
	unsigned x, y;

	set_es(0xa000); // VGA buffer

	// draw a colorful pattern
	for (y = 0, row = 0; y < 200; y++, row += 320) {
		for (x = 0; x < 320; x++) {
			es_write8(x^y, row + x);
		}
	}
}

int
main()
{
	flea_init();
	puts("Starting ...");

	// Testing... draw the same thing 10 times
	int i;
	for (i = 0; i < 10; i++)
		draw();
	// TODO: loop until a key is pressed

	flea_done();
	puts("Thank you for playing!");
	return 0;
}
