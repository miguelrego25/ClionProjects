#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int primeira(){
    int maior = 0;
    while(1){
        int x;
        scanf("%d",&x);
        if(maior < x) maior = x;
        if(x==0) return printf("%d",maior);
    }

}
int  segunda(){
    int somadevalores = 0;
    int numerovalores = 0;
    int flag=1;
    while(flag){
        int x;
        scanf("%d",&x);
        if(x==0) {
            flag = 0;
        }else{
            numerovalores += 1;
            somadevalores += x;
        }
    }
    return somadevalores/numerovalores;
}

int terceira(){
    int maior = 0;
    int  segundomaior = 0;
    int  flag=1;
    while(flag) {
        int x;
        scanf("%d", &x);
        if (x == 0) flag = 0;
        if (x > maior) {
            segundomaior = maior;
            maior = x;
        }
        if (x < maior && x > segundomaior) segundomaior = x;
    }
    return segundomaior ;
}
//int bitsUm (unsigned int n)
int quarta(unsigned int n){
    int k = 0;
    int p = n;
    while(p>1){
        if(p%2==0) {
            p=p/2;
        }
        else{
            p=p/2;
            k++;
        }
    }
    return k+1;
}

//int trailingZ (unsigned int n)
int quinta (unsigned int n) {
    int c=0;
    while(n%2 == 0){
        n/=2;
        c++;
    }
    return c;
}
int sexta (unsigned int n){
    int counter = 0;
    while(n>0){
        counter++;
        n=n/10;
    }
    return counter;
}

char setima (char s1[], char s2[]){
    int j=0,i=0;
    for (j = 0; s1[j] != '\0' ; j++);
    for (i = 0; s2[i] != '\0'; i++, j++) {
        s1[j] = s2[i];
    }
    s1[j] = '\0';
    return s1;
}
//oitava
char strcpyx (char s1[], const char s2[]) {
    int i;
    for (i = 0; s2[i] != '\0' ; i++) {
        s1[i]=s2[i];
    }
    s1[i] = '\0';
    return s1;
}

//nona
int mystrcmp(char s1[], char s2[]) {
    int flag,i=0;
    while(s1[i] != '\0' && s2[i]!='\0' && s1[i]==s2[i]) {
        i++;
    }
    flag = s1[i]-s2[i];
    return flag;
}

//decima

//da segmentation fault
char mystrstr (char s1[], char s2[]) {
    int i, j;
    char p = NULL;
    for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++) {
        if (s1[i] != s2[j]) j = 0;
        if (s1[i] == s2[j])
            p = i;
        for (j = 0; s1[i] == s2[j]; i++, j++);
    }
    return p;
}
//decima-primeira

void mystrrev (char s[]) {
    int len = 0,i;
    char temp ;
    for (len = 0; s[len] != '\0'; len++);
    for (i = 0; i < len;i++ ) {
        temp = s[i];
        s[i]=s[len-1];
        s[len-1] = temp;
        len--;
    }
}
//decima-segunda

void strnoV (char s[]){
    int i,j;
    int length = 0;
    for (length = 0; s[length] != '\0'; length++);
    for (i = 0; i!=length;i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            j=i;
            while(j!=length) {
                s[j] = s[j + 1];
                j++;
            }
            i--;
        }
    }
}

//decima-terceira
void truncW (char t[], int n) {
    int len, j=0;
    for (len = 0; t[len] != '\0'; len++);

    for (int i = 0; t[i]!='\0' ; i++,j++) {
        if(j==n){
            if(t[i] != ' '){
                for (j=i; t[j] != ' ' ; j++) {
                    t[j] = t[j+1];
                }
            }
            j=i;
        }

    }
}
//decima quarta

char charMaisfreq (char s[]) {
    int flag = 0, j=0, i=0;
    char maisfreq;
    int masfreq;


    for(i = 0; s[i] != '\0'; i++){
        int f = 0;
        for (j = 0; s[j] != '\0'; j++) if(s[i] == s[j]) f++;
        if (f>masfreq){
            maisfreq = s[i];
            masfreq=f;
        }
    }
    return maisfreq;

}

int main() {
    //primeira();
    //segunda();
    //terceira();
    //quarta();
    //quinta();
    //sexta();
    //setima();
    char s1[20] = "ola muundo cruel";
    char s2[6] = "mundo";
    //mystrrev(s1);
    charMaisfreq(s1);
    printf("%s",s1);
    return charMaisfreq(s1);

}

