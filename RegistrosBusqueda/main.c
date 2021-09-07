#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia, mes ,anio;
}Tfecha;


typedef struct
{
    char calle[10];
    int numero;
    char colonia[10];
    int CP;
    char cd[15];
}Tdir;


typedef struct
{
    char nombre[25];
    Tdir domicilio;
    char telefono[13];
    Tfecha fecha;
    char seguros, alergias;
    char observaciones[50];

}Tdato;

typedef struct
{
    Tdato paciente[10];
    int nPacientes;


}Tdatos;


void captura(Tdatos *info);
void leePaciente(Tdato *infoP);
int busquedaSecNoOrd(Tdatos info, char *nom);
void imprimePaciente(Tdato info);
void imprimeAlergias(Tdatos info);
void imprimeTodos(Tdatos info);
void ordenaPacientes(Tdatos info);


int main()
{
    Tdatos datos;
    char nombre[10];
    int pos;


    captura(&datos);
    fflush(stdin);
    printf("Como se llama tu paciente ");
    gets(nombre);
    pos = busquedaSecNoOrd(datos, nombre);
    if (pos < datos.nPacientes)
    {
        printf("Fecha de la ultima consulta %d/ %d /%d", datos.paciente[pos].fecha.dia, datos.paciente[pos].fecha.mes, datos.paciente[pos].fecha.anio );
    }
    else
    {
        printf("No lo encontre ");
    }



    return 0;
}

void captura(Tdatos *info)
{
    char resp;
    info->nPacientes = 0;
    do{
            leePaciente(&info->paciente[info->nPacientes]);  //Este dato ya esta pasado por referencia
            info->nPacientes++;
            printf("Deseas continuar con la captura: <S/N> ");
            scanf("%c", &resp);
            fflush(stdin);

    }while( resp == 'S' || resp == 's');

}


void leePaciente(Tdato *infoP)
{
    printf("---> Datos del paciente <--- ");
    printf("\n Nombre del paciente:  ");
    gets(infoP->nombre);
    printf("\n -> Domicilio <- ");
    printf("\n\t Calle: ");
    gets(infoP->domicilio.calle );
    printf("\n\t Numero: ");
    scanf("%d", &infoP->domicilio.numero );
    fflush(stdin);
    printf("\n\t Colonia: ");
    gets(infoP->domicilio.colonia );
    printf("\n\t Codigo Postal: ");
    scanf("%d", &infoP->domicilio.CP );
    fflush(stdin);
    printf("\n\t Ciudad: ");
    gets(infoP->domicilio.cd );
    printf("\n -> Fecha de la ultima consulta <- ");
    printf("\n\t DIA: ");
    scanf("%d", &infoP->fecha.dia);
    printf("\n\t MES: ");
    scanf("%d", &infoP->fecha.mes);
    printf("\n\t AÑO: ");
    scanf("%d", &infoP->fecha.anio);
    fflush(stdin);
    printf("\n El paciente tiene seguro? <S/N> ");
    scanf("%c", &infoP->seguros);
    fflush(stdin);
    printf("\n El paciente tiene alergias? <S/N> ");
    scanf("%c", &infoP->alergias);
    fflush(stdin);
    printf("\n Observaciones: ");
    gets(infoP->observaciones);

}

int busquedaSecNoOrd(Tdatos info, char *nom)
{
    int i = 0;
    int encontre = 0;
    do{
        if(strcmp(nom, info.paciente[i].nombre) == 0)
        {
            encontre = 1;
            i++;
        }
    }while(!encontre && i < info.nPacientes);
    if(encontre)
        i--;
    return(i);
}

void imprimePaciente(Tdato infoP)
{
    printf("---> Datos del paciente <--- ");
    printf("\n Nombre del paciente:  %s", infoP.nombre);
    printf("\n -> Domicilio <- ");
    printf("\n\t Calle: %s ", infoP.domicilio.calle);
    printf("\n\t Numero: %d ", infoP.domicilio.numero);
    printf("\n\t Colonia: %s ", infoP.domicilio.colonia);
    printf("\n\t Codigo Postal: %d ", infoP.domicilio.CP);
    printf("\n\t Ciudad: %s ", infoP.domicilio.cd);
    printf("\n -> Fecha de la ultima consulta <- ");
    printf("\n\t DIA: %d ", infoP.fecha.dia);
    printf("\n\t MES: %d ", infoP.fecha.mes);
    printf("\n\t AÑO: %d ", infoP.fecha.anio);
    printf("\n Tiene seguro? %c  ", infoP.seguros);
    printf("\n Tiene alergias? %c ", infoP.alergias);
    printf("\n Observaciones: %s ", infoP.observaciones);
}

void imprimeAlergias(Tdatos info)
{
    int i;
    for (i = 0; i < info.nPacientes; i++)
    {
        if(info.paciente[i].alergias == 'S' || info.paciente[i].alergias == 's' )
        {
            imprimePaciente(info.paciente[i]);
        }
    }
}

void imprimeTodos(Tdatos info)
{
    int i;
    for (i = 0; i < info.nPacientes; i++)
    {
            imprimePaciente(info.paciente[i]);
    }
}

void ordenaPacientes(Tdatos info)
{
    int it, i;

    for (it = 1 ; it < info->nPacientes ; it ++)
        for (i = 0; i < info->nPacientes-it-1 ; i++)
        {
            if(strcmp(info->paciente[i].nombre , info->paciente[i+1].nombre) > 0)
                intercambio(info->paciente[i].nombre , info->paciente[i+1].nombre);
        }
}

void intercambio(char *x, char y[])
{
    int z[25];

    strcpy( z, x);
    strcpy( x, y);
    strcpy( y, z);

}
