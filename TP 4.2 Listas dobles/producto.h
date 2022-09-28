#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>


///CONSTANTES

#define ESC 27

#define archProductos "archProductos.dat"

typedef struct
{
    int idProducto;
    char nombre[30];
    char marca[20];
    float precio;
    int eliminado; ///indica 1 o 0 si el producto fue elimiando
}stProducto;

stProducto cargaUnProducto();
void muestraUnProducto(stProducto p);
void cargaArchProducto(char nombreArch[]);
void muestraArchProducto(char nombreArch[]);



#endif // PRODUCTO_H_INCLUDED
