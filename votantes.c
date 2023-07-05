/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 100
#include <malloc.h>

struct persona{
  char nombre[MAX];   

    struct persona * sig;
    struct persona * ant;
};



struct persona * enlaza(struct persona * distrito, struct persona * new){
       if(distrito == NULL){
           distrito = new;
           distrito->ant = NULL; 
           distrito->sig = NULL;
       }
       else{
           new->ant=NULL;
           new->sig=distrito; 
           distrito->ant = new;  
           distrito=new; 
           
       }
       return distrito; 
} 

void imprimir(struct persona * distrito){
    while(distrito){
        printf("%s \n",distrito->nombre);
        distrito=distrito->sig; 
    }
}


int main()
{
   struct persona * distrito[4] = {NULL}; 
   int opc = 0;
   struct persona * aux; 
   
   while(1){
       
       printf("1. Agregar votante  \n");
       printf("2. Listar por distrito  \n");
       printf("3. Salir  \n");
       scanf("%i",&opc);
       getchar();
        
        switch(opc){
            case 1: 
                aux = malloc(sizeof(struct persona)); 
                 
                
                if(aux == NULL){
                    perror("");
                    break; 
                    
                    
                }
                
                printf("Cual es tu nombre?   \n");
                gets(aux->nombre);
                printf("En que distrito te encuentras?  \n");
                printf("1. Zapopan   \n");
                printf("2. GDL   \n");
                printf("3. Tonala   \n");
                printf("4. Tlaquepaque   \n");
                scanf("%i",&opc);
                getchar(); 
                
                
                distrito[opc-1] = enlaza(distrito[opc-1 ], aux); 
                
                break;
            case 2:
                printf("Cual distrito quieres desplegar? \n");
                printf("1. Zapopan   \n");
                printf("2. GDL   \n");
                printf("3. Tonala   \n");
                printf("4. Tlaquepaque   \n");
                scanf("%i",&opc);
                getchar();
                
                imprimir(distrito[opc-1]);
                break;
            case 3: 
                return 0; 
        }
       
   }
    return 0;
}
