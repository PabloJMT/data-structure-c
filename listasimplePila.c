#include <stdio.h>
#include <stdlib.h>

struct Dato {
    int numero;
    struct Dato* sig;
};

void despliega(struct Dato* i) {
    while (i) {
        printf("%i\n", i->numero);
        i = i->sig;
    }
}

int main() {
    struct Dato* Inicio = NULL;
    struct Dato* nuevo;

    nuevo = malloc(sizeof(struct Dato));

    printf("Dato: ");
    scanf("%i", &nuevo->numero);
    nuevo->sig = NULL;

    if (Inicio == NULL) {
        Inicio = nuevo;
    } else {
        nuevo->sig = Inicio;
        Inicio = nuevo;
    }

    despliega(Inicio);

    return 0;
}
