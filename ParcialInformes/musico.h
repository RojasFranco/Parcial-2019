#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int edad;
    int idOrquesta; /// agregar
    int idInstrumento; ///  agregar
    char apellido[TEXT_SIZE];

}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int size, char* valorBuscado, char* segundoValorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int lenOrquesta, Instrumento arrayInstrumento[], int lenInstrumento);
int musico_baja(Musico array[], int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[], int lenOrquesta);                              //cambiar musico
int musico_ordenarPorApellido(Musico array[],int size, int orderFirst);
int musico_listar(Musico array[], int size);
int musico_imprimir(Musico array[], int size, Instrumento arrayInstrumento[], int lenInstrumento);
