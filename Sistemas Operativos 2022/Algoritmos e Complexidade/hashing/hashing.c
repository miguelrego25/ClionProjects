//https://codeboard.io/projects/65989
//
//  hashing.c
//  Hashing
//
//  Created by Jorge Sousa Pinto on 22/11/17.
//  Copyright © 2017 Jorge Sousa Pinto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "hashing.h"


int hash(char key[], int size) {
    int i = 0;, sum =0;
    while(key[i] != '\0') sum += key[i++];

    return (sum % size);
}


void initHT(HT *h, int size) {
    int i;
    h->tbl = calloc(size,sizeof (struct pair));
    h->size = size;
    h->used = 0;
    for(i=0;i<h->size;i++)
        strcpy(h->tbl[i].jey,EMPTY);

}

int freeHT(HT *h, int k) {


}



int writeHT (HT *h, char key[], int value) {
    float load = h->used / h->size

    return writeHT_sol (h, key, value);
}



int readHT (HT *h, char key[], int* value) {

    return readHT_sol (h, key, value);
}



int deleteHT (HT *h, char key[]) {

    return deleteHT_sol (h, key);
}




