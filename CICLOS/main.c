#include <stdio.h>
#include <stdlib.h>

//escribir un programa que calcule los numeros primos que hay entre 1 y 100
// escribir un  programa que muestre en pantalla los primeros 10 numeros que son primos

int esPrimo( int num);

int main()
{
    int i = 1;
    int cuenta = 0;

    while(cuenta < 10 )
    {
        if(esPrimo(i))
        {
            printf("%d\n", i);
            cuenta++;
        }
        i++;
    }


    /*for(i = 1; i <= 100; i++ )
    {
        if(esPrimo(i))
            printf("\n%d", i);
    }*/

}


int esPrimo(int num)
{
    int i = 2;
    int primo = 1;

    while(i < num && primo)
    {
        if(num%i == 0)
        {
            primo = 0;
        }
        i++;
    }
    return (primo);
}

