#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int listarMarcas(eMarca marcas[], int cantMarc)
{
    int retorno =0;
    if (marcas!= NULL && cantMarc > 0)
    {
        printf("        * * * LISTA DE MARCAS * * *       \n");
        printf("   Id    Descripcion\n");
        printf("------------------------\n");
        for (int i = 0; i < cantMarc; i++)
        {
            printf("%4d   %10s\n",marcas[i].id,marcas[i].desc);
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}



int cargarDescMarca(eMarca marcas[], int cantMarc, int idMarcBusc, char* descripccion)
{
    int retorno = 0;
    if (marcas!= NULL && cantMarc >0  && idMarcBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantMarc; i++)
        {
            if (marcas[i].id == idMarcBusc)
            {
                strcpy(descripccion,marcas[i].desc);
            }
        }
        retorno = 1;
    }
    return retorno;
}
