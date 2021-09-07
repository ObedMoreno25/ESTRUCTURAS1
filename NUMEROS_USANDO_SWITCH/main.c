#include <stdio.h>
#include <stdlib.h>

void imprimeNumeros(int n);

int main()
{
    int numero;

    imprimeNumeros(numero);

    return 0;
}

void imprimeNumeros(int n)
{
     do{
        printf("Ingresa un numero del 1 al 9");
        scanf("%d", &n);
        switch(n)
        {
            case 1: printf("UNO");
                   break;
            case 2: printf("DOS");


                   break;
            case 3: printf("TRES");

            case 4: printf("CUATRO");
                   break;
            case 5: printf("CINCO");
                   break;
            case 6: printf("SEIS");


                   break;
            case 7: printf("SIETE");

            case 8: printf("OCHO");
                   break;

            case 9: printf("NUEVE");
                   break;
            default: printf("ERROR : VALOR INCORRECTO ");
        }
    }while (n >= 1 && n <= 9);

}
