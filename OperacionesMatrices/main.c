#include <stdio.h>
#include <stdlib.h>

#define MAXREN 10
#define MAXCOL 10
#define SALIR 5

int menu();
void sumaMatrices(int M1[MAXREN][MAXCOL], int B[MAXREN][MAXCOL], int Nren, int Ncol);
void imprimeMatriz(int M1[MAXREN][MAXCOL], int Nren, int Ncol);

int main()
{
    int opcion;

    int A[MAXREN][MAXCOL] = {{3,5,7,9}, {2,4,6,8}, {9,7,5,3}, {8,6,4,2}, {0,1,2,3}}; //5 x 4
    int B[MAXREN][MAXCOL] = {{1,2,3,4}, {5,6,7,8}, {9,9,8,7}, {6,5,4,3}, {2,1,1,2}}; //5 x 4
    int T[MAXREN][MAXCOL];
    int C[MAXREN][MAXCOL] = {{7,6},{5,4}, {3,2},{2,1}}; // 4 x 2
    int M[MAXREN][MAXCOL];

    printf("matriz A:\n");
    imprimeMatriz(A, 5, 4);
    printf("matriz B:\n");
    imprimeMatriz(B, 5, 4);

     do{
        opcion = menu();
        switch(opcion)
        {
            case 1: sumaMatrices(A, B, 5, 4);
                    break;
            case 2: //restaMatrices(A,B, 5, 4);
                    break;
            case 3: //transpuesta(A,5,4, T);
                    break;
            case 4: //multiplica(A, 5, 4, C, 4,2, M);
                    break;

        }


     }while (opcion != SALIR);

     return 0;
}
int menu()
{
    int op;
  do{

        printf("\n 1. Suma de Matrices");
        printf("\n 2. Resta de Matrices");
        printf("\n 3. Transpuesta");
        printf("\n 4. Multiplicación");
        printf("\n 5. Salir");
        printf("\n       opcion: ");
        scanf("%d", &op);

    }while (op < 1 || op > 5);
    return (op);
}
void sumaMatrices(int M1[MAXREN][MAXCOL],int M2[MAXREN][MAXCOL], int Nren, int Ncol)
{
    int r,c;
    int R[MAXREN][MAXCOL];

    for(r = 0; r < Nren; r++)
        for (c = 0; c<Ncol; c++)
            R[r][c] = M1[r][c] + M2[r][c];
    imprimeMatriz(R, Nren, Ncol);
}

void imprimeMatriz(int M1[MAXREN][MAXCOL], int Nren, int Ncol)
{
    int r,c;

    for (r = 0; r < Nren; r++)
    {
        for(c = 0; c < Ncol; c++)
            printf("%5d", M1[r][c] );
        printf("\n");
    }
}
