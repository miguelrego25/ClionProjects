//Resolução do guião 1
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1
//quando se aumenta o buffer dá merdass

int mycp(char* input_file, char* output_file){
    int n; //para o ciclo while
    int fd_in = open(input_file,O_RDONLY);
    if (fd_in < 0){
        perror("invalid input file");
        return -1;
    }
    int fd_out = open(output_file,O_CREAT|O_TRUNC|O_WRONLY, 0666);
    if (fd_out < 0){
        perror("invalid output file");
        return -1;
    }


    char buff[MAX];
    /*
    ssize_t byten_read = read(fd_in,buff,size);
    ssize_t byten_written = write(fd_out, buff, size);
    */
    while((n = read(fd_in,buff,MAX)>0)){
        write(fd_out,buff,n);
    }

    close(fd_in);
    close(fd_out);
}



int main(int argc, char* argv[argc]){
    if(argc!=3){
        printf("Usage: %s <SOURCE> <DESTINATION>", argv[0]);
        exit(EXIT_FAILURE);
    }
    mycp(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
