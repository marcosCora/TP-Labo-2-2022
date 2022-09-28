#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "funcionesAux.h"


///CONSTANTES
///const int ESC = 27;
#define archProductos  "ArchProductos.dat"
#define archPordenado1 "ArchOrdenadoProducto1.dat"
#define archPordenado2  "ArchOrdenadoProducto2.dat"

void muestraMenu();


int main()
{
    ///cargaArchProducto(archPordenado1);
    ///cargaArchProducto(archPordenado2);

    char opcion;
    nodo* listaProducto = inicLista();

    nodo* nodoBuscado = inicLista();

    nodo* listaFinal = inicLista();
    nodo* lista1 = inicLista();
    nodo* lista2 = inicLista();

    int datoAbuscar = 0;

    stProducto p;

    float sumaPrecio = 0;

    ///system("Color A8");

    do
    {


        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            cargaArchProducto(archProductos);

            break;

        case 50:

            muestraArchProducto(archProductos);
            opcion = getch();

            break;

        case 51:

            listaProducto = archivo2Lista(listaProducto, archProductos);
            printf("SE PASARON LOS DATOS\n\n");
            opcion = getch();

            break;
        case 52:

            printf("Esta es la lista de productos:\n\n");
            muestraLista(listaProducto);
            opcion = getch();

            break;
        case 53:

            listaProducto = cargaListaPrincipio(listaProducto);

            break;
        case 54:

            listaProducto = cargaListaFinal(listaProducto);

            break;
        case 55:

            listaProducto = borraLista(listaProducto);
            printf("La lista fue borrada\n\n");
            opcion = getch();

            break;
        case 56:

            listaProducto = eliminaPrimerNodo(listaProducto);
            ///listaProducto = eliminaPrimerNodo(listaProducto);
            printf("Se elimino el ultimo nodo o primer nodo\n\n");
            opcion = getch();

            break;
        case 57:

            muestraLista(listaProducto);
            printf("\nIngrese el ID del prodructo a buscar: ");
            scanf("%d", &datoAbuscar);

            nodoBuscado = buscarNodoId(listaProducto, datoAbuscar);

            if(nodoBuscado != NULL)
            {
                printf("El producto a sido encontrado:\n");
                muestraUnNodo(nodoBuscado);
            }
            else
            {
                printf("El producto NO se  encuentra en la lista.\n\n");
            }
            opcion = getch();


            break;
        case 97:

            muestraLista(listaProducto);
            printf("\nIngrese el ID del prodructo a borrar: ");
            scanf("%d", &datoAbuscar);

            nodoBuscado = buscarNodoId(listaProducto, datoAbuscar);

            if(nodoBuscado != NULL)
            {
                listaProducto = borrarNodoId(listaProducto, datoAbuscar);
                printf("El producto fue borrado\n");
            }
            else
            {
                printf("El producto NO se  encuentra en la lista.\n\n");
            }
            opcion = getch();

            break;
        case 98:

            printf("Ingrese el nuevo producto:\n\n");
            p = cargaUnProducto();
            listaProducto = agregarEnOrden(listaProducto, creaNodo(p));
            printf("\nEl producto ya fue agregado a la lista\n");
            opcion = getch();

            break;
        case 99:

            listaProducto = crearListaOrdenadaMarca(listaProducto);

            break;
        case 100:

            listaProducto = archivo2ListaOrdenado(listaProducto, archProductos);
            printf("SE PASARON LOS DATOS\n\n");
            opcion = getch();

            break;
        case 101:

            lista1 = archivo2Lista(lista1, archPordenado1);
            lista2 = archivo2Lista(lista2, archPordenado2);

            printf("Lista 1:\n\n");
            muestraLista(lista1);

            printf("Lista 2:\n");
            muestraLista(lista2);

            listaFinal = intercaloListas(lista1, lista2);
            printf("Esta es la lista final:\n\n");
            muestraLista(listaFinal);


            opcion = getch();


            break;
        case 102:

            printf("Lista de productos:\n\n");
            muestraLista(listaProducto);

            listaProducto = inviertoLista(listaProducto);

            printf("Esta es la lista invertida:\n\n");
            muestraLista(listaProducto);
            opcion = getch();


            break;

        case 103:

            sumaPrecio = sumaPrecioProductoListaRecursivo(listaProducto);
            printf("\nLa suma del precio de todos los productos es %.2f\n", sumaPrecio);
            opcion = getch();


            break;

        case 104:

            printf("Esta es la lista con sus nodos pares:\n\n");
            muestraNodosParesListaRecursivo(listaProducto);
            opcion = getch();

            break;

        case 105:

            listaProducto = inviertoListaRecursivo(listaProducto);
            printf("Esta es la lista invertida:\n\n");
            muestraLista(listaProducto);

            opcion = getch();
            break;
        case 106:

            muestraLista(listaProducto);
            printf("\nIngrese el ID del prodructo a borrar: ");
            scanf("%d", &datoAbuscar);

            nodoBuscado = buscarNodoId(listaProducto, datoAbuscar);

            if(nodoBuscado != NULL)
            {
                listaProducto = borraNodoRecursivoID(listaProducto, datoAbuscar);
                printf("El producto fue borrado\n");
            }
            else
            {
                printf("El producto NO se  encuentra en la lista.\n\n");
            }

            opcion = getch();
            break;
        case 107:

            printf("Ingrese el nuevo producto:\n\n");
            p = cargaUnProducto();
            listaProducto = agregarEnOrdenRecursivo(listaProducto, creaNodo(p));
            printf("\nEl producto ya fue agregado a la lista\n");

            opcion = getch();
            break;
        case 108:

            opcion = getch();
            break;
        case 109:

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
    printf("1- Carga un archivo de tipo producto\n");
    printf("2- Muestra un arcivo de tipo producto\n");
    printf("3- Archivo TWO lista\n");
    printf("4- Muestra Lista de productos\n");
    printf("5- Carga Lista de productos principio\n");
    printf("6- Agrega a la lista desde el final\n");
    printf("7- Borra lista completa\n");
    printf("8- Borro ultimo nodo o primero de la lista \n");
    printf("9- Busca prudcto por ID\n");
    printf("A- Borra nodo por ID \n");
    printf("B- Agrega producto a lista ordenada por marca\n");
    printf("C- Carga lista en orden por marca\n");
    printf("D- Archivo TWO lista ORDENADO por marca \n");
    printf("E- Cargo 2 listas ordenada y creo una lista final intercalada \n");
    printf("F- Invierto lista de productos \n");
    printf("G- Suma precio de una lista de productos recrusivo \n");
    printf("H- Muestra nodos pares recursivo \n");
    printf("I- Invierto lista recrusivo \n");
    printf("J- Borra nodo por ID recursivo\n");
    printf("K- Agrego en orden a lista ordenada recursivo \n");
}












