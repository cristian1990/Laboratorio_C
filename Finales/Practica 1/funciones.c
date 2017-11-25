#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int al_cargar(ArrayList* pList,char value[])
{
    int returned = -1;
    FILE* pFile = NULL;

    if((pFile = fopen ("destinatarios.csv", "r")) != NULL)
    {
        char name[100], email[150];
        while(!feof(pFile))
        {
            EPersona* newPersonas = (EPersona*) malloc(sizeof(EPersona));
            fscanf(pFile, "%[^,],%[^\n]\n", name, email);
            strcpy(newPersonas->name, name);
            strcpy(newPersonas->email, email);
            returned = pList->add(pList, newPersonas);
        }
        fclose(pFile);
    }
    else
    {
        printf("Error acuda a su programador\n");
    }
    return returned;
}


void al_show(ArrayList* pList)
{
    int i;
    EPersona* pPersona = NULL;

    if(pList->isEmpty(pList) == 0)
    {
        for(i = 0; i < pList->size; i++)
        {
            pPersona = (EPersona*) pList->get(pList, i);
            printf("%s ------ %s\n", pPersona->name, pPersona->email);
        }
    }
    else
    {
        printf("---------- Error el sistema esta vacio ---------\n");
    }
}

int al_depurar(ArrayList* destinatarios, ArrayList* listaNegra, ArrayList* listaDepurada)
{
    int i, j, returned;
    EPersona* auxDestinatarios;
    EPersona* auxListaNegra;

    if(destinatarios->isEmpty(destinatarios) == 0 && listaNegra->isEmpty(listaNegra) == 0)
    {
        for(i = 0; i < destinatarios->size; i++)
        {
            auxListaNegra = (EPersona*) listaNegra->get(listaNegra, i);
            auxDestinatarios = (EPersona*) destinatarios->get(destinatarios, i);

            if((listaNegra->contains(listaNegra,auxDestinatarios)) == 0)
            {
                //printf("%s ---- %s\n", auxDestinatarios->name, auxDestinatarios->email);
                returned = listaDepurada->add(listaDepurada, auxDestinatarios);
            }
        }
    }
    else
    {
        printf("---------- Error el sistema esta vacio ---------\n");
    }
    return returned;
}

int al_cargarBlackList(ArrayList* destinatarios, ArrayList* listaNegra, char value[])
{
    int i, returned = -1;
    FILE* pFile = NULL;
    EPersona* auxDestinatarios = NULL;

    if((pFile = fopen ("black_list.csv", "r")) != NULL)
    {
        char name[100], email[150];
        while(!feof(pFile))
        {
            EPersona* newPersonas = (EPersona*) malloc(sizeof(EPersona));
            fscanf(pFile, "%[^,],%[^\n]\n", name, email);
            strcpy(newPersonas->name, name);
            strcpy(newPersonas->email, email);

            for(i = 0; i < destinatarios->size; i++)
            {
                auxDestinatarios = (EPersona*) destinatarios->get(destinatarios, i);
                if(((strcmp(auxDestinatarios->name, newPersonas->name) == 0) && (strcmp(auxDestinatarios->email, newPersonas->email) == 0)))
                {
                    returned = listaNegra->add(listaNegra, auxDestinatarios);
                    break;
                }
            }
        }

        fclose(pFile);
    }
    else
    {
        printf("Error acuda a su programador\n");
    }
    return returned;
}



