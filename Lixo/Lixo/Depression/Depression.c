#include <string.h>


void inicioarray (char *token,SPointer s) {
    if (strncmp(token, "#", 1) == 0) {
        Tipoval s = POP(s);
        Tipoval Y = POP(s);
        Tipoval Z = POP(s);
    }
}

    void inicioarray(SPointer Y, SPointer Z, SPointer s) {
        SPointer ypslon = Y.array;
        Spointer ze = Z.array;
        Tipoval a[100] = {{0}};
        Tipoval z[100] = {{0}};
        int b;
        int y;
        int i;
        int countys;
        int countbs;
        for (b = 0; ypslon->top != -1; b++) {
            a[b] = POP(ypslon);
        }
        countbs = b;
        for (y = 0; ze->top != -1; y++) {
            z[y] = POP(ze);
            countys = y;
            y = 0;
            b = 0;
        }
        while (y < countys) {
            if (z[y] == a[b])b++;
            else b = 0;
            y++;
        }
        Tipoval aux;
        aux.valor = y;
        aux.tipo = 'i';
        if (y == count) Push(aux, s);
    }