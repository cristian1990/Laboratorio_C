#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "controller.h"

#define ABONADOS_CANTIDAD 10
#define LLAMADAS_CANTIDAD 100

int main()
{
    int menuOpcionElegida;
    char menuPrinsipalMensaje[] =
                "\n1-Alta de Abonado\
                 \n2-Modificar datos del Abonado\
                 \n3-Baja del Abonado\
                 \n4-Nueva Llamada\
                 \n5-Fin de Llamada\
                 \n6-Informar\
                 \n7-Listar Llamadas\
                 \n8-Listar Abonados\
                 \n9-Salir\n\
                 \nIngrese opcion: ";
    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 9";

    //Se crea el array de abonados y se inicializa
    sAbonado arrayAbonados[ABONADOS_CANTIDAD];
    abonados_init(arrayAbonados,ABONADOS_CANTIDAD);

    //Se crea el array de Llamadas y se inicializa
    sLlamada arrayLlamadas[LLAMADAS_CANTIDAD];
    llamadas_init(arrayLlamadas,LLAMADAS_CANTIDAD);

    // Carga datos de test
    controller_mock(arrayLlamadas, LLAMADAS_CANTIDAD,arrayAbonados,ABONADOS_CANTIDAD);

    do
    {
        clearScreen();
        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 9 , 2 );

        switch(menuOpcionElegida)
        {
        case 1: // ALTA ABONADO
            controller_altaAbonado(arrayAbonados,ABONADOS_CANTIDAD);
            break;
        case 2: // MODIFICAR ABONADO
            controller_modificarAbonado(arrayAbonados,ABONADOS_CANTIDAD);
            break;
        case 3: // BAJA ABONADO
            controller_bajaAbonado(arrayAbonados,ABONADOS_CANTIDAD);
            break;
        case 4: // NUEVA LLAMADA
            controller_nuevaLlamada(arrayLlamadas, LLAMADAS_CANTIDAD,arrayAbonados,ABONADOS_CANTIDAD);
            break;
        case 5: // FINALIZAR LLAMADA
            controller_cerrarLlamada(arrayLlamadas, LLAMADAS_CANTIDAD);
            break;
        case 6: // INFORMES
            controller_informeAbonadosConMasReclamos(arrayLlamadas, LLAMADAS_CANTIDAD,arrayAbonados,ABONADOS_CANTIDAD);
            controller_informeReclamosTiempos(arrayLlamadas, LLAMADAS_CANTIDAD);
            break;
        case 7: // LISTAR LLAMADAS
            controller_listarLlamadas(arrayLlamadas, LLAMADAS_CANTIDAD);
            pause();
            break;
        case 8: // LISTAR ABONADOS
            controller_listarAbonados(arrayAbonados,ABONADOS_CANTIDAD);
            pause();
            break;
        case 9:
            //SALIR
            break;
        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            pause();
            break;
        }

    }while(menuOpcionElegida != 9);

    return 0;

}

