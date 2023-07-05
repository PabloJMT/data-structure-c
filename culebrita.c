// Para poder correr este programa es necesario anexar la libreria 'conio4Linux.h'

/******************************************************************************
culebrita

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio4Linux.h"
#define ESC 27

struct Vibora{
  int x;
  int y;
  struct Vibora *sig,*ant;
};

void verVibora(struct Vibora *vibora){
    while(vibora){
        gotoxy(vibora->x, vibora->y);
        printf("@");
        vibora = vibora->ant;
    }
}

void actualizarVibora(struct Vibora *vibora){
    while(vibora->ant != NULL){
        vibora = vibora->ant;
    }

    while(vibora->sig != NULL){
        vibora->x = vibora->sig->x;
        vibora->y = vibora->sig->y;

        vibora = vibora->sig;
    }
}

int main()
{
    struct Vibora *inicio,*nuevo;
    int dir=1; //derecha
    char tecla;
    inicio=malloc(sizeof(struct Vibora));

    srand(time(NULL));
    int x = rand() % 80 + 1, y = rand() % 25 + 1;

    inicio->x = rand() % 80 + 1;
    inicio->y = rand() % 25 + 1;

    clrscr();

   do{
        do{
            clrscr();
            //manzana
            textcolor(RED);
            gotoxy(x, y);
            printf("m");

            // vibora
            textcolor(YELLOW);
            verVibora(inicio);
            system("sleep 0.3");


            switch(dir)
            {
                case 1: 
                    if(inicio->x < 80){
                        inicio->x++;
                    } else{
                        inicio->x = 1;
                    }
                    break;
                case 2: 
                    if(inicio->y < 25){
                        inicio->y++;
                    } else{
                        inicio->y = 1;
                    }
                    break; 
                case 3:
                    if(inicio->x > 1){
                    inicio->x--; 
                    } else{
                        inicio->x = 80;
                    }
                        break; 
                case 4:
                    
                    if(inicio->y > 1){
                        inicio->y--;
                    } else{
                        inicio->y = 25;
                    }
                    break; 
            }
            
            if((inicio->x == x)&&(inicio->y == y)){
                x = rand() % 80 + 1;
                y = rand() % 25 + 1;
                nuevo = malloc(sizeof(struct Vibora));
                nuevo->x = inicio->x;
                nuevo->y = inicio->y;
                nuevo->sig = NULL;
                nuevo->ant = inicio;
                inicio ->sig= nuevo;             
                inicio = nuevo;
                 
            }
            actualizarVibora(inicio);

        }while(!kbhit());//se para al presionar una tecla
        tecla=getch();
        switch(tecla){
            case 's':dir=2; break;
            case 'w': dir =4; break; 
            case 'a': dir =3; break;
            case 'd': dir=1;
        }
   }while(tecla!=ESC);
    return 0;
}
