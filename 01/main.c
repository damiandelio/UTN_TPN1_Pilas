/// 1. Cargar desde el teclado una pila DADA con 5 elementos.
///    Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vacío.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    // 5 ciclos de carga
    printf("Ingrese 5 elementos a la pila DADA\n");
    for (int i=0; i < 5; i++) {
        leer(&dada);
    }

    for (int i =0; i < 3; i++) {
        apilar(&aux1, desapilar(&dada));
    }

    for (int i =0; i < 2; i++) {
        apilar(&aux2, desapilar(&dada));
    }

    printf("\nPila AUX1");
    mostrar(&aux1);
    printf("\n\nPila AUX2");
    mostrar(&aux2);

    system("pause");
    return 0;
}
