#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int bytes_written;
    char buffer[4096];
    while (1) {
        int fifo = open("mkfifo", O_RDONLY);

        while (read(fifo, buffer, 4096) > 0) {
            write(1, buffer, 4096);
        }
        close(fifo);

        unlink("mkfifo");

    }
    mkfifo("mkfifo", 0666);
}
//version2
int main2(int argc, char* argv[]) {

    int bytes_written;
    char buffer[4096];
    int fifo = open("mkfifo", O_RDONLY);
    int fd = open("mkfifo2",O_WRONLY); // assim esta sempre a ler alguma coisa ou seja isto vai estar sempre a executar
    while (read(fifo, buffer, 4096) > 0) {
        write(1, buffer, 4096);
    }
    close(fifo);

    unlink("mkfifo");

    mkfifo("mkfifo", 0666);
}
