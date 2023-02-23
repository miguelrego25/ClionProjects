//Resolução do guião 1
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

int mycp(char* input_file, char* output_file, int size){
    int fd_in = open(input_file, O_RDONLY);
    if (fd_in < 0){
        perror("Erro ao abrir o ficheiro de entrada");
        return -1;
    }
    int fd_out = open(output_file, O_RDWR);
    if(fd_out < 0){
        perror("Erro ao abrir o ficheiro de entrada");
        return -1;
    }

    char buffer[MAX];
    ssize_t bytes_read = read(fd_in, buffer,size);

    ssize_t bytes_written = write(fd_out,buffer,size);

    close(fd_in);
    close(fd_out);

}


int main(int argc, char** argv) {
    mycp(argv[1], argv[2],argc);
}
