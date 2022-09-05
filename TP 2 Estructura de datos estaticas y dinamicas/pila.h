#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int* valores;
    int posTope;
} Pila;

void inicPila(Pila *p);
void apilar(Pila *p, int valor);
int desapilar(Pila* p);
int tope(Pila *p);
int pilaVacia(Pila *p);
void mostrar(Pila *p);
void leer(Pila *p);

void redimensionPila(Pila *p);


#endif // PILA_H_INCLUDED
