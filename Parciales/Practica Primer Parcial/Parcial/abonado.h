#ifndef ABONADO_H_INCLUDED
#define ABONADO_H_INCLUDED

    #define ABONADO_EMPTY 0
    #define ABONADO_USED 1
    #define ABONADO_DELETE 2

    typedef struct
    {
        unsigned int idAbonado;
        unsigned int numero;
        char nombre[50];
        char apellido[50];
        int flagEstado;

    }sAbonado;

#endif //ABONADO_H_INCLUDED

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int abonados_init(sAbonado* pAbonados, int length);

/** \brief Agrega a la lista de abonados un nuevo elemento, el id no lo recibe lo calcula
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param numero int Numero del abonado
 * \param nombre[] char Nombre del abonado
 * \param apellido[] char
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int abonados_append(sAbonado* pAbonados, int length, int numero, char nombre[],char apellido[]);


/** \brief Busca en la lista un abonado que coincida con el Id recibido
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
sAbonado* abonados_find(sAbonado* pAbonados, int length, int idAbonado);


/** \brief Elimina de manera logica un abonado de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
int abonados_remove(sAbonado* pAbonados, int length, int idAbonado);


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
int abonados_update(sAbonado* pAbonados, int length, int idAbonado, char* nombre, char* apellido);


