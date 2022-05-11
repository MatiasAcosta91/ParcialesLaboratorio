#include "fecha.h"
#include "servicio.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[7];
    int idServ;
    eFecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED
int listaTrabajo (eTrabajo trabajo,eAuto autoo,eServicio servicios[],int cantServ,int idServBusc);
int listaTrabajos (eTrabajo trabajos[],int cantTrabajos,eAuto autos[],int cantAutos,eServicio servicios[],int cantServ);
int cargarDesServ(eServicio servicios[], int cantServ, int idServBusc, char* descripccion);
int inicializarTrabajo(eTrabajo trabajos[], int tamTrab);
int altaTrabajo(eAuto autos[],int tamAutos,eMarca marcas[],int cantMarc, eColor colores[],int cantCol,eTrabajo trabajos[],int tamTrab,eServicio servicios[],int cantServ,int* nextTrabajo);
int buscarTrabLibre(eTrabajo trabajos[],int tamTrab, int* pIndex);
