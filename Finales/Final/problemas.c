#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
#include "problemas.h"

Eissue* __newIssue()
{
    Eissue* newIssue = (Eissue*) malloc(sizeof(Eissue));
    return newIssue;
}

int issue_cargarDatos(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char id[11], name[33], email[65];
        FILE* pFile;
        pFile = fopen("problemas.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                Eissue* issue = __newIssue();
                if(issue != NULL)
                {
                    fscanf(pFile,"%[^;];%[^;];%[^\n]\n", id, name, email);
                    issue->id = atoi(id);
                    strcpy(issue->name, name);
                    strcpy(issue->email, email);

                    result = pList->add(pList, issue);
                }
                else
                {
                    break;
                }
            }
            fclose(pFile);
        }
    }
    return result;
}

void issue_imprimirDatos(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            Eissue* issue = __newIssue();
            issue = (Eissue*) pList->get(pList, i);

            if(issue != NULL)
            {
                printf("-- %d -- %s -- %s --\n", issue->id, issue->name, issue->email);
            }
        }
    }
}

