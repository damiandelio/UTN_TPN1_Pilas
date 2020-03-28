#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void cargarpila(Pila *pila) {
    char s = 's';

    while (s == 's') {
        leer(pila);
        printf("Desea cargar otro dato en la pila? (s/n): ");
        fflush(stdin);
        scanf("%c",&s);
    }
    return;
}

int main()
{
    Pila dada;
    Pila aux1;
    Pila aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    // cargarpila(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    mostrar(&dada);

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));

    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    mostrar(&aux1);
    mostrar(&aux2);

    return 0;
}
