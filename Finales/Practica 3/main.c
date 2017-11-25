#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Post.h"
#include "Class.User.h"
#include "Class.Feed.h"

int main()
{
    char option[20], seguir = 's', string[200];
    ArrayList* pUsers = al_newArrayList();
    ArrayList* pPosts = al_newArrayList();
    ArrayList* pFeed = al_newArrayList();

    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("------------------------- MyBook System -------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                      1- Cargar Usuarios                       -\n");
        printf("-                      2- Cargar PostType                       -\n");
        printf("-                     3- Generar feed.csv                       -\n");
        printf("-                      4- Listar Feed.csv                       -\n");
        printf("-                           5- Salir                            -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------------------- Silva Cristian 1H --------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);

        switch(atoi(option))
        {
        case 1:
            if(pUsers->isEmpty(pUsers))
            {
                get_string("Ingrese el nombre de archivo: ", string);
                if(bundle_parserUsers(pUsers, string) == 0)
                {
                    printf("Lista de usuarios generada.\n");
                }
                else
                {
                    printf("A ocurrido un error.\n");
                }
            }
            else
            {
              printf("Ya cargo esta lista, genere feed.csv\n");
            }
            break;
        case 2:
            if(pPosts->isEmpty(pPosts))
            {
                get_string("Ingrese el nombre de archivo: ", string);
                if(bundle_parserPosts(pPosts, string) == 0)
                {
                    printf("Lista de mensajes generada.\n");
                }
                else
                {
                    printf("A ocurrido un error.\n");
                }
            }
            else
            {
              printf("Ya cargo esta lista, genere feed.csv\n");
            }
            break;
        case 3:
            if(!pPosts->isEmpty(pPosts) && !pUsers->isEmpty(pUsers))
            {
                if(bundle_controllerFeed(pFeed, pUsers, pPosts))
                {
                    printf("Lista de feeds generada.\n");
                }
                else
                {
                    printf("A ocurrido un error.\n");
                }
            }
            else
            {
                printf("Carge al sistema los mensajes y usuarios.\n");
            }
            break;
        case 4:
            if(!pFeed->isEmpty(pFeed))
            {
                bundle_loopFeed(pFeed);
            }
            else
            {
                printf("Carge al sistema los mensajes y usuarios.\n");
            }
            break;
        case 5:
            pPosts->deleteArrayList(pPosts);
            pUsers->deleteArrayList(pUsers);
            pFeed->deleteArrayList(pFeed);
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
        clear_screen();
    }
    return 0;
}
