#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    char buffer[1024];
    int res;

    int fdpass = open("/etc/passwd",O_RDONLY);
    int fdsaida = open("saida.txt",O_CREAT | O_TRUNC | O_WRONLY,0666);
    int fderr = open("erros.txt",O_CREAT | O_TRUNC | O_WRONLY,0666);
    int fdout = dup(1);

    dup2(fdpass,0);
    close(fdpass);

    dup2(fdsaida,1);
    close(fdpass);

    dup2(fderr,2);
    close(fdpass);

    while((res = read(0, buffer,100))>0){
        write(1,buffer,res);    //standard output
        write(2,buffer,res);   //standard error
    }

    dup2(fdout,1);

    printf("terminei \n");
    return 0;
}
