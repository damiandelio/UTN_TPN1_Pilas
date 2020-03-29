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

// mueve todo el contenido de una pila a otra
void mover(Pila *destino, Pila *origen){
    while(!pilavacia(origen)) {
        apilar(destino, desapilar(origen));
    }
}

// busca un valor dentro de una pila. Retorna 1 si lo encuentra o 0 si no lo encuentra
int valorPresente( int val, Pila *pila ) {
    Pila aux;
    int valTope = 0;

    inicpila(&aux);

    while(!pilavacia(pila)) {
        valTope = desapilar(pila);
        apilar(&aux, valTope);
        if(val == valTope) {
            mover(pila, &aux);
            return 1;
        }
    }
    mover(pila, &aux);
    return 0;
}

int main()
{
    Pila dada, modelo, aux1;
    int valorEncontrado = 0;
    char s = 'n';

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux1);

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
        valorEncontrado = valorPresente(tope(&dada), &modelo);
        if(valorEncontrado) {
            desapilar(&dada);
        } else {
            apilar(&aux1, desapilar(&dada));
        }
    }

    mover(&dada,&aux1);

    printf("Pila MODELO");
    mostrar(&modelo);
    printf("\n\nPila DADA");
    mostrar(&dada);

    system("pause");
    return 0;
}
