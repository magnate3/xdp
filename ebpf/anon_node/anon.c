#define _GNU_SOURCE
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int f = open(".", O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
    struct stat s;
    fstat(f, &s);
    printf("pid %jd\n", (intmax_t)getpid());
    printf("inode %jd\n", (intmax_t)s.st_ino);
    getchar();
}