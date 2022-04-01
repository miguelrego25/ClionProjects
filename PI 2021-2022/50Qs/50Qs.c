#include <stdio.h>
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
char strcpyx (char *dest, char source[]){
    int i;
    for (i = 0; dest[i] != '\0' ; i++) {
        source[i]=dest[i];
    }
    return source
}





int main() {
    //primeira();
    //segunda();
    //terceira();
    //quarta();
    //quinta();
    //sexta();
    //setima();
    char s1[20] = "Hello world";
    char s2[20] = "putas ss";
    strcpyx(s1, s2);
    printf("%s",s2);
    return 0;

}

