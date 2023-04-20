#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>


int main(int argc, char* argv[]){

    if(argc < 3){
        perror("not enough arguments");
        exit(1);
    }

    int fifo_fd = open("CFifo", O_WRONLY);







}