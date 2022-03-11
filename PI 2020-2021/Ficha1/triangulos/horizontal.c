#include <stdio.h>

int main() {
    int linhas=5, colunas, espacos,i,a,car,b;
    scanf("%d",&linhas);
    espacos = linhas - 1;
    a = espacos;
    b=1;
    for ( i=0; i < linhas ; i++) {
            a=a-1;
            for (espacos = a; espacos >= 0 ; --espacos) {
                printf(" ");
            }
            for (car = 1; car <= (b * 2) - 1 ; car++) {
                printf("#");

            }
            b=b+1;
            printf("\n");
            }
    return 0;
}
 /*   #
     ###
    #####
   #######
  #########
*/