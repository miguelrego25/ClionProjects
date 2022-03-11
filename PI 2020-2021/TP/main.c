#include <stdio.h>
int oblongos (int n){
    int f=0;
    for (int i = 0; i < n; i++) {
        if (n==(i*(i+1))) f=1;
    }
    return f;
}

int main (){
    int n = 47;
    int r = 0;
    int max=0;
    while (n != 1) {
        r = r + n;
        if (n%2 == 0) n = n/2;
        else n = 1+(3*n);

        if(n>max) max=n;
        if(oblongos(n)==1)printf("n=%i é oblongo \n",n);

    }
    printf("\nr=%i \n max=%i",r,max);
    return r;
}
