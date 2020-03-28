/// 3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// recibe como parametro un puntero a la pila a la que se le va a cargar datos
void ingresardatos(Pila *pila) {
    char s = 's';

    while (s == 's') {
        leer(pila);
        printf("Desea cargar otro dato en la pila? (s/n): ");
        fflush(stdin);
        scanf("%c",&s);
    }

    printf("\n");
    return;
}

int main()
{
    Pila dada, destinos;

    inicpila(&dada);
    inicpila(&destinos);

    ingresardatos(&dada);

    while(!pilavacia(&dada)) {
        if (tope(&dada) != 8) {
            apilar(&destinos, desapilar(&dada));
        } else {
            desapilar(&dada);
        }
    }

    printf("dada:");
    mostrar(&dada);
    printf("\n\n\n\n\n\n");

    printf("destinos:");
    mostrar(&destinos);
    printf("\n\n\n\n\n\n");

    return 0;
}
