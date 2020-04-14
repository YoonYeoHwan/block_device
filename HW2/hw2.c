#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define SECTOR_SIZE 512

int main() {

    int fd = 0;
    int LBA = 0;
    int size = 0;
    char *buff;

    fd = open("/dev/sda", __O_DIRECT);
    
    if(fd == -1) {
        printf("Fail to open.\n");
    }
    
    else {
        printf("LBA: ");
        scanf("%d", &LBA);
        printf("size: ");
        scanf("%d", &size);
	
	// posix_memalign(void **memptr, size_t alignment, size_t size)
	// size 바이트를 할당하여 할당한 메모리의 주소를 *memptr에 넣는다.
	// 할당한 메모리의 주소가 alignment의 배수가 된다.
	posix_memalign((void**)&buff, SECTOR_SIZE, 8192);

	lseek(fd, SECTOR_SIZE * LBA, SEEK_SET);
	read(fd, buff, size * SECTOR_SIZE);

    }

    close(fd);
    return 0;

}

