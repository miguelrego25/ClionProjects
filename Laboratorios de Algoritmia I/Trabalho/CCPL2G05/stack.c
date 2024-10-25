/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a struct/stack.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**
 *\brief Declaração de variaveis que correspondem ao tamanho maximo da stack,a struct, e o topo da stack respetivamente.
 *
 */



SPointer criaStack(SPointer s,int tamanho){
    s->top = -1;
    s-> stack = malloc(tamanho*sizeof(Tipoval));
    
    return s;
}

/**
 * \brief Esta funçao verifica se a SPointer se encontra vazia.
 * @return 1 se a stack estiver vazia e retorna 0 se tiver algum elemento.
 */

int vazio(SPointer s) {

    if(s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @param a Posição para onde vamos deslocar.
 */

void MOVE (int a,SPointer s){
    s->top = s->top + a;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @return data que é o elemento mais acima na stack.
 */

Tipoval POP(SPointer s) {
    Tipoval data;
    if(!vazio(s)) {
        data = s->stack[s->top];
        s->top = s->top - 1;
        
    }
    

    
    return data;
}
void PUSHARRAY(Tipoval a, SPointer s){
    s->top = s->top + 1;
    
    s->stack[s->top] = a;
    
    
    
    

}

/**
 * \brief Esta função serve para retirar um elemento numa posição espefica na stack.
 * @param a Posição onde queremos retirar o elemento.
 * @return Retorna o elemento na posição da stack inserida.
 */

Tipoval MOVEPOP (int a, SPointer s){
    s->top = s->top - a;
    
    Tipoval x = POP(s);
    return x;
}

/**
 * \brief Esta funçao adiciona o elemento no topo da stack.
 * @param data elemento mais a cima na stack
 * @param a Tipo do valor
 */

void PUSH(Tipoval a, SPointer s) {
    s->top = s->top + 1;
    
    s->stack[s->top] = a;
    
    
    
}
void print_stack(SPointer s);
/**
 * \brief Esta função imprime todos os elementos da stack.
 */


void printnormal(Tipoval data){
        if(data.tipo == 'c'){
                char cara = data.valor;
                printf("%c", cara);
                }else if (data.tipo == 'i'){
                    int inteiro = data.valor;
                    printf("%d", inteiro);
                }else if (data.tipo == 'l'){
                    long floate = data.valor;
                    printf("%ld", floate);
                    
                }else if (data.tipo == 'f'){
                    printf("%g", data.valor);
            }
}
void print_stack(SPointer s){
    
    Tipoval data;
    int i=0;
    Tipoval stacks[50];
    while(vazio(s) != 1) {
        data = POP(s);
        
        stacks[i]= data;
        i++;
        }
    i --;
    while (i>-1){
        if (stacks[i].tipo != 'a'){
        
            printnormal(stacks[i]);
        }else print_stack (stacks[i].array);

            i--;
        }
    
}

