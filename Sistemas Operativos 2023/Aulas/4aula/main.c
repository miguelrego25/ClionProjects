//EX 3 DO GUIAO 2
#include <syscall.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    pid_t pid;
    int status;

    // Executar sequencialmente
    for (int i=0; i<10; i++){
        pid = fork();
        if(pid == 0) {
            printf("Pai = %d , Filho = %d \n", getppid(), getpid());
            exit(i);        // Para sair do correto
        }

        int status;                                     // Para termos a espera entre cada um elemento do ciclo
        pid_t pid = wait(&status);
        if(WIFEXITED(status)) {
            printf("_exit: %d \n", WEXITSTATUS(status));
        }
    }
    return 1;
}


//int res= fork();
//for (int i = 0; i < 5; i++) {
//if (fork() == 0) {
//printf("filho: %d\n", res);
//exit(0);
//}
//}