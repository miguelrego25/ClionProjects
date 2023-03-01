#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t readln(int fd, char *line, size_t size){
    int counter = 0;
    while(read(0,line+counter,1)>0 && counter < size
        && line[counter] != '\n'){
        counter++;
    }
    if(counter == size) return 0;
    else{
        return counter;
    }
}

int main() {
    char buffer[10];

    printf ("%ld \n", readln (0, buffer, sizeof(buffer)));
    return 0;
}
