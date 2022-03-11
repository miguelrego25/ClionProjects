#include <stdio.h>
//1)
float multInt1 (int n, float m){
    float res = 0;
    for (int i = 0; i < n; i++) {
        res += m;
    }
    return res;
}
//2)
float multInt2 (int n, float m){
    float restm = 0;
    int i = 0;
    while(n>=1){
        if(n%2 == 1 ) restm += m;
        n=n/2;
        m=m*2;
    }
    printf("%d %f", i, restm);
    return restm;
}
//3)
int mdc1 (int a, int b){
    int divisor;
    int i = 1;
    if(a<b){
        int temp = b;
        b=a;
        a=temp;
    }
    while(i<a){
        if((a%i == 0)&&(b%i == 0)){
            divisor = i ;
        }
        i++;
    }
    return divisor;

//4)
}
int mdc2 (int a, int b){
    if(a<b){
        int temp = b;
        b=a;
        a=temp;
    }
    while (a>0){
        if(a-b<0) b-=a;
        else a-=b;
    }
    return b;
}

int main() {
    multInt1(5,2);
    multInt2(81,423);
    mdc1 (5,10);
    mdc2 (322,70);
    return mdc2 (126,45);
}
