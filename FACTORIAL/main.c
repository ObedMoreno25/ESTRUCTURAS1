#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int arr[20];
    float n1;
    float n2;
    float n3;
    int n4;
    float res;

}Numeros;

int factorialSinRecursividad(int n);
int factorial(int n);
int estadistica(Numeros *C, int n);


int main()
{
    Numeros num;
    int n;
    float media;
    printf("Cuantos datos quieres para sacar tu media: ");
    scanf("%d", &n);
    media = estadistica(&num, n);
    printf("La media es: %.2f", media);

    return 0;
}


int factorialSinRecursividad(int n)
{
    int i, fact = 1;

    if( n < 0)
    {
        fact = -1;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fact *= i;

        }
    }
    printf("Factorial = %d", fact);
    return (fact);
}


int factorial(int n)
{
    int fact = 1;

    if( n >= 0)
    {
        if(n == 0)
        {
            fact = 1; //caso base
        }
        else
        {
            fact = n * factorial(n-1);
        }
    }
    else
    {
       fact = 1;
    }
    return (fact);
}



int estadistica(Numeros *C, int n)
{
    int suma = 0;
    int i;

    for ( i = 0; i < n ; i++)
    {
        printf("Ingresa tus datos:   ");
        scanf("%d", &C->arr[i]);
        suma = suma + C->arr[i];
    }
    suma = suma / n;
    return (suma);
}
