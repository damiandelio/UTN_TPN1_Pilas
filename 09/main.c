/// 9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// recibe como parametro un puntero a la pila a la que se le va a cargar datos
// y su nombre en string
void ingresardatos(Pila* pila, char* name) {
    char s = 's';

    while (s == 's') {
        leer(pila);
        printf("Desea cargar otro dato en la pila %s? (s/n): ", name);
        fflush(stdin);
        scanf("%c",&s);
    }

    printf("\n");
    return;
}

int main()
{
    Pila a, b, aux;
    int numElementsA, numElementsB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);
    numElementsA = 0;
    numElementsB = 0;

    printf("Pila A\n");
    ingresardatos(&a, "A");
    printf("Pila B\n");
    ingresardatos(&b, "B");

    // pasa todos los elementos de la pila a a la pila aux
    // y cuenta los elementos pasados
    while(!pilavacia(&a)) {
        apilar(&aux, desapilar(&a));
        numElementsA++;
    }

    // vuelve a pasar todo a a de vuelta y livera la pila aux
    while(!pilavacia(&aux)) {
        apilar(&a, desapilar(&aux));
    }

    // pasa todos los elementos de la pila b a la pila aux
    // y cuenta los elementos pasados
    while(!pilavacia(&b)) {
        apilar(&aux, desapilar(&b));
        numElementsB++;
    }

    // vuelve a pasar todo a b
    while(!pilavacia(&aux)) {
        apilar(&a, desapilar(&aux));
    }

    printf(
           "la pila A tiene %i elementos y la pila B tiene %i.\n",
           numElementsA,
           numElementsB
           );

    system("pause");
    return 0;
}
