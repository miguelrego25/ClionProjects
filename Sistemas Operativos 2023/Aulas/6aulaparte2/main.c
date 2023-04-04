#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void pai_to_filho(){
    int status;
    int p[2];
    if(pipe(p) == -1){
        perror("erro ao criar pipe \n");
    }
    printf("p[o] = %d, p[1] = %d\n", p[0], p[1]);
    int fork_ret = fork();
    if(fork_ret == 0) {
        int res = 0;
        if (read(p[0], &res, sizeof(int)) == -1) {
            perror("FILHO|ERRO AO LER DO PIPE\n");
        }
        printf("FILLHO | li o valor %d\n ", res);
        _exit(0);
    }else{
        int value= 40;
        close(p[0]);
        printf("pai | vou envivar o valor %d\n", value);
        if(write(p[1],&value, sizeof(int))== -1){
            perror("PAI| erro ao escrever para o pipe \n");
        }
        close(p[1]);
        wait(&status);
    }
}

void filho_to_pai(){
    
}


int main() {
    pai_to_filho();
    return 0;
}
