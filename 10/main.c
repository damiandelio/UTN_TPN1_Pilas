/// 10. Comparar las pilas A y B. Mostrar por pantalla el resultado.

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

int sonIguales(Pila *a, Pila *b){
    while(!pilavacia(a) && !pilavacia(b)){
        if(desapilar(a) != desapilar(b)){
            return 0;
        }
    }
    if(pilavacia(a) && pilavacia(b)){
        return 1;
    } else{
        return 0;
    }
}

int main()
{
    Pila a, b, aux1, aux2;

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux1);
    inicpila(&aux2);

    ingresardatos(&a);
    ingresardatos(&b);

    int iguales = sonIguales(&a,&b);
    if(iguales==1){
        printf("son iguales\n\n");
    }else{
        printf("son distintas\n\n");
    }

    system("pause");
    return 0;
}
