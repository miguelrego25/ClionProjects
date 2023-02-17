#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if(argc !=3){
        fprintf(stderr, "usage:usage:%s source destination \n", argv[0]);
        return 1;
    }
    int sfd = open(argv[1], O_RDONLY);
    if(sfd == -1) {
        perror (argc [1]);
        return 1;
    }
    int dfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if(sfd == -1) {
        perror (argc[2]);
        return 1;
    }
    int n;
    char c;
    while(1){
        n=read(sfd, &c, sizeof (c));
        if (n <= 0) break;
        write (dfd, &c, n);
    }
    close(sfd);
    close(dfd);

    return 0; /* EXIT_SUCESS */
}
/*
gcc -Wall mycp.c -o mycp
./mycp
cat > coiso.txt
 ola pessoal de sistemas operativos
 tudo ok?
 ls -l
 ./mycp coiso.txt
./mycp coiso.txt copia.txt
echo $?
ls -l
cmp coiso.txt mycp.c
cat coiso.txt
vi coiso.txt
ls -lh
 */