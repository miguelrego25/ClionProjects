#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    for (int i = 0; i < argc; i++) {
        pid_t pid = fork();
    }
    return 0;
}
