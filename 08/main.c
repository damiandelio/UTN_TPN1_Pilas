/// 8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternada.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila mazo, jugador1, jugador2;
    int cantCartas = 0;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    printf("Ingrese la cantidad de cartas a repartir: ");
    fflush(stdin);
    scanf("%i", &cantCartas);

    // rellena el mazo con cartas
    for(int i=1; i <= cantCartas; i++) {
        apilar(&mazo, i);
    }

    // las reparte entre ambos jugadores
    while(!pilavacia(&mazo)) {
        apilar(&jugador1, desapilar(&mazo));
        if (!pilavacia(&mazo)) {
            apilar(&jugador2, desapilar(&mazo));
        }
    }

    // muestra las cartas de los jugadores
    printf("\nJUGADOR1:");
    mostrar(&jugador1);

    printf("\nJUGADOR2:");
    mostrar(&jugador2);

    system("pause");
    return 0;
}
