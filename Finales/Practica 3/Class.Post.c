#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Post.h"

EPost* __newPost()
{
    EPost* newPost = (EPost*) malloc(sizeof(EPost));
    return newPost;
}

int bundle_parserPosts(ArrayList* pList, char file_name[])
{
    int result = -1;

    if(pList != NULL)
    {
        char id_msg[100], msg[100000], popularidad[100], id_user[100];
        FILE* pFile;
        pFile = fopen(file_name, "r");

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                EPost* post = __newPost();
                if(post != NULL)
                {
                    fscanf(pFile ,"%[^,],%[^,],%[^,],%[^\n]\n", id_msg, id_user, popularidad, msg);

                    post->_id_mensaje = atoi(id_msg);
                    post->_id_usuario_p = atoi(id_user);
                    post->_popularidad_p = atoi(popularidad);
                    strcpy(post->_mensaje, msg);

                    result = pList->add(pList, post);
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

void bundle_loopPost(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            EPost* post = __newPost();
            post = (EPost*) pList->get(pList, i);

            if(post != NULL)
            {
                printf("-- %d -- %d -- %d -- %s --\n", post->_id_mensaje, post->_id_usuario_p, post->_popularidad_p, post->_mensaje);
            }
        }
    }
}
