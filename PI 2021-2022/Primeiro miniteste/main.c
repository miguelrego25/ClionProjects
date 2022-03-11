#include <stdio.h>

int func(int x) {
    int r = 0;
    while (x > 0) {
        r += 1;
        x = x - r;
    }
    return r;
}
void pila() {
    int x, y;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            if (x + y <= 7) putchar('#');
            else putchar('.');
        }
        putchar('\n');
    }
}


    int main() {
        pila();
        for (int i = 0; i < 100; i++) {
            int z = 0;
            z = func(i);
            if (z == 5) return printf("%d /n", i);
        }
        pila();
        return 0;
    }
