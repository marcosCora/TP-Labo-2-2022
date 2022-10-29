#include "cliente.h"


#define ARCHIVO_CLIENTE "cliente.dat"
#define ESC 27

stCliente cargaUnCliente()
{
    stCliente c;

    cleanAndSetScreen();
    printf(" Ingrese Nombre: ");
    fflush(stdin);
    gets(c.nombre);
    cleanAndSetScreen();
    printf(" Ingrese Apellido: ");
    fflush(stdin);
    gets(c.apellido);
    cleanAndSetScreen();
    printf(" Ingrese UserName: ");
    fflush(stdin);
    gets(c.userName);
    cleanAndSetScreen();
    printf(" Ingrese Password: ");
    fflush(stdin);
    gets(c.password);
    cleanAndSetScreen();
    printf(" Ingrese Mail: ");
    fflush(stdin);
    gets(c.mail);
    cleanAndSetScreen();
    printf(" Ingrese Genero: ");
    fflush(stdin);
    scanf("%c", &c.genero);

    c.rol = 0;
    c.activo = 1;

    return c;
}

void muestraUnCliente(stCliente c)
{
    printf("\n ID.........: %d", c.idCliente);
    printf("\n Nombre.....: %s", c.nombre);
    printf("\n Apellido...: %s", c.apellido);
    printf("\n UserName...: %s", c.userName);
    printf("\n Password...: %s", c.password);
    printf("\n Mail.......: %s", c.mail);
    printf("\n Genero.....: %c", c.genero);
    printf("\n Rol........: %d", c.rol);
    printf("\n ------------------------\n");
}

void cargaArchivoCliente(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stCliente c;
    char opcion = 0;
    int id = ultimoIdCliente(ARCHIVO_CLIENTE);
    if(archi)
    {
        do
        {
            system("cls");
            c = cargaUnCliente();
            id++;
            c.idCliente = id;
            fwrite(&c, sizeof(stCliente), 1, archi);
            printf("\n ESC para salir / cualquier tecla para seguir cargando...\n");
            opcion = getch();

        }
        while(opcion!=ESC);
        fclose(archi);
    }
}
//FUNCION QUE RETORNA EL ULTIMO ID PARA PODER HACER EL AUTOINCREMENTO DEL ID EN EL ARCHIVO
int ultimoIdCliente(char nombreArchivo[])
{
    int id=0;
    stCliente c;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        fseek(archi, -1*(sizeof(stCliente)), SEEK_END);
        if(fread(&c, sizeof(stCliente), 1, archi)>0)
        {
            id=c.idCliente;
        }
        fclose(archi);
    }
    return id;
}

void mostrarArchivoCliente(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente c;
    if(archi)
    {
        while(fread(&c, sizeof(stCliente), 1, archi)>0)
        {
            muestraUnCliente(c);
        }
        fclose(archi);
    }
}

void altaUnClienteArchivo(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stCliente c;
    int id = ultimoIdCliente(nombreArchivo);
    if(archi)
    {
        system("cls");
        c = cargaUnCliente();           //EN ESTA FUNCION AL IGUAL QUE EN CARGA ARCHIVO CLIENTE TENEMOS QUE HACER TODAS LAS VALIDACIONES
        id++;
        c.idCliente = id;
        fwrite(&c, sizeof(stCliente), 1, archi);
        printf("\nRegistro exitoso!\n");
        system("pause");
        fclose(archi);
    }
}
