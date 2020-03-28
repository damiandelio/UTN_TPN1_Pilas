/// 8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternada.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila mazo, jugador1, jugador2;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    // rellena el mazo con cartas
    for(int i=1; i <= 60; i++) {
        apilar(&mazo, i);
    }

    // las reparte entre ambos jugadores
    while(!pilavacia(&mazo)) {
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
    }

    // muestra las cartas de los jugadores
    printf("jugafor1:");
    mostrar(&jugador1);

    printf("jugafor2:");
    mostrar(&jugador2);

    system("pause");
    return 0;
}
