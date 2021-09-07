#include <stdio.h>
#include <stdlib.h>


// TIPOS DEFINIDOS POR EL USUARIO
typedef char TDato;


//ESTRUCTURAS

typedef struct
{
    TDato datos[10];
    int tope, max;
}TPila;


typedef struct
{
    TDato datos[10];
    int final, frente, max;
}TCola;

// ---------------->


// FUNCIONES PARA PILAS

void inicializaPila(TPila *p);
int pilaLlena(TPila p);
int pilaVacia(TPila p);
void push(TPila *p, TDato d);
int pop(TPila *p, TDato *d);

// FUNCIONES PARA COLAS

void inicializaCola(TCola *c);
int colaLlena(TCola c);
int colaVacia(TCola c);
void enqueue(TCola *c, TDato d);
int dequeue(TCola *c, TDato *d);
void imprimeCola(TCola c);

//FUNCIONES PARA EL PROGRAMA

int esOperador(TDato signo);
int tienePrioridad(TDato signo);
TCola conviertePosfija(TCola exp);
int consultaOperador(TPila p, TDato *d);
void capturaCola(TCola *c);


int main()
{
    TCola expresion = {"X+Z*W", 0, 5, 10};






    return 0;
}


void inicializaPila(TPila *p)
{
    p->tope = -1;
    p->max = 10;
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

int esOperador(char signo)
{
    int res = 0;
    if (signo == '+' || signo == '-'|| signo == '/'|| signo == '*'|| signo == '^')
    {
        res = 1;
    }
    return (res);

}
int tienePrioridad(char signo)
{
    int res = 0;
    if (signo == ')')
    {
        return (res);
    }
        else if (signo == '+' || signo == '-')
        {
            res = 1;
        }
            else if (signo == '/' || signo == '*')
            {
                res = 2;
            }
                else
                {
                    res = 3;
                }
    return (res);
}


void imprimeCola(TCola c)
{
    TDato d;

    while(!colaVacia(c))
    {
        dequeue(&c, &d);
        printf("%d", d);
    }
}

int consultaOperador(TPila p, TDato *d)
{
    int res = 0;

    if(!pilaVacia(p))
    {
        p->tope--;
        *d = p->datos[p->tope];
        res = 1;
    }
    return (res);
}

void capturaCola(TCola *c)
{
    TDato d;

    printf("Expresion a comvertir: ");
    fflush(stdin);
    d = getchar();

    while (d != "\n")
    {
        enqueue(c , d);
        d = getchar();
    }
}
