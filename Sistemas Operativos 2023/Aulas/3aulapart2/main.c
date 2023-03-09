#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int i = 10;
    int status;
    pid_t my_pid = getpid();
    printf("my pid = %d\n", my_pid);

    pid_t pid_parent = getppid();
    printf("parent pid = %d\n", pid_parent);


    pid_t res = fork();

    if(res==0){
        i = i - 5;
        printf("filho |pid = %d\n", getpid());
        printf("filho |parent pid = %d\n", getppid());
        printf("filho | %i \n", i);
        _exit(0);
    }
    else{
        i = i + 5;
        printf("pai |pid = %d\n", getpid());
        printf("pai |parent pid = %d\n", getppid());
        printf("pai |filho pid = %d\n", res);
        pid_t filho_terminou = wait(&status);
        printf("filho |pid = %d\n", getpid());
        printf("pai | depois do wait\n");
        printf("pai | %i \n", i);
        if(WIFEXITED(status)){
            printf("filho return value %d\n", WIFEXITED(status));
        }
    }

    printf("pid = %d vou terminar :)\n", getpid());

    printf("fork res = %d\n", res);
}
