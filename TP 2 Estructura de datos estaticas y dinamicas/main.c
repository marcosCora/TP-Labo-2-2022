#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "pila.h"

///CONSTANTES
const int ESC = 27;

void muestraMenu();


int main()
{
    char opcion;

    Pila pilota;
    inicPila(&pilota);

    int num = 8;

    while(opcion != ESC)
    {
        printf("Ingresa un numero entero: ");
        scanf("%d", &num);

        apilar(&pilota, num);

        printf("\nESC para salir\n\n");
        opcion = getch();
    }

    mostrar(&pilota);

    int desapil = desapilar(&pilota);
    printf("\ndesapilado: %d\n\n", desapil);

    mostrar(&pilota);

    int flag = pilaVacia(&pilota);

    printf("\nsi tiene datos 0 /si esta vacia 1 : %d\n\n", flag);

    leer(&pilota);
    leer(&pilota);
    mostrar(&pilota);

    /**
    do
    {


        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            break;

        case 50:

            break;

        case 51:

            break;
        case 52:

            break;
        case 53:

            break;
        case 54:

            break;

        }
    }
    while(opcion != ESC);
    */

    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga que funcion desea realizar\n");
    printf("1- \n");
    printf("2- \n");
    printf("3- \n");
    printf("4- \n");
    printf("5- \n");
    printf("6- \n");
    printf("7- \n");
}
