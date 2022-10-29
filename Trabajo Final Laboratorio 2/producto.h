#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ESC 27
#define ARCHIVO_PRODUCTO "producto.dat"

typedef struct
{
    int idProducto;     //autoincremental
    char nombre[30];
    char marca[20];
    float precio;
    int eliminado;      //indica 1 o 0 si el producto esta eliminado
    int stock;
} stProducto;


//FUNCIONES DE CARGA Y MUESTRA DE PRODUCTO, FUNCION PARA ID AUTOINCREMENTRAL
stProducto cargaUnProducto();
void cargaArchivoProducto(char nombreArchivo[]);
void muestraUnProducto(stProducto p);
void mostrarArchivoProducto(char nombreArchivo[]);
int ultimoIdProducto(char nombreArchivo[]);

//FUNCION QUE PASA DEL ARCHIVO A UN ARREGLO PARA LUEGO HACER AGREGACION BINARIA EN EL ARBOL DE PRODUCTOS
int archivo2ArrayProducto(stProducto p[], int dim, int v, char nombreArchivo[]);
void mostrarArrayProducto(stProducto p[], int v);

int cuentaCantProductosActivos (char nombreArchivo[]);

#endif // PRODUCTO_H_INCLUDED
