#include "menu.h"

void cleanAndSetScreen()
{
    system("cls");
    titulo();
    gotoxy(10,10);
}

void titulo()
{
    system("cls");
    marco();
    gotoxy(30,5);
    printf("TecBeer");
    /*gotoxy(30,6);
    printf("-------");*/
}

int leerOpcion()
{
    int opcion;
    gotoxy(10, 20);
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void lineaRecta(int x)
{
    for(; 9<x; x--)
    {
        printf("%c", 205);
    }
}

void lineaRectavertical(int x,int y)
{
    for(; 3<y; y--)
    {
        gotoxy(x,y);
        printf("%c",186);
    }
}



void marco()
{
    gotoxy(8,3);
    printf("%c", 201);
    lineaRecta(58);
    gotoxy(8,22);
    printf("%c", 200);
    lineaRecta(58);
    gotoxy(58,22);
    printf("%c", 188);
    gotoxy(58,3);
    printf("%c", 187);
    lineaRectavertical(58, 21);
    lineaRectavertical(8, 21);


}

void menuPrincipal()
{

    int opcion;

    arbolProducto* productosArbol = inicArbol();
    productosArbol = subprogramaArchivo2ArbolBalanceado(ARCHIVO_PRODUCTO, productosArbol);

    nodoCliente* listaCliente = inicListaCliente();

    ///FALTA PROBAR MAÑANA VIERNES

    listaCliente = subProgramaCargaSistema(listaCliente, productosArbol, ARCHIVO_CLIENTE, ARCHIVO_CABECERA_PEDIDO, ARCHIVO_DETALLE_PRODUCTO);

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1. Loguearse");
        gotoxy(10,11);
        printf("2. Registrarse");
        gotoxy(10,12);
        printf("0. Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            logIn(listaCliente);
            getch();
            break;

        case 2:
            registrarse();
            break;

        case 0:
            break;
        }

    }
    while(opcion != 0);
}

void logIn(nodoCliente* listaCliente)
{

    char guardaUsuario[20];
    char guardaPassword[20];
    int guardaRol;
    titulo();
    cleanAndSetScreen();
    printf(" Ingrese UserName: ");
    fflush(stdin);
    scanf("%s", guardaUsuario);
    gotoxy(10,12);
    printf(" Ingrese Password: ");
    fflush(stdin);
    scanf("%s", guardaPassword);

    guardaRol = buscaRolEnListaCliente(listaCliente, guardaUsuario);
    //EN ESTA PARTE TENDRIA QUE LLAMAR A UNA FUNCION QUE BUSCA EN LA LISTA DE CLIENTES PARA VER SI EL USUARIO SE ENCUENTRA ACTIVO, SI NO SE ENCUENTRA LE PREGUNTO SI SE QUIERE REGISTRAR

    if(guardaRol == 1)
    {
        //MUESTRO MENU PARA EL ADMINISTRADOR
        subMenuAdmin(listaCliente);
    }
    else
    {
        //MUESTRO MENU PARA EL USUARIO
        subMenuUsuario(listaCliente);
    }
}

void registrarse()
{
    titulo();
    altaUnClienteArchivo(ARCHIVO_CLIENTE);//EN ESTA PARTE SOLO CARGO UN CLIENTE YA QUE ENTRO COMO USUARIO
}


//SUB MENU PARA EL ADMINISTRADOR (EN ESTA SECCION SE PUEDE ELEGIR OPCIONES PARA CLIENTE, PEDIDO, PRODUCTO O LIBERAR TODO EL ESPACIO DEL SISTEMA)
void subMenuAdmin(nodoCliente* listaCliente)
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Cliente");
        gotoxy(10,11);
        printf("2.Pedido");
        gotoxy(10,12);
        printf("3.Producto");
        gotoxy(10,13);
        printf("4.Liberar sistema");
        gotoxy(10,14);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            adminCliente(listaCliente);
            break;

        case 2:
            adminPedido(listaCliente);
            break;

        case 3:
            adminProducto();
            break;

        case 4:
            //SUMAR FUNCION PARA LIBERAR TODO EL SISTEMA
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}


//SUB MENU PARA EL USUARIO (EN ESTA SECCION PUEDE ELEGIR OPCIONES DE CLIENTE, PEDIDO O PRODUCTO)
void subMenuUsuario(nodoCliente* listaCliente)
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Cliente");
        gotoxy(10,11);
        printf("2.Pedido");
        gotoxy(10,12);
        printf("3.Producto");
        gotoxy(10,13);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            usuarioCliente();
            break;

        case 2:
            usuarioPedido(listaCliente->listaPedidos);
            break;

        case 3:
            usuarioProducto();
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}



//SUB MENU PARA EL ADMINISTRADOR EN LA SECCION CLIENTE(EN ESTA SECCION TENDRA DISPONIBLE TODAS LAS OPCIONES QUE COMPETEN AL CLIENTE)
void adminCliente(nodoCliente* listaCliente)
{
    int opcion;
    nodoCliente* aux = listaCliente;///se utiliza para mostrar un solo nodo de la lista

    int guardaId;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Ver un cliente");
        gotoxy(10,11);
        printf("2.Ver todos los clientes");
        gotoxy(10,12);
        printf("3.Alta");
        gotoxy(10,13);
        printf("4.Baja");
        gotoxy(10,14);
        printf("5.Modificar");
        gotoxy(10,15);
        printf("6.Eliminar");
        gotoxy(10,16);
        printf("7.Bloquear");
        gotoxy(10,17);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            gotoxy(10, 23);
            printf("Ingrese ID de cliente: ");
            fflush(stdin);
            scanf("%d", &guardaId);
            aux = buscarNodoIdCliente(aux, guardaId);
            gotoxy(11, 24);
            muestraUnNodoCliente(aux);
            getch();

            break;

        case 2:
            gotoxy(11, 24);
            muestraListaCliente(listaCliente);
            getch();
            break;

        case 3:

            break;

        case 4:
            break;

        case 5:
            //HACER FUNCION DE MODIFICACION EN LA LISTA

            break;

        case 6:
            break;

        case 7:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}

void usuarioCliente()
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Ver mi usuario");
        gotoxy(10,11);
        printf("2.Baja");
        gotoxy(10,12);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            break;

        case 2:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}


void adminPedido(nodoCliente* listaCliente)
{
    int opcion;
    int idABuscar = -1;
    nodoCliente* aux = listaCliente;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Ver un pedido"); ///HAY QUE BUSCARLO POR LA FECHA O POR EL ID BUSCA UN PEDIDO DE UN SOLO CLIENTE (SI ELIGE ESTA OPCION PRIMERO INGRESA EL ID DEL CLIENTE QUE QUIERE BUSCAR Y LUEGO LA FECHA O EL ID DEL PEDIDO)
        gotoxy(10,11);
        printf("2.Ver todos los pedidos de un cliente");
        gotoxy(10,12);
        printf("3.Ver todos los pedidos del sistema");
        gotoxy(10,13);
        printf("4.Eliminar pedido");
        gotoxy(10,14);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            break;

        case 2:

            printf("Ingrese el ID del cliente: ");
            scanf("%d", &idABuscar);

            aux = buscarNodoIdCliente(aux, idABuscar);

            if(aux)
            {
                muestraUnNodoCliente(aux);
                printf("\n\nEstos son los pedidos del usuario:\n\n");
                muestraListaPedido(aux->listaPedidos);
            }
            else
            {
                printf("El usuario no existe.\n");
            }
            opcion = getch();

            break;

        case 3:
            break;

        case 4:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}


void usuarioPedido(nodoPedido* listaPedido)
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Ver pedido");
        gotoxy(10,11);
        printf("2.Ver todos los pedidos");
        gotoxy(10,12);
        printf("3.Hacer pedido");
        gotoxy(10,13);
        printf("4.Eliminar pedido");
        gotoxy(10,14);
        printf("4.Modificar pedido");
        gotoxy(10,15);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:

            printf("Estos son los pedidos que tiene cargado:\n\n");
            muestraListaPedido(listaPedido);

            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}

void adminProducto()
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Alta");
        gotoxy(10,11);
        printf("2.Baja");
        gotoxy(10,12);
        printf("3.Modificar");
        gotoxy(10,13);
        printf("4.Eliminar");
        gotoxy(10,14);
        printf("5.Ver todos los productos");
        gotoxy(10,15);
        printf("6.Crear promocion");
        gotoxy(10,16);
        printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}


void usuarioProducto()
{
    int opcion;

    do
    {
        titulo();
        gotoxy(10,10);
        printf("1.Ver productos");
        gotoxy(10,11);
        printf("2.Ver promociones");
        gotoxy(10,12),
               printf("0.Salir");

        opcion = leerOpcion();

        switch(opcion)
        {

        case 1:
            break;

        case 2:
            break;

        case 0:
            break;

        }

    }
    while(opcion != 0);
}






