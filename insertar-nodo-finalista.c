ultimo -> siguiente = crearNodo(x); 
ultimo -> siguiente -> siguiente = NULL; 
ultimo = ultimo -> siguiente;  



void insertFinal(Nodo** cabeza, Item entrada){
    Nodo*ultimo; 
    ultimo = *cabeza; 

    if(ultimo == NULL){

    } else{
        for(; ultimo ->; )
            ultimo = ultimo -> siguiente; 
        ultimo -> siguiente = crearNodo(entrada); 
    }

}