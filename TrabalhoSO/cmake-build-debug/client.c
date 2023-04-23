#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>


int main(int argc, char* argv[]) {

    if (argc < 3) {
        perror("not enough arguments");
        exit(1);
    }
    while (1) {

        /*
        int server_fd = open("server_Fifo", O_WRONLY);
        if (server_fd < 0) {
            perror("Erro ao abrir FIFO");
            exit(1);
        }
//
        //passar a informação para o servidor
        //esta errado tem que se arranjar uma maneira atraves de
        //uma struct ou assim
        for (int i = 1; i < argc; i++) {
            write(server_fd, argv[i], strlen(argv[i]) + 1);
        }
         */

        pid_t pid = fork();

        if(pid < 0){
            perror("erro ao criar processo");
            exit(1);

        }else if(pid == 0){
            pid_t child_pid = getpid();
            int server_fd = open("server_Fifo", O_WRONLY);

            if(server_fd < 0){
                perror("erro ao abrir pipe do servidor");
                exit(1);
            }
            //falta aqui escrever para o server as informaçoes
            //atraves da estrutura que decidirmos fazer
            //write(server_fd, message, strlen(message)

            //mais 3 argumentos são "name of file", "execute", "-u"
            execvp("cliente", argv+2);
            perror("erro ao executar o comando");
            exit(1);
        }else{
            //codigo processo pai
            //vai ser necessario para transmitir o tempo que passou
            //ao servidor

            //espera pelo filho terminar
            int status;
            waitpid(pid,&status,0);
        }
    }
    return 0;
}