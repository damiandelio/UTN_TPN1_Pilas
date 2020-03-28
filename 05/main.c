/// 5. Cargar desde el teclado la pila DADA.
///    Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.

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
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    ingresardatos(&dada);

    while(!pilavacia(&dada)) {
        apilar(&aux1, desapilar(&dada));
        apilar(&aux2, desapilar(&aux1));
    }

    while(!pilavacia(&aux2)) {
        apilar(&dada, desapilar(&aux2));
    }

    printf("dada:");
    mostrar(&dada);

    return 0;
}
