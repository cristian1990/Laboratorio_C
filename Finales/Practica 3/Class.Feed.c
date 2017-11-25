#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Feed.h"
#include "Class.User.h"
#include "Class.Post.h"

EFeed* __newFeed()
{
    EFeed* newFeed = (EFeed*) malloc(sizeof(EFeed));
    return newFeed;
}

int bundle_controllerFeed(ArrayList* pList, ArrayList* pUsers, ArrayList* pPosts)
{
    int result = -1;

    if(pList != NULL && pUsers != NULL && pPosts != NULL)
    {
        pList->clear(pList);
        int i, j;
        for(i = 0; i < pUsers->len(pUsers); i++)
        {
            EUser* user = __newUser();
            user = (EUser*) pUsers->get(pUsers, i);

            for(j = 0; j < pPosts->len(pPosts); j++)
            {
                EPost* post = __newPost();
                post = (EPost*) pPosts->get(pPosts, j);

                if(user->_id_usuario_u == post->_id_usuario_p)
                {
                    EFeed* feed = __newFeed();
                    if(feed != NULL)
                    {
                        feed->_id_mensaje_f = post->_id_mensaje;
                        feed->_id_usuario_f = user->_id_usuario_u;
                        strcpy(feed->_mensaje_f, post->_mensaje);
                        strcpy(feed->_nick_name_f, user->_nick_name);
                        feed->_popularidad_m_f = post->_popularidad_p;
                        feed->_popularidad_u_f = user->_popularidad_u;

                        result = pList->add(pList, feed);
                    }
                }
            }
        }
        pUsers->clear(pUsers);
        pPosts->clear(pPosts);
        if(result == 0 && (pList->sort(pList,bundle_orderBy,0) == 0))
        {
            result = bundle_generateFeed(pList);
        }
    }

    return result;
}

void bundle_loopFeed(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            EFeed* feed = __newFeed();
            feed = (EFeed*) pList->get(pList, i);

            if(feed != NULL)
            {
                printf("{\n   id_mensaje: '%d',\n   mensaje: '%s',\n   followes_mensaje: '%d',\n   id_user: '%d',\n   user_nick: '%s',\n   followes_user: '%d'\n}\n", feed->_id_mensaje_f, feed->_mensaje_f, feed->_popularidad_m_f, feed->_id_usuario_f, feed->_nick_name_f, feed->_popularidad_u_f);
            }
        }
    }
}

int bundle_generateFeed(ArrayList* pList)
{
    int result = 0;
    if(pList != NULL)
    {
        FILE* pFile;
        pFile = fopen("feed.csv", "w");

        if(pFile == NULL)
        {
            pFile = fopen("feed.csv", "a");
        }

        if(pFile != NULL)
        {
            int i;
            for(i = 0; i < pList->len(pList); i++)
            {
                EFeed* feed = __newFeed();
                feed = (EFeed*) pList->get(pList, i);
                if(feed != NULL)
                {
                    result = fprintf(pFile,"%d,%s,%d,%d,%s,%d\n",feed->_id_mensaje_f, feed->_mensaje_f, feed->_popularidad_m_f, feed->_id_usuario_f, feed->_nick_name_f, feed->_popularidad_u_f);
                }
            }
            fclose(pFile);
        }
    }
    return result;
}

int bundle_orderBy(EFeed* feed1, EFeed* feed2)
{
    if(feed1->_popularidad_u_f > feed2->_popularidad_u_f)
    {
        return 1;
    }
    if(feed1->_popularidad_u_f < feed2->_popularidad_u_f)
    {
        return -1;
    }
    if(feed1->_popularidad_u_f == feed2->_popularidad_u_f)
    {
        if(feed1->_popularidad_m_f > feed2->_popularidad_m_f)
        {
            return 1;
        }
        if(feed1->_popularidad_m_f < feed2->_popularidad_m_f)
        {
            return -1;
        }
    }
    return 0;
}




