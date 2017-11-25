#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
#include "tickets.h"
#include "problemas.h"

Etickets* __newTickets()
{
    Etickets* newTickets = (Etickets*) malloc(sizeof(Etickets));
    return newTickets;
}

int tickets_cargarDatos(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char date[11], time[6], issueId[100], gravedad[100], msg[65];
        FILE* pFile;
        pFile = fopen("ticket.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                Etickets* ticket = __newTickets();
                if(ticket != NULL)
                {
                    fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n", date, time, issueId, gravedad, msg);
                    strcpy(ticket->date, date);
                    strcpy(ticket->time, time);
                    ticket->issueId = atoi(issueId);
                    ticket->gravedad = atoi(gravedad);
                    strcpy(ticket->msg, msg);

                    result = pList->add(pList, ticket);
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

void tickets_imprimirDatos(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            Etickets* ticket = __newTickets();
            ticket = (Etickets*) pList->get(pList, i);

            if(ticket != NULL)
            {
                printf("-- %s -- %s -- %d -- %d -- %s --\n", ticket->date, ticket->time, ticket->issueId, ticket->gravedad, ticket->msg);
            }
        }
    }
}

int procesarInformacion(ArrayList* pList, ArrayList* pIssue)
{
    int result = -1;

    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            Etickets* ticket = __newTickets();
            ticket = (Etickets*) pList->get(pList, i);

            if(ticket != NULL)
            {
                if(ticket->gravedad <= 3)
                {
                    if(ticket->gravedad < 3)
                    {
                        result = pList->remove(pList, i);
                    }
                    else if(ticket->issueId != 3)
                    {
                        result = crearArchivos(ticket,pIssue, 1);
                    }
                }
               else if(ticket->gravedad >=5 && ticket->gravedad <=8)
                {
                    result = crearArchivos(ticket,pIssue, 2);
                }
                else if(ticket->gravedad > 8)
                {
                    int j;
                    for(j = 0; j < pIssue->len(pIssue); j++)
                    {
                        Eissue* issue = __newIssue();
                        issue = (Eissue*) pIssue->get(pIssue, j);
                        if(ticket->issueId == issue->id)
                        {
                            printf("-- %s -- %s -- %s -- %s -- %s --\n", ticket->date, ticket->time, issue->name, ticket->msg, issue->email);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int crearArchivos(Etickets* ticket, ArrayList* pList, int type)
{
    int result = 0;
    if(pList != NULL)
    {
        FILE* pFile;
        switch(type)
        {
        case 1:
            pFile = fopen("solucionar.txt", "a");
            break;
        case 2:
            pFile = fopen("solucionarUrgente.txt", "a");
            break;
        }

        if(pFile != NULL)
        {
            int i;
            for(i = 0; i < pList->len(pList); i++)
            {
                Eissue* issue = __newIssue();
                issue = (Eissue*) pList->get(pList, i);
                if(issue != NULL)
                {
                    if(ticket->issueId == issue->id)
                    {
                        result = fprintf(pFile,"%s;%s;%s;%s\n",ticket->date, ticket->time, issue->name, ticket->msg);
                    }
                }
            }
            fclose(pFile);
        }
    }
    return result;
}

int controlarDatos(ArrayList* pTickets, ArrayList* pIssue, int min, int max)
{
    int cont = 0;
    if(pTickets != NULL && pIssue != NULL)
    {
        int i, j;
        for(i = 0; i < pIssue->len(pIssue); i++)
        {
            Eissue* issue = __newIssue();
            issue = (Eissue*) pIssue->get(pIssue, i);

            for(j = 0; j < pTickets->len(pTickets); j++)
            {
                Etickets* ticket = __newTickets();
                ticket = (Etickets*) pTickets->get(pTickets, j);

                if(ticket->gravedad > min && ticket->gravedad < max)
                {
                    if(ticket->issueId == issue->id)
                    {
                        cont++;
                    }
                }
            }
        }
    }
    return cont;
}

int issue_contador(ArrayList* pIssue, int id)
{
    int i, cont = 0;
    for(i = 0; i < pIssue->len(pIssue); i++)
    {
        Eissue* issue = __newIssue();
        issue = (Eissue*) pIssue->get(pIssue, i);
        if(issue->id == id)
        {
            cont++;
        }
    }
    return cont;
}





