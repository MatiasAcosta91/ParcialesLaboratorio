#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define MAX_AUTOS 2000
#define CANT_MARC 5
#define CANT_COL 5
#define CANT_SERV 4
#define MAX_TRABAJOS 2000


int menu();




int main()
{

    eAuto autos[MAX_AUTOS];
    eTrabajo trabajos[MAX_TRABAJOS];
    char continuar = 's';
    int nextTrabajo = 0;
    eMarca marcas[CANT_MARC]=
    {
        {1000,"Renault"},
        {1001,"Ford"},
        {1002,"Fiat"},
        {1003,"Chevrole"},
        {1004,"Peugeot"}
    };
    eColor colores[CANT_COL]=
    {
        {5000,"Naranja"},
        {5001,"Blanco"},
        {5002,"Rojo"},
        {5003,"Gris"},
        {5004,"Azul"}
    };
    eServicio servicios[CANT_SERV]=
    {
        {20000,"Lavado",450},
        {20001,"Pulido",500},
        {20002,"Encerado",600},
        {20003,"Completo",900}
    };
    inicializarAutos (autos,MAX_AUTOS);
    inicializarTrabajo(trabajos,MAX_TRABAJOS);
    do
    {
        switch(menu())
        {
        case 1:
            IngresarNuevoAuto(autos,MAX_AUTOS,colores,CANT_COL,marcas,CANT_MARC,servicios,CANT_SERV);
            break;
        case 2:
            break;
        case 3:
            modificarAuto(autos,MAX_AUTOS,colores,CANT_COL,marcas,CANT_MARC);
            break;
        case 4:
            listarAutos(autos,MAX_AUTOS,colores,CANT_COL,marcas,CANT_MARC);
            break;
        case 5:
            listarMarcas(marcas,CANT_MARC);
            break;
        case 6:
            listarColores(colores,CANT_COL);
            break;
        case 7:
            listarServicios(servicios,CANT_SERV);
            break;
        case 8:
            altaTrabajo(autos,MAX_AUTOS,marcas,CANT_MARC,colores,CANT_COL,trabajos,MAX_TRABAJOS,servicios,CANT_SERV,&nextTrabajo);
            break;
        case 9:
            listaTrabajos(trabajos,MAX_TRABAJOS,autos,MAX_AUTOS,servicios,CANT_SERV);
            break;
        case 10:
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        system("pause");
    }
    while(continuar == 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("*********************************************************\n");
    printf("*                        A B M                           *\n");
    printf("*********************************************************\n");
    printf("1.ALTA AUTO .\n");
    printf("2.BAJA .\n");
    printf("3.MODIFICAR AUTO.\n");
    printf("4.LISTAR AUTOS .\n");
    printf("5.LISTAR MARCAS .\n");
    printf("6.LISTAR COLORES .\n");
    printf("7.LISTAR SERVICIOS .\n");
    printf("8.ALTA TRABAJO .\n");
    printf("9. .\n");
    printf("10. .\n");
    fflush(stdin);
    scanf("%d",&opcion);
    fflush(stdin);
    system("cls");
    return opcion;

}

