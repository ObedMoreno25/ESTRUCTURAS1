#include <stdio.h>
#include <stdlib.h>

typedef int TDato;
typedef struct
{
    TDato elemento[20];
    int cardinalidad, max;
}TSet;

void inicializaSet(TSet *A);
int conjuntoVacio(TSet A);
int pertenece(TSet A, TDato elemento);
void agregaElemento(TSet *A, TDato elemento);
void eliminaElemento(TSet *A, TDato elemento);
int posicion(TSet A, TDato elemento);
void unionSet(TSet A, TSet B, TSet *C);
TSet interseccion(TSet A, TSet B);
TSet diferencia(TSet A, TSet B);
int subconjunto(TSet A, TSet B);
int iguales(TSet A, TSet B);
void imprimeSet(TSet A);


int main()
{
    TSet conjuntoA = {{2,5,4,8,6}5,20};
    TSet conjuntoB = {{3,9,7,6,1,4}6,20};
    TSet conjuntoC;
    inicializaSet(&conjuntoA);
    inicializaSet(&conjuntoB);
    inicializaSet(&conjuntoC);
    int elemento;
    do{
        fflush(stdin);
        switch(menuPrincipal()){
            case 1:
                printf("\n Aritmética:\n");
                opcion = menuAritmetica();
                aritmetica(&num, opcion);
                break;
            case 2:
                printf("\n Trigonometría:\n");
                opcion = menuTrigonometria();
                trigonometria(&num, opcion);
                break;

            case 3:
                printf("\n Elemento a verificar si pertenece al conjunto:\n");
                scanf("%d", &elemento);
                if(pertenece(conjuntoA, elemento))
                {
                    printf("El elemento %d si pertenece al conjunto ", elemento);
                }
                else
                {
                     printf("El elemento %d si pertenece no conjunto ", elemento);
                }
                break;

            case 4:
                printf("\n Elemento a agregar al conjunto \n");
                scanf("%d", &elemento);
                agregaElemento(&conjuntoA, elemento);
                break;

            case 5:
                printf("\n Elemento a eliminar al conjunto \n");
                scanf("d", &elemento);
                eliminaElemento(&conjuntoA, elemento);
                break;

            case 6:
                printf("\n UNION (A U B):\n");
                unionSet(conjuntoA, conjuntoB, &conjuntoC);

                break;

            case 7:
                printf("\n Interseccion (A U B): \n");
                conjuntoC = interseccion(conjuntoA, conjuntoB);
                break;

            case 8:
                printf("\n Diferencia (A U B): \n");
                conjuntoC = diferencia(conjuntoA, conjuntoB);
                break;

            case 9:
                printf("\n Fuerza:\n");
                fuerza(&num);
                break;
        }
        fflush(stdin);
        printf("\n\n¿Desea seleccionar otra opcion diferente? (s/n) ");
        fflush(stdin);
        scanf("%c", &resp);
    }while( resp == 's');
    return 0;
}

int menuPrincipal(){
    int op;
    printf("Elige la operacion que desees ejecutar:\n\n ");
    do{
        printf("1.- Inicializar conjunto\n ");
        printf("2.- Conjunto Vacio\n ");
        printf("3.- Pertenencia\n ");
        printf("4.- Agregar Elemento\n ");
        printf("5.- Eliminar elemento \n ");
        printf("6.- Union \n ");
        printf("7.- Interseccion ");
        printf("8.- Diderencia \n ");
        printf("9.- Fuerza\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 9);
    return (op);
}

void inicializaSet(TSet *A)
{
    A->cardinalidad = 0;
    A->max = 20;
}

int conjuntoVacio(TSet A)
{
    int res = 0;

    if(A.cardinalidad == 0)
    {
        res = 1;
    }
    return (res);
}

int pertenece(TSet A, TDato elemento)
{
    int i = 0;
    int res = 0;

    while(i < A.cardinalidad && A.elemento[i] != elemento)
    {
        i++;

    }
    if(i < A.cardinalidad)
    {
        res = 1;
    }
    return (res);
}


int posicion(TSet A, TDato elemento)
{
    int i = 0;
    int res = -1;

    while(i < A.cardinalidad && A.elemento[i] != elemento)
    {
        i++;

    }
    if(i < A.cardinalidad)
    {
        res = i;
    }
    return (res);
}

void agregaElemento(TSet *A, TDato elem)
{
    int res;

    res = pertenece(*A, elem);
    if(!res)
    {
        A->elemento[A->cardinalidad] = elem;
        A->cardinalidad++;
    }
}

void eliminaElemento(TSet *A, TDato elemento)
{
    int pos;

    pos = posicion(*A, elemento);
    if (pos != -1)
    {
        A->cardinalidad--;
        A->elemento[pos] = A->elemento[A->cardinalidad];
    }
}

void unionSet(TSet A, TSet B, TSet *C)
{
    int i;

    *C = A;

    for( i = 0; i < B.elemento[i]; i++)
    {
        agregaElemento(C , B.elemento[i]);
    }

}

TSet interseccion(TSet A, TSet B)
{
    TSet C;
    int i;

    inicializaSet(&C);

    for(i = 0; i < A.cardinalidad; i++)
    {
        if(pertenece(B, A.elemento[i]))
            agregaElemento(&C , A.elemento[i]);
    }
    return(C);

}
TSet diferencia(TSet A, TSet B)
{
    TSet C;
    int i;

    inicializaSet(&C);

    for(i = 0; i < A.cardinalidad; i++)
    {
        if(!pertenece(B, A.elemento[i]))
            agregaElemento(&C , A.elemento[i]);
    }
    return(C);

}

int subconjunto(TSet A, TSet B)
{
    int i = 0;
    int res = 1;

    while(res)
    {
        if(!pertenece(B, A.elemento[i]))
        {
            res = 0;
        }
         i++;
    }
    return(res);
}

int iguales(TSet A, TSet B)
{
    int res;

    if(subconjunto(A , B) && A.cardinalidad == B.cardinalidad)
    {
        res = 1;
    }
    return(res);
}

void imprimeSet(TSet A)
{
    int i;

    printf("\n");
    for(i = 0; i< A.cardinalidad; i++)
    {
        printf("%d  ", A.elemento[i]);
    }
    printf("\n");
}
