#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 5

void push(char dato, char * pila, char ** tope); 
int pop(char * pila, char**tope );

int main(void){
    char cadena[] = "(a+b]",*p_cadena; 
    char pila[MAX], *tope, x; 
    tope = &pila[0]; 
    p_cadena = cadena;
    while(*p_cadena != '\0')
    {
        if(*p_cadena == '(')
            push(*p_cadena, pila, &tope); 
        else if(*p_cadena == ')')
            {
                x = pop(pila, &tope); 
                if(x != '(' &&*p_cadena == ')')
                  {
                     printf("Error en la cadena");  
                  
                      break;
                  }
                   
                
            }
            p_cadena++; 
    }

} 


void push(char dato, char * pila, char ** tope )
{

if(*tope >= pila + MAX)
    printf("Malo");
else{

    **tope = dato; 
    (*tope)++;
    printf("1%p\n",*tope); 

}
}

int pop(char * pila, char**tope )
{
    char x; 
    if(*tope == pila)
        printf("Vacio");
    else{
        
        (*tope)--;
        x = **tope; 
       
        //printf("%p\n",*tope); 
        return x; 
        
    }
}
