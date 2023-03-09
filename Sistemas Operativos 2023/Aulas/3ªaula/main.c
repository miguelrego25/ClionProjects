#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syscall.h>
#include <fcntl.h>
#include "person.h"

int AddPerson(char* name, int age){
    Person p;
    strcpy(p.name,name);
    p.age = age;

    //append permite escrever logo no fim
    int fd = open(FILENAME, O_WRONLY || O_CREATE || O_APPEND);

    if(fd == -1){
        perror("Error opening file");
        return -1;
    }

    int bytes_written = write(fd,&p,sizeof(Person));

    if (bytes_written == -1){
        perror("Error writting in file");
        return -1;
    }
    close(bytes_written);
    close(fd);

}

int updateAge(char* name, int age){
    while((look = read(FILENAME,&p,sizeof(Person)))){
        if(p.name == p){
            lseek(FILENAME,sizeof(&p))
        }
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
/*
FD = open ...;
Pessoa P;
write(FD,&P,Sizeof(p))
close*/