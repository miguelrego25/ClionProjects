#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main1(int argc, char* argv[]) {

    int res = mkfifo("fifo",0666);

    return 0;
}


int main(int argc, char* argv[]) {


    int buffer[4096];
    int bytes_read;
    int fd = open("fifo",O_WRONLY);

    printf("abri fifo escritor \n");

    while((bytes_read = read(fd,buffer,4096))>0){
        write(1,buffer,bytes_read);
    }
    printf("sai do while escritor \n");
    close(fd);

    return 0;
}

