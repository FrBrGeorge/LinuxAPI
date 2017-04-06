/*
   mmcopy source-file dest-file
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *src, *dst;
    int fdSrc, fdDst;
    struct stat sb;

    fdSrc = open("in.txt", O_RDONLY);

    fstat(fdSrc, &sb);

    src = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fdSrc, 0);

    fdDst = open("out.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    ftruncate(fdDst, sb.st_size);

    dst = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdDst, 0);

    memcpy(dst, src, sb.st_size);

    msync(dst, sb.st_size, MS_SYNC);

    exit(EXIT_SUCCESS);
}
