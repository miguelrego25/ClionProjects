#include <stdio.h>

int main( )
{


    int x,y;
    for (y=0;y<8;y++) {
        for (x=0;x<8;x++) {
            if (x
                -
                y <
                0
                    ) putchar('.');
            else putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
