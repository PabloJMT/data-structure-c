/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct AG{
    char nombre[20];
    struct AG *hijo[8];
};
void iniciaANull(struct AG * nodo)
{
    int i;
    for (i=0;i<8;i++)
      nodo->hijo[i]=NULL;
}

void desplegar(struct AG * nodo){
    int i;
    printf("%s  \n",nodo->nombre);
    for (i=0;i<8;i++){
        
        printf("%s  \n",nodo->hijo[i]->nombre); 
    }   
        
}


int main()
{
    struct AG *raiz;
    int opc = 0;
    raiz= (struct AG *) malloc(sizeof(struct AG));
    if (raiz==NULL)
    {
        perror("");
        return -1;
    }
    strcpy(raiz->nombre,"Margarita");
    iniciaANull(raiz);
    
    raiz->hijo[0]=(struct AG *) malloc(sizeof(struct AG));
    strcpy(raiz->hijo[0]->nombre,"Leticia");
    iniciaANull(raiz->hijo[0]);
    
    raiz->hijo[1]=(struct AG *)malloc(sizeof(struct AG)); 
    strcpy(raiz->hijo[1]->nombre, "Gabriel"); 
    iniciaANull(raiz->hijo[1]); 
    
    raiz->hijo[2]=(struct AG *)malloc(sizeof(struct AG)); 
    strcpy(raiz->hijo[2]->nombre, "Enrique"); 
    iniciaANull(raiz->hijo[2]); 
    
    raiz->hijo[3]=(struct AG *)malloc(sizeof(struct AG)); 
    strcpy(raiz->hijo[3]->nombre, "Ramon"); 
    iniciaANull(raiz->hijo[3]);
    
    raiz->hijo[4]=(struct AG *)malloc(sizeof(struct AG));
    strcpy(raiz->hijo[4]->nombre, "Abel"); 
    iniciaANull(raiz->hijo[4]); 
     
    raiz->hijo[0]->hijo[0]=(struct AG *)malloc(sizeof(struct AG));
    strcpy(raiz->hijo[0]->hijo[0]->nombre, "Hector"); 
    iniciaANull(raiz->hijo[0]->hijo[0]); 
    
    raiz->hijo[0]->hijo[1]=(struct AG *)malloc(sizeof(struct AG));
    strcpy(raiz->hijo[0]->hijo[1]->nombre, "Wilbert"); 
    iniciaANull(raiz->hijo[0]->hijo[1]); 
    
    raiz->hijo[0]->hijo[2]=(struct AG *)malloc(sizeof(struct AG));
    strcpy(raiz->hijo[0]->hijo[2]->nombre, "JP"); 
    iniciaANull(raiz->hijo[0]->hijo[2]); 
     
    printf("*** MENU ***    \n");
    printf("1. Mostrar niveles  \n");
    printf("2. Mostrar por familia \n");
    printf("3. Mostrar todo \n");
     printf("4. Salir \n");
    scanf("%i", &opc); 
    
    switch(opc){
        case 1: 
            break; 
        
        
        case 2: 
            printf("Que familia quieres desplegar? (1 al 5)\n");
            scanf("%i", &opc);
                if(opc==1){
                    desplegar(raiz); 
                }else{
                    desplegar(raiz->hijo[opc-2]);
                }
            
            break; 
        
        case 3: 
            break; 
        
        case 4: 
            break; 
            
    }
    return 0;
}

