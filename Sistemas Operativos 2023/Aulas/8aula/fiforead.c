#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//s
//escreve linhas para o input
int main(int argc, char* argv[]) {


    int buffer[4096];
    int bytes_read;

    int fd = open("fifo",O_RDONLY);

    printf("abri fifo escritor \n");

    while((bytes_read = read(fd,buffer,4096))>0){
        write(1,buffer,bytes_read);
    }
    printf("sai do while escritor \n");
    close(fd);

    unlink("mkfifo");

    return 0;

}

