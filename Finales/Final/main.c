#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include "tickets.h"
#include "problemas.h"

int main()
{
    char option[20], seguir = 's';
    ArrayList* pTickets = al_newArrayList();
    ArrayList* pIssue = al_newArrayList();
    int block = 0, menor3 = 0, cuatro = 0, entre5y8 = 0, mayores8 = 0;

    while(seguir == 's')
    {
        printf("*****************************************************************\n");
        printf("*                                                               *\n");
        printf("*                        1- Leer tickets                        *\n");
        printf("*                   2- Procesar informacion                     *\n");
        printf("*                  3- Mostrar estadisiticas                     *\n");
        printf("*                          4- Salir                             *\n");
        printf("*                                                               *\n");
        printf("*****************************************************************\n");
        get_string("Ingrese una opcion: ", option);

        switch(atoi(option))
        {
        case 1:
            if(tickets_cargarDatos(pTickets) == 0 && issue_cargarDatos(pIssue) == 0)
            {
                printf("Tickets Leidos.\n");
            }
            else
            {
                printf("Ha ocurrido un error.\n");
            }
            break;
        case 2:
            if(pTickets->isEmpty(pTickets) == 0 && pIssue->isEmpty(pIssue) == 0)
            {
                if(procesarInformacion(pTickets, pIssue) == 0)
                {
                    block = 1;
                    printf("Datos procesados.\n");
                }
                else
                {
                    printf("Ha ocurrido un error.\n");
                }
            }
            else
            {
                printf("Cargue los Logs.\n");
            }
            break;
        case 3:
            if(block)
            {
                menor3 = controlarDatos(pTickets, pIssue, -1, 3);
                cuatro = controlarDatos(pTickets, pIssue, 3, 5);
                entre5y8 = controlarDatos(pTickets, pIssue, 4, 9);
                mayores8 = controlarDatos(pTickets, pIssue, 7, 10);

                printf("-- Menores a 3: %d\n", menor3);
                printf("-- Iguales a 4: %d\n", cuatro);
                printf("-- Entre 5 y 8 (inclusive): %d\n", entre5y8);
                printf("-- Mayores a 8: %d\n", mayores8);
            }
            else
            {
                printf("Debe procesar la informacion primero.\n");
            }
            break;
        case 4:
            pTickets->deleteArrayList(pTickets);
            pIssue->deleteArrayList(pIssue);
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
        clear_screen();
    }
    return 0;
}
