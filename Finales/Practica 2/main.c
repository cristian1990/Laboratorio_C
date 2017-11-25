#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Random.h"

int main()
{
    char seguir = 's', option[30], turno[100];
    ArrayList* pList = al_newArrayList();
    ArrayList* pResolved = al_newArrayList();

    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("------------------------- System Persons ------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                      1- Tramite urgente                       -\n");
        printf("-                      2- Tramite regular                       -\n");
        printf("-                      3- Proximo cliente                       -\n");
        printf("-                           4- Listar                           -\n");
        printf("-                          5- Informar                          -\n");
        printf("-                           6- Salir                            -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------------------- Silva Cristian 1H --------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);
        switch(atoi(option))
        {
        case 1:
            if(bundle_alta("Ingrese su dni: ", pList, turno, 1))
            {
                printf("Numero de turno: %s.\n", turno);
            }
            else
            {
                printf("A ocurrido un error.\n");
            }
            break;
        case 2:
            if(bundle_alta("Ingrese su dni: ", pList, turno, 0))
            {
                printf("Numero de turno: %s.\n", turno);
            }
            else
            {
                printf("A ocurrido un error.\n");
            }
            break;
        case 3:
            if(!pList->isEmpty(pList))
            {
                if(!bundle_resolved(pList, pResolved))
                {
                  printf("El cliente a sido llamado.\n");
                }
                else
                {
                  printf("A ocurrido un error.\n");
                }
            }
            else
            {
                printf("No hay turnos en espera.\n");
            }
            break;
        case 4:
            if(!pList->isEmpty(pList))
            {
                bundle_loop(pList);
            }
            else
            {
              printf("No hay elementos para listar.\n");
            }
            break;
        case 5:
            if(!pResolved->isEmpty(pResolved))
            {
                pResolved->sort(pResolved,bundle_order,1);
                bundle_loop(pResolved);
            }
            else
            {
              printf("No hay elementos para informar.\n");
            }
            break;
        case 6:
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        clear_screen();
    }
    return 0;
}
