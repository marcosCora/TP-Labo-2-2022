#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menuPrincipal.h"

typedef struct{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int rol;                         //1: es admin - 0: es comun
    int activo;                      //1 activo - 0 inactivo
}stCliente;

stCliente cargaUnCliente();
void muestraUnCliente(stCliente c);
void cargaArchivoCliente(char nombreArchivo[]); //OPCION PARA CARGAR VARIOS CLIENTES (MODO ADMIN)
void altaUnClienteArchivo(char nombreArchivo[]); //OPCION PARA CARGAR SOLO UN CLIENTE (MODO USUARIO)
int ultimoIdCliente(char nombreArchivo[]);
void mostrarArchivoCliente(char nombreArchivo[]);

#endif // CLIENTE_H_INCLUDED




