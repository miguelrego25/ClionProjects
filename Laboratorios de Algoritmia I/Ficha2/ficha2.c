#include <stdio.h>
#include <math.h>
#include <assert.h>
int main() {
    int a,b,c,perimetro;
    float area, d;

    assert( scanf("%d %d %d", &a, &b, &c) == 3);
    perimetro = a+b+c;
    d = (a + b + c);
    d=d/2;
    area = sqrt(d * (d - a) * (d - b) * (d - c));
    if ((a+b)>c && (b+c)>a && (a+c)>b){
    if (a==b && b==c) printf("EQUILATERO %d %.2f\n", perimetro, area);
    if (a==b && b!=c) printf("ISOSCELES %d %.2f\n", perimetro, area);
    if (a!=b && b==c) printf("ISOSCELES %d %.2f\n", perimetro, area);
    if (b!=a && a==c) printf("ISOSCELES %d %.2f\n", perimetro, area);
    if (a!=b && b!=c) {
        if (a * a == (b * b) + (c * c)) printf("RETANGULO %d %.2f\n", perimetro, area);
        else if (b * b == (a * a) + (c * c)) printf("RETANGULO %d %.2f\n", perimetro, area);
        else if (c * c == (b * b) + (a * a)) printf("RETANGULO %d %.2f\n", perimetro, area);
        else printf("ESCALENO %d %.2f\n", perimetro, area);
    }
    }else printf("INVALIDO\n");
    return 0;
}
