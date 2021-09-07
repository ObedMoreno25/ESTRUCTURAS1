#include <stdio.h>
#include <stdlib.h>


typedef int TDato;
typedef struct
{
    TDato datos[10];
    int final, frente, max;
}TCola;

void inicializaCola(TCola *c);
int colaLlena(TCola c);
int colaVacia(TCola c);
void enqueue(TCola *c, TDato d);
int dequeue(TCola *c, TDato *d);
int menu();
void imprimeCola(TCola c);


int main()
{
    int opcion;
    TCola cola;
    TDato dato;
    int resp;
     do{
        opcion = menu();
        switch(opcion)
        {
            case 1: inicializaCola(&cola);
                   break;
            case 2: printf("\n Dato a ingresar ");
                    scanf("%d", &dato);
                    enqueue(&cola, dato);
                   break;
            case 3: resp = dequeue(&cola, &dato);
                    if(resp)
                    {
                        printf("\n ----> Dato Eliminado: %d <----", dato);
                    }
            case 4: imprimeCola(cola);
                   break;
        }
    }while (opcion != 5);

    return 0;
}


void inicializaCola(TCola *c)
{
    c->final = c->frente = 0;
    c->max = 10;
}

int colaLlena(TCola c)
{
    int res = 0;

    if((c.max + c.frente -1)%c.max == c.final)
    {
        res = 1;
    }
    return (res);
}

int colaVacia(TCola c)
{
    int res = 0;

    if(c.frente == c.final)
    {
        res = 1;
    }
    return (res);
}


void enqueue(TCola *c, TDato d)
{
    if( !colaLlena(*c) )
    {
        c->datos[c->final] = d;
        c->final = (c->final + 1)%c->max;
    }
    else
    {
        printf("\n Cola Llena ");
    }
}

int dequeue(TCola *c, TDato *d)
{
    int res = 0;

    if(!colaVacia(*c))
    {

        *d = c->datos[c->frente];
        c->frente = (c->frente + 1)% c->max;
        res = 1;
    }
    else
    {
        printf("\n Cola vacia ");
    }
    return (res);
}

int menu()
{
    int op;

    do{
        printf("\n 1.- Inicializacion ");
        printf("\n 2.- inserta Dato ");
        printf("\n 3.- Elimina dato ");
        printf("\n 4.- Muestra cola ");
        //printf("\n 5.- Busqueda secuencial no Ordenada ");
        //printf("\n 6.-Imprime arreglo ");
        printf("\n 5.- Salir ");
        printf("\n    ---Opcion: ");
        scanf("%d", &op);

    }while (op < 1 || op > 4);
    return (op);
}


void imprimeCola(TCola c)
{
    int i;
    for(i = c.frente; i<c.final; i++)
    {
        printf("%d ", c.datos[i]);
    }
}

