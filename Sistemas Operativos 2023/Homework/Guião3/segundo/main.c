#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();


    if(pid == 0){
        execlp("ls","ls","-l",NULL);
        _exit(0);
    }
    int status;
    pid = wait(&status);
    if(WIFEXITED(status))printf("\n_exit: %d \n", WEXITSTATUS(status));
    return 1;
}
