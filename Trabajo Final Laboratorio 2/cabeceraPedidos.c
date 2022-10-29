#include "cabeceraPedidos.h"

int ultimoIdPedido(char nombreArchivo[])
{
    int id = 0;
    stCabeceraPedido c;

    FILE* archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        fseek(archi, -1*(sizeof(stCabeceraPedido)), SEEK_END);
        if(fread(&c, sizeof(stCabeceraPedido), 1, archi)>0)
        {
            id = c.idCabezeraPedido;
        }
        fclose(archi);
    }
    return id;
}


void muestraUnaCabezeraPedido(stCabeceraPedido p)
{
    printf("ID CABECERA PEDIDO...: %d\n", p.idCabezeraPedido);
    printf("ID FECHA.............: %s\n", p.fechaPedido);
    printf("ID CLIENTE...........: %d", p.idCliente);

}










