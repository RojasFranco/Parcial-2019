#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informe.h"

int informe_orquestasPorLugar(Orquesta array[], int size)
{
    int i;
    int retorno=-1;
    char lugarBuscado[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        if(!utn_getTexto("\nIngrese lugar:", "\nlugar invalido", 1, TEXT_SIZE, 1, lugarBuscado))
        {
            for(i=0; i<size; i++)
            {
                printf("\n%s\n", lugarBuscado);
                if(strncpy(array[i].lugar, lugarBuscado, sizeof(lugarBuscado)) == 0)
                {
                    printf("\nID orquesta: %d \nNombre: %s \nTipo:%d \nLugar: %s\n", array[i].idOrquesta, array[i].nombre, array[i].tipoOrquesta, array[i].lugar);

                }

            }
            retorno=0;
        }
    }
    return retorno;
}

int informe_musicosPorEdad(Musico array[], int size, Instrumento arrayInstrumento[], int lenInstrumento, Orquesta arrayOrquesta[], int lenOrquesta)
{
    int i;
    int retorno=-1;
    int posicionInstrumento;
    int posicionOrquesta;
    char nombreInstrumento[TEXT_SIZE];
    char nombreOrquesta[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        retorno=0;
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else if(array[i].edad<25)
            {
                if(!instrumento_buscarID(arrayInstrumento, lenInstrumento, array[i].idInstrumento, &posicionInstrumento))
                {
                    strncpy(nombreInstrumento, arrayInstrumento[posicionInstrumento].nombre, sizeof(nombreInstrumento));
                }
                if(!orquesta_buscarID(arrayOrquesta, lenOrquesta, array[i].idOrquesta, &posicionOrquesta))
                {
                    strncpy(nombreOrquesta, arrayOrquesta[posicionOrquesta].nombre, sizeof(nombreOrquesta));
                    printf("\nId musico: %d", array[i].idMusico);
                    printf("\nNombre: %s", array[i].nombre);
                    printf("\nApellido: %s", array[i].apellido);
                    printf("\nedad: %d", array[i].edad);
                    printf("\nNombre Instrumento: %s", nombreInstrumento);
                    printf("\nNombre Orquesta: %s\n", nombreOrquesta);
                }

            }

        }
    }
    return retorno;
}


int informe_cantidadMusicos(Orquesta array[], int size, Musico arrayMusico[], int lenMusico)
{
    printf("ASDASD");
    int i;
    int j;
    int retorno=-1;
    int cantidadMusicos=0;
    int IDbuscado;
    if(array!=NULL && size>=0 && arrayMusico!=NULL && lenMusico>=0)
    {
        retorno=0;
        for(i=0; i<size; i++)
        {
            IDbuscado=array[i].idOrquesta;
            for(j=0; i<lenMusico; j++)
            {
                if(arrayMusico[j].idOrquesta==IDbuscado)
                {
                    cantidadMusicos+=1;
                }
            }
            if(cantidadMusicos<6)
            {
                printf("\nID orquesta: %d\nNombre:%s\n Tipo:%d \nLugar: %s", array[i].idOrquesta, array[i].nombre, array[i].tipoOrquesta, array[i].lugar);

            }
        }
    }
    return retorno;
}


int informe_instrumentosDeOrquesta(Orquesta array[], int size, Instrumento arrayInstrumento[], int lenInstrumento, Musico arrayMusico[], int lenMusico)
{
    int i;
    int retorno=-1;
    int posicionOrquesta;
    int idPedido;
    int posicionInstrumento;
    if( array!=NULL) ///completar
    {
        utn_getUnsignedInt("\nID de orquesta", "\nerror", 1, sizeof(int), 1, size, 1, &idPedido);
        orquesta_buscarID(array, size, idPedido, &posicionOrquesta);
        for(i=0; i<lenMusico; i++)
        {
            if(arrayMusico[i].idOrquesta==idPedido)
            {
                instrumento_buscarID(arrayInstrumento, lenInstrumento, arrayMusico[i].idInstrumento, &posicionInstrumento);

                printf("\nNombre instrumento: %s", arrayInstrumento[posicionInstrumento].nombre);
                printf("\nTipo instrumento: %d", arrayInstrumento[posicionInstrumento].tipo);
                printf("\nNombre musico: %s", arrayMusico[i].nombre);


            }
        }
        retorno=0;
    }

    return retorno;
}


int informe_orquestaCompleta(Orquesta array[], int size, Musico arrayMusico[], int lenMusico, Instrumento arrayInstrumento[], int lenInstrumento)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int idBuscado;
    int cantidadCuerda=0;
    int cantidadViento=0;
    int cantidadPercusion=0;
    int idInstrumentoBuscado;
    //int posicionMusico;
    if(array !=NULL) ///commpletar
    {
        for(i=0; i<size; i++)
        {
            idBuscado=array[i].idOrquesta;

            for(j=0; i< lenMusico; i++)
            {
                if(arrayMusico[j].idOrquesta==idBuscado)
                {
                    idInstrumentoBuscado=arrayMusico[j].idInstrumento;

                    for(k=0; i<lenInstrumento; k++)
                    {
                        if(arrayInstrumento[k].idInstrumento==idInstrumentoBuscado)
                        {
                            if(arrayInstrumento[k].tipo==1)
                            {
                                cantidadCuerda+=1;
                            }
                            if(arrayInstrumento[k].tipo==2 || arrayInstrumento[k].tipo==3)
                            {
                                cantidadViento+=1;
                            }
                            if(arrayInstrumento[k].tipo==4)
                            {
                                cantidadPercusion+=1;
                            }

                        }

                    }

                }
            }
            if(cantidadPercusion>=1 && cantidadViento>=4 && cantidadCuerda>=4)
            {
                printf("n ID: %d\n tipoOrquesta: %d \nnombre: %s\n lugar: %s\n", array[i].idOrquesta,array[i].tipoOrquesta, array[i].nombre, array[i].lugar);
            }
        }



    }
    return retorno;
}



