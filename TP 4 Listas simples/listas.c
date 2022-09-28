#include "listas.h"

nodo* inicLista()
{
    return NULL;
}

///funcion que crea un nuevo nodo

nodo* creaNodo(stProducto dato)
{
    ///creo en espacio de memoria un lugar para almacenar mi nuevo nodo
    nodo* nodoNuevo = (nodo*) malloc(sizeof(nodo));

    ///le asigno el dato a el nodo nuevo
    nodoNuevo->dato = dato;

    ///marco el siguiente nodo como NULL
    nodoNuevo->sig = NULL;


    return nodoNuevo;
}

///Funcion que agrega datos a la lista desde el principio

nodo* agregarPrincipioLista(nodo* lista,nodo * nodoNuevo)
{
    ///si la lista no tiene nodos asgina el nuevoNodo como primer elemento de la lista
    if(lista == NULL)
    {
        lista = nodoNuevo;
    }
    else
    {
        ///si no al nuevo nodo le carga la direccion de memoria del primer nodo de la lista
        nodoNuevo->sig = lista;

        ///piso lo que almacena lista con el nodoNuevo ya que este contiene las direcciones de los siguientes nodo al
        ///almacenarse en el principio de la lista
        lista = nodoNuevo;
    }

    return lista;
}


///muestra un nodo

void muestraUnNodo(nodo * nodo)
{
    muestraUnProducto(nodo->dato);
}



///muestra lista

void muestraLista(nodo* lista)
{
    nodo* aux = lista;

    ///printf("Esta es la lista:\n\n");

    while(aux != NULL)
    {
        ///muestraUnProducto(aux->dato);
        muestraUnNodo(aux);
        aux = aux->sig;
    }

}

///busca ultimo nodo

nodo* buscaUltimoNodo(nodo* lista)
{
    nodo* aux = lista; ///creo una variable auxilar

    if(aux != NULL)
    {
        while(aux->sig != NULL) ///recorrre la lista hasta que el siguiente sea NULL
        {
            aux = aux->sig;
        }
    }

    return aux;///retorno el ultimo
}

///agrego el final de la lista
/// A PROBAR

nodo* agregoFinalLista(nodo* lista, nodo* nuevoNodo)
{
    nodo* ultimo;

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ultimo = buscaUltimoNodo(lista);///almaceno el ultimo nodo en la variable ultimo
        ultimo->sig = nuevoNodo;///le asigno el nuevo nodo al siguiente de ultimo
    }

    return lista;
}


///borrar lista

nodo* borraLista(nodo* lista)
{
    stProducto* aux;///creo una variable para ir liberando esa parte de memoria

    while(lista != NULL)
    {
        aux = lista;///le asigno a aux la lista
        lista = lista->sig;///lista se asigna el siguiente y pierdo el primer valor
        free(aux);///borro el nodo con la informacion de aux
    }

    return lista;
}

///funcion que elimina el ultimo nodo de una lista
nodo* eliminaUltimoNodo(nodo* lista)
{
    nodo* aux = lista;///creo una variable auxiliar
    nodo* ante;///anterior

    if(lista != NULL)
    {
        while(aux->sig != NULL)///recorro hasta el ultimo nodo de la lista
        {
            ante = aux;///le asigno a ante lo que se almacena en aux antes de correr hacia adelante
            aux = aux->sig;///me corro de la lista
        }
    }
    ante->sig = NULL;
    free(aux);


    return lista;
}


nodo* eliminaPrimerNodo(nodo* lista)
{
    nodo* aux = lista;///creo una lista auxilliar y el asigno la lista recibida

    if(lista != NULL)
    {
        lista = lista->sig;///le asgino a lista el siguiente nodo que sera el primero
        free(aux);///elimino el primer nodo
    }


    return lista;///retorno la lista
}

///busca un nodo por numero de id
///retorna el nodo si se encuentra y si no retorna null
nodo* buscarNodoId(nodo* lista, int id)
{
    nodo* aux = lista;///creo una variable seguidora

    while((aux != NULL) && (aux->dato.idProducto != id))///recorro la lista mientras no finalize o no se encuentre el nodo
    {
        aux = aux->sig;
    }


    return aux;///retorno el nodo donde del que se busco o NULL si no se encuentra
}

nodo* borrarNodoId(nodo* lista, int id)
{
    ///creo dos listas que sirven para recorrer la lista sin perder datos
    nodo* seg;
    nodo* ante;

    if(lista != NULL && lista->dato.idProducto == id)///si la lista no esta vacia y el primer nodo es el buscado se elimina
    {
        lista = eliminaPrimerNodo(lista);
    }
    else
    {
        seg = lista;///le asgino la lista a siguiente
        while((seg != NULL) && seg->dato.idProducto != id)///recorre la lista mientras no sea NULL y no se encuentre el dato
        {
            ante = seg;
            seg = seg->sig;
        }
        if(seg != NULL)///si seg no es NULL significa que el dato se encontr
        {
            ante->sig = seg->sig;///redirreciono los nodos
            free(seg);///elimino el nodo
        }
    }

    return lista;
}


///funcion que agrega en orden a una lista ya ordenada

nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo)
{
    nodo* seg = lista;
    nodo* ante;


    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ///si el nuevo nodo debe colocarse al principio se llama a la funcion de agregar el principio
        if((seg != NULL) && (strcmpi(seg->dato.marca, nuevoNodo->dato.marca) > 0))
        {
            lista = agregarPrincipioLista(lista, nuevoNodo);
        }
        else///si no recoore la lista y busca el hueco donde ubicarlo
        {
            while((seg != NULL) && (strcmpi(seg->dato.marca, nuevoNodo->dato.marca) < 0))
            {
                ante = seg;
                seg = seg->sig;

            }
            ante->sig = nuevoNodo;
            nuevoNodo->sig = seg;
        }
    }

    return lista;
}


///funcion que va creando una lista ordenada a medida que es cargada
nodo* crearListaOrdenadaMarca(nodo* lista)
{
    char opcion;
    stProducto p;
    nodo* nuevoNodo;

    nodo* seg;
    nodo* ante;

    while(opcion != ESC)
    {
        p = cargaUnProducto();
        nuevoNodo = creaNodo(p);

        if(lista == NULL)
        {
            lista = agregoFinalLista(lista, nuevoNodo);
        }
        else
        {
            lista = agregarEnOrden(lista, nuevoNodo);
        }

        printf("\nESC para salir/otro para continuar\n\n");
        opcion = getch();

    }

    return lista;
}



///funcion que devincula un nodo de la lista recibida y lo retorna solo

nodo* desvinculaNodo(nodo** pLista)
{
    nodo* aux;

    if((*pLista))
    {
        aux  = (*pLista);
        (*pLista) = (*pLista)->sig;
        aux->sig = NULL;
    }
    return aux;
}


///FUNCIONES DE LISTAS RECURSIVAS

void muestraListaRecursiva(nodo* lista)
{

    if(lista)
    {
        muestraUnNodo(lista);
        muestraListaRecursiva(lista->sig);
        ///muestraUnNodo(lista); usando esta linea en vez de la de arriba se mostraria al reves
    }
}


///funcion que elimina el primer nodo de manera recursiva

nodo* borraNodoRecursivoID(nodo* lista, int id)
{
    if(lista)///si la lista tiene datos
    {
        if(lista->dato.idProducto == id)///si el id el nodo corresponde al id del nodo a borrar
        {
            lista = eliminaPrimerNodo(lista);///se elimina el primer nodo  que es el buscado
        }
        else
        {
            lista->sig = borraNodoRecursivoID(lista->sig, id);///el siguiente de la lista es lo que sigue sin el nodo que se queria borrar
        }
    }

    return lista;
}

///funcion que inserta un nodo en una lista de forma recursiva
nodo* agregarEnOrdenRecursivo(nodo* lista, nodo* nuevoNodo)
{

    if(lista)
    {
        if(strcmpi(lista->dato.marca, nuevoNodo->dato.marca) > 0)
        {
            lista = agregarPrincipioLista(lista, nuevoNodo);
        }
        else
        {
            lista->sig = agregarEnOrdenRecursivo(lista->sig, nuevoNodo);
        }
    }
    else
    {
        lista = agregoFinalLista(lista, nuevoNodo);
    }

    return lista;
}













