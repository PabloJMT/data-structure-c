#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define True 1

typedef struct {
    char nombre[20];
    char nombre_completo[50];
    int edad;
    char correo[30];
} cuates; 

void agregar(cuates nuevo, cuates * todos, int * total); 
void desplegar(cuates todos[5], int total); 


int main() {
cuates nuevo; 
int total = 1; 
cuates todos[5] = 

{
        {"Pancho", "Francisco Lopez", 21, "pancho@lopez.com"},
        {"Leticia", "Leticia Lopez", 23, "leticialopez@gmail.com"}
      //  {"Ana sofi", "Ana Sofi Garza", 24, "sofigarza@gmail.com"},
    //    {"Claudia", "Claudia Torres", 20, "claudiatorres@gmail.com"},
       // {"Carlos", "Carlos Ledesma", 26, "carlosle@gmail.com"}
    };
int opcion;

while(True){

    printf("    ////// Bienvenidos ////// \n");
    printf("Elige una opcion \n");
    printf("1. Alta \n");
    printf("2. Desplegar \n");
    printf("3. Salir \n");

    scanf("%i", &opcion);
    getchar(); 

    switch(opcion){
        case 1: //cuates nuevo

            printf("Dame el nombre  \n"); 
            scanf("%[^\n]c",nuevo.nombre);
            getchar();
            printf("Dame nombre y apellido  \n"); 
            scanf("%[^\n]c",nuevo.nombre_completo);
            getchar();
            printf("Escribe la edad: \n"); 
            scanf("%i",&nuevo.edad);
            printf("Escribe el correo: \n");         
            scanf("%c",nuevo.correo);   
             getchar();
            agregar(nuevo,todos,&total); 

            break; 
        case 2: desplegar(todos,total); 
                  break; 
        case 3: 
            printf("Error! Ingrese una opcion valida    \n"); 
            exit(0); 

    }

}   
    return 0;
    
}

 void agregar(cuates nuevo, cuates * todos, int * total)
    {
        if(*total < MAX)
        {
            
        
            todos[*total] = nuevo; 
            (*total)++; 
    }
        else
        printf("espacio insuficiente"); 
        
}
void desplegar(cuates todos[5], int total){

        int c; 
        for(c=0; c < total; c++)
           printf("%s,%s,%i,%s \n", todos[c].nombre, todos[c].nombre_completo, todos[c].edad, todos[c].correo ); 
    
}
    
