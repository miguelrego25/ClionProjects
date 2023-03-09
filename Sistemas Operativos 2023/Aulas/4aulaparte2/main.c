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
            if(pid == 0)
                printf("Pai = %d , Filho = %d \n", getppid(), getpid());
            // Para sair do correto
            _exit(i);
        }
    }
    for(int i = 1; i<10;i++){
        pid_t terminated_pid = wait(&status);

        if(WIFEXITED(status)){
            printf("Pid: %d, _exit: %d \n", pid, WEXITSTATUS(status));
        }


    }

    return 0;
}
