#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int leeEntero(char *letrero);
void leeArreglo(int num[], int n);
int opArreglo(int num[], int n, int val, int *cuenta);
void Imprime(int sum, int cu, int v );


int main()
{
    int numeros[100];
    int valor, N;
    int suma, cuantos;

    N = leeEntero("Numero de elementos en el arreglo: ");
    leeArreglo(numeros, N);
    valor = leeEntero("Valor de referencia: ");
    suma = opArreglo(numeros, N, valor, &cuantos);
    Imprime(suma, cuantos, valor);

    return 0;
}


int leeEntero(char *letrero)
{
    int entero;

    printf("\n %s", letrero);
    scanf("%d", &entero);

    return (entero);
}

void leeArreglo(int num[], int n)
{
    int i;

    for(i = 0; i < n; i++ )
    {
        num[i] = leeEntero("Ingresa el valor del elemento de tu arreglo: ");
    }
}


int opArreglo(int num[], int n, int val, int *cuenta)
{
    int i, sum = 0;

    *cuenta = 0;
    for(i = 0; i < n; i++)
    {
        if(num[i]> val)
            sum = sum + num[i];
        else
            *cuenta++;
    }
    return (sum);

}


void Imprime(int sum, int cu, int v )
{
    printf("La suma de tus valores despues del %d es igual a: %d ", v, sum);
    printf("La cantidad de numeros despues del %d es igual a: %d ", v, cu);

}

