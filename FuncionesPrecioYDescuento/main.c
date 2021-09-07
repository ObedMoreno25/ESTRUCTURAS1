#include <stdio.h>
#include <stdlib.h>


/* Hacer un programa que pida el precio, la cantidad de un producto y un %de
descuento y llame a una funcion para calcular el total a pagar amtes y después del
descuento */

//int leeEntero( char letrero[]);
int LeeEntero( char *letrero);
void Calcula(int p, int c, int d, int *a, int *ds );
void imprime(int a, int ds);

int main()
{
    int Precio, CantProducto, Descuento;
    int antes, despues;

    Precio = leeEntero("Precio: ");
    CantProducto = leeEntero("Cantidad: ");
    Descuento = leeEntero("Descuento: ");

    Calcula(Precio, CantProducto, Descuento, &antes, &despues);
    imprime(antes, despues);

    return 0;
}


int leeEntero(char *letrero)
{
    int entero;

    printf("\n %s", letrero);
    scanf("%d", &entero);

    return (entero);
}


void Calcula(int p, int c, int d, int *a, int *ds )
{
    *a  = p * c;
    *ds = -(*a * d/100) + *a  ;
}

void imprime(int a, int ds)
{
    printf("\n Total antes del descuento: %d ", a);
    printf("\n Total despues del descuento: %d ", ds);
}
