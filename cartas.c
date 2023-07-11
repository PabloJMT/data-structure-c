#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_JUGADORES 2
#define NUM_CARTAS 52
#define NUM_CARTAS_MANO 5
#define NUM_PARES_GANAR 3

typedef struct {
    int valor;
    int asignada;
} Carta;

void inicializarMazo(Carta* mazo) {
    int i;
    for (i = 0; i < NUM_CARTAS; i++) {
        mazo[i].valor = i % 13 + 1;
        mazo[i].asignada = 0;
    }
}

void revolverMazo(Carta* mazo) {
    int i, j;
    Carta temp;
    for (i = 0; i < NUM_CARTAS; i++) {
        j = rand() % NUM_CARTAS;
        temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void repartirCartas(Carta* mazo, Carta** manos) {
    int i, j;
    for (i = 0; i < NUM_CARTAS_MANO; i++) {
        for (j = 0; j < NUM_JUGADORES; j++) {
            manos[j][i] = mazo[i + j * NUM_CARTAS_MANO];
            mazo[i + j * NUM_CARTAS_MANO].asignada = 1;
        }
    }
}

void mostrarManos(Carta** manos) {
    int i, j;
    for (i = 0; i < NUM_JUGADORES; i++) {
        printf("Jugador %d:\n", i + 1);
        for (j = 0; j < NUM_CARTAS_MANO; j++) {
            printf("  Carta %d: %d\n", j + 1, manos[i][j].valor);
        }
        printf("\n");
    }
}

void tomarCarta(Carta* mazo, Carta* mano) {
    int i;
    for (i = 0; i < NUM_CARTAS; i++) {
        if (!mazo[i].asignada) {
            mano->valor = mazo[i].valor;
            mano->asignada = 1;
            mazo[i].asignada = 1;
            break;
        }
    }
}

int formarPar(Carta* mano, int carta1, int carta2) {
    if (!mano[carta1].asignada || !mano[carta2].asignada) {
        return 0;
    }
    if (mano[carta1].valor == mano[carta2].valor) {
        mano[carta1].asignada = 0;
        mano[carta2].asignada = 0;
        return 1;
    }
    return 0;
}

int contarPares(Carta* mano) {
    int i, contador = 0;
    for (i = 0; i < NUM_CARTAS_MANO; i++) {
        if (mano[i].asignada) {
            contador++;
        }
    }
    return (NUM_CARTAS_MANO - contador) / 2;
}
int main() {
    Carta mazo[NUM_CARTAS];
    Carta* manos[NUM_JUGADORES];
    Carta cartaTomada;
    int jugadorActual = 0;
    int paresGanados[NUM_JUGADORES] = {0};
    int i;

    // Resto del código

    return 0;
}

