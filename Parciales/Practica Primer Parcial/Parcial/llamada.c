#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"


static int llamadas_findEmptyPlace(sLlamada* pLlamadas, int length);
static int llamadas_findNextId(sLlamada* pLlamadas, int length);


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int llamadas_init(sLlamada* pLlamadas, int length)
{
    int i;
    int retorno=-1;
    if(pLlamadas != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pLlamadas+i)->flagEstado = LLAMADA_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Agrega a la lista de llamadas un nuevo elemento, fija el estado como "En curso"
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \param idAbonado int Id del abonado
 * \param motivo int El motivo de la llamada
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int llamadas_open(sLlamada* pLlamadas, int length, int idAbonado, int motivo)
{

    int retorno=-1;
    int id,index;
    if(pLlamadas != NULL && length > 0)
    {
        index = llamadas_findEmptyPlace(pLlamadas, length);
        if(index != -1)
        {
            id = llamadas_findNextId(pLlamadas, length);
            (pLlamadas+index)->estado = ENCURSO;
            (pLlamadas+index)->idLlamada = id;
            (pLlamadas+index)->idAbonado = idAbonado;
            (pLlamadas+index)->motivo = motivo;
            (pLlamadas+index)->tiempo = 0;
            (pLlamadas+index)->flagEstado = LLAMADA_USED;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca en la lista una llamada que coincida con el Id recibido
 *
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \param idLlamada int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro la llamada] - (0) si Ok
 *
 */
sLlamada* llamadas_find(sLlamada* pLlamadas, int length, int idLlamada)
{
    sLlamada* pRetorno = NULL;
    int i;
    if(pLlamadas != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pLlamadas+i)->idLlamada == idLlamada && (pLlamadas+i)->flagEstado == LLAMADA_USED)
            {
                pRetorno = (pLlamadas+i);
                break;
            }
        }
    }
    return pRetorno;
}


/** \brief Finaliza una llamada en curso
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \param idAbonado int Id del abonado que realiza la llamada
 * \param estado int Estado de la llamada
  * \param tiempo int Tiempo que insumio
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int llamadas_close(sLlamada* pLlamadas, int length, int idLlamada, int estado, int tiempo)
{
    int retorno=-1;
    sLlamada* pAuxLlamada;

    if(pLlamadas != NULL && length > 0)
    {
        pAuxLlamada = llamadas_find(pLlamadas, length,idLlamada);
        if(pAuxLlamada != NULL)
        {
            pAuxLlamada->estado = estado;
            pAuxLlamada->tiempo = tiempo;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief  Busca en el array la primer posicion libre
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
static int llamadas_findEmptyPlace(sLlamada* pLlamadas, int length)
{
    int i;
    int retorno=-1;
    if(pLlamadas != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pLlamadas+i)->flagEstado == LLAMADA_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


/** \brief  Busca en el array el id mas alto entre los usados
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
static int llamadas_findNextId(sLlamada* pLlamadas, int length)
{
    int i, maxId=-1;
    int retorno=-1;
    if(pLlamadas != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pLlamadas+i)->flagEstado == LLAMADA_USED )
            {
                if((pLlamadas+i)->idLlamada > maxId || maxId == -1)
                    maxId = (pLlamadas+i)->idLlamada;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}

