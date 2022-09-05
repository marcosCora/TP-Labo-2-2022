#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

///CONSTANTES
const int ESC = 27;

///PROTOTIPADOS

void muestraArrayInt(int a[], int v);
int inicializacionArray(int a[], int dim);
int cargaArrayInt(int a[], int dim);
int sumaCantArray(int a[], int v);
int contArray(int a[], int v);
float promedioArrayInt(int a[], int v);

int cargaArrayChar(char a[], int dim);
void muestraArrayaChar(char a[], int v);
int invierteArrayChar(char a[], int v);

int concatenaArray(int array[], int v);

int posMaxArrayInt(int a[], int v);

int palindromoArrayChar(char a[], int v);

void intercambioInt(int *p1, int *p2);

int intercalaArray(int a[], int vA, int b[], int vB, int c[], int dimC);

void ejercicio10(int a[], int v, int *maximo, int *minimo, float *promedio);
void buscaMaximoArray(int a[], int v, int **maximo);
void buscaMinimoArray(int a[], int v, int **minimo);

int main()
{
    int arrayInt[10];
    int vArrayInt = 0;
    float promedioArray = 0;

    char arrayChar[10];
    int vArrayChar = 0;

    ///EJERCICIO 1

    ///inicializo todo el arreglo en -1
    ///vArrayInt = inicializacionArray(arrayInt, 10);

    ///carga array usuario
    ///vArrayInt = cargaArrayInt(arrayInt, 10);


    ///muestro el array
    ///printf("\nEste es el arreglo de enteros:\n");
    ///muestraArrayInt(arrayInt, vArrayInt);

    ///muestro el promedio del array
    ///promedioArray = promedioArrayInt(arrayInt, vArrayInt);
    ///printf("\n\nEl promedio del arreglo es %.2f\n\n", promedioArray);


    ///EJERCICIO 2

    ///cargp arreglo de tipo char
    ///vArrayChar = cargaArrayChar(arrayChar, 10);

    ///muestra arreglo de tipo char
    ///printf("Array char:\n");
    ///muestraArrayaChar(arrayChar, vArrayChar);
    /**
    ///invierto arreglo char
    vArrayChar = invierteArrayChar(arrayChar, vArrayChar);

    printf("\nEste es el arreglo char invertido: \n");
    muestraArrayaChar(arrayChar, vArrayChar);
    */

    ///EJERCICIO 3
    /**
    int numeroConcatenado = concatenaArray(arrayInt, vArrayInt);
    printf("Este es el numero concatenado %d\n\n", numeroConcatenado);
    */

    ///EJERCICIO 4
    /**
    int posMax = posMaxArrayInt(arrayInt, vArrayInt);
    printf("\nLa posicion donde se encuentra el maximo elemento del arreglo es la %d\n\n", posMax);
    */
    /**
    int flagPalindromo = palindromoArrayChar(arrayChar, vArrayChar);
    if(flagPalindromo == 1)
    {
        printf("\n\nEl arreglo es un palindromo.\n\n");
    }
    else
    {
        printf("\n\nEl arreglo NO es un palindromo.\n\n");
    }
    */

    ///EJERCICIO 7
    /**int n1 = 15;
    int n2 = 8;

    intercambioInt(&n1, &n2);
    printf("El valor de N1 es %d y el de N2 es %d\n\n", n1, n2);
    */

    ///EJERCICIO 8
    int array1[] = {8,14,24,3,15};
    int v1 = 5;
    /**
    int array2[] = {2,4,6,8,10};
    int v2 = 5;

    vArrayInt = intercalaArray(array1, v1, array2, v2, arrayInt, 10);
    printf("\nEste es el arreglo de intercalado:\n\n");
    muestraArrayInt(arrayInt, vArrayInt);
    */

    int maximo = 0;
    int minimo = 0;

    printf("Este es el arreglo:\n");
    muestraArrayInt(array1, v1);

    ejercicio10(array1, v1, &maximo, &minimo, &promedioArray);
    printf("\nNUMERO MAXIMO: %d\n", maximo);
    printf("NUMERO MINIMO: %d\n", minimo);
    printf("PROMEDIO.....: %.2f\n", promedioArray);




    return 0;
}


///1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:

///a. Hacer una función que inicialice las celdas del arreglo en –1.

int inicializacionArray(int a[], int dim)
{
    int v;

    for(v = 0; v<dim; v++)
    {
        a[v] = -1;
    }

    return v;
}

///b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.

int cargaArrayInt(int a[], int dim)
{
    int v = 0;
    char opcion = ' ';

    while(v<dim && opcion != ESC)
    {
        printf("Ingrese un valor a cargar en el arreglo: ");
        scanf("%d", &a[v]);
        v++;

        printf("\nESC para salir\n\n");
        opcion = getch();
    }

    return v;
}

///c. Hacer una función que sume el contenido del arreglo y lo retorne.

int sumaCantArray(int a[], int v)
{
    int suma = 0;

    for(int i = 0; i<v; i++)
    {
        suma += a[i];
    }
    return suma;
}

///d. Hacer una función que cuente la cantidad de valores ingresados.

int contArray(int a[], int v)
{
    int cont = 0;

    for(int i = 0; i<v; i++)
    {
        cont++;
    }
    return cont;
}

///e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio usando las funciones anteriores (c y d).

float promedioArrayInt(int a[], int v)
{
    float promedio = 0;

    int suma = sumaCantArray(a, v);
    int cont = contArray(a, v);

    promedio = (float) suma/cont;


    return promedio;
}


///funcion que muestra el contenido del arreglo

void muestraArrayInt(int a[], int v)
{
    int i;

    for(i = 0; i<v; i++)
    {
        printf(" |%d| ", a[i]);
    }
}


///2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
///a. Hacer una función para la carga del arreglo char.

int cargaArrayChar(char a[], int dim)
{
    int v = 0;
    char opcion = ' ';

    while(v<dim && opcion != ESC)
    {
        printf("Ingrese un valor a cargar en el arreglo CHAR: ");
        fflush(stdin);
        scanf("%c", &a[v]);
        v++;

        printf("\nESC para salir\n\n");
        opcion = getch();
    }

    return v;

}

///b. Hacer una función para invertir el arreglo.

int invierteArrayChar(char a[], int v)
{
    int i = 0;
    int f = v-1;
    char aux;

    ///while(i != f || i<=f )
    while(i <= f)
    {
        aux = a[i];
        a[i] = a[f];
        a[f] = aux;

        i++;
        f--;
    }

    return v;
}

///c. Hacer una función para mostrar el contenido del arreglo.

void muestraArrayaChar(char a[], int v)
{
    int i;

    for(i = 0; i<v; i++)
    {
        printf(" |%c| ", a[i]);
    }

}


///3. Hacer una función que reciba como parámetro un arreglo de números enteros de un dígito y
///retorne el valor decimal de dicho número. Por ejemplo, un arreglo que tiene cargados los
///valores 3, 2, 8 y 9, la fn retorna el valor 3289.

int concatenaArray(int array[], int v)
{
    int a = array[0];
    int b = array[1];
    int c = array[2];
    int d = array[3];
    int numeroConcatenado = a*1000 + b*100 + c*10 + d*1;

    return numeroConcatenado;
}

///4. Hacer una función que retorne la posición del valor máximo de un arreglo de
///   números enteros

int posMaxArrayInt(int a[], int v)
{
    int posMax = 0;
    int i;

    for(i = 1; i<v; i++)
    {
      if(a[posMax] < a[i])
      {
          posMax = i;
      }
    }

    return posMax;
}


///6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena es palíndromo
/// (se lee de igual forma de adelante para atrás como viceversa) o no.
///La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta.

 int palindromoArrayChar(char a[], int v)
 {
     int flag = 1;///retorna 1 si es palindromo 0 si no
     int i = 0;
     int f = v-1;///final

     while(i<v && flag == 1)
     {
         if(a[i] == a[f])
         {
             flag = 1;
             i++;
             f--;
         }
         else
         {
             flag = 0;
         }
     }

     return flag;
 }

///7. Hacer una función que intercambie el contenido de dos variables. (pasaje de parámetros
///por referencia)

void intercambioInt(int *p1, int *p2)
{
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}


///8. Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba
///como parámetros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores,
/// también ordenados. Se los debe intercalar.

int intercalaArray(int a[], int vA, int b[], int vB, int c[], int dimC)
{
    int iA = 0;
    int iB = 0;
    int vC = 0;

    while(iA < vA && iB < vB)
    {
        c[vC] = a[iA];
        vC++;
        c[vC] = b[iB];
        vC++;
        iA++;
        iB++;
    }
    return vC;
}


///10. Hacer una función que reciba como parámetros de entrada un arreglo de enteros y su dimensión,
///y tres parámetros de salida, tres números enteros que representen: valor máximo, valor mínimo y
///promedio. Se debe usar pasaje de parámetros por referencia

void ejercicio10(int a[], int v, int *maximo, int *minimo, float *promedio)
{
    buscaMaximoArray(a, v, &maximo);
    buscaMinimoArray(a, v, &minimo);
    *promedio = promedioArrayInt(a, v);
}

///funcion que busca el valor maximo dentro de un arreglo de enteros usando punteros dobles
void buscaMaximoArray(int a[], int v, int **maximo)
{
    **maximo = a[0];

    for(int i =1; i<v; i++)
    {
        if(a[i] > **maximo)
        {
            **maximo = a[i];
        }
    }
}

///funcion que busca el valor minimo dentro de un arreglo de enteros usando punteros dobles
void buscaMinimoArray(int a[], int v, int **minimo)
{
    **minimo = a[0];

    for(int i =1; i<v; i++)
    {
        if(a[i] < **minimo)
        {
            **minimo = a[i];
        }
    }
}
















