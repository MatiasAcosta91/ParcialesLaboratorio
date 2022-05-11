#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "auto.h"
#include "ingresosValidaciones.h"
#define INTENTOSINF -1
int menuModificacion()
{
    int opcion;
    printf("1. MODIFICAR COLOR.\n");
    printf("2. MODIFICAR MARCA.\n");
    printf("3. CONFIRMA CAMBIOS.\n");
    printf("4. SALIR.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int inicializarAutos (eAuto autos[], int tam)
{
    int retorno = 0;
    if (autos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            autos[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarExistencia (eAuto autos[],int tamAutos, char patBuscada[])
{
    int retorno = 0;
    if (autos != NULL && tamAutos >0 && patBuscada!= NULL )
    {
        for (int i = 0; i < tamAutos; i++)
        {
            if(autos[i].isEmpty == 0 && stricmp(autos[i].patente,patBuscada)== 0)
            {
                retorno = 1;
                break;

            }
        }
    }
    return retorno;
}

int listarAuto (eAuto autoo,eColor colores[],int cantCol,int idColor,eMarca marcas[], int cantMarc,int idMarc)
{
    int retorno = 0;
    char descColor[25];
    char descMarca[20];
    if (colores != NULL && marcas != NULL && cantCol >0 && cantMarc >0 && idColor >= 5000 && idColor <= 5004 && idMarc >= 1000  && idMarc <= 1004 )
    {
        cargarDescMarca(marcas,cantMarc,idMarc,descMarca);
        cargarDesColor(colores,cantCol,idColor,descColor);
        printf("%7s     %10s     %10s   %5c\n",autoo.patente,descMarca,descColor,autoo.caja);
        retorno = 1;
    }
    return retorno;
}
int listarAutos(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc)
{
    int retorno = 0;
    int flag = 0;
    if ( autos != NULL &&colores != NULL && marcas != NULL && cantCol >0 && cantMarc >0 )
    {
        printf("PATENTE          MARCA          COLOR     CAJA\n");
        printf("-----------------------------------------------\n");
        for (int i = 0; i <tamAutos; i++)
        {
            if (autos[i].isEmpty == 0)
            {
                listarAuto(autos[i],colores,cantCol,autos[i].idColor,marcas,cantMarc,autos[i].idMarca);
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

int buscarLugarLibre(eAuto autos[],int tamAutos, int* pIndex)
{
    int retorno = 0;
    if (autos !=  NULL && tamAutos >0 && pIndex != NULL)
    {
        *pIndex = -1;
        for (int i = 0; i < tamAutos; i++)
        {
            if (autos[i].isEmpty ==1)
            {
                *pIndex =  i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
int buscarAuto(eAuto autos[],int maxAutos,char idAbuscar[], int* pIndex)
{
    int retorno = 0;
    if (autos != NULL && pIndex != NULL && idAbuscar != NULL && maxAutos >0)
    {
        for (int i = 0; i < maxAutos; i++)
        {
            if ( !autos[i].isEmpty && stricmp (autos[i].patente,idAbuscar) == 0 )
            {
                *pIndex = i;
                retorno = 1;
                break;
            }
        }
    }
    return  retorno;
}
int IngresarNuevoAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc, eServicio servicios[],int cantServ)
{
    int retorno = 0;
    int indiceLibre;
    char mensajePat[]="Ingrese Patente de 6 caracteres alfanumericos: ";
    char mensajeColor[]="Seleccione Color: ";
    char mensajeMarca[]="Seleccione Marca: ";
    char mensajeError[]="ERROR=";
    char confirmaAlta;
    eAuto auxAuto;
    if (autos != NULL && colores != NULL && marcas != NULL && servicios != NULL && tamAutos >0 && cantCol >0 && cantMarc >0 && cantServ >0)
    {
        if (!buscarLugarLibre(autos,tamAutos,&indiceLibre) )
        {
            printf("No hay mas lugar disponible para ingresar autos.\n");
        }
        else
        {
            utn_getAlfanumerico(auxAuto.patente,mensajePat,mensajeError,6,6,INTENTOSINF);
            if (buscarExistencia(autos,tamAutos,auxAuto.patente) )
            {
                printf("La patente ingresada ya existe.\n");
            }
            else
            {
                listarMarcas(marcas,cantMarc);
                utn_getNumeroInt(&auxAuto.idMarca,mensajeMarca,mensajeError,1000,1004,INTENTOSINF);

                listarColores(colores,cantCol);
                utn_getNumeroInt(&auxAuto.idColor,mensajeColor,mensajeError,5000,5004,INTENTOSINF);

                printf("Ingrese caja m (manual) o a (automatica): ");
                fflush(stdin);
                scanf("%c",&auxAuto.caja);
                auxAuto.caja= tolower(auxAuto.caja);
                while (auxAuto.caja != 'a' && auxAuto.caja !='m')
                {
                    printf("ERROR=Ingrese caja m (manual) o a (automatica): ");
                    fflush(stdin);
                    scanf("%c",&auxAuto.caja);
                    auxAuto.caja= tolower(auxAuto.caja);
                }

                printf("\n\n");
                printf("PATENTE          MARCA          COLOR     CAJA\n");
                printf("-----------------------------------------------\n");
                listarAuto(auxAuto,colores,cantCol,auxAuto.idColor,marcas,cantMarc,auxAuto.idMarca);

                printf("Confirma el alta? s/n: ");
                fflush(stdin);
                scanf("%c",&confirmaAlta);
                confirmaAlta=tolower(confirmaAlta);
                while (confirmaAlta != 's' && confirmaAlta != 'n')
                {
                    printf("ERROR=Confirma el alta? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirmaAlta);
                    confirmaAlta=tolower(confirmaAlta);
                }
                if (confirmaAlta == 's')
                {
                    printf("Alta confirmada.\n");
                    autos[indiceLibre]=auxAuto;
                    autos[indiceLibre].isEmpty = 0;
                }
            }

        }
    }
    return retorno;
}
int modificarAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc)
{
    int retorno = 0;
    char mensajePat[]="Ingrese Patente de 6 caracteres alfanumericos: ";
    char mensajeColor[]="Seleccione Color: ";
    char mensajeMarca[]="Seleccione Marca: ";
    char mensajeError[]="ERROR=";
    char confirmaModificacion;
    char continua = 's';
    char patente[7];
    int indiceBuscado;
    eAuto auxAuto;
    if (autos != NULL && colores != NULL && marcas != NULL && tamAutos >0 && cantCol >0 && cantMarc >0 )
    {
        system("cls");
        printf("*** MODIFICAR AUTO ****\n");
        if ( !listarAutos(autos,tamAutos,colores,cantCol,marcas,cantMarc) )
        {
            continua ='n';
        }
        else
        {
            utn_getAlfanumerico(patente,mensajePat,mensajeError,6,6,INTENTOSINF);
            if (!buscarAuto(autos,tamAutos,patente,&indiceBuscado) )
            {
                printf("Patente no encontrada.");
            }
            else
            {
                auxAuto=autos[indiceBuscado];
                do
                {
                    system("cls");
                    printf("PATENTE          MARCA          COLOR     CAJA\n");
                    printf("-----------------------------------------------\n");
                    listarAuto(auxAuto,colores,cantCol,auxAuto.idColor,marcas,cantMarc,auxAuto.idMarca);
                    printf("\n\n\n");
                    switch(menuModificacion())
                    {
                    case 1:
                        listarColores(colores,cantCol);
                        utn_getNumeroInt(&auxAuto.idColor,mensajeColor,mensajeColor,5000,5004,INTENTOSINF);
                        break;
                    case 2:
                        listarMarcas(marcas,cantMarc);
                        utn_getNumeroInt(&auxAuto.idMarca,mensajeMarca,mensajeError,1000,1004,INTENTOSINF);
                        break;
                    case 3:
                        printf("Confirma el camio s/n: ");
                        fflush(stdin);
                        scanf("%c",&confirmaModificacion);
                        confirmaModificacion=tolower(confirmaModificacion);
                        while (confirmaModificacion != 's' && confirmaModificacion != 'n')
                        {
                            printf("ERROR=Confirma el cambio/n: ");
                            fflush(stdin);
                            scanf("%c",&confirmaModificacion);
                            confirmaModificacion=tolower(confirmaModificacion);
                        }
                        if (confirmaModificacion == 's')
                        {
                            autos[indiceBuscado] = auxAuto;
                            printf("Modificacion Realizada.\n");
                        }
                        else
                        {
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 4:
                        continua = 'n';
                        break;
                    default:
                        printf("Ingrese opcion correcta.\n");
                        break;
                    }
                    system("pause");
                }
                while (continua == 's');
            }
        }
    }
    return retorno;
}
int bajaAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc)
{
    int retorno = 0;
    char mensajePat[]="Ingrese Patente de 6 caracteres alfanumericos: ";
    char mensajeError[]="ERROR=";
    int indiceBuscado;
    char confirmaBaja;
    char patente[7];
    if (autos != NULL && colores != NULL && marcas != NULL && tamAutos >0 && cantCol >0 && cantMarc >0 )
    {
        system("cls");
        printf("*** BAJA AUTO ****\n");
        if ( !listarAutos(autos,tamAutos,colores,cantCol,marcas,cantMarc) )
        {
            printf("No hay autos ingresados.\n");
        }
        else
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
                printf("Confirma Baja? s/n");
                fflush(stdin);
                scanf("%c",&confirmaBaja);
                confirmaBaja=tolower(confirmaBaja);
                while (confirmaBaja!= 's' && confirmaBaja != 'n')
                {
                    printf("ERROR=Confirma el cambio/n: ");
                    fflush(stdin);
                    scanf("%c",&confirmaBaja);
                    confirmaBaja=tolower(confirmaBaja);
                }
                if (confirmaBaja == 's')
                {
                    autos[indiceBuscado].isEmpty = 1;
                    printf("Baja Realizada.\n");
                }
                else
                {
                    printf("Baja cancelada.\n");
                }

            }
        }
    }
    return retorno;
}
