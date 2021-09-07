#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    int x , y;
}punto;

punto leepunto();
float distancia(punto p1, punto p2);
void pendiente(punto p1, punto p2, float *m1);

int main()
{
    punto a , b;
    float dist;
    float m;

    a = leepunto();
    b = leepunto();

    dist = distancia(a,b);
    pendiente(a,b, &m);

    printf("\n Distancia = %f ", dist);
    printf("\n Pendiente = %f ", m);


    return 0;
}


punto leepunto()
{
    punto p;

    printf("\nx = ");
    scanf("%d", &p.x);
    printf("\ny = ");
    scanf("%d", &p.y);

    return (p);
}

float distancia(punto p1, punto p2)
{
    float d;

    d = sqrt(pow ((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

    return (d);
}

void pendiente(punto p1, punto p2, float *m1)
{
    *m1 = ((float)(p2.y - p1.y)) / (p2.x - p1.x);
}

