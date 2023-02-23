#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
//casos de paragem do readline
//no while temos que meter enquanto o readc está a devolver algo maior que zero(ou
//seja quer dizer que conseguimos ler algo

//como sabemos se queremos ler mais ou nao
ssize_t readc(int fd,char* ch){
    return read(fd,ch, 1);
}
ssize_t readln(int fd, char *line, size_t size) {
    ssize_t i = 0;
    while (i < size - 1) {
        ssize_t bytesread = readc(fd, line);
        if (bytesread < -1) break;
        if (line[i++] == '\n') break;
        i++;
    }
}

    int main(int argc, char **argv) {
        printf("Hello, World!\n");
        return 0;
    }

/* versao da sora
 * ssize_t readln(int fd, char* line, size_T size){
 *      int pos = 0;
 *      //ler caractere a caracter enquanto houver algo para ler
 *      //e houver espaço no buffer (pos< size)
 *      while(pos< size && readch(fd,&line[pos]>0){
 *          pos++;
 *          if(line[pos-1] == '\n') break;
 *          }
 *          }
 *          //devolver a posiçao atual (= numero de bytes lidos)
 *          return pos;
*///tenho fotos no telemovel da resoluçao do nl tb 23 fevereiro