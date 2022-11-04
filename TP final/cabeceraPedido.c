#include "cabeceraPedido.h"

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
            id = c.idCabeceraPedido;
        }
        fclose(archi);
    }
    return id;
}


void muestraUnaCabeceraPedido(stCabeceraPedido p)
{
    printf("ID CABECERA PEDIDO...: %d\n", p.idCabeceraPedido);
    printf("ID FECHA.............: %s\n", p.fechaPedido);
    printf("ID CLIENTE...........: %d\n", p.idCliente);


}

stCabeceraPedido fechaActual(stCabeceraPedido c)
{
    /// Tiempo actual
    time_t t = time(NULL);

    struct tm tiempoLocal = *localtime(&t);

    /// El lugar en donde se pondrá la fecha y hora formateadas
    char fechaHora[20];

    /// El formato. Mira más en https://en.cppreference.com/w/c/chrono/strftime
    char *formato = "%d/%m/%Y %H:%M:%S";

    /// Intentar formatear
    int bytesEscritos = strftime(fechaHora, sizeof (fechaHora), formato, &tiempoLocal);


    if(bytesEscritos != 0)
    {
        strcpy(c.fechaPedido, fechaHora);
    }

    return c;
}
















