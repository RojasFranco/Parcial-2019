#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \param posicion int* Puntero a la posicion del array donde se encuentra el segundo valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, char* segundoValorBuscado, int* indice)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0 && strcmp(array[i].apellido, segundoValorBuscado)==0)                                        //cambiar campo nombre
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int lenOrquesta, Instrumento arrayInstrumento[], int lenInstrumento)
{
    int retorno=-1;
    char auxNombre[20];
    char auxApellido[20];
    int posicion;
    int auxIdOrquesta;
    int auxIdInstrumento;
    int posicionIdOrquesta;
    int posicionValorBuscado;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            orquesta_listar(arrayOrquesta, lenOrquesta);
            if(!utn_getUnsignedInt("\nIngrese id de orquesta:", "Error\n", 1, sizeof(int), 1,10, 2, &auxIdOrquesta))
            {
                if(!orquesta_buscarID(arrayOrquesta, lenOrquesta, auxIdOrquesta, &posicionIdOrquesta))
                {
                    array[posicion].idOrquesta = auxIdOrquesta;
                    printf("\n\n%d\n\n",posicionIdOrquesta);
                    instrumento_listar(arrayInstrumento, lenInstrumento);
                    if( (!utn_getUnsignedInt("\nIngrese id de instrumento:", "Error\n", 1, sizeof(int), 1,10, 2, &auxIdInstrumento)) && (!instrumento_buscarID(arrayInstrumento, lenInstrumento, auxIdInstrumento, &array[posicion].idInstrumento)))
                    {
                        if( (!utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,auxNombre)) && (!utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,auxApellido)))
                        {
                            if(!utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),1,10,1,&array[posicion].edad))
                            {

                                if(!musico_buscarString(array, size, auxNombre, auxApellido, &posicionValorBuscado))
                                {
                                    printf("\nEl musico ya pertenece a una orquesta\n");
                                }
                                else
                                {
                                    (*contadorID)++;
                                    array[posicion].idMusico=*contadorID;
                                    array[posicion].isEmpty=0;
                                    strncpy(array[posicion].nombre, auxNombre, TEXT_SIZE);
                                    strncpy(array[posicion].apellido, auxApellido, TEXT_SIZE);
                                    retorno=0;
                                }
                            }
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array, sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {

            array[posicion].isEmpty=1;
            /*array[posicion].idMusico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo edad

            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;*/
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo edad

                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[], int lenOrquesta)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    int auxIdOrquesta;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array, sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n ID musico: %d\nnombre: %s\n apellido: %s",
                   array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido);
                utn_getChar("\nModificar: A- Edad\nB-Id Orquesta\nS(salir)\nOpcion:","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nNueva edad: ","\nError",1,sizeof(int),1,10,1,&array[posicion].edad);
                        break;
                    case 'B':
                        orquesta_listar(arrayOrquesta, lenOrquesta);
                        utn_getUnsignedInt("\nId nueva orquesta:","\n Error", 1, sizeof(int), 1, 10,1, &auxIdOrquesta);
                        //printf("\n\nID:%d\n\n", auxIdOrquesta);
                        if(!orquesta_buscarID(arrayOrquesta, lenOrquesta, auxIdOrquesta, &array[posicion].idOrquesta))
                        {
                            printf("\nSe modifico id exitoxamente\n");
                        }
                        else
                        {
                            printf("\n No se encontro id\n");
                        }
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorDobleCriterio(Musico array[],int size, int orderFirst, int orderSecond)                              //cambiar musico
{
    int retorno=-1;
    int i;
    Musico buffer;
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
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
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n",
                   i, array[i].idMusico,array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}


int musico_imprimir(Musico array[], int size, Instrumento arrayInstrumento[], int lenInstrumento)
{
    int retorno=-1;
    int i;
    int posicionInstrumento;
    char tipoInstrumentoTexto[15];
    if(array!=NULL && size>=1 && arrayInstrumento!=NULL && lenInstrumento>=1)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                instrumento_buscarID(arrayInstrumento, lenInstrumento, array[i].idInstrumento, &posicionInstrumento);
                instrumento_tipoEnTexto(arrayInstrumento[posicionInstrumento].tipo, tipoInstrumentoTexto);
                printf("ID:%d \n Nombre musico:%s \n Apellido musico:%s \n nombre instrumento: %s \nTipo instrumento: %d (%s)\n",
                    array[i].idMusico, array[i].nombre, array[i].apellido, arrayInstrumento[posicionInstrumento].nombre, arrayInstrumento[posicionInstrumento].tipo, tipoInstrumentoTexto);
            }
        }
        retorno=0;
    }
    return retorno;
}

