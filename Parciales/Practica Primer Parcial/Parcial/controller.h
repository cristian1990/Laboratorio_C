#include "abonado.h"
#include "llamada.h"

#ifndef CONTROLER_H_INCLUDED
#define CONTROLER_H_INCLUDED


#endif // CONTROLER_H_INCLUDED


/** \brief Carga datos de prueba tanto en el array de abonados como en el de llamadas
 * \param void
 * \return void
 */
void controller_mock(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado);


/** \brief Pide al usuario los datos de un nuevo abonado y luego lo agrega al array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int controller_altaAbonado(sAbonado* pAbonados, int length);


/** \brief Pide al usuario el ID, Nombre y Apellido  de un abonado a ser modificadolos luego los modifica
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_modificarAbonado(sAbonado* pAbonados, int length);


/** \brief Pide al usuario el ID de un abonado a ser dado de baja
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_bajaAbonado(sAbonado* pAbonados, int length);


/** \brief Registra una nueva llamada - Pide al usuario el ID del Abonado y el Motivo de la llamada
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param lengthAbonado int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_nuevaLlamada(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado);


/** \brief Cierra una llamada en curso - Pide al usuario el ID de la llamada
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_cerrarLlamada(sLlamada* pLlamadas, int length);


/** \brief Recorre el array de abonados y los muestra por pantalla
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarAbonados(sAbonado* pAbonados, int length);


/** \brief Recorre el array de llamadas y las muestra por pantalla
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarLlamadas(sLlamada* pLlamadas, int length);


/** \brief Informa los abonados con mas reclamos
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param lengthAbonado int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    ( 0) si Ok
 */
int controller_informeAbonadosConMasReclamos(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado);


/** \brief Informa el/los reclamos con mayor tiempo promedio de atencion (Solo reclamos finalizados)
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    ( 0) si Ok
 */
int controller_informeReclamosTiempos(sLlamada* pLlamadas, int lengthLlamada);
