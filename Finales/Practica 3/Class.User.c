#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.User.h"

EUser* __newUser()
{
    EUser* newUser = (EUser*) malloc(sizeof(EUser));
    return newUser;
}

int bundle_parserUsers(ArrayList* pList, char file_name[])
{
    int result = -1;

    if(pList != NULL)
    {
        char id[100], nick[100], popularidad[100];
        FILE* pFile;
        pFile = fopen(file_name, "r");

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                EUser* user = __newUser();
                if(user != NULL)
                {
                    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nick, popularidad);
                    user->_id_usuario_u = atoi(id);
                    strcpy(user->_nick_name, nick);
                    user->_popularidad_u = atoi(popularidad);

                    result = pList->add(pList, user);
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

void bundle_loopUser(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            EUser* user = __newUser();
            user = (EUser*) pList->get(pList, i);

            if(user != NULL)
            {
                printf("-- %d -- %s -- %d --\n", user->_id_usuario_u, user->_nick_name, user->_popularidad_u);
            }
        }
    }
}
