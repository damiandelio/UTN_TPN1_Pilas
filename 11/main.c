/// 11. Suponiendo la existencia de una pila MODELO que no esté vacía,
///     eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.


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
    Pila dada, modelo, aux;
    int topeModelo;

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    topeModelo = 0;

    printf("Pila MODELO\n");
    leer(&modelo);
    printf("\nPila DADA\n");
    ingresardatos(&dada);

    // muestra la pila dada
    mostrar(&dada);

    topeModelo = tope(&modelo);

    // elimina los elementos de dada iguales al tope de la pila modelo
    while(!pilavacia(&dada)) {
        if(tope(&dada) == topeModelo) {
            // elimina el tope de pila dada
            desapilar(&dada);
        } else {
            // mueve el tope a aux
            apilar(&aux, desapilar(&dada));
        }
    }

    // reacomoda los datos de aux en dada
    while(!pilavacia(&aux)) {
        apilar(&dada, desapilar(&aux));
    }

    // muestra la pila dada con los elementos ya eliminados
    mostrar(&dada);

    system("pause");
    return 0;
}
