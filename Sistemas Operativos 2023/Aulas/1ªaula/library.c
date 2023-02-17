#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int mycp(char* input_file, char* output_file, int size){

    //abrir o ficheiro de entrada
    int fd_in = open(input_file, O_RDONLY);
    if(fd_in < 0){
        perror("erro ao abrir ficheiro de entrada" );
        return -1;
    }

    //abrir ficheiro de saida
    int fd_out = open(output_file, O_WRONLY | O_CREAT, 0640);
    if(fd_out < 0 ){
        perror("erro ao abir o ficheiro de saida");
        return -1;
    }

    //ler do ficheiro de input
    char buff[size];
    ssize_t bytes_read = read(fd_in, buff ,size);

    //escrever no ficheiro de output
    ssize_t bytes_written = write(fd_out, buff, size );

    //fechar ficheiro de entrada
    close(fd_in);

    //fechar ficheiro de saida
    close(fd_out);

}

int main(int argc, char** argv){
    mycp(argv[1],argv[2],argc);
}
