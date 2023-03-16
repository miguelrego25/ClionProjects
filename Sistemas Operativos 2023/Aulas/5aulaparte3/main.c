#include <stdio.h>

int main() {

    char commando1[] = "ls -l -a -h";
    char commando2[] = "sleep 10";
    char commando3[] = "ps";
    int ret;

    printf("a executar mysystem para %s \n", commando1);
    ret = mysystem(commando1);
    printf("ret: %d\n",ret);

    printf("a executar mysystem para %s \n", commando2);
    mysystem(commando2);
    printf("a executar mysystem para %s \n", commando3);
    mysystem(commando3);
    //nao acabado
}
