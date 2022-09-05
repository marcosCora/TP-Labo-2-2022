#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

///CONSTANTES
const int ESC = 27;
#define archEnteros  "ArchivoEnteros.dat"

///PROTOTIPADOS
void muestraMenu();
int factorial(int numero);
int potenciaDeUnNumero(int numero, int potencia);
void muestraArrayRecursivo(int a[], int v, int pos);
void muestraArrayRecursivoInvertido(int a[], int v, int pos);
int arrayCapicuaRecrusivo(int a[], int v, int pos);
int sumaArrayrecursivo(int a[], int v, int pos);
int buscaMenorArrayRecursivo(int a[], int v, int pos);
void cargaArchInt(char nombreArch[]);
void muestraArchInt(char nombreArch[]);
void abreArch(char nombreArch[]);
int buscaMenorArchRecursivo(FILE * arch);
void ejercicio9(char nombreArch[]);
void inviertoArchivoInt(FILE *arch, int i, int f);
void ejercicio10(char nombreArch[]);
void muestraArchIntRecursivo(FILE* arch);
///void cargaMuestraArrayCharRecursivo(char a);
void cargaMuestraArrayCharRecursivo();
int buscaElementoArrayRecursivo(int a[], int v, int i, int dato);


int main()
{
    srand(time(NULL));

    ///cargaArchInt(archEnteros);

    char opcion;
    int numero = 0;///uso para la funcion del factorial
    int numeroFactorial = 0;
    int flag = 0;
    int menor = 0;

    char letra;
    int arrayInt[] = {5, 8, 6, 2, 9, 13};
    /// {5, 5, 2, 2, 5, 5}
    int vArrayInt = 6;




    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            printf("Ingrese el numero que desee calcular su facotrial: ");
            scanf("%d", &numero);
            numeroFactorial = factorial(numero);
            printf("\nEl factorial de %d es %d\n\n", numero, numeroFactorial);
            opcion = getch();
            break;

        case 50:

            numero = potenciaDeUnNumero(5, 4);
            printf("La potencia de 5 elevado a la 4 es %d\n", numero);
            opcion = getch();
            break;

        case 51:

            printf("Este es el arreglo mostrado de forma recursiva: \n");
            muestraArrayRecursivo(arrayInt, vArrayInt, 0);
            opcion = getch();

            break;
        case 52:

            muestraArrayRecursivo(arrayInt, vArrayInt, 0);
            printf("\n\nEste es el arreglo mostrado de forma recursiva Invertido: \n");
            muestraArrayRecursivoInvertido(arrayInt, vArrayInt, 0);
            opcion = getch();

            break;
        case 53:

            printf("Este es el arreglo mostrado de forma recursiva: \n");
            muestraArrayRecursivo(arrayInt, vArrayInt, 0);

            flag = arrayCapicuaRecrusivo(arrayInt, vArrayInt, 0);
            if(flag == 1)
            {
                printf("\nEl arreglo es capicua.\n");
            }
            else
            {
                printf("\nEl arreglo NO es capicua.\n");
            }
            opcion = getch();

            break;
        case 54:

            muestraArrayRecursivo(arrayInt, vArrayInt, 0);

            numero = sumaArrayrecursivo(arrayInt, vArrayInt, 0);
            printf("\nLa suma del array es: %d\n\n", numero);
            opcion = getch();

            break;
        case 55:

            menor = buscaMenorArrayRecursivo(arrayInt, vArrayInt, 0);
            printf("Menor = %d\n\n", menor);
            opcion = getch();

            break;
        case 56:

            muestraArchInt(archEnteros);
            opcion = getch();

            break;
        case 57:

            abreArch(archEnteros);
            opcion = getch();

            break;
        case 97:

            muestraArchInt(archEnteros);
            opcion = getch();
            ejercicio9(archEnteros);
            muestraArchInt(archEnteros);

            opcion = getch();

            break;
        case 98:

            ejercicio10(archEnteros);
            opcion = getch();

            break;
        case 99:

            cargaMuestraArrayCharRecursivo(letra);
            opcion = getch();

            break;
        case 100:

            printf("Que dato desea buscar del arreglo: ");
            scanf("%d", &numero);

            flag = buscaElementoArrayRecursivo(arrayInt, vArrayInt, 0, numero);///numero a buscar

            if(flag == 1)
            {
                printf("\nEl numero %d se encuentra en el arreglo.\n", numero);
            }
            else
            {
                printf("\nEl numero NO %d se encuentra en el arreglo.\n", numero);
            }
            opcion = getch();



            break;
        case 101:



            break;


        }
    }
    while(opcion != ESC);

    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga que funcion desea realizar\n\n");
    printf("1- Calcula factorial de un numero.\n");
    printf("2- Calcula la potencia de un numero\n");
    printf("3- Muestra array de manera recursiva\n");
    printf("4- Muestra array de manera recursiva invertido\n");
    printf("5- Arreglo capicua V/F\n");
    printf("6- Suma array recursivo\n");
    printf("7- Busca menor recursivo array\n");
    printf("8- Muestra archivo de enteros\n");
    printf("9- Busca menor archivo de enteros\n");
    printf("A- Invierte archivo de enteros\n");
    printf("B- Muestra archivo de forma recursiva invertido\n");
    printf("C- Carga y muestra array char\n");
    printf("D- Busca elemento array int de manera recursiva\n");
}





///1. Calcular el factorial de un número en forma recursiva.

int factorial(int numero)
{
    int rta = 0;

    if(numero == 0)
    {
        rta = 1;
    }
    else
    {
        rta = numero * factorial(numero -1);
    }
    return rta;
}


///2. Calcular la potencia de un número en forma recursiva.

int potenciaDeUnNumero(int numero, int potencia)
{
    int rta = 0;

    if(potencia == 0)
    {
        rta = 1;
    }
    else
    {
        rta = numero * potenciaDeUnNumero(numero, potencia-1);
    }


    return rta;
}


///3 y 4. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void muestraArrayRecursivo(int a[], int v, int pos)
{

    if(pos < v)
    {
        printf("|%d| ", a[pos]);
        muestraArrayRecursivo(a, v, pos+1);
    }
}


///4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

void muestraArrayRecursivoInvertido(int a[], int v, int pos)
{

    if(pos < v)
    {
        muestraArrayRecursivoInvertido(a, v, pos+1);
        printf("|%d| ", a[pos]);
    }

}


///5. Determinar en forma recursiva si un arreglo es capicúa.

int arrayCapicuaRecrusivo(int a[], int v, int pos)///en este caso la variable v la uso como indice de final de arreglo y pos del principio
{
    int flag = 0;///1 verdadero 0 falso

    if(pos >= v)
    {
        flag = 1;
    }
    else if (a[v-1] == a[pos])
    {
        flag = arrayCapicuaRecrusivo(a, v-1, pos+1);
    }
    else
    {
        flag = 0;
    }

    return flag;
}


///6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int sumaArrayrecursivo(int a[], int v, int pos)
{
    int rta = 0;

    if(pos < v)
    {
        rta = a[pos] + sumaArrayrecursivo(a, v, pos+1);
    }

    return rta;
}



///7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscaMenorArrayRecursivo(int a[], int v, int pos)
{
    int menor = 0;

    if(pos == v-1)
    {
        menor = a[pos];
    }
    else
    {
        menor = buscaMenorArrayRecursivo(a, v, pos +1);
        if(a[pos] < menor)
        {
            menor = a[pos];
        }
    }

    return menor;
}


///carga archivo de enteros

void cargaArchInt(char nombreArch[])
{
    int a = 0;

    FILE *arch = fopen(nombreArch, "wb");

    if(arch)
    {
        for(int i = 0; i<10; i++)
        {
            a = rand()%16;
            fwrite(&a, sizeof(int), 1, arch);
        }
        fclose(arch);
    }
}

void muestraArchInt(char nombreArch[])
{
    int num = 0;

    FILE *arch = fopen(nombreArch, "rb");
    printf("\nArchivo de enteros:\n\n");
    if(arch)
    {
        while(fread(&num, sizeof(int), 1, arch) > 0)
        {
            printf("|%d| ", num);
        }
        fclose(arch);
    }
}




///8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)

void abreArch(char nombreArch[])
{
    int menor = 0;

    FILE *arch = fopen(nombreArch, "rb");///abro el archivo en forma lectura

    if(arch)
    {
        menor = buscaMenorArchRecursivo(arch);///llamo a la funcion que busca el menor elemento, retorna el menor y le paso el puntero FILE

        printf("El menor del archivo es %d\n\n", menor);///muestro el menor

        fclose(arch);
    }

}

int buscaMenorArchRecursivo(FILE * arch)
{
    int menor = 0;
    int dato = 0;

    if(fread(&dato, sizeof(int), 1, arch) == 0)
    {
        fseek(arch, sizeof(int)*-1, SEEK_END);
        fread(&menor, sizeof(int), 1, arch);
    }
    else
    {
        menor = buscaMenorArchRecursivo(arch);
        if(dato < menor)
        {
            menor = dato;
        }

    }
    return menor;
}

///9. Invertir los elementos de un archivo de números enteros de forma recursiva.

void ejercicio9(char nombreArch[])
{
    FILE * arch = fopen(nombreArch, "r+b");
    int cant = 0;
    int i = 0;

    if(arch)
    {
        fseek(arch, 0, SEEK_END);
        cant = ftell(arch)/sizeof(int);
        fseek(arch, 0, SEEK_SET);

        inviertoArchivoInt(arch, i, cant-1);///se le pasa menos 1 para no tener que mover el cursor para atras y modificar
        printf("\nEl archivo fue invertido\n");

        fclose(arch);
    }
}

void inviertoArchivoInt(FILE *arch, int i, int f)///i inicio//f final -1
{
    int p = 0;///almaecena la variable donde se encuentra el cursor al principio
    int fin = 0;///almacena el valor donde se encuentre el cursor en la parte final del archivo

    if(i<f)
    {
        fseek(arch, sizeof(int)*i, SEEK_SET);
        fread(&p, sizeof(int), 1, arch);///alamacena el primer valor del archivo en p
        printf("\nPrincipio: %d\n", p);
        fseek(arch, sizeof(int)*f, SEEK_SET);///mueve el indicador de posicion al final
        fread(&fin, sizeof(int), 1, arch);///alamacena el ultimo valor en la variable final
        printf("\nfin: %d\n", fin);
        fseek(arch, sizeof(int)*(-1), SEEK_CUR);///muevo el indicador 1 hacia atras para almacenar fin en el ultimo lugar
        fwrite(&p, sizeof(int), 1, arch);///almacena en el final la variable p

        fseek(arch, sizeof(int)*i, SEEK_SET);///muevo el indicador al principio del archivo
        fwrite(&fin, sizeof(int), 1, arch);///almaceno el fin en el principio del archivo

        inviertoArchivoInt(arch, i+1, f-1);
    }

}

///10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.

void ejercicio10(char nombreArch[])
{

    FILE *arch = fopen(nombreArch, "rb");///abro el archivo en forma lectura

    if(arch)
    {
        printf("Este es el archivo mostrado inveetido de forma recursiva:\n\n");
        muestraArchIntRecursivo(arch);

        fclose(arch);
    }

}

void muestraArchIntRecursivo(FILE* arch)
{
    int num = 0;

    if(fread(&num, sizeof(int), 1, arch) > 0)
    {
        muestraArchIntRecursivo(arch);
        printf("|%d| ", num);
    }
    fclose(arch);

}

///11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden
///inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.


void cargaMuestraArrayCharRecursivo()
{
    char letra;

    printf("Ingrese letra al arreglo/ * para terminar: ");
    fflush(stdin);
    scanf("%c", &letra);

    if(letra != '*')
    {
        cargaMuestraArrayCharRecursivo();
    }

    if(letra != '*')
    {
        printf("|%c| - ", letra);
    }
}


/*
void cargaMuestraArrayCharRecursivo(char a)
{


    if(a != '*')
    {
        printf("Ingrese letra al arreglo: ");
        fflush(stdin);
        scanf("%c", &a);

        cargaMuestraArrayCharRecursivo(a);


        if(a != '*')
        {
            printf("|%c| - ", a);
        }
    }
}
*/
///12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.

int buscaElementoArrayRecursivo(int a[], int v, int i, int dato)
{
    int flag = 0;///1 VERDADERO/0 Falso

    if(i == v)
    {
        flag = 0;
    }
    else
    {
        if(a[i] == dato)
        {
            flag = 1;
        }
        else
        {
            flag = buscaElementoArrayRecursivo(a, v, i+1, dato);
        }

    }


    return flag;
}





















