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

    execlp("wc","wc",NULL);

    PIPE(pfd);
    if(fork()==0){
        close(pfd);
        dup2(pfd(0));
        execlp("wc","wc",NULL);
    }else{
        close(pfd(0));
        while((read(0,buffer,1024))>0){
            write(pfo,)
        }
    }
    return 0;
}
