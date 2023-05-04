
//EXERCICIO 5 GUIAO 6
//EXERCICIO 5 GUIAO 6
//EXERCICIO 5 GUIAO 6
//EXERCICIO 5 GUIAO 6

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Processo filho 1: executa 'ls /etc'
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "/etc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Processo filho 2: executa 'wc -l'
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Processo pai: fecha os descritores de arquivo e espera pelos processos filhos
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}


