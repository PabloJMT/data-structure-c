nuevo = crearNodo(entrada);

nuevo -> siguiente = anterior -> siguiente

void insertar(Nodo*anterior, Item entrada){
    Nodo * nuevo; 

    nuevo = crearNodo(entrada); 
    nuevo -> siguiente = anterior -> siguiente; 
    anterior -> siguiente = nuevo; 
}

void insertar(Nodo** cabeza, Item testigo, Item entrada){
    Nodo * nuevo, *despues; 

    nuevo = crearNodo(entrada); 
    if(*cabeza == NULL)
    *cabeza = nuevo; 
    else(
        int esta = 0; 
        despues = *cabeza; 
        while((despues != NULL) && !esta){
            if( despues -> dato != testigo)
                despues = despues -> siguiente; 
            else
                esta = 1; 
        }

        if(esta){
            nuevo -> siguiente = despues -> siguiente; 
            despues -> siguiente = nuevo; 
        }


    )
}