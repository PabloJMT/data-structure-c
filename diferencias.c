#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
void mostrar_malloc(char *memoria);
void mostrar_calloc(char *memoria);
void mostrar_realloc(char *memoria);
void mostrar_diferencias();

int main() {
    char *memoria;
    int opcion;

    // Asignar memoria de tamaño 400 bytes
    memoria = (char*)malloc(400 * sizeof(char));

    // Copiar la funcionalidad de malloc() en los primeros 100 bytes
    strcpy(memoria, "Funcionalidad de malloc():\n\n/* Implementación de malloc aquí */");

    // Copiar la funcionalidad de calloc() en los siguientes 100 bytes
    strcpy(memoria + 100, "Funcionalidad de calloc():\n\n/* Implementación de calloc aquí */");

    // Copiar la funcionalidad de realloc() en los penúltimos 100 bytes
    strcpy(memoria + 200, "Funcionalidad de realloc():\n\n/* Implementación de realloc aquí */");

    // Mostrar el menú y procesar la opción elegida
    do {
        printf("=== Menú ===\n");
        printf("1. Mostrar funcionalidad de malloc()\n");
        printf("2. Mostrar funcionalidad de calloc()\n");
        printf("3. Mostrar funcionalidad de realloc()\n");
        printf("4. Mostrar diferencias entre malloc(), calloc() y realloc()\n");
        printf("5. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrar_malloc(memoria);
                break;
            case 2:
                mostrar_calloc(memoria);
                break;
            case 3:
                mostrar_realloc(memoria);
                break;
            case 4:
                mostrar_diferencias();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

        printf("\n");
    } while (opcion != 5);

    // Liberar la memoria asignada
    free(memoria);

    return 0;
}

void mostrar_malloc(char *memoria) {
    printf("%s\n", memoria);
}

void mostrar_calloc(char *memoria) {
    printf("%s\n", memoria + 100);
}

void mostrar_realloc(char *memoria) {
    printf("%s\n", memoria + 200);
}

void mostrar_diferencias() {
    printf("Diferencias entre malloc(), calloc() y realloc():\n");
    printf("-----------------------------------------------\n");
    printf("malloc():\n");
    printf("   - Asigna memoria de tamaño especificado.\n");
    printf("   - No inicializa el contenido de la memoria.\n");
    printf("\n");
    printf("calloc():\n");
    printf("   - Asigna memoria de tamaño especificado.\n");
    printf(" Inicializa el contenido de la memoria a cero   \n"); 
}