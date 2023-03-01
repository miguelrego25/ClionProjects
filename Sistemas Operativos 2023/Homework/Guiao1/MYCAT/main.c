#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4

//Implemente em C um programa mycat com funcionalidade similar ao
//comando cat, que lê do seu stdin e escreve para o seu stdout


int main(int argc,char* argv[]) {
    char buff[MAX];
    int fd_out, fd_in, n;
    while((n = read(0,buff,sizeof(buff))>0)){
        write(1,buff, n);
    }

    return 0;
}
