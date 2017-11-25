#include "ArrayList.h"

typedef struct
{
    int id;
    char name[33];
    char email[65];
}Eissue;

/** \brief Genera un espacio en memoria para un dato de tipo Services
 *
 * \param void
 * \return Puntero a Services
 *
 */
Eissue* __newIssue();

/** \brief Genera un objeto cargado con los datos de un archivo
 *
 * \param Puntero a lista
 * \param Nombre del archivo a cargar
 * \return retorna cero (0) si todo es OK
                   menos uno (-1) si ocurrio un error
 *
 */
int issue_cargarDatos(ArrayList* pList);

/** \brief Imprime en pantalla el contenido del objeto
 *
 * \param Puntero a lista
 * \return void
 *
 */
void issue_imprimirDatos(ArrayList* pList);



