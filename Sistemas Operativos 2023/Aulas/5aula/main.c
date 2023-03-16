#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int rows;
    int needle;
    int status;
    int cols;
    char** matrix;

    for (int i = 0; i < rows; i++) {
        if(pid = fork() == 0){
            printf("[pid %d] row: %d\n", getpid(), i);

            open();
            lseek(fd, i*j*sizeof (int));

            for (int j = 0; j < cols; ++j) {
                if(matrix[i][j] == needle){
                    _exit(i);
                }
            }
            _exit(-1);

            //start search
        }
    }


    int res[rows];
    for (int i = 0; i < rows; ++i) {
        pid_t terminated_pid = wait(&status);
        if(WIFEXITED(status)){
            if(WIFEXITED(status)<255)
                printf("[pai]process %d exited.found at row: %d\n", terminated_pid, WIFEXITED(status));
            else
                printf("[pai]process %d exited.nothing found: %d\n", terminated_pid);
        }
        else{
            printf("[pai] process %d exited. something went wrong\n", terminated_pid);
        }
    }

    printf("Hello, World!\n");
    return 0;
}
