#include <stdio.h>

struct planetas {
    char nombre[15];
    int luna;
    char descripcion[50];
};

typedef struct planetas Planetas;

void Capturar_datos(Planetas SS[10], int total);
void Eliminar_planeta(Planetas SS[10], int *total, int indice);
int menu(Planetas ss[10], int total);

int main() {
    int total = 1, opc;
    Planetas SS[10] = { {"mercurio", 0, "planetas más cercanos "} };
    do {
        opc = menu(SS, total);
        if (opc <= total) {
            printf("%s tiene %i lunas y es %s\n", SS[opc - 1].nombre, SS[opc - 1].luna, SS[opc - 1].descripcion);
        } else if (opc == total + 1) {
            Capturar_datos(SS, total);
            total++;
        } else if (opc == total + 2) {
            printf("¿Cuál quieres eliminar?\n");
            int indice;
            scanf("%i", &indice);
            Eliminar_planeta(SS, &total, indice);
        }
    } while (opc != total + 4);

    return 0;
}

void Capturar_datos(Planetas SS[10], int total) {
    printf("Nombre del planeta:     ");
    scanf("%s", SS[total].nombre);
    printf("Ingresa una descripcion:     ");
    scanf("%s", SS[total].descripcion);
    printf("Ingresa el numero de lunas:     ");
    scanf("%i", &SS[total].luna);
    getchar();
    printf("Descripcion:    ");
    scanf("%[^\n]c", SS[total].descripcion);
}

void Eliminar_planeta(Planetas SS[10], int *total, int indice) {
    if (indice < 1 || indice > *total) {
        printf("Índice inválido\n");
        return;
    }

    for (int i = indice - 1; i < *total - 1; i++) {
        SS[i] = SS[i + 1];
    }

    (*total)--;
    printf("El planeta ha sido eliminado\n");
}

int menu(Planetas ss[10], int total) {
    int i, opc;
    for (i = 0; i < total; i++) {
        printf("%i. %s\n", i + 1, ss[i].nombre);
    }

    printf("%i. Agregar \n", total + 1);
    printf("%i. Eliminar \n", total + 2);
    printf("%i. Modificar \n", total + 3);
    printf("%i. Salir \n", total + 4);
    scanf("%i", &opc);

    return opc;
}
