#include "arbolProducto.h"

arbolProducto * inicArbol ()
{
    return NULL;
}

arbolProducto * crearNodoArbol (stProducto dato)
{
    arbolProducto * arbol = (arbolProducto *)malloc(sizeof(arbolProducto)); // creo el nodo
    arbol->datoProducto = dato;       // igualo la variable datos a la que recivo
    arbol->der=NULL;               /// inicializo dereca en NULL
    arbol->izq=NULL;                /// inicializo izquierda en NULL

    return arbol;   /// retorno el arbol
}

void muestraUnNodoArbol (arbolProducto * arbol)
{
    muestraUnProducto(arbol->datoProducto);
}


void preorder (arbolProducto * arbol)
{

    if(arbol)
    {
        muestraUnNodoArbol(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder (arbolProducto * arbol)
{
    if(arbol)
    {
        inorder(arbol->izq);
        muestraUnNodoArbol(arbol);
        inorder(arbol->der);
    }
}

void posorder(arbolProducto * arbol)
{
    if(arbol)
    {
        posorder(arbol->izq);
        posorder(arbol->der);
        muestraUnNodoArbol(arbol);

    }

}

arbolProducto * insertarArbolId (arbolProducto * arbol, arbolProducto * nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->datoProducto.idProducto > arbol->datoProducto.idProducto)
        {
            arbol->der = insertarArbolId(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarArbolId(arbol->izq, nuevo);
        }
    }
    return arbol;
}

///funcion que pasa del archivo de productos a un arbol balanceado
arbolProducto * subprogramaArchivo2ArbolBalanceado (char nombreArchivo[], arbolProducto * arbol)
{
    int dimension = cuentaCantProductosActivos(ARCHIVO_PRODUCTO);///la funcion que se invoca devuelve la cantidad de productos activos en el sistema
    stProducto* p = (stProducto*) malloc(sizeof(stProducto)* dimension);///creo un arreglo del tamaño justo
    int validos = 0;


    validos = archivo2ArrayProducto(p, dimension, validos, nombreArchivo);

    arbol = array2Arbol(p, 0, validos-1);

    return arbol;  /// retorno el arbol
}

arbolProducto * buscarArbolId (arbolProducto * arbol, int id)
{

    arbolProducto * aux = NULL;
    if(arbol)
    {
        if(arbol->datoProducto.idProducto == id)
        {
            aux = arbol;
        }
        else
        {
            if(id > arbol->datoProducto.idProducto)
            {
                aux = buscarArbolId(arbol->der, id);
            }
            else
            {
                aux=buscarArbolId(arbol->izq, id);
            }
        }

    }
    return aux;
}


///FUNCION PARA LA AGREGAR EN UN ARBOL DESDE UN ARRAY Y QUE ESTE EQUILIBRADO
arbolProducto* array2Arbol(stProducto p[], int i, int v) ///LE PASO EL INICIO DEL ARRAY Y LOS VALIDOS
{
    int medio;
    arbolProducto* arbol = NULL;

    if(!(i>v))
    {
        medio = (i+v)/2;
        arbol = crearNodoArbol(p[medio]);
        arbol->izq = array2Arbol(p, i, medio-1);
        arbol->der = array2Arbol(p, medio+1,v);
    }
    return arbol;
}
