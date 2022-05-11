#include "servicio.h"
#include "color.h"
#include "marca.h"
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
typedef struct
{
    char patente[7];
    int idColor;
    int idMarca;
    char caja;
    int isEmpty;
}eAuto;
int menuModificacion();
int inicializarAutos (eAuto autos[], int tam);
int buscarAuto(eAuto autos[],int maxAutos,char idAbuscar[], int* pIndex);
int IngresarNuevoAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc, eServicio servicios[],int cantServ);
int modificarAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc);
int listarAuto (eAuto autoo,eColor colores[],int cantCol,int idColor,eMarca marcas[], int cantMarc,int idMarc);
int listarAutos(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc);
int buscarExistencia (eAuto autos[],int tamAutos, char patBuscada[]);
int bajaAuto(eAuto autos[],int tamAutos,eColor colores[],int cantCol,eMarca marcas[], int cantMarc);

#endif // AUTO_H_INCLUDED
