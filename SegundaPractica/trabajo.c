#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"
#include "auto.h"
#include "servicio.h"
#include "ingresosValidaciones.h"
#define INTENTOSINF -1

int listaTrabajo (eTrabajo trabajo,eAuto autoo,eServicio servicios[],int cantServ,int idServBusc)
{
    int retorno = 0;
    char descServ[25];
    if (servicios != NULL && cantServ >0 )
    {
        cargarDescServ(servicios,cantServ,idServBusc,descServ);
        printf("%s   %5s   %5.2f\n",autoo.patente,descServ,servicios->precio);
        retorno = 1;
    }
    return retorno;
}
int listaTrabajos (eTrabajo trabajos[],int cantTrabajos,eAuto autos[],int cantAutos,eServicio servicios[],int cantServ)
{
    int retorno = 0;
    int flag = 0;
    int indiceAutBuscado;
    if ( trabajos != NULL && autos != NULL && servicios != NULL && cantTrabajos >0 && cantAutos >0 && cantServ >0)
    {
        printf("PATENTE     SERVICIO   PRECIO\n");
        printf("---------------------------------\n");
        for (int i = 0; i <cantTrabajos; i++)
        {
            buscarAuto(autos,cantAutos,trabajos[i].patente,&indiceAutBuscado);
            if (trabajos[i].isEmpty == 0)
            {
                listaTrabajo(trabajos[i],autos[indiceAutBuscado],servicios,cantServ,trabajos[i].idServ);
                flag = 1;
                retorno = 1;
            }
        }
        if (!flag)
        {
            printf("No hay autos activos.\n");
        }

    }
    return retorno;
}
int cargarDesServ(eServicio servicios[], int cantServ, int idServBusc, char* descripccion)
{
    int retorno = 0;
    if (servicios!= NULL && cantServ >0  && idServBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantServ; i++)
        {
            if (servicios[i].id == idServBusc)
            {
                strcpy(descripccion,servicios[i].desc);
            }
        }
        retorno = 1;
    }
    return retorno;
}

int inicializarTrabajo(eTrabajo trabajos[], int tamTrab)
{
    int retorno = 0;
    if (trabajos!= NULL && tamTrab> 0)
    {
        for (int i = 0; i < tamTrab; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarTrabLibre(eTrabajo trabajos[],int tamTrab, int* pIndex)
{
    int retorno = 0;
    if (trabajos !=  NULL && tamTrab >0 && pIndex != NULL)
    {
        *pIndex = -1;'
        for (int i = 0; i < tamTrab; i++)
        {
            if (trabajos[i].isEmpty ==1)
            {
                *pIndex =  i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int altaTrabajo(eAuto autos[],int tamAutos,eMarca marcas[],int cantMarc, eColor colores[],int cantCol,eTrabajo trabajos[],int tamTrab,eServicio servicios[],int cantServ,int* nextTrabajo)
{
    int retorno = 0;
    int posLibre;
    char mensajePat[]="Ingrese Patente de 6 caracteres alfanumericos: ";
    char mensajeServ[]="Elija un servicio: ";
    char mensajeError[]="ERROR=";
    char patente[7];
    char descServ[25];
    int indiceBuscado;
    char confirmaServicio;
    int servicioElejido;
    eTrabajo auxTrabajo;
    if (autos != NULL && marcas != NULL &&  colores != NULL && trabajos != NULL && servicios != NULL && tamAutos >0 && cantMarc >0 && cantCol >0 &&tamTrab >0 && cantCol >0)
    {
        if(!buscarTrabLibre(trabajos,tamTrab,&posLibre))
        {
            printf("No hay espacio para cargar mas trabajos.\n");
        }
        else
        {
            if ( listarAutos(autos,tamAutos,colores,cantCol,marcas,cantMarc) )
            {
                utn_getAlfanumerico(patente,mensajePat,mensajeError,6,6,INTENTOSINF);
                if (!buscarAuto(autos,tamAutos,patente,&indiceBuscado) )
                {
                    printf("Patente no encontrada.");
                }
                else
                {
                    printf("PATENTE          MARCA          COLOR     CAJA\n");
                    printf("-----------------------------------------------\n");
                    listarAuto(autos[indiceBuscado],colores,cantCol,autos[indiceBuscado].idColor,marcas,cantMarc,autos[indiceBuscado].idMarca);
                    listarServicios(servicios,cantServ);
                    utn_getNumeroInt(&servicioElejido,mensajeServ,mensajeError,20000,20004,INTENTOSINF);
                    switch(servicioElejido)
                    {
                    case 20000:
                        printf("Lavado agregado.\n");
                        auxTrabajo.idServ=20000;
                        break;
                    case 20001:
                        printf("Lavado agregado.\n");
                        auxTrabajo.idServ=20001;
                        break;
                    case 20002:
                        printf("Lavado agregado.\n");
                        auxTrabajo.idServ=20002;
                        break;
                    case 20003:
                        printf("Lavado agregado.\n");
                        auxTrabajo.idServ=20003;
                        break;
                    case 20004:
                        printf("Lavado agregado.\n");
                        auxTrabajo.idServ=20004;
                        break;
                    }
                    cargarDescServ(servicios,cantServ,servicioElejido,descServ);
                    printf("PATENTE     SERVICIO     PRECIO\n");
                    printf("-------------------------------------\n");
                    printf("%s %10s    %5.2f\n",autos[indiceBuscado].patente,descServ,servicios[posLibre].precio);
                    printf("Confirma Trabajo?: s/n");
                    fflush(stdin);
                    scanf("%c",&confirmaServicio);
                    confirmaServicio=tolower(confirmaServicio);
                    while (confirmaServicio!= 's' && confirmaServicio != 'n')
                    {
                        printf("ERROR=Confirma el cambio/n: ");
                        fflush(stdin);
                        scanf("%c",&confirmaServicio);
                        confirmaServicio=tolower(confirmaServicio);
                    }
                    if (confirmaServicio == 's')
                    {
                        trabajos[posLibre]=auxTrabajo;
                        trabajos[posLibre].isEmpty = 0;
                    }
                    else
                    {
                        printf("Trabajo Cancelado.\n");
                    }

                }

            }
            retorno = 1;
        }


    }
    return retorno;
}
