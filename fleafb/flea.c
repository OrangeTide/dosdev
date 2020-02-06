#include "fleafb.h"
#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define PATCH_VERSION 0
#define VERSION_ID(maj,min) ( \
	((unsigned)(maj) << 8) | \
	(unsigned)(min))
unsigned flea_version(void) { return VERSION_ID(MAJOR_VERSION, MINOR_VERSION); }
