/******************************************************************************

Arboles binarios recorrido inorden 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct AB{
    char letra; 
    struct AB * izq;
    struct AB * der;     
}; 


void inorden(struct AB * raiz){
    if(raiz==NULL)
        return 0; 
    
    inorden(raiz->izq);
    printf("%c \n", raiz->letra);
    inorden(raiz->der);
}

void preorder(struct AB *raiz)
{
    if (raiz==NULL)
       return 0;
    printf("%c  \n",raiz->letra);
    preorder(raiz->izq);
    preorder(raiz->der);
    
}

void posorden(struct AB * raiz){
    
    if(raiz==NULL)
        return 0; 
    posorden(raiz->izq); 
    posorden(raiz->der);
    printf("%c ",raiz->letra);
        

}

int main()
{
   struct AB * raiz; 
    raiz = malloc(sizeof(struct AB)); 
    
    raiz ->letra='A'; 
    raiz -> izq = malloc(sizeof(struct AB));
    raiz ->izq ->letra = 'B';
    raiz -> der = malloc(sizeof(struct AB));
    raiz -> der ->letra='D';
    raiz -> der -> izq = malloc(sizeof(struct AB));
    raiz -> der-> izq -> letra = 'G'; 
    raiz ->izq->der=malloc(sizeof(struct AB)); 
    raiz -> izq->der ->letra = 'K';
    
    printf("Podemos observar el orden inorden:  \n");
    inorden(raiz); 
    printf("Podemos observar el orden preorden:  \n");
    preorder(raiz); 
    printf("Podemos observar el orden posorden:  \n");
    posorden(raiz);

    return 0;
}
