#define _GNU_SOURCE
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int fd = open( "/tmp/file", O_CREAT | O_RDWR, 0666 );
    getchar();
	unlink( "/tmp/file" );
}
