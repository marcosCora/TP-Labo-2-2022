#include "funcionesAux.h"

///carga elementos a la lista al principo

nodo* cargaListaPrincipio(nodo* lista)
{
    nodo* nuevoNodo;
    char opcion = ' ';
    stProducto p;

    while(opcion != ESC)///carga nodos hasta que el usuario lo desee
    {
        p = cargaUnProducto();
        nuevoNodo = creaNodo(p);///creo el nuevo nodo con los datos de la persona
        lista = agregarPrincipioLista(lista, nuevoNodo);///agrego el neuvo nodo al principio de la lista

        printf("\nESC si desea salir/OTRO continuar\n\n");
        opcion = getch();
    }

    return lista;///retorno la lista con los nuevos nodos
}

///carga elementos a la lista al final

nodo* cargaListaFinal(nodo* lista)
{
    nodo* nuevoNodo;
    char opcion = ' ';
    stProducto p;

    while(opcion != ESC)///carga nodos hasta que el usuario lo desee
    {
        p = cargaUnProducto();
        nuevoNodo = creaNodo(p);///creo el nuevo nodo con los datos de la persona
        lista = agregoFinalLista(lista, nuevoNodo);///agrego el neuvo nodo al principio de la lista

        printf("\nESC si desea salir/OTRO continuar\n\n");
        opcion = getch();
    }

    return lista;///retorno la lista con los nuevos nodos
}



///paso de un archivo a una lista

nodo* archivo2Lista(nodo* lista, char nombreArch[])
{
    stProducto p;
    nodo* nuevoNodo;

    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&p, sizeof(stProducto), 1, arch))
        {
            nuevoNodo = creaNodo(p);
            lista = agregoFinalLista(lista, nuevoNodo);
        }
        fclose(arch);
    }

    return lista;
}

///funcion que pasa los datos de una archivo a una lista de manera ordenada por marca

nodo* archivo2ListaOrdenado(nodo* lista, char nombreArch[])
{
    stProducto p;
    nodo* nuevoNodo;

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


///intercalo 2 listas sin crear nuevos nodos EJERCICIO 4

nodo* intercaloListas(nodo* lista1, nodo* lista2)
{
    nodo* listaFinal = inicLista();
    nodo* aux;


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


///funcion que invierte una lista sin hacer nuevos nodos

nodo* inviertoLista(nodo* lista)
{
    nodo* listaInvertida = inicLista();
    nodo* aux = NULL;

    while(lista)
    {
        /**
        aux = lista;
        lista = lista->sig;
        aux->sig = NULL;
        */
        aux = desvinculaNodo(&lista);
        listaInvertida = agregarPrincipioLista(listaInvertida, aux);
    }

    return listaInvertida;
}

///invierto lista de forma recursiva
///funcion que cumple pero es pedorra
/**
nodo* inviertoListaRecursivo(nodo* lista)
{
    nodo* listaInvertida = inicLista();
    nodo* aux = NULL;


    if(lista->sig != NULL) /// si la lista esta vacia explota
    {
        listaInvertida = inviertoListaRecursivo(lista->sig);
    }
    aux = desvinculaNodo(&lista);

    listaInvertida = agregoFinalLista(listaInvertida, aux);


    return listaInvertida;
}
*/

nodo* inviertoListaRecursivo(nodo* lista)
{
    nodo * aux;
    if(lista)
    {
        ///desvinculo el primer nodo de la lista dejandolo en auxiliar
        ///el nuevo primer nodo sera el "segundo" que estaba antes de la llavada a la funcion
        aux = desvinculaNodo(&lista);

        ///llamo a la recursividad (no se pone lista siguiente ya que la funcion desvincular deja
        ///como primer nodo al siguiente que se encontraba en la lista antes de ser invocada
        lista = inviertoListaRecursivo(lista);

        ///cuando la rescursividad llegue al final de la lista se ira agregando al final de la
        ///la misma lista ya que al desvincular quedara vacia
        lista = agregoFinalLista(lista, aux);
    }
    return lista;
}



///funcion que suma todos los precios de los productos de una lista de forma recursiva
float sumaPrecioProductoListaRecursivo(nodo* lista)
{
    float rta = 0;

    if(lista)
    {
        rta = (float) lista->dato.precio + sumaPrecioProductoListaRecursivo(lista->sig);
    }

    return rta;
}

///funcion que muestra los elemtnos de una lista en sus posiciones pares empezando desde la 1

void muestraNodosParesListaRecursivo(nodo* lista)
{

    if(lista)
    {
        lista = lista->sig;
        muestraUnNodo(lista);
        muestraNodosParesListaRecursivo(lista->sig);
    }
}








