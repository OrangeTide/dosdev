#include <stdio.h>
#include <fleafb.h>
int
main()
{
	puts("Starting ...");
	flea_init();
	// TODO: loop on something cool
	flea_done();
	puts("Thank you for playing!");
	return 0;
}
