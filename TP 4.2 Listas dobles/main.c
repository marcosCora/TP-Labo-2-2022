#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "producto.h"
#include "funcionesAux.h"

///CONSTANTES

void muestraMenu();


int main()
{
    char opcion;

    nodoDoble* listaDobleProductos = inicListaDoble();
    int idAbuscar = 0;

    do
    {


        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            printf("Cargando archivo de productos:\n\n");
            cargaArchProducto(archProductos);

            break;

        case 50:

            muestraArchProducto(archProductos);
            opcion = getch();

            break;

        case 51:

            listaDobleProductos = archivo2Lista(listaDobleProductos, archProductos);
            printf("Se pasaron los datos.\n\n");
            opcion = getch();

            break;
        case 52:

            printf("Esta es la lista de productos:\n\n");
            muestraListaDoble(listaDobleProductos);
            opcion = getch();

            break;
        case 53:

            listaDobleProductos = cargaListaDoblePrincipio(listaDobleProductos);

            break;
        case 54:

            listaDobleProductos = cargaListaDobleFinal(listaDobleProductos);

            break;
        case 55:

            listaDobleProductos = borraListaDoble(listaDobleProductos);
            printf("La lista a sido borrada\n");
            opcion = getch();

            break;
        case 56:

            listaDobleProductos = eliminaUltimoNodoDoble(listaDobleProductos);
            printf("El ultimo nodo a sido borrado\n\n");
            opcion = getch();

            break;
        case 57:

            listaDobleProductos = eliminaPrimerNodoDoble(listaDobleProductos);
            printf("El primer nodo a sido eliminado");
            opcion = getch();

            break;
        case 97:

            printf("Esta es la lista:\n\n");
            muestraListaDoble(listaDobleProductos);

            printf("Ingrese el ID del producto a borrar: ");
            scanf("%d", &idAbuscar);

            listaDobleProductos = borrarNodoId(listaDobleProductos, idAbuscar);
            printf("El dato a sido eliminado\n\n");
            opcion = getch();

            break;

        }
    }
    while(opcion != ESC);

    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga que funcion desea realizar\n\n");
    printf("1- Carga archivo de productos\n");
    printf("2- Muestra archivo de productos\n");
    printf("3- Archivo TWO lista doble\n");
    printf("4- Muestra lista doble\n");
    printf("5- Carga lista doble principio\n");
    printf("6- Carga lista doble final\n");
    printf("7- Borrar lista doble\n");
    printf("8- Elimina ultimo nodo lista doble\n");
    printf("9- Elimina primer nodo de lista doble\n");
    printf("A- Elimina nodo por ID\n");
    printf("B- Agrega un dato a la lista ordenado por marca\n");
    printf("C- \n");
    printf("D- \n");
    printf("E- \n");
    printf("F- \n");
    printf("G- \n");
}
