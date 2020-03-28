/// 4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
///    Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

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
    Pila origen, destino, aux;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    ingresardatos(&origen);

    while(!pilavacia(&origen)) {
        apilar(&aux, desapilar(&origen));
        apilar(&destino, desapilar(&aux));
    }

    printf("origen:");
    mostrar(&origen);

     printf("destino:");
    mostrar(&destino);

    return 0;
}
