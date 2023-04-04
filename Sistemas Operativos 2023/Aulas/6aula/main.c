#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

//retorna -1 se fork falha senao retorna valor do comando executado

int mysystem(char *command){
    int fork_ret, exec_ret, status, res;
    int buf[100];
    //estamos a assumir o numero maximo de argumentos isto teria de ser melhorado

    char* exec_args[20];
    char* string = NULL;
    int i  = 0;
    char* cmd = strdup(command);

    string = strsep(&cmd, " ");
    while(string!= NULL){
        exec_args[i] = string;
        string = strsep(&cmd, " ");
        i++;
    }
    exec_args[i] =NULL;

    pid_t pid;
    x = fork();

    if(pid==0) {
        execvp(buff[0], buf);
        _exit(1);
        return 0;
    }

    wait(&status);


}

int main() {
    printf("Hello, World!\n");
    return 0;
}
