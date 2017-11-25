#include "ArrayList.h"

//Class for ...
typedef struct
{
    char date[11];
    char time[6];
    int issueId;
    int gravedad;
    char msg[65];
}Etickets;

//Metodos for class

/** \brief Genera un espacio en memoria para un dato de tipo Log
 *
 * \param void
 * \return Puntero a Log
 *
 */
Etickets* __newTickets();

/** \brief Genera un objeto cargado con los datos de un archivo
 *
 * \param Puntero a lista
 * \return retorna cero (0) si todo es OK
 *                 menos uno (-1) si ocurrio un error
 *
 */
int tickets_cargarDatos(ArrayList* pList);

/** \brief Imprime en pantalla el contenido del objeto
 *
 * \param Puntero a lista
 * \return void
 *
 */
void tickets_imprimirDatos(ArrayList* pList);

/** \brief Procesa las dos listas
 *
 * \param Lista de logs
 * \param Lista de servicios
 * \return retorna cero (0) si todo es OK
 *                 menos uno (-1) si ocurrio un error
 */
int procesarInformacion(ArrayList* pList, ArrayList* pIssue);

/** \brief Genera o el archivo warnings.txt o errors.txt
 *
 * \param Puntero a un objeto log
 * \param Lista de services
 * \param Tipo de archivo uno(1) genera warnings.txt
 *                        dos(2) genera errors.txt
 * \return retorna cero (0) si todo es OK
 *                 menos uno (-1) si ocurrio un error
 */
int crearArchivos(Etickets* ticket, ArrayList* pList, int type);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int issue_contador(ArrayList* pIssue, int id);

int controlarDatos(ArrayList* pTickets, ArrayList* pIssue, int min, int max);

