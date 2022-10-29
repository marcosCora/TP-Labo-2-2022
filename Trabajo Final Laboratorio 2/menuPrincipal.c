#include "menuPrincipal.h"
#define ARCHIVO_CLIENTE "cliente.dat"

void cleanAndSetScreen(){
    system("cls");
    titulo();
    gotoxy(10,10);
}

void titulo(){
    system("cls");
    marco();
    gotoxy(30,5);
    printf("TecBeer");
    gotoxy(30,6);
    printf("-------");
}

int leerOpcion(){
    int opcion;
    gotoxy(10, 20);
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void lineaRecta(int x){
    for(;9<x;x--){
        printf("%c", 205);
    }
}

void lineaRectavertical(int x,int y){
    for(;3<y;y--){
        gotoxy(x,y);
        printf("%c",186);
    }
}



void marco(){
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

void menuPrincipal(){

    int opcion;

    do{
        titulo();
        gotoxy(10,10);
        printf("1. Loguearse");
        gotoxy(10,11);
        printf("2. Registrarse");
        gotoxy(10,12);
        printf("0. Salir");

        opcion = leerOpcion();

        switch(opcion){

            case 1:
                logIn();
                getch();
                break;

            case 2:
                registrarse();
                break;

            case 0:
                break;
        }

    }while(opcion != 0);
}

void logIn(){
    char guardaUsuario[20];
    char guardaPassword[20];
    titulo();
    cleanAndSetScreen();
    printf(" Ingrese UserName: ");
    fflush(stdin);
    scanf("%s", guardaUsuario);
    cleanAndSetScreen();
    printf(" Insgrese Password: ");
    fflush(stdin);
    scanf("%s", guardaPassword);
    //EN ESTA PARTE TENDRIA QUE LLAMAR A UNA FUNCION QUE BUSCA EN LA LISTA DE CLIENTES PARA VER SI EL USUARIO SE ENCUENTRA ACTIVO, SI NO SE ENCUENTRA LE PREGUNTO SI SE QUIERE REGISTRAR
}

void registrarse(){
    titulo();
    altaUnClienteArchivo(ARCHIVO_CLIENTE);//EN ESTA PARTE SOLO CARGO UN CLIENTE YA QUE ENTRO COMO USUARIO
}
