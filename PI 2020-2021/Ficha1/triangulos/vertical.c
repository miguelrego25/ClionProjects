#include<stdio.h>
int main() {
    int m;
    int j=0;
    int i;
    int b=0;

    scanf("%d",&m);
    for (i = 0; i <= m; i++) {
        j=0;
        while (j != i) {
            j=j+1;
            putchar('#');

        }
        printf("\n");

    }
    m=m-1;
    for (; m>=0; m--) {
        b=0;
        while (b<m){
            b++;
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

