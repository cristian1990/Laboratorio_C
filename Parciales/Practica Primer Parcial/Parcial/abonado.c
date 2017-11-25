#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"

static int abonados_findEmptyPlace(sAbonado* pAbonados, int length);
static int abonados_findNextId(sAbonado* pAbonados, int length);

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int abonados_init(sAbonado* pAbonados, int length)
{
    int i;
    int retorno=-1;
    if(pAbonados != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pAbonados+i)->flagEstado = ABONADO_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Agrega a la lista de abonados un nuevo elemento, el id no lo recibe lo calcula
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param numero int Numero del abonado
 * \param nombre[] char Nombre del abonado
 * \param apellido[] char
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int abonados_append(sAbonado* pAbonados, int length, int numero, char nombre[],char apellido[])
{

    int retorno=-1;
    int id,index;
    if(pAbonados != NULL && length > 0)
    {
        index = abonados_findEmptyPlace(pAbonados, length);
        if(index != -1)
        {
            id = abonados_findNextId(pAbonados, length);
            strcpy((pAbonados+index)->nombre,nombre);
            strcpy((pAbonados+index)->apellido,apellido);
            (pAbonados+index)->numero = numero;
            (pAbonados+index)->idAbonado = id;
            (pAbonados+index)->flagEstado = ABONADO_USED;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca en la lista un abonado que coincida con el Id recibido
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
sAbonado* abonados_find(sAbonado* pAbonados, int length, int idAbonado)
{
    sAbonado* pRetorno = NULL;
    int i;
    if(pAbonados != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAbonados+i)->idAbonado == idAbonado && (pAbonados+i)->flagEstado == ABONADO_USED)
            {
                pRetorno = (pAbonados+i);
                break;
            }
        }
    }
    return pRetorno;
}


/** \brief Elimina de manera logica un abonado de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 *
 */
int abonados_remove(sAbonado* pAbonados, int length, int idAbonado)
{
    sAbonado* pAuxAbonado;
    int retorno = -1;

    pAuxAbonado = abonados_find(pAbonados, length, idAbonado);
    if(pAuxAbonado != NULL)
    {
        pAuxAbonado->flagEstado = ABONADO_DELETE;
        retorno = 0;
    }

    return retorno;
}


/** \brief Modifica el nombre y el apellido de un abonado existente
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \param nombre int Nombre del abonado
 * \param apellido int Apellido del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o si la longitud del nombre/apellido es < 1] - (0) si Ok
 *
 */
int abonados_update(sAbonado* pAbonados, int length, int idAbonado, char* nombre, char* apellido)
{
    int retorno=-1;
    sAbonado* pAuxAbonado;

    if(pAbonados != NULL && length > 0)
    {
        pAuxAbonado = abonados_find(pAbonados, length,idAbonado);
        if(pAuxAbonado != NULL)
        {
            strcpy(pAuxAbonado->nombre,nombre);
            strcpy(pAuxAbonado->apellido,apellido);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Busca en el array la primer posicion libre
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
static int abonados_findEmptyPlace(sAbonado* pAbonados, int length)
{
    int i;
    int retorno=-1;
    if(pAbonados != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAbonados+i)->flagEstado == ABONADO_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
static int abonados_findNextId(sAbonado* pAbonados, int length)
{
    int i, maxId=-1;
    int retorno=-1;
    if(pAbonados != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAbonados+i)->flagEstado == ABONADO_USED || (pAbonados+i)->flagEstado == ABONADO_DELETE)
            {
                if((pAbonados+i)->idAbonado > maxId || maxId == -1)
                    maxId = (pAbonados+i)->idAbonado;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
