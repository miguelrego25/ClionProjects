#include <stdio.h>
#include <assert.h>

void sortt(int *p,int n){
    int i, j, temp;
    for(i=0; i < n-1; i++){
        for(j=0; j < n-i-1; j++){
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

            }
        }
    }
}




int main() {

    int givenl[100];
    int er=0;
    int size=0;
    int io;
    for (io = 0; io < 101; io++) {
        assert(scanf("%d", &givenl[io])==1);
        if (givenl[io] == -1) break;
    }
    for (; er != -1; size++) {
        er= givenl[size];
    }
        sortt(givenl, size);
//for (int p = 0; p < 10 ; p++) {
//        printf("%d",givenl[p]);
//    };
        int i = 0;
        int p ;
        while (givenl[i] >= 0 || givenl[i] == -1) {
            i++;
            printf("0|");
            while (givenl[i] <= 9) {
                printf("%d", givenl[i]);
                i++;
            }
            printf("\n");
            printf("1|");
            while (givenl[i] <= 19 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("2|");
            while (givenl[i] <= 29 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("3|");
            while (givenl[i] <= 39 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("4|");
            while (givenl[i] <= 49 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("5|");
            while (givenl[i] <= 59 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("6|");
            while (givenl[i] <= 69 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("7|");
            while (givenl[i] <= 79 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("8|");
            while (givenl[i] <= 89 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            printf("9|");
            while (givenl[i] <= 99 && givenl[i] > 0) {
                p = givenl[i] % 10;
                printf("%d", p);
                i++;
            }
            printf("\n");
            break;
        }
    return 0;}
