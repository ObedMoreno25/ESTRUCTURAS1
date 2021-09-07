#include <stdio.h>
#include <stdlib.h>


typedef int TDato;
typedef struct
{
    TDato datos[10];
    int tope, max;
}TPila;

void inicializaPila(TPila *p);
int pilaLlena(TPila p);
int pilaVacia(TPila p);
void push(TPila *p, TDato d);
int pop(TPila *p, TDato *d);
void imprimePila(TPila p);
int menu();


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
            case 1: inicializaPila(&cola);
                   break;
            case 2: printf("\n Dato a ingresar ");
                    scanf("%d", &dato);
                    push(&cola, dato);
                   break;
            case 3: resp = pop(&cola, &dato);
                    if(resp)
                    {
                        printf("\n ----> Dato Eliminado: %d <----", dato);
                    }
            /*case 4: imprimePila(pila);
                   break;*/
        }
    }while (opcion != 5);

    return 0;
}


void inicializaPila(TPila *p)
{
    p->tope = -1;
    p->max = 100;
}

int pilaLlena(TPila p)
{
    int res = 0;

    if(p.tope == p.max)
    {
        res = 1;
    }
    return (res);
}

int pilaVacia(TPila p)
{
    int res = 0;

    if(p.tope == 0)
    {
        res = 1;
    }
    return (res);
}


void push(TPila *p, TDato d)
{
    if( !pilaLlena(*p) )
    {
        p->datos[p->tope] = d;
        p->tope++;
    }
    else
    {
        printf("\n Pila Llena (Stack Overflow)");
    }
}

int pop(TPila *p, TDato *d)
{
    int res = 0;

    if(!pilaVacia(*p))
    {
        p->tope--;
        *d = p->datos[p->tope];
        res = 1;
    }
    else
    {
        printf("\n Pila vacia (Stack Empty)");
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
       // printf("\n 4.- Muestra pila ");
        //printf("\n 5.- Busqueda secuencial no Ordenada ");
        //printf("\n 6.-Imprime arreglo ");
        printf("\n 5.- Salir ");
        printf("\n    ---Opcion: ");
        scanf("%d", &op);

    }while (op < 1 || op > 4);
    return (op);
}


void imprimePila(TPila p)
{
    int i;
    for(i = 0; i<p.tope; i++)
    {
        printf("%d \n", p.datos[i]);
    }
}
