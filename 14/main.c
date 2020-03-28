///*********************************************************************************************************************
///*  TP Nº1 - 14                                                                                                      *
///*                                                                                                                   *
///*                                                                                                                   *
///*  14. Determinar si la cantidad de elementos de la pila DADA es par.                                               *
///*  Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.  *
///*                                                                                                                   *
///*********************************************************************************************************************


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
    // declaracion
    Pila dada, aux, par, impar;
    int cantElementos;

    // inicializacion
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);
    cantElementos = 0;

    // carga de datos por el usuario
    ingresardatos(&dada);

    // pasa todos los elementos de dada a aux y los cuenta.
    while (!pilavacia(&dada)) {
        // pasa el tope de la pila dada a aux
        apilar(&aux, desapilar(&dada));
        // incrementa el contador
        cantElementos++;
    }

    // si la cantidad de elementos en dada es par
    if ((cantElementos % 2) == 0) {
        printf("La cantidad de elementos en dada es par.\n\n");

        // pasa el tope de la la pila aux a la pila par
        apilar(&par, desapilar(&aux));

    } else { // si la cantidad de elementos en dada es impar
        printf("La cantidad de elementos en dada es impar.");

        // pasa el tope de la la pila aux a la pila impar
        apilar(&impar, desapilar(&aux));
    }

    // imprime el contenido de las pilas por pantalla
    printf("\n\n/////////////// Pila dada ///////////////\n\n");
    mostrar(&dada);

    printf("\n\n/////////////// Pila aux ///////////////\n\n");
    mostrar(&aux);

    printf("\n\n/////////////// Pila par ///////////////\n\n");
    mostrar(&par);

    printf("\n\n/////////////// Pila impar ///////////////\n\n");
    mostrar(&impar);

    // fin
    system("pause");
    return 0;
}
