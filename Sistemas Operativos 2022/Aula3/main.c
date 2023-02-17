#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
//ficha 2
int main() {
    /*
    puts("ola");
    pid_t pid;
    fork();
    //pid=fork();
    printf("pid=%d\n",pid);
    return 0;

printf("I'm printed once!\n");
fork();
// Now there are two processes running one is parent and another child.
// and each process will print out the next line.
printf("You see this line twice!\n");
*/
    pid_t pid;
    pid=fork();
    if(pid==0){/*filho*/
        printf("filho=%d, pai=%d\n",getpid(),getfpid());
        // ->exit(0) ->_exit(0);
        printf("pai=%d,filho=%d,bash=%d\n",getpid(),pid,getfpid());
        return 0;
    }
}
//atexit(void(*f)(void) faz algo no fim do programa
