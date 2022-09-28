#include "funcionesAux.h"

///carga elementos a la lista al principo

nodoDoble* cargaListaDoblePrincipio(nodoDoble* lista)
{
    nodoDoble* nodoNuevo;
    char opcion = ' ';

    printf("Cargando lista doble desde el principio:\n\n");
    while(opcion != ESC)
    {
        nodoNuevo = creaNodoDoble(cargaUnProducto());
        lista = agregarPrincipioListaDoble(lista, nodoNuevo);

        printf("ESC para salir/otro para continuar\n\n");
        opcion = getch();
    }

    return lista;
}


///carga elementos a la lista al final

nodoDoble* cargaListaDobleFinal(nodoDoble* lista)
{
    nodoDoble* nodoNuevo;
    char opcion = ' ';

    printf("Cargando lista doble desde el principio:\n\n");
    while(opcion != ESC)
    {
        nodoNuevo = creaNodoDoble(cargaUnProducto());
        lista = agregoFinalListaDoble(lista, nodoNuevo);

        printf("ESC para salir/otro para continuar\n\n");
        opcion = getch();
    }

    return lista;
}




///paso de un archivo a una lista

nodoDoble* archivo2Lista(nodoDoble* lista, char nombreArch[])
{
    stProducto p;
    nodoDoble* nuevoNodo;

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&p, sizeof(stProducto), 1, arch))
        {
            nuevoNodo = creaNodoDoble(p);
            lista = agregarEnOrden(lista, nuevoNodo);
        }
        fclose(arch);
    }

    return lista;
}



///funcion que pasa los datos de una archivo a una lista de manera ordenada por marca
/*
nodoDoble* archivo2ListaOrdenado(nodoDoble* lista, char nombreArch[])
{
    stProducto p;
    nodoDoble* nuevoNodo;

    int id = buscaUltimoId(nombreArch);

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {

        while(fread(&p, sizeof(stProducto), 1, arch) > 0)
        {
            p.idProducto++;
            nuevoNodo = creaNodo(p);

            if(lista == NULL)
            {
                lista = agregoFinalLista(lista, nuevoNodo);
            }
            else
            {
                lista = agregarEnOrden(lista, nuevoNodo);
            }
        }
        fclose(arch);
    }

    return lista;
}
*/

///intercalo 2 listas sin crear nuevos nodos EJERCICIO 4
/*
nodoDoble* intercaloListas(nodoDoble* lista1, nodoDoble* lista2)
{
    nodoDoble* listaFinal = inicLista();
    nodoDoble* aux;


    while(lista1 != NULL && lista2 != NULL)
    {

        if(strcmpi(lista1->dato.marca, lista2->dato.marca) < 0)
        {
            aux = lista1;
            lista1 = lista1->sig;

        }
        else
        {
            aux = lista2;
            lista2 = lista2->sig;
        }

        aux->sig = NULL;
        listaFinal = agregoFinalLista(listaFinal, aux);
    }

    if(lista1 != NULL)
    {
        listaFinal = agregoFinalLista(listaFinal, lista1);
    }
    else
    {
        listaFinal = agregoFinalLista(listaFinal, lista2);
    }

    return listaFinal;
}
*/

///funcion que invierte una lista sin hacer nuevos nodos
/*
nodoDoble* inviertoLista(nodoDoble* lista)
{
    nodoDoble* listaInvertida;
    nodoDoble* aux = NULL;

    while(lista)
    {
        aux = lista;
        lista = lista->sig;
        aux->sig = NULL;

        listaInvertida = agregarPrincipioLista(listaInvertida, aux);
    }

    return listaInvertida;
}
*/












