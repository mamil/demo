#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int fd, offset;
    char* data;
    struct stat sbuf;

    if (argc != 2) {
        fprintf(stderr, "usage:mmapdemo offset\n");
        exit(1);
    }

    if ((fd = open("test.dat", O_RDONLY)) == -1) {//打开文件自身
        perror("open");
        exit(1);
    }

    if (stat("test.dat", &sbuf) == -1) {//文件大小，mmap的有效内存大小不超过该值
        perror("stat");
        exit(1);
    }

    offset = atoi(argv[1]);//文件偏移量
    if (offset < 0 || offset > sbuf.st_size - 1) {
        fprintf(stderr, "mmapdemo: offset must be in the range 0-%d\n",
                sbuf.st_size - 1);
        exit(1);
    }

    data = (char*)mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if (data == (caddr_t)(-1)) {
        perror("mmap");
        exit(1);
    }

    printf("byte at offset %d is '%c'\n", offset, data[offset]);

    return 0;
}