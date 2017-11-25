#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#include "utn.h"

  /**
 * \brief inicializa el estado en un array de autos
 * \param autoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */
void establecerEstadoAuto(Autos autoArray[],int largoArray, int valor)
{
    int i;
    for(i=0; i<largoArray; i++)
    {
        autoArray[i].estado = valor;
    }
}

  /**
 * \brief inicializa el estado en un array de estacionamiento
 * \param estacionamientoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */
void establecerEstadoEstacionamiento(Estacionamiento estacionamientoArray[],int largoArray,int valor)
{
    int i;
    for(i=0; i<largoArray; i++)
    {
        estacionamientoArray[i].estado = valor;
    }
}

  /**
 * \brief inicializa el estado en un array de autos
 * \param autoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */

 void establecerValoresAuto(Autos autoArray[], int indiceLugarLibre, char patenteAux[], char marcaAux[], char modeloAux[], int idProfAux)
 {
     strcpy(autoArray[indiceLugarLibre].patente,patenteAux);
     strcpy(autoArray[indiceLugarLibre].marca,marcaAux);
     strcpy(autoArray[indiceLugarLibre].modelo,modeloAux);
     autoArray[indiceLugarLibre].idProfesor = idProfAux;
     autoArray[indiceLugarLibre].estado = 1;
     autoArray[indiceLugarLibre].estadoEst = 0;
 }



  /**
 * \brief cargar los valores del estacionamiento
 * \param estacionamientoArray Es el array del estacionamiento
 * \param IndiceLugarLibre Indica la posicion a setear
 * \param idProf Codigo del profesor
 * \param idprofAux Id del profesor
 * \return -
 *
 */
 void establecerValoresEstacionamiento(Estacionamiento estacionamientoArray[], int indiceLugarLibre, int idProfAux)
 {
     estacionamientoArray[indiceLugarLibre].idProfesor = idProfAux;
     estacionamientoArray[indiceLugarLibre].estado = 1;
 }


     /**
 * \brief buscar la primer ocurrencia de un auto mediante su id
 * \param estacionamientoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
 int encontrarprofesorPorId(Estacionamiento estacionamientoArray[],int largoArray, int idProf)
 {
     int i;
     for(i=0; i<largoArray; i++)
     {
         if(estacionamientoArray[i].idProfesor == idProf && estacionamientoArray[i].estado == 1)
         {
             return i;
         }
     }
     return -1;
 }


    /**
 * \brief buscar la primer ocurrencia de un profesor mediante su id
 * \param autoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
 int encontrarAutoPorId(Autos autoArray[],int largoArray, int idProf)
 {
     int i;
     for(i=0; i<largoArray; i++)
     {
         if(autoArray[i].idProfesor == idProf && autoArray[i].estado == 1)
         {
             return i;
         }
     }
     return -1;
 }

     /**
 * \brief buscar el primer lugar no utilizado en el array
 * \param estacionamientoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
 int encontrarLugarVacioEstacionamiento(Estacionamiento estacionamientoArray[],int largoArray)
 {
    int i;
    for(i=0; i<largoArray; i++)
    {
        if(estacionamientoArray[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
 }


    /**
 * \brief buscar el primer lugar no utilizado en el array
 * \param autoArray Es el array en el cual buscar
 * \param largoArray Indica la longitud del array
 * \param value Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
 int encontrarLugarVacioAuto(Autos autoArray[],int largoArray)
 {
    int i;
    for(i=0; i<largoArray; i++)
    {
        if(autoArray[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
 }


  /**
 * \brief Muestra los autos activos por pantalla
 * \param autoArray Es el array de autos
 * \param largoArray Indica la longitud del array
 * \return -
 *
 */
 void mostrarArrayAuto(Autos autoArray[], int largoArray)
 {
     int i;
     printf("\n| PATENTE |      MARCA      |    MODELO   | ID PROFESOR |");
     for(i=0; i<largoArray; i++)
     {
         if(autoArray[i].estado != 0)
         {
             printf("\n| %6s | %-15s | %11s | %11i |",autoArray[i].patente, autoArray[i].marca, autoArray[i].modelo, autoArray[i].idProfesor);
         }
     }
 }


   /**
 * \brief Muestra los autos activos por pantalla
 * \param autoArray Es el array de autos
 * \param largoArray Indica la longitud del array
 * \return -
 *
 */
 void mostrarArrayEstacionamiento(Estacionamiento estacionamientoArray[], int largoArray)
 {
     int i;
     printf("\n| ID PROFESOR |");
     for(i=0; i<largoArray; i++)
     {
         if(estacionamientoArray[i].estado != 0)
         {
             printf("\n| %18i |",estacionamientoArray[i].idProfesor);
         }
     }
 }

 void ordenarAutoArrayPorMarca(Autos autoArray[],int largoArray)
 {
     Autos autoAux;
     int i,j;

     for(i=0; i<CANT_AUTO-1; i++)
     {
         if(autoArray[i].estado == 0)
         {
             continue;
         }
         for(j=i+1; j<CANT_AUTO; j++)
         {
             if(autoArray[j].estado == 0)
             {
                 continue;
             }
             if(strcmp(autoArray[j].marca,autoArray[i].marca)<0)
             {
                 autoAux = autoArray[j];
                 autoArray[j] = autoArray[i];
                 autoArray[i] = autoAux;
             }
             else if(strcmp(autoArray[j].marca , autoArray[i].marca) == 0)
             {
                     if(autoArray[j].estado == 0)
                     {
                        continue;
                     }
                     if(strcmp(autoArray[j].patente,autoArray[i].patente)<0)
                     {
                         autoAux = autoArray[j];
                         autoArray[j] = autoArray[i];
                         autoArray[i] = autoAux;
                     }
                 //ORDENA POR ID PROFESOR ANTE IGUALDAD
                   /*
                 if(autoArray[i].idProfesor > autoArray[j].idProfesor)
                 {
                     autoAux = autoArray[j];
                     autoArray[j] = autoArray[i];
                     autoArray[i] = autoAux;
                 }
                 */
                 //
             }
         }
     }
 }


