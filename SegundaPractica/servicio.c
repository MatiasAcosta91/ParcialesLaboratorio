#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


int listarServicios (eServicio servicios[], int cantServ)
{
    int retorno =0;
    if (servicios!= NULL && cantServ > 0)
    {
        printf("        * * * LISTA DE SERVICIOS * * *       \n");
        printf("   Id    Descripcion\n");
        printf("------------------------\n");
        for (int i = 0; i < cantServ; i++)
        {
            printf("%4d   %10s\n",servicios[i].id,servicios[i].desc);
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}

int cargarDescServ(eServicio servicios[], int cantServ, int idServBusc, char* descripccion)
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
