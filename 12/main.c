/// 12. Suponiendo la existencia de una pila MODELO (vacía o no),
///     eliminar de la pila DADA todos los elementos que existan en MODELO.


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
        s = getche();
        printf("\n");
    }

    printf("\n");
    return;
}

// busca un valor dentro de una pila. Retorna 1 si lo encuentra y 0 si no lo encuentra
int buscarValor( int val, Pila *pila, Pila *aux ) {
    int valTope = 0;

    while(!pilavacia(pila)) {
        valTope = desapilar(pila);
        apilar(aux, valTope);

        if(val == valTope) {
            while(!pilavacia(aux)) {
                apilar(pila, desapilar(aux));
            }

            return 1;
        }
    }

    while(!pilavacia(aux)) {
        apilar(pila, desapilar(aux));
    }

    return 0;
}

int main()
{
    Pila dada, modelo, aux1, aux2;
    int valorEncontrado = 0;
    char s = 'n';

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux1);
    inicpila(&aux2);

    printf("Desea ingresar datos en la pila MODELO? (s/n)");
    fflush(stdin);
    s = getche();

    if(s == 's') {
        printf("\n\nPila MODELO\n");
        ingresardatos(&modelo);
    }

    printf("\n\nPila DADA\n");
    ingresardatos(&dada);

    while(!pilavacia(&dada)) {
        valorEncontrado = buscarValor(tope(&dada), &modelo, &aux2);

        if(valorEncontrado) {
            desapilar(&dada);
        } else {
            apilar(&aux1, desapilar(&dada));
        }
    }

    while(!pilavacia(&aux1)) {
        apilar(&dada, desapilar(&aux1));
    }

    printf("Pila MODELO");
    mostrar(&modelo);
    printf("\n\nPila DADA");
    mostrar(&dada);

    system("pause");
    return 0;
}
