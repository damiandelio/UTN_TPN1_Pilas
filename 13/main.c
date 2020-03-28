/// 13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o
///     iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.

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

int main()
{
    Pila dada, limite, mayores, menores;
    int topeLimite;

    inicpila(&dada);
    inicpila(&limite);
    inicpila(&mayores);
    inicpila(&menores);

    printf("Ingrese datos para la pila DADA\n");
    ingresardatos(&dada);
    printf("Ingrese datos para la pila LIMITE\n");
    ingresardatos(&limite);

    topeLimite = tope(&limite);

    while(!pilavacia(&dada)) {
        if(tope(&dada) >= topeLimite) {
            apilar(&mayores, desapilar(&dada));
        } else {
            apilar(&menores, desapilar(&dada));
        }
    }

    printf("Pila MAYORES\n");
    mostrar(&mayores);
    printf("\n\nPila MENORES\n");
    mostrar(&menores);

    system("pause");
    return 0;
}
