/// 7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope),
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
    int lastValue;

    inicpila(&dada);
    inicpila(&aux);
    lastValue = 0;

    ingresardatos(&dada);

    while(!pilavacia(&dada)) {
        apilar(&aux, desapilar(&dada));
    }

    lastValue = desapilar(&aux);

    while(!pilavacia(&aux)) {
        apilar(&dada, desapilar(&aux));
    }

    apilar(&dada, lastValue);

    printf("dada:");
    mostrar(&dada);

    system("pause");
    return 0;
}
