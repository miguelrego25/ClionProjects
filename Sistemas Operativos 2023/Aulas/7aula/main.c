#include <stdio.h>
#include <unistd.h>

void filho_to_pai(){

    //int status;
    int p[2];
    if(pipe(p) == -1){
        perror("erro ao criar o pipe\n");
    }

    printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);

}



int main() {
    printf("Hello, World!\n");
    return 0;
}
