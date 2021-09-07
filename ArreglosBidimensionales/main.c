#include <stdio.h>
#include <stdlib.h>
//Lectura de una matriz cuadrada, obtener
// suma de la diagonal principal, la primera columna, el ultimo renglon y la segunda diagonal

#define N 4
int leeEntero(char *letrero);
void lectura(int m[N][N], int n );
int sumaDiagonal(int m[N][N], int n );
int sumaColumna(int m[N][N], int n, int col);
int sumaRenglon(int m[N][N], int n, int ren);
int sumaSegunda(int m[N][N], int n);


int main()
{
    int matriz[N][N];
    int diagonal, columna,renglon;

    lectura(matriz , N);
    diagonal = sumaDiagonal(matriz, N);
    columna = sumaColumna(matriz, N, 0);
    renglon = sumaRenglon(matriz, N, N-1);


    return 0;
}

int leeEntero(char *letrero)
{
    int entero;

    printf("\n %s", letrero);
    scanf("%d", &entero);

    return (entero);
}

void lectura(int m[N][N], int n )
{
    int r, c;

    for(r = 0; r < n; r++)
    {
        for(c = 0; c < n; c++)
        {
            m[r][c] = leeEntero("Dame Elemento: ");
        }
    }

}



int sumaDiagonal(int m[N][N], int n )
{
    int i;
    int suma = 0;

    for(i = 0; i < n; i++)
    {
        suma = suma + m[i][i];
    }
    return (suma);
}

int sumaColumna(int m[N][N], int n, int col)
{
    int r;
    int suma = 0;

    for(r = 0; r < n; r++)
    {
        suma = suma + m[r][col];
    }
    return (suma);
}

int sumaRenglon(int m[N][N], int n, int ren)
{
    int c;
    int suma = 0;

    for(c = 0; c < n; c++)
    {
        suma = suma + m[ren][c];
    }
    return (suma);
}

int sumaSegunda(int m[N][N], int n)
{
    int r;
    int suma = 0;

    for(r = n-1; r >= 0; r--)
    {
        suma = suma + m[r][n-1-r];
    }
    return (suma);
}
