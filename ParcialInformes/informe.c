#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informe.h"


/** \brief lista las orquestas que coinciden con el lugar ingresado por usuario
* \param array Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordeno exitosamente
*
*/
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
                if(strncmp(array[i].lugar, lugarBuscado, sizeof(lugarBuscado)) == 0)
                {
                    printf("\nID orquesta: %d", array[i].idOrquesta);
                    printf("\nNombre: %s", array[i].nombre);
                    printf("\nTipo: %d", array[i].tipoOrquesta);
                    printf("\nLugar: %s\n", array[i].lugar);
                }

            }
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Lista los musicos menor a 25 anios
* \param arrayMusico Array de musico
* \param lenMusico tamaño del array de musico
* \param arrayInstrumento musico Array de Instrumento
* \param lenInstrumento Tamaño del arrayInstrumento
* \param arrayOrquesta musico Array de Orquesta
* \param lenOrquesta Tamaño del arrayOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_musicosPorEdad(Musico arrayMusico[], int lenMusico, Instrumento arrayInstrumento[], int lenInstrumento, Orquesta arrayOrquesta[], int lenOrquesta)
{
    int i;
    int retorno=-1;
    int posicionInstrumento;
    int posicionOrquesta;
    char nombreInstrumento[TEXT_SIZE];
    char nombreOrquesta[TEXT_SIZE];
    if(arrayMusico!=NULL && lenMusico>=0)
    {
        retorno=0;
        for(i=0; i<lenMusico; i++)
        {
            if(arrayMusico[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayMusico[i].edad<25)
            {
                if(!instrumento_buscarID(arrayInstrumento, lenInstrumento, arrayMusico[i].idInstrumento, &posicionInstrumento) &&
                   !orquesta_buscarID(arrayOrquesta, lenOrquesta, arrayMusico[i].idOrquesta, &posicionOrquesta))
                {
                    strncpy(nombreInstrumento, arrayInstrumento[posicionInstrumento].nombre, sizeof(nombreInstrumento));
                    strncpy(nombreOrquesta, arrayOrquesta[posicionOrquesta].nombre, sizeof(nombreOrquesta));
                    printf("\nId musico: %d", arrayMusico[i].idMusico);
                    printf("\nNombre: %s", arrayMusico[i].nombre);
                    printf("\nApellido: %s", arrayMusico[i].apellido);
                    printf("\nedad: %d", arrayMusico[i].edad);
                    printf("\nNombre Instrumento: %s", nombreInstrumento);
                    printf("\nNombre Orquesta: %s\n", nombreOrquesta);
                }
            }
        }
    }
    return retorno;
}


/** \brief Lista orquestas con menos de 6 musicos
* \param arrayOrquesta Array de orquesta
* \param lenOrquesta tamaño del array de orquesta
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_cantidadMusicos(Orquesta arrayOrquesta[], int lenOrquesta, Musico arrayMusico[], int lenMusico)
{
    int i;
    int j;
    int retorno=-1;
    int cantidadMusicos;
    if(arrayOrquesta!=NULL && lenOrquesta>=0 && arrayMusico!=NULL && lenMusico>=0)
    {
        retorno=0;
        for(i=0; i<lenOrquesta; i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
            {
                continue;
            }
            cantidadMusicos=0;
            for(j=0; j<lenMusico; j++)
            {
                if(arrayMusico[j].idOrquesta == arrayOrquesta[i].idOrquesta && arrayMusico[j].isEmpty==0)
                {
                    cantidadMusicos+=1;
                }
            }
            if(cantidadMusicos<6)
            {
                printf("\nID orquesta: %d", arrayOrquesta[i].idOrquesta);
                printf("\nNombre: %s", arrayOrquesta[i].nombre);
                printf("\nTipo: %d", arrayOrquesta[i].tipoOrquesta);
                printf("\nLugar: %s\n", arrayOrquesta[i].lugar);
            }
        }
    }
    return retorno;
}


/** \brief Lista instrumentos de orquesta
* \param arrayOrquesta de orquesta
* \param lenOrquesta tamaño del array de orquesta
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \param arrayInstrumento array de instrumento
* \param lenInstrumento tamaño del arrayInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_instrumentosDeOrquesta(Orquesta arrayOrquesta[], int lenOrquesta, Instrumento arrayInstrumento[], int lenInstrumento, Musico arrayMusico[], int lenMusico)
{
    int i;
    int retorno=-1;
    int posicionOrquesta;
    int idPedido;
    int posicionInstrumento;
    if( arrayOrquesta!=NULL) ///completar
    {
        utn_getUnsignedInt("\nID de orquesta: ", "\nerror", 1, sizeof(int), 1, lenOrquesta, 1, &idPedido);
        if(!orquesta_buscarID(arrayOrquesta, lenOrquesta, idPedido, &posicionOrquesta))
        {
            for(i=0; i<lenMusico; i++)
            {
                if(arrayMusico[i].isEmpty==1)
                {
                    continue;
                }
                if(arrayMusico[i].idOrquesta == idPedido)
                {
                    instrumento_buscarID(arrayInstrumento, lenInstrumento, arrayMusico[i].idInstrumento, &posicionInstrumento);
                    printf("\nNombre instrumento: %s", arrayInstrumento[posicionInstrumento].nombre);
                    printf("\nTipo instrumento: %d", arrayInstrumento[posicionInstrumento].tipo);
                    printf("\nNombre musico: %s\n", arrayMusico[i].nombre);
                }
            }
        }
        else
        {
            printf("\nNo existe id ingresado\n");
        }
        retorno=0;
    }

    return retorno;
}


/** \brief Lista orquestas con al menos 4 instrumentos de cuerda, 4 de viento y 1 de percusion
* \param array Array de orquesta
* \param size tamaño del array de orquesta
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \param arrayInstrumento array de instrumento
* \param lenInstrumento tamaño del arrayInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_orquestaCompleta(Orquesta array[], int size, Musico arrayMusico[], int lenMusico, Instrumento arrayInstrumento[], int lenInstrumento)
{
    int retorno=-1;
    int i;
    int j;
    int cantidadCuerda=0;
    int cantidadViento=0;
    int cantidadPercusion=0;
    int posicionInstrumento;
    if(array !=NULL && arrayInstrumento!=NULL && arrayMusico!=NULL && size>=0 && lenInstrumento>=0 && lenMusico>=0)
    {
        retorno=0;
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            for(j=0; j<lenMusico; j++)
            {
                if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta == array[i].idOrquesta)
                {
                    instrumento_buscarID(arrayInstrumento, lenInstrumento, arrayMusico[j].idInstrumento, &posicionInstrumento);
                    if(arrayInstrumento[posicionInstrumento].tipo==1)
                    {
                        cantidadCuerda+=1;
                    }
                    else if(arrayInstrumento[posicionInstrumento].tipo==2 || arrayInstrumento[posicionInstrumento].tipo==3)
                    {
                        cantidadViento+=1;
                    }
                    else if(arrayInstrumento[posicionInstrumento].tipo==4)
                    {
                        cantidadPercusion+=1;
                    }
                }
            }
            if(cantidadPercusion>=1 && cantidadViento>=4 && cantidadCuerda>=4)
            {
                printf("\n ID: %d", array[i].idOrquesta);
                printf("\n tipoOrquesta: %d", array[i].tipoOrquesta);
                printf("\n nombre: %s", array[i].nombre);
                printf("\n lugar: %s\n", array[i].lugar);
            }
        }
    }
    return retorno;
}


/** \brief Lista orquesta/s con menos cantidad de musicos
* \param arrayOrquesta Array de orquesta
* \param lenOrquesta tamaño del array de orquesta
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_orquestaMenosMusicos(Orquesta arrayOrquesta[], int lenOrquesta, Musico arrayMusico[], int lenMusico)
{
    Orquesta auxOrquesta[lenOrquesta];
    int retorno=-1;
    int menorCantidadMusicos;
    int cantidadMusicos;
    int orquestasMismaCantidadMusicos=0;
    int i;
    int j;

    if(arrayOrquesta!=NULL && arrayMusico!=NULL && lenMusico>=0 && lenOrquesta>=0)
    {
        retorno=0;
        for(i=0; i<lenOrquesta; i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
            {
                continue;
            }
            cantidadMusicos=0;
            for(j=0; j<lenMusico; j++)
            {
                if (arrayMusico[j].isEmpty==1)
                {
                    continue;
                }
                if(arrayMusico[j].idOrquesta == arrayOrquesta[i].idOrquesta)
                {
                    cantidadMusicos+=1;
                }
            }
            if(i==0)
            {
                menorCantidadMusicos=cantidadMusicos;
                auxOrquesta[0]=arrayOrquesta[i];
                continue;
            }
            else if(cantidadMusicos==menorCantidadMusicos)
            {
                orquestasMismaCantidadMusicos+=1;
                auxOrquesta[orquestasMismaCantidadMusicos] = arrayOrquesta[i];
            }

            else if(cantidadMusicos<menorCantidadMusicos)
            {
                menorCantidadMusicos=cantidadMusicos;
                auxOrquesta[0]= arrayOrquesta[i];
                orquestasMismaCantidadMusicos=0;
            }
        }
        orquesta_listar(auxOrquesta, orquestasMismaCantidadMusicos+1);
        printf("\n Cantidad de musicos: %d", menorCantidadMusicos);
    }
    return retorno;
}


/** \brief Informa promedio de instrumentos por orquesta
* \param arrayOrquesta Array de orquesta
* \param lenOrquesta tamaño del array de orquesta
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_promedioInstrumentosPorOrquesta(Orquesta arrayOrquesta[], int lenOrquesta, Musico arrayMusico[], int lenMusico)
{
    int retorno=-1;
    int i;
    int j;
    int cantidadInstrumentos=0;
    int cantidadOrquestas=0;
    if(arrayMusico!=NULL && arrayOrquesta!=NULL && lenOrquesta>=0 && lenMusico>=0)
    {
        retorno=0;
        for(i=0; i<lenOrquesta; i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
            {
                continue;
            }
            cantidadOrquestas+=1;
        }

        for(j=0; j<lenMusico; j++)
        {
            if(arrayMusico[j].isEmpty==1)
            {
                continue;
            }
            cantidadInstrumentos+=1;
        }
        printf("\nCantidad instrumentos: %d", cantidadInstrumentos);
        printf("\nCantidad orquestas: %d", cantidadOrquestas);
        printf("\nEl promedio es: %.2f\n", (float)cantidadInstrumentos/cantidadOrquestas);

    }
    return retorno;
}


/** \brief Lista musicos sin instrumentos de viento
* \param arrayMusico Array de musico
* \param lenMusico Tamaño del arrayMusico
* \param arrayInstrumento array de instrumento
* \param lenInstrumento tamaño del arrayInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa exitosamente
*
*/
int informe_musicoSinInstrumentoViento(Musico arrayMusico[], int lenMusico, Instrumento arrayInstrumento[], int lenInstrumento)
{
    int retorno=-1;
    int i;
    int posicionInstrumento;
    if(arrayInstrumento!=NULL && arrayMusico!=NULL && lenInstrumento>=0 && lenMusico>=0)
    {
        musico_ordenarPorApellido(arrayMusico, lenMusico, 1);
        for(i=0; i<lenMusico; i++)
        {
            if(arrayMusico[i].isEmpty==1)
            {
                continue;
            }
            instrumento_buscarID(arrayInstrumento, lenInstrumento, arrayMusico[i].idInstrumento, &posicionInstrumento);
            if(arrayInstrumento[posicionInstrumento].tipo ==2 || arrayInstrumento[posicionInstrumento].tipo==3)
            {
                continue;
            }
            printf("\n Nombre musico: %s", arrayMusico[i].nombre);
            printf("\n Apellido musico: %s", arrayMusico[i].apellido);
            printf("\n Edad Musico: %d", arrayMusico[i].edad);
            printf("\n Nombre instrumento: %s", arrayInstrumento[posicionInstrumento].nombre);
            printf("\n Tipo instrumento: %d\n", arrayInstrumento[posicionInstrumento].tipo);
        }
        retorno=0;
    }
    return retorno;
}

