#include <stdio.h>
#include <conio.h>
#include <string.h>


typedef char cadena[15];
typedef cadena Arreglo[6];

void Pide_arreglo(Arreglo p, int tam);
void invierte_cadenas(Arreglo P, int limi, int lims);
void muestra_cadena(Arreglo p, int tam);

int main()
{
    //Arreglo Patos = { "Hugo", "Paco", "Donald", "Luis", "Daisy", "Ciro"};
    Arreglo Patos;
    int tam = sizeof(Patos) / sizeof(cadena);
    int limiinf, limisup;

    Pide_arreglo(Patos, tam);
    /*printf("Ingresa tu limite inferior: ");
    scanf("%d", &limiinf);
    printf("Ingresa tu limite superior: ");
    scanf("%d", &limisup);

    invierte_cadenas(Patos, limiinf, limisup);*/
    muestra_cadena(Patos, tam);

}

void Pide_arreglo(Arreglo p, int tam)
{
    int i;
    for(i=0 ; i<tam ; i++)
    {
        printf("Ingresa el arreglo de cadenas de tamaño %d; ", tam);
        scanf("%s", &p[i]);
    }
}

void invierte_cadenas(Arreglo p, int limi, int lims)
{
    int i;
    cadena cad1, cad2;
    int aux = limi;

    for( i=lims ; i<limi ; i-- )
    {
        strcpy(cad1, p[lims]);
        strcpy(cad2, p[aux]);
        strcpy(p[lims], cad2);
        strcpy(p[aux], cad1);
        aux++;
    }
}


void muestra_cadena(Arreglo p, int tam)
{
    int i;
    for(i=0; i<tam; i++ )
        printf("%s, ", p[i]);
    printf("\n");
}
