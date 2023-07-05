/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
    int numero; 
    int * memoria; 
    int * memoria2; 
    int i = 0; 
    

    printf("¿Cuantas calificaciones necesitas");
    scanf("%i",&numero);

    memoria = malloc(sizeof(int)*numero); 
    memoria2 = memoria; 
    
    for(i = 0; i<numero; i++){
        
        printf("Dame la calificacion: \n");
        scanf("%i",memoria);
        memoria++; 
    }
    
    int suma = 0; 
    memoria = memoria2;
    
     for(i = 0; i<numero; i++){
        suma = (*memoria)+suma;
        memoria++; 
    
    }
    
    printf("El promedio es: %f  \n ",suma/(float)numero);
    
    
    
    return 0;
}
