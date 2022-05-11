#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int listarColores (eColor colores[], int cantCol)
{
    int retorno =0;
    if (colores!= NULL && cantCol > 0)
    {
        printf("        * * * LISTA DE COLORES * * *       \n");
        printf("   Id    Descripcion\n");
        printf("------------------------\n");
        for (int i = 0; i < cantCol; i++)
        {
            printf("%4d   %10s\n",colores[i].id,colores[i].desc);
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}


int cargarDesColor(eColor colores[], int cantCol, int idColBusc, char* descripccion)
{
    int retorno = 0;
    if (colores!= NULL && cantCol >0  && idColBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantCol; i++)
        {
            if (colores[i].id == idColBusc)
            {
                strcpy(descripccion,colores[i].desc);
            }
        }
        retorno = 1;
    }
    return retorno;
}
