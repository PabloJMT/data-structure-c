#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3
#define SIZE 5
#define MINAS 5

typedef struct{
    char nombre[20];
    int nivel;
}Info;

void inicializa(char grid[SIZE+2][SIZE+2]){
    for(int j = 0; j<SIZE+2; j++){
        for(int i = 0; i<SIZE+2; i++){
            grid[j][i] = '.'; 
        }
    }
}



void ver(char grid[SIZE+2][SIZE+2]){
    for(int j = 0; j<SIZE+2; j++){
        for(int i = 0; i<SIZE+2; i++){
            if(grid[j][i] >= 0 && grid[j][i] < 9){
                printf("%i", grid[j][i]);
            } else{
                printf("%c", grid[j][i]);
            }
        }
        printf("\n");
    }
}

void seleccionar(int *x, int *y){
    printf("x: ");
    scanf("%d", x);

    printf("y: ");
    scanf("%d", y);
}

int checar(char grid[SIZE+2][SIZE+2],int x,int y){
    int contador = 0;
    if(grid[y][x] == 'x' ){
        printf("Perdiste\n");
        exit(0);
    }
    else{
        if(grid[y-1][x] == 'x')
            contador++;
        
        else if(grid[y-1][x+1] == 'x')
                contador++;
             else if(grid[y][x+1] == 'x')
                    contador++;
               else if(grid[y+1][x+1] == 'x')
                        contador++;
                   else if(grid[y+1][x] == 'x')
                            contador++;
                       else if(grid[y+1][x-1] == 'x')
                                contador++;
                           else if(grid[y][x-1] == 'x')
                                    contador++;
                                else if(grid[y-1][x-1] == 'x')
                                        contador++;
        //ASIGNACION
        grid[y][x] = contador; 
    }
    
    


    return 0;
}

int main(){
    int coor_x, coor_y;
    int puntos=0;
    Info best_scores[MAX];
    Info *tope=&best_scores[0];
    // inicializar arreglo vacio
    char grid[SIZE+2][SIZE+2];
    
    inicializa(grid); 
    for(int i = 0; i<MINAS; i++){
        int x = rand() % SIZE+1;
        int y = rand() % SIZE+1;

        grid[y][x] = 'x';
    }
 while(1)
 {
    while(puntos < SIZE*SIZE-MINAS){
        // printf mapa
        ver(grid);
    
        // seleccionar casilla
      SIZE*SIZE-MINAS;  seleccionar(&coor_x, &coor_y);
    
        // checar al rededor
        checar(grid, coor_x, coor_y);
    }
    if (puntos==SIZE*SIZE-MINAS )
    {
       
       //pedir los datos
       //hacer el push
      
    }
    puntos=0;
 }  
 //escribir a disco
 //open
 //write
    return 0;
}


void push(Info dato, Info * pila, Info ** tope )
{

if(*tope >= pila + MAX)
    printf("Malo");
else{

    **tope = dato; 
    (*tope)++;
}

Info pop(Info * pila, Info**tope )
{
    Info x; 
    if(*tope == pila)
        printf("Vacio");
    else{
        x = **tope; 
        *tope--;
        return x; 
    }
}
}
