#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Random.h"
#include "ArrayList.h"
#include "Functions.h"

ETramite* __reserved()
{
    ETramite* pTramite = (ETramite*) malloc(sizeof(ETramite));
    return pTramite;
}

int bundle_alta(char msg[], ArrayList* pList, char turno[], int type)
{
    int result = -1;
    char dni[40];
    char id[200] = {"T"};
    ETramite* pTramite = __reserved();

    if(pList != NULL && pTramite != NULL)
    {
        char index[100];
        sprintf(index, "%d", (pList->len(pList) + 1));

        get_string(msg, dni);
        if(type)
        {
            strcat(id,"H");
            strcat(id,index);
        }
        else
        {
            strcat(id,"L");
            strcat(id,index);
        }
        strcpy(pTramite->_id,id);
        pTramite->_dni = atoi(dni);
        pTramite->_estado = 1;
        pTramite->_tramite = type;
        if(!pList->add(pList, pTramite))
        {
            strcpy(turno,pTramite->_id);
            result = 1;
        }
    }
    return result;
}

void bundle_loop(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            ETramite* pTramite = __reserved();
            pTramite = (ETramite*) pList->get(pList, i);

            if(pTramite != NULL)
            {
                if(pTramite->_estado && pTramite->_tramite)
                {
                    printf("-- %s -- %d -- Tramite urgente --\n",pTramite->_id, pTramite->_dni);
                }
                else if(pTramite->_estado && !pTramite->_tramite)
                {
                    printf("-- %s -- %d -- Tramite regular --\n",pTramite->_id, pTramite->_dni);
                }
                else if(!pTramite->_estado && pTramite->_tramite)
                {
                    printf("-- %s -- %d -- Tramite urgente --\n",pTramite->_id, pTramite->_dni);
                }
                else if(!pTramite->_estado && !pTramite->_tramite)
                {
                    printf("-- %s -- %d -- Tramite regular --\n",pTramite->_id, pTramite->_dni);
                }
            }
        }
    }
}

int bundle_resolved(ArrayList* pList, ArrayList* pResolved)
{
    int result = -1;
    if(pList != NULL)
    {
        int index = pList->len(pList) - 1;
        ETramite* pTramite = __reserved();
        pTramite = (ETramite*) pList->get(pList, index);

        if(pTramite != NULL)
        {
            if(pTramite->_estado && pTramite->_tramite)
            {
                printf("-- %s -- %d -- Tramite urgente --\n",pTramite->_id, pTramite->_dni);
            }
            else if(pTramite->_estado && !pTramite->_tramite)
            {
                printf("-- %s -- %d -- Tramite regular --\n",pTramite->_id, pTramite->_dni);
            }
            pTramite->_estado = 0;
            result = pResolved->add(pResolved, pTramite);
            result = pList->remove(pList, index);
        }
    }
    return result;
}


int bundle_order(ETramite* pTramite1, ETramite* pTramite2)
{
    if(pTramite1->_dni > pTramite2->_dni)
    {
        return 1;
    }
    if(pTramite1->_dni < pTramite2->_dni)
    {
        return -1;
    }
    return 0;
}

