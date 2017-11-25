#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Letras.h"
#include "utn.h"


Eletras* __nuevaLetra()
{
    Eletras* nuevaLetra = (Eletras*) malloc(sizeof(Eletras));
    return nuevaLetra;
}

int lista_CargarDatos(ArrayList* pList, char nombreArchivo[])
{
    int returnAux = -1;

    if(pList != NULL)
    {
        char letra[10], nombre[22], vocal[20],consonante[20];
        FILE* pFile;
        pFile = fopen(nombreArchivo,"r");

        printf("\nletra - nombre - vocal - consonante\n");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                Eletras* let = __nuevaLetra();

                if(let!= NULL)
                {
                    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", letra, nombre, vocal, consonante);
                    strcpy(let->_letra, letra);
                    strcpy(let->_nombre, nombre);
                    let->_vocal = atoi(vocal);
                    let->_consonante = atoi (consonante);

                    returnAux = pList->add(pList, let);

                    printf("%s - %s - %d - %d \n", let->_letra, let->_nombre, let->_vocal, let->_consonante);
                }
                else
                {
                    break;
                }
            }
            fclose(pFile);
        }
    }
    return returnAux;
}


void* lista_constructor()
{
    Eletras* let = (Eletras*) malloc(sizeof(Eletras));

    if(let != NULL)
    {

        printf("\nIngrese nueva letra: ");
        fflush(stdin);
        gets(let->_letra);
        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(let->_nombre);
        let->_vocal = 0;
        let->_consonante = 0;

    }
    return let;
}


int lista_nuevoDato(ArrayList* pList)
{
    int returnAux = -1;

    Eletras* let = lista_constructor();
    returnAux = pList->add(pList, let);

    return returnAux;
}


void lista_imprimirDatos(ArrayList* pList)
{
    int i;
    Eletras* let;

    if(pList->isEmpty(pList) == 0)
    {
        for(i = 0; i < pList->size; i++)
        {
            let = (Eletras*) pList->get(pList, i);
            printf("%s - %s - %d - %d \n", let->_letra, let->_nombre, let->_vocal, let->_consonante);
        }
    }
    else
    {
        printf("---------- Error el sistema esta vacio ---------\n");
    }
}

int lista_modificarDatos(ArrayList* pList, char msg[])
{
    int indice, returnAux = -1;
    char valor[10];
    int flag = 0;
    void* pElement = NULL;
    Eletras* let = NULL;

    if(pList->isEmpty(pList) == 0)
    {
        fflush(stdin);
        printf("Ingrese letra a modificar: ");
        gets(valor);
        do{
            let = (Eletras*) lista_buscarLetra(pList, valor);

            if(let != NULL)
            {
                fflush(stdin);
                printf("%s - %s \n", let->_letra, let->_nombre);

                indice = pList->indexOf(pList, let);
                if(flag==0){
                    pElement = lista_constructor();
                }
                flag = 1;
                if(pElement != NULL && indice != -1)
                {
                    returnAux = pList->set(pList, indice, pElement);
                }
            }
            else
            {
                printf("\n");
            }
        }while(let != NULL);
    }

    return returnAux;

}

void* lista_buscarLetra(ArrayList* pList, char value[])
{
    int i;
    Eletras* let = NULL;

    for(i = 0; i < pList->size; i++)
    {
        let = (Eletras*) pList->get(pList, i);

        if(strcmp(let->_letra , value)== 0)
        {
            break;
        }
        else
        {
            let = NULL;
        }
    }
    return let;
}

int lista_borrarDatos(ArrayList* pList, char msg[])
{
    char valor[10];
    int returnAux = -1;
    int valorAux;
    Eletras* let = NULL;

    if(pList->isEmpty(pList) == 0)
    {
        fflush(stdin);
        printf("Ingrese letra a eliminar: ");
        gets(valor);

        let = (Eletras*) lista_buscarLetra(pList, valor);
        valorAux = pList->indexOf(pList, let);
        returnAux = pList->remove(pList, valorAux);
    }

    return returnAux;
}

int lista_completar(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        int i;
        char letraA [10] = "a";
        char letraE [10] = "e";
        char letraI [10] = "i";
        char letraO [10] = "o";
        char letraU [10] = "u";
        for(i = 0; i < pList->len(pList); i++)
        {
            Eletras* let = __nuevaLetra();
            let = (Eletras*) pList->get(pList, i);

                if(let!= NULL)
                {
                    if(strcmp(let->_letra , letraA)==0)
                    {
                        result = let->_vocal = 1;
                        result = let->_consonante = 0;
                    }
                     else if(strcmp(let->_letra , letraE)==0)
                    {
                        result = let->_vocal = 1;
                        result = let->_consonante = 0;
                    }
                    else if(strcmp(let->_letra , letraI)==0)
                    {
                        result = let->_vocal = 1;
                        result = let->_consonante = 0;
                    }
                    else if(strcmp(let->_letra , letraO)==0)
                    {
                        result = let->_vocal = 1;
                        result = let->_consonante = 0;
                    }
                    else if(strcmp(let->_letra , letraU)==0)
                    {
                        result = let->_vocal = 1;
                        result = let->_consonante = 0;
                    }
                    else{
                        result = let->_consonante = 1;
                    }

                }
        }

    }

    return result;
}


int lista_ordenar(void* pLetraA,void* pLetraB)
{
    return strcmp(pLetraA, pLetraB);
}

