/// 6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
///    dejando los restantes elementos en el mismo orden.

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
    Pila dada, aux;
    int topValue;

    inicpila(&dada);
    inicpila(&aux);
    topValue = 0;

    ingresardatos(&dada);

    topValue = desapilar(&dada);

    while(!pilavacia(&dada)) {
        apilar(&aux, desapilar(&dada));
    }

    apilar(&dada, topValue);

    while(!pilavacia(&aux)) {
        apilar(&dada, desapilar(&aux));
    }

    printf("dada:");
    mostrar(&dada);

    system("pause");
    return 0;
}
