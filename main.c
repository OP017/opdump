#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "dump.h"

int main(int argc, char *argv[])
{	unsigned char buffer[16];
	size_t offset = 0;
	size_t bytes_read;

	if (argc == 2) {
	
		FILE *ptr = fopen(argv[1], "rb");
		if (ptr == NULL) {
			fprintf(stderr, "opdmp: %s: %s\n", argv[1], strerror(errno));

			return 1;
		}
	
		bytes_read = fread(buffer, 1, 16, ptr);

		while (bytes_read > 0) {
		
			dump_line(offset, bytes_read, buffer);
			offset = offset + bytes_read;
			bytes_read = fread(buffer, 1, 16, ptr);
		}
		
		fclose(ptr);
	}
	else {
	printf("Example Usage: > hacksdump example.bin");
	return 1;
	}

	return 0;
}
