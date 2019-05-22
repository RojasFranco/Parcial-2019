#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informe.h"

#define QTY_ARRAY_ORQUESTA 50
#define QTY_ARRAY_MUSICO 1000
#define QTY_ARRAY_INSTRUMENTO 20
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;                   //cambiar
    int opcionInforme;
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
    strcpy(arrayInstrumento[0].nombre, "Inst 1");
    arrayInstrumento[0].tipo=1;
    contadorIdInstrumento++;

    arrayInstrumento[1].idInstrumento=2;
    arrayInstrumento[1].isEmpty=0;
    strcpy(arrayInstrumento[1].nombre,"Inst 2");
    arrayInstrumento[1].tipo=2;
    contadorIdInstrumento++;

    arrayInstrumento[2].idInstrumento=3;
    arrayInstrumento[2].isEmpty=0;
    strcpy(arrayInstrumento[2].nombre,"Inst 3");
    arrayInstrumento[2].tipo=2;
    contadorIdInstrumento++;

    arrayInstrumento[3].idInstrumento=4;
    arrayInstrumento[3].isEmpty=0;
    strcpy(arrayInstrumento[3].nombre,"Inst 4");
    arrayInstrumento[3].tipo=3;
    contadorIdInstrumento++;

    arrayInstrumento[4].idInstrumento=5;
    arrayInstrumento[4].isEmpty=0;
    strcpy(arrayInstrumento[4].nombre,"Inst 5");
    arrayInstrumento[4].tipo=4;
    contadorIdInstrumento++;


    arrayOrquesta[0].idOrquesta=1;
    arrayOrquesta[0].isEmpty=0;
    strcpy(arrayOrquesta[0].lugar,"Lugar1");
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");
    arrayOrquesta[0].tipoOrquesta=1;
    contadorIdOrquesta++;

    arrayOrquesta[1].idOrquesta=2;
    arrayOrquesta[1].isEmpty=0;
    strcpy(arrayOrquesta[1].lugar,"Lugar2");
    strcpy(arrayOrquesta[1].nombre,"Orquesta2");
    arrayOrquesta[1].tipoOrquesta=2;
    contadorIdOrquesta++;


    arrayOrquesta[2].idOrquesta=3;
    arrayOrquesta[2].isEmpty=0;
    strcpy(arrayOrquesta[2].lugar,"Lugar3");
    strcpy(arrayOrquesta[2].nombre,"Orquesta3");
    arrayOrquesta[2].tipoOrquesta=3;
    contadorIdOrquesta++;


    arrayOrquesta[3].idOrquesta=4;
    arrayOrquesta[3].isEmpty=0;
    strcpy(arrayOrquesta[3].lugar,"Lugar4");
    strcpy(arrayOrquesta[3].nombre,"Orquesta4");
    arrayOrquesta[3].tipoOrquesta=2;
    contadorIdOrquesta++;


    arrayMusico[0].idMusico=1;
    arrayMusico[0].isEmpty=0;
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"AMus1");
    arrayMusico[0].edad=30;
    arrayMusico[0].idInstrumento=2;
    arrayMusico[0].idOrquesta=1;


    arrayMusico[1].idMusico=2;
    arrayMusico[1].isEmpty=0;
    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"AMus2");
    arrayMusico[1].edad=20;
    arrayMusico[1].idInstrumento=5;
    arrayMusico[1].idOrquesta=2;

    arrayMusico[2].idMusico=3;
    arrayMusico[2].isEmpty=0;
    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"AMus3");
    arrayMusico[2].edad=25;
    arrayMusico[2].idInstrumento=2;
    arrayMusico[2].idOrquesta=4;


    arrayMusico[3].idMusico=4;
    arrayMusico[3].isEmpty=0;
    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"AMus4");
    arrayMusico[3].edad=27;
    arrayMusico[3].idInstrumento=1;
    arrayMusico[3].idOrquesta=4;

    arrayMusico[4].idMusico=5;
    arrayMusico[4].isEmpty=0;
    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"AMus5");
    arrayMusico[4].edad=22;
    arrayMusico[4].idInstrumento=3;
    arrayMusico[4].idOrquesta=1;

    arrayMusico[5].idMusico=6;
    arrayMusico[5].isEmpty=0;
    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"AMus6");
    arrayMusico[5].edad=35;
    arrayMusico[5].idInstrumento=4;
    arrayMusico[5].idOrquesta=3;


    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta orquesta \n2) Eliminar orquesta \n3) Listar orquesta \n"
                            "4) Alta musico \n5) Modificar musico \n6) Eliminar musico\n7) Listar musicos\n"
                            "8) Alta instrumento\n9) Listar instrumentos\n10) Informes\n11) Salir\n",                   //cambiar
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
                utn_getUnsignedInt("\n1)Orquesta por lugar\n 2)Musicos menor de 25 años\n 3) Orquestas menos 6 musicos\n"
                        "4)inst de orquesta\n5)Orq completas\n6)\nopcion:", "Opcion invalida",1, sizeof(int), 1, 10, 1, &opcionInforme);
                switch(opcionInforme)
                {
                    case 1:
                        informe_orquestasPorLugar(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                        break;
                    case 2:
                        informe_musicosPorEdad(arrayMusico, QTY_ARRAY_MUSICO, arrayInstrumento, QTY_ARRAY_INSTRUMENTO, arrayOrquesta, QTY_ARRAY_ORQUESTA);
                        break;
                    case 3:
                        informe_cantidadMusicos(arrayOrquesta, QTY_ARRAY_ORQUESTA, arrayMusico, QTY_ARRAY_MUSICO);
                        break;
                    case 4:
                        informe_instrumentosDeOrquesta(arrayOrquesta, QTY_ARRAY_ORQUESTA, arrayInstrumento, QTY_ARRAY_INSTRUMENTO, arrayMusico, QTY_ARRAY_MUSICO);
                        break;
                    case 5:
                        informe_orquestaCompleta(arrayOrquesta, QTY_ARRAY_ORQUESTA, arrayMusico, QTY_ARRAY_MUSICO, arrayInstrumento, QTY_ARRAY_INSTRUMENTO);
                        break;
                    default:
                        printf("\nOpcion invalida");
                }
                break;
            case 11:
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
