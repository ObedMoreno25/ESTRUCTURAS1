#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menuPrincipal();

int main()
{
    int num1, num2, res, opcion;
    float n1, n2;
    char resp;

    do{
                printf("\n ---- CALCULADORA ---- \n ");
                printf("Ingresa tu primer numero: ");
                scanf("%d", &num1);
                printf("Ingresa tu segundo numero: ");
                scanf("%d", &num2);
                fflush(stdin);
          opcion = menuPrincipal();
        switch(opcion)
        {
            case 1:
                    res = (num1 + num2);
                    printf("El resultado de la suma es: %d", res);
                break;
            case 2:
                    res = (num1 - num2);
                    printf("El resultado de la resta es: %d", res);
                break;

            case 3:
                    res = (num1 * num2);
                    printf("El resultado de la multiplicacion es: %d", res);
                break;

            case 4:
                    res = (num1 / num2);
                    printf("El resultado de la division es: %d", res);
                break;

            case 5:
                    printf("\n El numero %d elevado a la potencia %d \n ", num1, num2);
                    res = pow (num1 , num2);
                    printf("\n Es igual a: %d ", res);
                break;

            case 6:
                    n1 = num1;
                    n2 = num2;
                    printf ( "fmod de %.2f / %.2f es %f\n",n1,n2, fmod (n1,n2) );

                break;

            case 7:
                    n1 = num1;
                    n2 = num2;
                    printf ("\nLa raiz cuadrada es: %.2f \n", sqrt(n1));
                    printf ("\nLa raiz cuadrada es: %.2f \n", sqrt(n2));

                break;

        }
        fflush(stdin);
        printf("\n\n¿Desea seleccionar otra opcion diferente? (s/n) ");
        fflush(stdin);
        scanf("%c", &resp);

    }while( resp == 's');
    return 0;
}

int menuPrincipal()
{
    int op;
    printf("Elige la operacion que desees ejecutar:\n\n ");
    do{
        printf("1.- Suma \n ");
        printf("2.- Resta\n ");
        printf("3.- Multiplicación\n ");
        printf("4.- División \n ");
        printf("5.- Potencia \n ");
        printf("6.- Modulo \n ");
        printf("7.- Raiz\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 7);
    return (op);
}
