#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char * argv[]) {
    pid_t pid;
    int needle = atoi(argv[1]);
    int rows = 10;
    int cols = 10000;
    int rand_max = 10000;
    int status;
    int **matrix;

    //seed random numbers
    srand(time(NULL));

    //Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d..", rand_max);
    matrix = (int **) malloc(sizeof (int*)*rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(sizeof (int) * cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % rand_max;
        }
    }
    printf("Done.\n");

}
