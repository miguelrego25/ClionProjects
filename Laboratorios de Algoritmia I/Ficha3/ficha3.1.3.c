#include<stdio.h>
int hash (char s[]) {
    int r = 0, i=1;
    while (*s) {
        r = r + (*s)*i;
        s++;
        i++;
    }
    return r;
}

void main(){
    char s[] = "programacao imperativa";
    printf("%d",hash(s));
}