#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("index.html", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    close(fd);

    return 0;
}
