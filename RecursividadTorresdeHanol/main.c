#include <stdio.h>
#include <stdlib.h>


void hanoi(int N, char origen, char destino, char auxiliar);
int main()
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}

void hanoi(int N, char origen, char destino, char auxiliar)
{
    if(N == 1)
    {
        hanoi(N-1, origen, auxiliar, destino);
       printf("\n %c -> %c" , origen, destino);
       hanoi(N-1, auxiliar, destino, origen);
    }
}

