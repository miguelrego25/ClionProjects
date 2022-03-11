#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() {
    int x, y, z, p, a, u;

    assert(scanf("%d%d%D", &x, &y, &z) == 3);

    p = x + y + z;

    u = (x+y+z) / 2.0;

    a = sqrt (u (u-x)(u-y)(u-z));

    if (x == y == z) printf ("EQUILATERO %d %.2f", p, a);
    if (x == y != z) printf ("ISOSCELES %d %.2f", p, a);
    if (x != y == z) printf ("ISOSCELES %d %.2f", p, a);
    if (x == z != y) printf ("ISOSCELES %d %.2f", p, a);
    if (x != y != z) printf ("ESCALENO %d %.2f", p, a); else {

        if (pow (x,2)) + (pow (y,2)) == (pow (z,2)) printf ("RETANGULO");
        if (pow (y,2)) + (pow (z,2)) == (pow (x,2)) printf ("RETANGULO");
        if (pow (x,2)) + (pow (z,2)) == (pow (y,2)) printf ("RETANGULO");
    }
    else printf ("INVALIDO")

    return 0;

}