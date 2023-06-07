#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 5

void push(int dato, int * pila, int ** tope); 
int pop(int * pila, int**tope );

int main(void){
    int pila[MAX], *tope; 
    tope = &pila[0]; 

    push(30,pila,&tope); 
    push(90,pila,&tope);
    x = pop(pila,&tope); 
    printf("%i",x);
    x = pop(pila,&tope); 
    printf("%i",x); 
} 
}

void push(int dato, int * pila, int ** tope )
{

if(*tope >= pila + MAX)
    printf("Malo");
else{

    **tope = dato; 
    (*tope)++;
}

int pop(int * pila, int**tope )
{
    int x; 
    if(*tope == pila)
        printf("Vacio");
    else{
        x == **tope; 
        *tope--;
        return x; 
    }
}
}