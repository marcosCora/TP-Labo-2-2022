#include "producto.h"

stProducto cargaUnProducto()
{
    stProducto p;

    system("cls");
    printf("\n Ingrese nombre: ");
    fflush(stdin);
    gets(p.nombre);

    printf("\n Ingrese marca: ");
    fflush(stdin);
    gets(p.marca);

    printf("\n Ingrese precio: ");
    fflush(stdin);
    scanf("%f", &p.precio);

    printf("\n Ingrese stock: ");
    fflush(stdin);
    scanf("%d", &p.stock);


    p.eliminado = 0;

    return p;
}

void muestraUnProducto(stProducto p)
{
    printf("\n ID......: %d",p.idProducto);
    printf("\n Nombre..: %s",p.nombre);
    printf("\n Marca...: %s",p.marca);
    printf("\n Precio..: $ %.2f",p.precio);
    printf("\n Stock...: %d lts",p.stock);
    printf("\n--------------------------");
}

void cargaArchivoProducto(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stProducto p;
    char opcion = 0;
    int id= ultimoIdProducto(ARCHIVO_PRODUCTO);
    if(archi)
    {
        do
        {
            system("cls");
            p = cargaUnProducto();
            id++;
            p.idProducto = id;
            fwrite(&p, sizeof(stProducto), 1, archi);
            printf("\n ESC para salir / cualquier tecla para continuar...\n");
            opcion = getch();

        }
        while(opcion!=27);

        fclose(archi);
    }
}

//FUNCION QUE RETORNA EL ULTIMO ID PARA PODER HACER EL AUTOINCREMENTO DEL ID EN EL ARCHIVO
int ultimoIdProducto(char nombreArchivo[])
{
    int id=0;
    stProducto p;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        fseek(archi, -1*(sizeof(stProducto)), SEEK_END);
        if(fread(&p, sizeof(stProducto), 1, archi)>0)
        {
            id=p.idProducto;
        }
        fclose(archi);
    }
    return id;
}

void mostrarArchivoProducto(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stProducto p;
    if(archi)
    {
        while(fread(&p, sizeof(stProducto), 1, archi)>0)
        {
            muestraUnProducto(p);
        }

        fclose(archi);
    }
}


//FUNCION QUE PASA DEL ARCHIVO A UN ARREGLO PARA LUEGO HACER AGREGACION BINARIA EN EL ARBOL DE PRODUCTOS
int archivo2ArrayProducto(stProducto p[], int dim, int v, char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(v<dim && fread(&p[v], sizeof(stProducto), 1, archi)>0)
        {
            v++;
        }
        fclose(archi);
    }
    return v;
}

void mostrarArrayProducto(stProducto p[], int v)
{
    for(int i=0; i<v; i++)
    {
        muestraUnProducto(p[i]);
    }
}


///funcion que retorna la cantidad de productos activos que hay en el archivo

int cuentaCantProductosActivos(char nombreArchivo[])
{
    FILE * archi = fopen (nombreArchivo, "rb");
    stProducto p;
    int cont=0;

    if(archi)
    {
        while(fread(&p, sizeof(stProducto), 1, archi)>0)
        {
            if(p.eliminado == 0)
            {
                cont++;
            }
        }
        fclose(archi);
    }
    return cont;
}

