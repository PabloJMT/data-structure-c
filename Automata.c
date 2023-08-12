#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definición de estados del autómata
enum State {
    INITIAL,
    OPERATOR,
    NUMBER,
    ERROR
};

// Función para verificar la sintaxis de la asignación
bool verificaSintaxisAsignacion(char *cadena) {
    enum State estado = INITIAL;
    int i = 0;
    int longitud = strlen(cadena);

    while (i < longitud) {
        switch (estado) {
            case INITIAL:
                if (cadena[i] == '+' || cadena[i] == '-') {
                    estado = OPERATOR;
                    i++;
                } else if (isdigit(cadena[i])) {
                    estado = NUMBER;
                    i++;
                } else {
                    estado = ERROR;
                }
                break;
            case OPERATOR:
                if (isdigit(cadena[i])) {
                    estado = NUMBER;
                    i++;
                } else {
                    estado = ERROR;
                }
                break;
            case NUMBER:
                if (isdigit(cadena[i])) {
                    i++;
                } else {
                    estado = ERROR;
                }
                break;
            case ERROR:
                return false;
        }
    }

    // Verificar el estado final
    return estado == NUMBER;
}

int main() {
    char cadena[100];

    printf("Ingrese una asignación con sumas y restas: ");
    scanf("%s", cadena);

    if (verificaSintaxisAsignacion(cadena)) {
        printf("La sintaxis es válida.\n");
    } else {
        printf("La sintaxis es inválida.\n");
    }

    return 0;
}
