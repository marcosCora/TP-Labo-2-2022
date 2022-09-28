#ifndef FUNCIONESAUX_H_INCLUDED
#define FUNCIONESAUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "producto.h"
#include "listaDoble.h"


///CONSTANTES
#define ESC 27

nodoDoble* cargaListaDoblePrincipio(nodoDoble* lista);
nodoDoble* archivo2ListaDoble(nodoDoble* lista, char nombreArch[]);

nodoDoble* cargaListaDobleFinal(nodoDoble* lista);
///nodoDoble* archivo2ListaOrdenado(nodoDoble* lista, char nombreArch[]);
///nodoDoble* intercaloListas(nodoDoble* lista1, nodoDoble* lista2);
///nodoDoble* inviertoLista(nodoDoble* lista);


#endif // FUNCIONESAUX_H_INCLUDED
