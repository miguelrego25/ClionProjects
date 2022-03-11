#include <stdio.h>



void quadrado (int j){
    for (j = 0; j < 5; j++) {
        printf("\n");

        for (int i = 0; i < 5; i++) {
            printf("#");
        }
    }
}
/*
#####
#####
#####
#####
#####
*/

void alternado (int a) {
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 6; b++) {
            if (b % 6 == 0) printf("\n");
            else {
                if (a % 2 == 0) {
                    if (b % 2 == 0) printf("_");
                    else printf("#");
                } else {
                    if (b % 2 == 0) printf("#");
                    else printf("_");
                }
            }
        }
    }
}
/*
#_#_#
_#_#_
#_#_#
_#_#_
#_#_#
*/


int main() {
    quadrado( 0);
    printf("\n");
    alternado( 0);
    printf("\n");
    printf("\n");
    return 0;
}

