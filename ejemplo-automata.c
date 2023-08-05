//Automata finito

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main(){
    int EDO = 1;
    char * p; 

    char dato[] = "3+PATO"; 

    p = dato;    

    switch (EDO)
    {
    case 1:
        if(*p == '-' || isalpha(*p))
            EDO = 2;
        else{
            EDO = 100; 
        }
        break;
    case 2: 
        if(isdigit(*p) || *p == '-' || isalpha(*p))
            EDO = 2;
        else{
            EDO = 101; 
        }
        break; 
    case 3: 
        if(*p == 3 || isdigit(*p))
            EDO = 3; 
        else{
            EDO = 102; 
        }

    case 4:
        if (*p == '-' && *(p + 1) == '1') {
            EDO = 4; // Avanzar solo si recibe un número negativo '-1'
            p += 2; // Avanzar al siguiente elemento después de '-1'
        } else {
            // Si el siguiente elemento después de '-' no es '1', cambiar a EDO = 101
            EDO = 101;
        }
        break;
    case 5:
        if (*p == '+') {
            EDO = 5; // Avanzar solo si recibe un número positivo '+'
            p++; // Avanzar al siguiente elemento después de '+'
            if (isdigit(*p)) {
                // Si es un dígito después del '+', volver al estado anterior (EDO = 3)
                EDO = 3;
            }
        } else {
            // Si no es un número positivo, cambiar a EDO = 102
            EDO = 102;
        }
        break;
  
        }

    case 6: 
        if(*p ==)

        break;
    case 7: 
        if(*p == )

        break;
        
    }

}
