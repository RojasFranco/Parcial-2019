#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_ARRAY_ORQUESTA 50
#define QTY_ARRAY_MUSICO 1000
#define QTY_ARRAY_INSTRUMENTO 20
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;                   //cambiar

    int contadorIdOrquesta=0;
    Orquesta arrayOrquesta[QTY_ARRAY_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta, QTY_ARRAY_ORQUESTA);

    int contadorIdMusico;
    Musico arrayMusico[QTY_ARRAY_MUSICO];
    musico_Inicializar(arrayMusico, QTY_ARRAY_MUSICO);

    int contadorIdInstrumento;
    Instrumento arrayInstrumento[QTY_ARRAY_INSTRUMENTO];
    instrumento_Inicializar(arrayInstrumento, QTY_ARRAY_INSTRUMENTO);

    //*******************************************************************
    arrayInstrumento[0].idInstrumento=1;
    arrayInstrumento[0].isEmpty=0;
    strcpy(arrayInstrumento[0].nombre, "PEPE");
    arrayInstrumento[0].tipo=2;
    contadorIdInstrumento++;

    arrayInstrumento[1].idInstrumento=4;
    arrayInstrumento[1].isEmpty=0;
    strcpy(arrayInstrumento[1].nombre,"JOSE");
    arrayInstrumento[1].tipo=3;
    contadorIdInstrumento++;


    arrayOrquesta[0].idOrquesta=1;
    arrayOrquesta[0].isEmpty=0;
    strcpy(arrayOrquesta[0].lugar,"asdasd 123");
    strcpy(arrayOrquesta[0].nombre,"JUAN");
    arrayOrquesta[0].tipoOrquesta=1;
    contadorIdOrquesta++;

    arrayOrquesta[1].idOrquesta=2;
    arrayOrquesta[1].isEmpty=0;
    strcpy(arrayOrquesta[1].lugar,"av saas 124");
    strcpy(arrayOrquesta[1].nombre,"ADOLFO");
    arrayOrquesta[1].tipoOrquesta=3;
    contadorIdOrquesta++;



    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta orquesta \n2) Eliminar orquesta \n3) Listar orquesta \n"
                            "4) Alta musico \n5) Modificar musico \n6) Eliminar musico\n7) Listar musicos\n"
                            "8) Alta instrumento\n9) Listar instrumentos\n10) Salir\n",                   //cambiar
                            "\nError",1,sizeof(int),1,10,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);                   //cambiar
                break;

            case 2: //Modificar
                orquesta_baja(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                break;

            case 3: //Baja
                orquesta_listar(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                break;

            case 4://Listar
                musico_alta(arrayMusico, QTY_ARRAY_MUSICO, &contadorIdMusico, arrayOrquesta, QTY_ARRAY_ORQUESTA, arrayInstrumento, QTY_ARRAY_INSTRUMENTO);
                break;

            case 5://Ordenar
                musico_modificar(arrayMusico, QTY_ARRAY_MUSICO, arrayOrquesta, QTY_ARRAY_ORQUESTA);
                break;

            case 6:
                musico_baja(arrayMusico, QTY_ARRAY_MUSICO);
                break;
            case 7:
                musico_imprimir(arrayMusico, QTY_ARRAY_MUSICO, arrayInstrumento, QTY_ARRAY_INSTRUMENTO);
                break;
            case 8:
                instrumento_alta(arrayInstrumento, QTY_ARRAY_INSTRUMENTO, &contadorIdInstrumento);
                break;
            case 9:
                instrumento_listar(arrayInstrumento, QTY_ARRAY_INSTRUMENTO);
                break;
            case 10:
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
