/******************************************************************************
Insertar como cola
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct Dato{
    int numero;
    struct Dato * sig;
    struct Dato *ant;
};
void despliega(struct Dato *i){
    while(i)
    {
        printf("%i\n",i->numero);
        i=i->sig;
    }
    
}

int main()
{
    struct Dato *Inicio=NULL, *nuevo,*aux;
    //3
    nuevo=malloc(sizeof(struct Dato));
   
    printf("dato:");
    scanf("%i",&nuevo->numero);
    nuevo->sig=NULL;
    nuevo->ant=NULL; // ---------------------
    
    if(Inicio==NULL)
    {
        Inicio=nuevo;
    }
    else{
        aux=Inicio;
        //buscar el final
        while(aux->sig)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux; //----------------
    }
    
    
    
    
    despliega(Inicio);
    
    return 0;
}

