#include <stdio.h>
#include <stdlib.h>

void resta(int op1, int op2, int *res);
int suma(int op1, int op2);


int main()
{
    int operando1;
    int operando2;
    int resultado;

    printf("operando 1: ");
    scanf("%d", &operando1);
    printf("operando 2: ");
    scanf("%d", &operando2);

    resultado = suma(operando1, operando2);

    printf("El resultado de la suma es: %d", resultado);

    resta(operando1, operando2, &resultado);

    printf("\nEl resultado de la resta es: %d", resultado);

    return 0;


}

void resta(int op1, int op2, int *res)
{
    *res = op1 - op2;
}
int suma(int op1, int op2)
{
    return op1 + op2;
}
