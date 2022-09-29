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

    nodo* pilota;
    inicPila(&pilota);

    leer(&pilota);

    int flag = 0;

    do
    {


        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            cargaPila(&pilota);

            break;

        case 50:

            printf("Esta es la pila:\n");
            mostrar(&pilota);
            opcion = getch();

            break;

        case 51:

            flag = pilaVacia(&pilota);
            printf("1 TIENE DATOS\\0 SI NO TIENE DATOS: %d", flag);
            opcion = getch();

            break;
        case 52:

            if(pilaVacia(&pilota))
            {
                flag = tope(&pilota);
                printf("El tope de la pila es el siguiente: %d", flag);

            }
            else
            {
                printf("La pila esta vacia.\n\n");
            }
            opcion = getch();

            break;
        case 53:

            if(pilaVacia(&pilota))
            {
                flag = desapilar(&pilota);
                printf("El dato %d ya fue desapilado", flag);

            }
            else
            {
                printf("La pila esta vacia.\n\n");
            }
            opcion = getch();
            break;
        case 54:

            break;

        }
    }
    while(opcion != ESC);

    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga que funcion desea realizar\n");
    printf("1- Carga una pila\n");
    printf("2- Muestra pila\n");
    printf("3- pila vacia\n");
    printf("4- Tope pila\n");
    printf("5- Desapila\n");
    printf("6- \n");
    printf("7- \n");
}



void cargaPila(nodo** pila)
{
    char opcion;
    int dato = 0;

    while(opcion != ESC)
    {
        printf("Ingrese un dato: ");
        scanf("%d", &dato);

        apilar(pila, dato);

        printf("\nESC para salir//otro para continuar\n\n");
        opcion = getch();
    }
}















