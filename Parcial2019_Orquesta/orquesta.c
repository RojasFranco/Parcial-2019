#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)                                    //cambiar orquesta
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipoOrquesta==valorBuscado)                                                   //cambiar campo tipoOrquesta
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)                          //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int auxTipoOrquesta;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)                          //cambiar orquesta
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            if(!utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre))
            {
                if(!utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar))
                {
                    if(!utn_getUnsignedInt("\nTipo\n1-Sinfonica\n2-Filarmonica\n3-Camara\nOpcion: ","\nError",1,sizeof(int),1,10,1,&auxTipoOrquesta))
                    {
                        printf("%d", auxTipoOrquesta);
                        if(auxTipoOrquesta>=1 && auxTipoOrquesta<=3)
                        {
                            array[posicion].tipoOrquesta=auxTipoOrquesta;
                            (*contadorID)++;
                            array[posicion].idOrquesta=*contadorID;
                            array[posicion].isEmpty=0;
                            retorno=0;
                            printf("\nAlta correcta - ID: %d \n", array[posicion].idOrquesta);
                        }
                        else
                        {
                            printf("\nTipo de orquesta invalida\n");
                        }

                    }
                }
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;
    orquesta_listar(array, sizeArray);
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            /*array[posicion].idOrquesta=0;                                                                   //cambiar campo id
            array[posicion].tipoOrquesta=0;                                                               //cambiar campo tipoOrquesta

            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].lugar,"");*/
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idOrquesta=0;                                                                   //cambiar campo id
                array[i].tipoOrquesta=0;                                                               //cambiar campo tipoOrquesta

                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].lugar,"");                                               //cambiar campo lugar
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int sizeArray)                                //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipoOrquesta: %d\nnombre: %s\n lugar: %s",
                   posicion, array[posicion].idOrquesta,array[posicion].tipoOrquesta,array[posicion].nombre,array[posicion].lugar);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipoOrquesta);           //mensaje + cambiar campo tipoOrquesta
                        break;
                    case 'B':
                        ///utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);             //mensaje + cambiar campo lugar
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond)                              //cambiar orquesta
{
    int retorno=-1;
    int i;
    Orquesta buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                /*else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }*/
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n tipoOrquesta: %d\nnombre: %s\n lugar: %s",
                   i, array[i].idOrquesta,array[i].tipoOrquesta,array[i].nombre,array[i].lugar);     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}



