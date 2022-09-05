#include "pila.h"

///inicializa la pila de 10 elementos
void inicPila(Pila *p)
{
    p->valores = malloc(sizeof(int)*5);
    p->posTope = 0;

}

///funcion que redimenciona una pila
/**
void redimensionPila(Pila *p)
{
    p->valores = realloc(p, sizeof(int)*5);
}
*/


///apila la variable valor en el lugar que corresponde
void apilar(Pila *p, int valor)
{
    if(p->posTope == 5)
    {
        /**redimensionPila(p);
        p->posTope++;*/
        printf("\n\nLA PILA SE LLENO\n\n");
    }
    else
    {
        p->valores[p->posTope] = valor;
        p->posTope++;
    }
}

int desapilar(Pila* p)
{

    int aux = p->valores[p->posTope-1];
    p->posTope--;

    return aux;
}


int tope(Pila *p)
{
    int aux = p->valores[p->posTope-1];
    return aux;
}

int pilaVacia(Pila *p)
{
    int flag = 0;///0 tiene datos /// 1 no tiene datos

    if(p->posTope == 0)
    {
        flag = 1;
    }

    return flag;
}

void mostrar(Pila *p)
{
    int i = 0;

    printf("\n\nBASE-----------------------------TOPE\n\n");
    for(i = 0; i<p->posTope; i++)
    {
        printf("%d - ", p->valores[i]);
    }
    printf("\n\nBASE-----------------------------TOPE\n\n");

}


void leer(Pila *p)
{
    int dato;

    printf("Ingrese dato: ");
    scanf("%d", &dato);

    apilar(p, dato);

}



































