#include <stdio.h>
#include <stdlib.h>



// generator de matrix

int RANDOM_MAX;

int** genMatrix(int rows, int cols){
    int** matrix = malloc(sizeof (int*) * rows);

    for (int i = 0; i < rows; ++i) {
        matrix[i] = malloc(sizeof (int)*cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % RANDOM_MAX;
        }
    }
    return matrix;
}

void lookupNumber(int** matrix, int rows, int cols, int target, int* result){}

int main(int argc, char* argv[]) {
    
    if(argc<2) return 1; //missing target number

    srand(time(NULL));
    int rows =10;
    int cols = 1e6;
    printf("cols: %d \n", cols);
    int target = atoi(argv[1]);
    int** matrix = genMatrix(rows, cols);
    int *vector = malloc(sizeof (int) *cols);
    lookupNumber(matrix, rows, cols, target,vector);

    //print the resulting vector
    printf("vector = [");
    for (int i = 0; i < rows; ++i) {
        printf("%d",vector[i]);
    }
    printf("]\n");

    //free matrix and vector
}
