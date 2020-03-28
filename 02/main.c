/// 2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
///    Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// resibe como parametro un puntero a
// la pila a la que se le va a cargar datos
void ingresardatos(Pila *pila) {
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
    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    ingresardatos(&origen);

    while(!pilavacia(&origen)) {
        apilar(&destino, desapilar(&origen));
    }

    printf("Pila destino:");
    mostrar(&destino);

    return 0;
}
