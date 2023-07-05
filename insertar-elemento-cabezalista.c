typedef int Item; 
typedef struct nodo{
    Item dato; 
    struct nodo * siguiente; 
    
} Nodo; 

Nodo * nuevo; 
nuevo = (Nodo*)malloc(sizeof(Nodo)); 
nuevo -> dato = entrada; 

nuevo -> siguiente = cabeza; 

cabeza = nuevo; 

void insertPrimero(Nodo** cabeza, Item entrada){

    Nodo * nuevo; 
    nuevo = (Nodo*)malloc(sizeof(Nodo)); 
    nuevo -> dato = entrada; 
    nuevo -> siguiente = *cabeza; 
    *cabeza = nuevo;  
}

