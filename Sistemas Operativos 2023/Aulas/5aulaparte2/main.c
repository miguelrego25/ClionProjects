#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    for (int i = 1; i != argc; i++) {
        pid = fork();
        if(pid == 0) {
            int exec_ret = execlp(argv[i], argv[i], NULL);
            perror("reached return");
            _exit(exec_ret);
        }
    }
    for (int j = 0; j != argc; j++) {
        int status;
        printf("sou o pai e estou a espera dos filhos");
        pid_t pid = wait(&status);
        if(WIFEXITED(status)){
            printf("_exit: %d \n", WEXITSTATUS(status));
        }
    }
    return 1;
}

