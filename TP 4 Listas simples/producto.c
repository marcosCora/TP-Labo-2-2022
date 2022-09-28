#include "producto.h"

stProducto cargaUnProducto()
{
    stProducto p;

    printf("Nombre del producto..: ");
    fflush(stdin);
    gets(p.nombre);

    printf("Marca del producto...: ");
    fflush(stdin);
    gets(p.marca);

    printf("Precio...............: ");
    scanf("%f", &p.precio);

    p.eliminado = 0;

    return p;
}

void muestraUnProducto(stProducto p)
{
    printf("-----------------------------\n");
    printf("ID.........: %d\n", p.idProducto);
    printf("NOMBRE.....: %s\n", p.nombre);
    printf("MARCA......: %s\n", p.marca);
    printf("PRECIO.....: %.2f\n", p.precio);
    printf("ELIMINADO..: %d\n", p.eliminado);
    printf("-----------------------------\n");

}

void cargaArchProducto(char nombreArch[])
{
    stProducto p;
    char opcion = ' ';

    int id = buscaUltimoId(nombreArch);
    FILE *arch = fopen(nombreArch, "ab");

    if(arch)
    {
        while(opcion != ESC)
        {
            p = cargaUnProducto();
            id++;
            p.idProducto = id;
            fwrite(&p, sizeof(stProducto), 1, arch);

            printf("\nESC si desea salir/OTRO continuar\n\n");
            opcion = getch();
        }

        fclose(arch);
    }

}


void muestraArchProducto(char nombreArch[])
{

    stProducto p;

    FILE *arch = fopen(nombreArch, "rb");

    printf("\nArchivo de productos:\n\n");
    if(arch)
    {
        while(fread(&p, sizeof(stProducto), 1, arch) > 0)
        {
            muestraUnProducto(p);
        }
        fclose(arch);
    }
}


///busca ultimo ID en archivo de productos

int buscaUltimoId(char nombreArch[])
{
    int UltimoId = 0;
    stProducto p;

    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        fseek(arch, sizeof(stProducto)*(-1), SEEK_END);
        if(fread(&p, sizeof(stProducto), 1, arch) > 0)
        {
            UltimoId = p.idProducto;
        }
        fclose(arch);
    }

    return UltimoId;
}





















