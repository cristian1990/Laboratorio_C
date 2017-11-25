#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

    #define LLAMADA_EMPTY 0
    #define LLAMADA_USED 1

    #define FALLA_3G 0
    #define FALLA_LTE 1
    #define FALLA_EQUIPO 2

    #define ENCURSO 0
    #define SOLUCIONADO 1
    #define NOSOLUCIONADO 2

    typedef struct
    {
        int idLlamada;
        int idAbonado;
        int motivo;
        int estado;
        int tiempo;
        int flagEstado;

    }sLlamada;

#endif // LLAMADA_H_INCLUDED

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int llamadas_init(sLlamada* pLlamadas, int length);

/** \brief Agrega a la lista de llamadas un nuevo elemento, fija el estado como "En curso"
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \param idLlamada int Id de la llamada
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int llamadas_open(sLlamada* pLlamadas, int length, int idAbonado, int motivo);

/** \brief Finaliza una llamada en curso
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \param idAbonado int Id del abonado que realiza la llamada
 * \param estado int Estado de la llamada
  * \param tiempo int Tiempo que insumio
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int llamadas_close(sLlamada* pLlamadas, int length, int idLlamada, int estado, int tiempo);


/** \brief Busca en la lista una llamada que coincida con el Id recibido
 *
 * \param sLlamadas* pLlamada Puntero al array de Llamadas
 * \param length int Longitud del array
 * \param idLlamada int Id de llamada buscado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro la llamada] - (0) si Ok
 *
 */
sLlamada* llamadas_find(sLlamada* pLlamadas, int length, int idLlamada);



