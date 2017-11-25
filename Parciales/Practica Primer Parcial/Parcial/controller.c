#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "abonado.h"
#include "llamada.h"

#define CANTIDAD_TIPOS_RECLAMO 3
#define RECLAMOS 50

static char motivoLlamada[3][15] = {"FALLA 3G","FALLA LTE","FALLA EQUIPO"};
static char estadoLlamada[3][15] = {"EN CURSO","SOLUCIONADO","NO SOLUCIONADO"};

/** \brief Carga datos de prueba tanto en el array de abonados como en el de llamadas
 * \param void
 * \return void
 */
void controller_mock(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado)
{
    abonados_append(pAbonados,lengthAbonado, 2226465,"JUAN", "PEREZ");
    abonados_append(pAbonados,lengthAbonado, 2226466,"LUCAS", "GONZALES");
    abonados_append(pAbonados,lengthAbonado, 2226467,"PEDRO", "LOPEZ");

    llamadas_open(pLlamadas, lengthLlamada, 0, FALLA_3G);
    llamadas_open(pLlamadas, lengthLlamada, 0, FALLA_LTE);
    llamadas_open(pLlamadas, lengthLlamada, 1, FALLA_EQUIPO);
    llamadas_open(pLlamadas, lengthLlamada, 1, FALLA_EQUIPO);
    llamadas_open(pLlamadas, lengthLlamada, 2, FALLA_EQUIPO);

    llamadas_close(pLlamadas, lengthLlamada,0, SOLUCIONADO, 1000);
    llamadas_close(pLlamadas, lengthLlamada,1, SOLUCIONADO, 100);
    llamadas_close(pLlamadas, lengthLlamada,2, SOLUCIONADO, 200);
    llamadas_close(pLlamadas, lengthLlamada,3, SOLUCIONADO, 100);
    llamadas_close(pLlamadas, lengthLlamada,4, NOSOLUCIONADO, 90);
}


/** \brief Pide al usuario los datos de un nuevo abonado y luego lo agrega al array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int controller_altaAbonado(sAbonado* pAbonados, int length)
{
    char nombre[50];
    char apellido[50];
    int numero;
    int retorno=-1;

    system("clear");
    retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 50", nombre,50,3);
    if(retorno == 0)
    {
        retorno = getValidString("\nApellido: ","\nNo es un apellido valido","\nLongitud maxima 50", apellido,50,3);
        if(retorno == 0)
        {
            retorno = getValidInt("\nNumero: ","\nRango valido 100000 - 10000000", &numero,100000,10000000,3);
            if(retorno == 0)
            {
                retorno = abonados_append(pAbonados, length, numero, nombre, apellido);
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario el ID, Nombre y Apellido  de un abonado a ser modificadolos luego los modifica
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_modificarAbonado(sAbonado* pAbonados, int length)
{
    char nombre[50];
    char apellido[50];
    int id;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID a Modificar: ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(abonados_find(pAbonados, length, id) == NULL)
        {
            printf("El abonado elegido no existe\n");
            pause();

        }
        else
        {
            retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 50", nombre,50,3);
            if(retorno == 0)
            {
                retorno = getValidString("\nApellido: ","\nNo es un apellido valido","\nLongitud maxima 50", apellido,50,3);
                if(retorno == 0)
                {
                    retorno = abonados_update(pAbonados, length, id, nombre, apellido);
                }
            }
        }
    }
    return retorno;
}


/** \brief Pide al usuario el ID de un abonado a ser dado de baja
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_bajaAbonado(sAbonado* pAbonados, int length)
{
    int id;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID a dar de Baja: ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(abonados_find(pAbonados, length, id) == NULL)
        {
            printf("El abonado elegido no existe\n");
            pause();
        }
        else
        {
            retorno = abonados_remove(pAbonados, length, id);
        }
    }
    return retorno;
}


/** \brief Registra una nueva llamada - Pide al usuario el ID del Abonado y el Motivo de la llamada
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param lengthAbonado int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_nuevaLlamada(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado)
{
    int id, motivo;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID del Abonado ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(abonados_find(pAbonados, lengthAbonado, id) == NULL)
        {
            printf("El abonado elegido no existe\n");
            pause();

        }
        else
        {
            retorno = getValidInt("\nMotivo:\n  Falla 3g [0]\n  Falla LTE [1]\n  Falla Equipo [2]\n Opcion:  ","\nRango valido 0-2", &motivo,0,2,3);
            if(retorno == 0)
            {
                llamadas_open(pLlamadas, lengthLlamada,id, motivo);
            }
        }
    }
    return retorno;
}


/** \brief Cierra una llamada en curso - Pide al usuario el ID de la llamada
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_cerrarLlamada(sLlamada* pLlamadas, int length)
{
    int id, tiempo,estado;
    sLlamada* pAuxLlamada;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID de la llamada ","\nRango valido 0-9999", &id,0,9999,3);

    if(retorno == 0)
    {
        pAuxLlamada = llamadas_find(pLlamadas, length, id);
        if(pAuxLlamada == NULL)
        {
            printf("La llamada no existe\n");
            pause();

        }
        else if(pAuxLlamada->estado != ENCURSO)
        {
            printf("Solo se pueden finalizar llamadas en curso\n");
            pause();
        }
        else
        {
            retorno = getValidInt("\nTiempo insumido [minutos] :","\nRango valido 0-600", &tiempo,0,600,3);
            if(retorno == 0)
            {
                retorno = getValidInt("\nEstado de Cierre:\n  Resuelto [1]\n  No Resuelto [2]\n\n Opcion:  ","\nRango valido 1-2", &estado,0,1,3);
                if(retorno == 0)
                {
                    llamadas_close(pLlamadas, length,id, estado, tiempo);
                }
            }
        }
    }
    return retorno;
}


/** \brief Recorre el array de abonados y los muestra por pantalla
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarAbonados(sAbonado* pAbonados, int length)
{
    int retorno=-1,i;
    if(pAbonados != NULL && length > 0)
    {
        clearScreen();
        printf("\n\n%4s - %-20s - %-20s - %-8s\n"," ID","    NOMBRE","    APELLIDO","   NUMERO");
        for(i=0;i<length;i++)
        {
            if((pAbonados+i)->flagEstado == ABONADO_USED)
                printf("%4d - %-20s - %-20s - %-8d\n",(pAbonados+i)->idAbonado,(pAbonados+i)->nombre,(pAbonados+i)->apellido,(pAbonados+i)->numero);
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Recorre el array de llamadas y las muestra por pantalla
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarLlamadas(sLlamada* pLlamadas, int length)
{
    int retorno=-1,i;
    if(pLlamadas != NULL && length > 0)
    {
        clearScreen();
        printf("\n\n%4s - %8s - %-12s - %-12s- %8s\n"," ID","  ID AB","MOTIVO","ESTADO","TIEMPO");
        for(i=0;i<length;i++)
        {
            if((pLlamadas+i)->flagEstado == LLAMADA_USED)
                printf("%4d - %8d - %-12s - %-12s - %8d\n",(pLlamadas+i)->idLlamada,(pLlamadas+i)->idAbonado,motivoLlamada[(pLlamadas+i)->motivo],estadoLlamada[(pLlamadas+i)->estado],(pLlamadas+i)->tiempo);
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Informa los abonados con mas reclamos
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param lengthAbonado int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    ( 0) si Ok
 */
int controller_informeAbonadosConMasReclamos(sLlamada* pLlamadas, int lengthLlamada ,sAbonado* pAbonados, int lengthAbonado)
{
    int retorno=-1,i, maximoReclamo=0;
    int reclamosArray[RECLAMOS]; // Uso el indice para el id de Abonado y el valor como acumulador de reclamos
    sAbonado* auxAbonado;

    for(i=0;i<RECLAMOS;i++)
    {
        reclamosArray[i] = 0;
    }

    if(pLlamadas != NULL && lengthLlamada > 0 && pAbonados != NULL && lengthAbonado > 0)
    {
        clearScreen();
        for(i=0;i<lengthLlamada;i++)
        {
            if((pLlamadas+i)->flagEstado == LLAMADA_USED)
            {
                reclamosArray[(pLlamadas+i)->idAbonado]++;
            }
        }
        for(i=0;i<RECLAMOS;i++)
        {
            if(reclamosArray[i] > maximoReclamo)
            {
                maximoReclamo = reclamosArray[i];
            }
        }
        printf("*************************************************************\n");
        printf("**************** ABONADOS CON MAS RECLAMOS ******************\n");
        printf("*************************************************************\n");
        for(i=0;i<RECLAMOS;i++)
        {
            if(reclamosArray[i] == maximoReclamo)
            {
                auxAbonado = abonados_find(pAbonados, lengthAbonado, i);
                printf("NOMBRE: %-14s  APELLIDO: %-14s  RECLAMOS:%2d\n",auxAbonado->nombre,auxAbonado->apellido,maximoReclamo);
                printf("*************************************************************\n");
            }
        }
        printf("*************************************************************\n");
        pause();

        retorno = 0;
    }
    return retorno;

}


/** \brief Informa el/los reclamos con mayor tiempo promedio de atencion (Solo reclamos finalizados)
 * \param sLlamada* pLlamadas Puntero al array de llamadas
 * \param lengthLlamada int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    ( 0) si Ok
 */
int controller_informeReclamosTiempos(sLlamada* pLlamadas, int lengthLlamada)
{
    int retorno=-1,i, maximoReclamo,maximoTiempoPromedioReclamo;
    int reclamosOcurrencia[CANTIDAD_TIPOS_RECLAMO];
    int reclamosTiempoAcumulado[CANTIDAD_TIPOS_RECLAMO]; // Uso el indice segun tipo de reclamo
    float reclamosTiempoPromedio[CANTIDAD_TIPOS_RECLAMO];

    for(i=0;i<CANTIDAD_TIPOS_RECLAMO;i++)
    {
        reclamosOcurrencia[i] = 0;
        reclamosTiempoAcumulado[i] = 0;
        reclamosTiempoPromedio[i] = 0;
    }

    if(pLlamadas != NULL && lengthLlamada > 0)
    {
        clearScreen();
        for(i=0;i<lengthLlamada;i++)
        {
            if( ((pLlamadas+i)->flagEstado == LLAMADA_USED) && (((pLlamadas+i)->estado) == SOLUCIONADO || ((pLlamadas+i)->estado) == NOSOLUCIONADO))
            {
                reclamosOcurrencia[(pLlamadas+i)->motivo]++;
                reclamosTiempoAcumulado[(pLlamadas+i)->motivo] = reclamosTiempoAcumulado[(pLlamadas+i)->motivo] + (pLlamadas+i)->tiempo;
            }
        }
        printf("*************************************************************\n");
        printf("**************** SOLO RECLAMOS FINALIZADOS ******************\n");
        printf("*************************************************************\n");
        printf("%15s - %8s - %8s- %11s\n","Tipo Reclamo","Cantidad", "Tiempo", "Promedio");
        maximoReclamo = 0;
        maximoTiempoPromedioReclamo = 0;
        for(i=0;i<CANTIDAD_TIPOS_RECLAMO;i++)
        {
            reclamosTiempoPromedio[i] = (float)reclamosTiempoAcumulado[i] / (float)reclamosOcurrencia[i];
            if(reclamosTiempoPromedio[i] > reclamosTiempoPromedio[maximoTiempoPromedioReclamo]) maximoTiempoPromedioReclamo = i;
            if(reclamosOcurrencia[i] > reclamosOcurrencia [maximoReclamo]) maximoReclamo = i;
            printf("%15s - %8d - %8d - %8.2f\n",motivoLlamada[i],reclamosOcurrencia[i],reclamosTiempoAcumulado[i],reclamosTiempoPromedio[i]);
        }
        printf("\nReclamo con mayor ocurrencia: %s\n",motivoLlamada[maximoReclamo]);
        printf("Reclamo que mas demora en ser atendido: %s\n",motivoLlamada[maximoTiempoPromedioReclamo]);
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        pause();

        retorno = 0;
    }
    return retorno;

}
