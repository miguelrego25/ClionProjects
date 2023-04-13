#include <stdio.h>
#include <unistd.h>
int main() {
    execlp("ls","ls", "-l",NULL);
    printf("foi usado");
    return 0;
}
