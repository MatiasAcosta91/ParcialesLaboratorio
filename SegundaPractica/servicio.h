#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
typedef struct
{
    int id;
    char desc[25];
    float precio;
}eServicio;



#endif // SERVICIO_H_INCLUDED
int listarServicios (eServicio servicios[], int cantServ);
int cargarDescServ(eServicio servicios[], int cantServ, int idServBusc, char* descripccion);
