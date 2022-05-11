#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
typedef struct
{
    int id;
    char desc[20];

}eMarca;
int listarMarcas(eMarca marcas[], int cantMarc);
int cargarDescMarca(eMarca marcas[], int cantMarc, int idMarcBusc, char* descripccion);

#endif // MARCA_H_INCLUDED
