#include <stdio.h>
#include <stdlib.h>


void Burbuja(int A[], int N);
void insercion(int A[], int N);
void Seleccion(int A[], int N);
void Quicksort(int A[], int inicio, int fin);
int acomodaFoco(int A[], int inicio, int fin);
int BusquedaSecuencialNoOrd(int A[], int N, int num);
int BusquedaSecuencialOrd(int A[], int N, int num);
void intercambio(int *x, int *y);
void imprime(int A[], int N);
int menu();

int main()
{
    int Arreglo[] = {13, 25, 5, 18, 26, 84, 30, 12, 22 };
    int N = 10;
    int opcion, valor, pos;


    do{
        opcion = menu();
        switch(opcion)
        {
            case 1: Burbuja(Arreglo, N);
                   break;
            case 2: insercion(Arreglo, N);
                   break;
            case 3: Seleccion(Arreglo, N);
                   break;
            case 4: Quicksort(Arreglo, 0 , N-1);
                   break;

            case 5: printf("\n ¿Cual es el valor a buscar?");
                    scanf("%d", &valor);
                    pos = BusquedaSecuencialNoOrd(Arreglo, N , valor);
                    if(pos >= 0  &&  pos <= N-1)
                    {
                        printf(" La posicion de tu dato es:  %d", pos);
                    }
                    else
                    {
                        printf("El dato no se encuentra");
                    }
                   break;
            case 6: imprime(Arreglo, N);
        }
    }while (opcion != 6);
}


void Burbuja(int A[], int N)
{
    int it, i;

    for (it = 1; it < N; it ++)
        for (i = 0; i < N-it-1 ; i++)
        {
            if(A[i] > A[i+1])
                intercambio(&A[i] , &A[i+1]);
        }
}

void intercambio(int *x, int *y)
{
    int z;

    z = *x;
    *x = *y;
    *y = z;
}

int menu()
{
    int op;

    do{
        printf("\n 1.- Metodo de la burbuja ");
        printf("\n 2.- Metodo de Insercion ");
        printf("\n 3.- Metodo de Seleccion ");
        printf("\n 4.- Metodo Quicksort ");
        printf("\n 5.- Busqueda secuencial no Ordenada ");
        printf("\n 6.-Imprime arreglo ");
        printf("\n 7.- Salir ");
        printf("\n         Opcion: ");
        scanf("%d", &op);

    }while (op < 1 || op > 7);
    return (op);
}

void imprime(int A[], int N)
{
    int i;
    for(i = 0; i < N; i++)
    {
        printf("%d  ", A[i]);
    }
}

void insercion(int A[], int N)
{
    int i, it;

    for (it = 1; it < N; it++)
    {
        i = it;
        while(i > 0 && A[i] < A[i-1])
        {
            intercambio(&A[i], &A[i-1]);
        }
    }
}

void Seleccion(int A[], int N)
{
    int i, it, pos;
    int mayor;  //tipo de dato del arreglo

    for(it = 1; it < N; it++)
    {
        mayor = A[0];
        pos = 0;
        for( i = 1; i <= N-it; i++)
        {
            if(A[i] > mayor)
            {
                mayor = A[i];
                pos = i;
            }
        }
        A[pos] = A[N-it];
        A[N-it] = mayor;
    }
}

void Quicksort(int A[],int inicio, int fin)
{
    int posfoco;

    if(inicio < fin)
    {
        posfoco = acomodaFoco(A, inicio, fin);
        Quicksort(A, inicio, posfoco-1);
        Quicksort(A, posfoco+1, fin);
    }
}

int acomodaFoco(int A[], int inicio, int fin)
{
    int izq, der;
    int foco;

    foco = A[inicio];
    izq = inicio;
    der = fin;

    do{
            while(A[izq] <= foco && izq < fin )
                izq++;
            while(A[der] > foco)
                der--;
            if (izq < der)
            {
                intercambio(&A[izq] , &A[der]);
            }

    }while(izq < der);
    A[inicio] = A[der];
    A[der] = foco;

    return der;
}

int BusquedaSecuencialNoOrd(int A[], int N, int num)
{
    int i, encontre;
    i = encontre = 0;
    do{
            if(A[i] == num)
            {
                encontre = 1;
            }
            i++;

    }while(!encontre && i < N);
    if (encontre)
    {
        i--;
    }
    return (i);
}

int BusquedaSecuencialOrd(int A[], int N, int num)
{
    int i, encontre;
    i = encontre = 0;
    do{
            if(A[i] == num)
            {
                encontre = 1;
            }
            i++;

    }while(!encontre && i < N  && A[i-1] < num);
    if (encontre)
    {
        i--;
    }
    else
    {
        i = N;  // Le asiganmos un dato no valido para que nos salga el mensaje no se encontro.
    }
    return (i);
}
