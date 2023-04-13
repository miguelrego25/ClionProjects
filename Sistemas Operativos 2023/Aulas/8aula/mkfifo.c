#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[]){

    if(mkfifo("fifo", 0600) < 0) perror("Erro fifo");

    //unlink("fifo");        MATA O PIPE

}