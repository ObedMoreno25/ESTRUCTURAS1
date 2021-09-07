#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hora, minutos, segundos;
}tiempo;

void leeTiempo(tiempo *t);
void calculaTiempo(int s, tiempo ti, tiempo *tf);
void leeSegundos(int *s);
void imprime(tiempo ti, int s, tiempo tf);

int main()
{
    tiempo tinicial, tfinal;
    int seg;

    leeTiempo(&tinicial);
    leeSegundos(&seg);
    calculaTiempo(seg, tinicial, &tfinal);
    imprime(tinicial, seg, tfinal);

    return 0;
}

void leeTiempo(tiempo *t)
{
    printf("\n Hora = ");
    scanf("%d", &t->hora);
    printf("\n Minutos = ");
    scanf("%d", &t->minutos);
    printf("\n Segundos = ");
    scanf("%d", &t->segundos);
}

void calculaTiempo(int s, tiempo ti, tiempo *tf)
{
    int tt;

    tt = s + ti.segundos;
    tf->segundos = tt % 60;
    tt = tt / 60 + ti.minutos;
    tf->minutos = tt % 60;
    tt = tt/ 60 + ti.hora;
    tf->hora = tt%24;
}
void leeSegundos(int *s)
{
    printf("\n Segundos del experimento ");
    scanf("%d", s);
}
void imprime(tiempo ti, int s, tiempo tf)
{
    printf("\n Hora Inicial %d:%d:%d" , ti.hora, ti.minutos, ti.segundos);
    printf("\n Duracion del Experimento  %d ", s);
    printf("\n Hora Inicial %d:%d:%d" , tf.hora, tf.minutos, tf.segundos);
}
