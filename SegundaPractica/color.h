#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
typedef struct
{
    int id;
    char desc[20];
}eColor;


#endif // COLOR_H_INCLUDED
int listarColores (eColor colores[], int cantCol);
int cargarDesColor(eColor colores[], int cantCol, int idColBusc, char* descripccion);
