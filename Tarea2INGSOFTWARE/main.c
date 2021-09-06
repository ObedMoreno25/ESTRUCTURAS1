//Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Constantes definidas por el usuario
#define pi 3.141592654

//Estructuras
typedef struct
{
    int arr[20];
    float n1;
    float n2;
    float n3;
    int n4;
    float res;

}Numeros;
//Menús

int menuPrincipal();
int menuAritmetica();
int menuTrigonometria();
int menuGeo2DPeri();
int menuGeo2DArea();
int menuGeo3D();


//Funciones para las operaciones

void aritmetica(Numeros *C, int op);
void trigonometria(Numeros *C, int op);
float conv_aRadianes(float anguloDec);
void geo2DPeri(Numeros *C, int op);
void geo2DArea(Numeros *C, int op);
void geometria3d(Numeros *C, int op);
int estadistica(Numeros *C, int n);
int factorial(int n);
void velocidad(Numeros *C);
void fuerza(Numeros *C);

int main(){
    char resp;
    float media;
    int opcion, r, n;
    Numeros num;

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
                printf("\n Geometría 2D (Perímetro):\n");
                opcion = menuGeo2DPeri();
                geo2DPeri(&num, opcion);
                break;

            case 4:
                printf("\n Geometría 2D (Área):\n");
                opcion = menuGeo2DArea();
                geo2DArea(&num, opcion);
                break;

            case 5:
                printf("\n Geometría 3D (Volumen):\n");
                opcion = menuGeo3D();
                geometria3d(&num, opcion);
                break;

            case 6:
                printf("\n Estadísitica:\n");
                printf("Cuantos datos quieres para sacar tu media: ");
                scanf("%d", &n);
                media = estadistica(&num, n);
                printf("La media es: %.2f", media);
                break;

            case 7:
                printf("\n Factorial:\n");
                printf("Ingresa un numero: ");
                scanf("%d", & num.n4);
                r = factorial(num.n4);
                printf("El factorial de tu numero es: %d\n", r);
                break;

            case 8:
                printf("\n Velocidad:\n");
                velocidad(&num);
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
}


int menuPrincipal(){
    int op;
    printf("Elige la operacion que desees ejecutar:\n\n ");
    do{
        printf("1.- Aritmética\n ");
        printf("2.- Trigonometría\n ");
        printf("3.- Geometría 2D (perímetro)\n ");
        printf("4.- Geometría 2D (área)\n ");
        printf("5.- Geometría 3D (volumen)\n ");
        printf("6.- Estadística\n ");
        printf("7.- Factorial\n ");
        printf("8.- Velocidad\n ");
        printf("9.- Fuerza\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 9);
    return (op);
}


int menuAritmetica(){
    int op;
    printf("Elige que operacion arimetica deseas ejecutar:\n\n");
    do{
        printf("1.- Suma\n ");
        printf("2.- Resta\n ");
        printf("3.- Multiplicacion\n ");
        printf("4.- Division\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 4);
    return (op);
}


int menuTrigonometria(){
    int op;
    printf("Elige que operacion trigonometrica  deseas ejecutar:\n\n");
    do{
        printf("1.-Seno \n ");
        printf("2.-Coseno  \n ");
        printf("3.-Tangente \n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 3);
    return (op);
}

int menuGeo2DPeri(){
    int op;
    printf("Elige el polígono del que quiere obtener el perímetro:\n\n");
    do{
        printf("1.- Rectángulo\n ");
        printf("2.- Triángulo\n ");
        printf("3.- Círculo\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 3);
    return (op);
}


int menuGeo2DArea(){
    int op;
    printf("Elige el polígono del que quiere obtener el área:\n\n");
    do{
        printf("1.- Rectángulo\n ");
        printf("2.- Triángulo\n ");
        printf("3.- Círculo\n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 3);
    return (op);
}


int menuGeo3D(){
    int op;
    printf("Elige el poliedro del que quiere obtener el volumen:\n\n");
    do{
        printf("1.- Cubo\n ");
        printf("2.- Prisma \n ");
        printf("3.- Esfera \n ");
        printf("  -----Opcion ");
        scanf("%d", &op);
    }while (op < 1 || op > 3);
    return (op);
}


void aritmetica(Numeros *C, int op)
{
    printf("\nIngrese el primer dato: ");
    scanf("%f",&C->n1);
    printf("\nIngrese el segundo dato: ");
    scanf("%f",&C->n2);
    switch(op)
    {
    case 1:
        C->res = (C->n1 + C->n2);
        break;
    case 2:
        C->res = (C->n1 - C->n2);
        break;
    case 3:
        C->res = (C->n1 * C->n2);
        break;
    case 4:
        C->res = (C->n1 / C->n2);
        break;
        default:
        printf("Error, opcion no valida");
    }
    printf("El resultado es: %.1f", C->res );
}


void trigonometria(Numeros *C, int op)
{
    int disc = 0;
    printf("\n Ingrese el ángulo x: ");
    scanf("%f", &C->n1);
    switch(op){
        case 1:
            C->res = sin(conv_aRadianes(C->n1));
            break;

        case 2:
            C->res = cos(conv_aRadianes(C->n1));
            break;

        case 3:
            if(conv_aRadianes(C->n1) == conv_aRadianes(90))
            {
                printf("\n El resultado es indefinido\n");
                disc++;
            }
            else
                C->res = tan(conv_aRadianes(C->n1));
            break;
    }
    if(disc != 1)
        printf("\n El resultado es: %.5f\n", C->res);
}


float conv_aRadianes(float anguloDec)
{
    float rad;
    rad=(anguloDec*pi)/180;
    return(rad);
}


void geo2DPeri(Numeros *C, int op)
{
    switch(op){
        case 1:
            printf(" Introduce la base: ");
            scanf("%f", &C->n1);
            printf(" Introduce la altura: ");
            scanf("%f", &C->n2);
            C->res = 2*(C->n1+C->n2);
            break;

        case 2:
            printf(" Introduce el lado A: ");
            scanf("%f", &C->n1);
            printf(" Introduce el lado B: ");
            scanf("%f", &C->n2);
            printf(" Introduce el lado C: ");
            scanf("%f", &C->n3);
            C->res = C->n1 + C->n2 + C->n3;
            break;

        case 3:
            printf(" Introduce el radio: ");
            scanf("%f", &C->n1);
            C->res = 2* pi * C->n1;
            break;
    }
    printf("El perímetro es: %.2f", C->res);
}


void geo2DArea(Numeros *C, int op)
{
    switch(op){
        case 1:
            printf(" Introduce la base: ");
            scanf("%f", &C->n1);
            printf(" Introduce la altura: ");
            scanf("%f", &C->n2);
            C->res = C->n1 * C->n2;
            break;

        case 2:
            printf(" Introduce la base: ");
            scanf("%f", &C->n1);
            printf(" Introduce la altura: ");
            scanf("%f", &C->n2);
            C->res = (C->n1 * C->n2)/2;
            break;

        case 3:
            printf(" Introduce el radio: ");
            scanf("%f", &C->n1);
            C->res = pi * C->n1 * C->n1;
            break;
    }
    printf("El área es: %.2f", C->res);
}


void geometria3d(Numeros *C, int op)
{
    float resultado;
    switch(op)
    {
    case 1:
        printf("Ingrese el lado del cubo: ");
        scanf("%f",&C->n1);
        resultado=(C->n1*C->n1*C->n1);//son flotantes, no me deja usar ^ por eso lo hice asi
        break;
    case 2:
        printf("\nIngrese la base: ");
        scanf("%f",&C->n1);
        printf("\nIngrese la altura: ");
        scanf("%f",&C->n2);
        printf("\nIngrese la profundidad: ");
        scanf("%f",&C->n3);
        resultado=(C->n1*C->n2*C->n3);
        break;
    case 3:
        printf("\nIngrese el radio: ");
        scanf("%f",&C->n1);
        resultado=(C->n1*C->n1*C->n1);
        resultado=((4/3)*pi*resultado);
        break;
        default:
        printf("Error, opcion no valida");
    }
    printf("El resultado es: %.1f",resultado);
}

int estadistica(Numeros *C, int n)
{
    int suma = 0;
    int i;

    for ( i = 0; i < n ; i++)
    {
        printf("Ingresa tus datos:   ");
        scanf("%d", &C->arr[i]);
        suma = suma + C->arr[i];
    }
    suma = suma / n;
    return (suma);
}

int factorial(int n)
{
    int fact = 1;

    if( n >= 0)
    {
        if( n == 0)
        {
            fact = 1; //caso base
        }
        else
        {
            fact = n * factorial( n -1);
        }
    }
    else
    {
       fact = 1;
    }
    return (fact);
}


void velocidad(Numeros *C)
{
    printf("\nIngresa la distancia en km: ");
    scanf("%d",&C->n4);
    printf("\nIngresa el tiempo en hr: ");
    scanf("%f",&C->n1);
    C->n2=C->n4/C->n1; //C->n2 es igual a la velocidad
    printf("\nLa velocidad es %.2f km/hr",C->n2);
}

void fuerza(Numeros *C)
{
    printf("\nIngrese la masa: ");
    scanf("%f",&C->n1);
    printf("\nIngrese la aceleracion: ");
    scanf("%f",&C->n2);
    C->n3=C->n1*C->n2;
    printf("\nLa fuerza es %.1f F",C->n3);
}


