#ifndef FUNCIONESAUX_H_INCLUDED
#define FUNCIONESAUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "producto.h"
#include "listas.h"

///CONSTANTES
#define ESC 27

nodo* cargaListaPrincipio(nodo* lista);
nodo* cargaListaFinal(nodo* lista);
nodo* archivo2Lista(nodo* lista, char nombreArch[]);
nodo* archivo2ListaOrdenado(nodo* lista, char nombreArch[]);
nodo* intercaloListas(nodo* lista1, nodo* lista2);
nodo* inviertoLista(nodo* lista);

///FUNCIONES RECURSIVAS
float sumaPrecioProductoListaRecursivo(nodo* lista);
nodo* inviertoListaRecursivo(nodo* lista);



#endif // FUNCIONESAUX_H_INCLUDED
