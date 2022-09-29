#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void inicPila(nodo** pila);
int pilaVacia(nodo** pila);
int tope(nodo** pila);
int desapilar(nodo** pila);
void apilar(nodo** pila, int dato);
void mostrar(nodo** pila);
void leer(nodo** pila);




#endif // PILA_H_INCLUDED
