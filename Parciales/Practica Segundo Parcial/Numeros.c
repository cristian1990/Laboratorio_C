#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Numeros.h"
#include "utn.h"

int contPar;
int contImpar;
int contPrimo;
int contCero;

Enumeros* __nuevoNumero()
{
    Enumeros* nuevoNumero = (Enumeros*) malloc(sizeof(Enumeros));
    return nuevoNumero;
}

int lista_CargarDatos(ArrayList* pList, char nombreArchivo[])
{
    int returnAux = -1;

    if(pList != NULL)
    {
        char numero[20], nombre[50], par[20],impar[20],primo[20];
        FILE* pFile;
        pFile = fopen(nombreArchivo,"r");

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                Enumeros* num = __nuevoNumero();

                if(num != NULL)
                {
                    fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", numero, nombre, par ,impar, primo);
                    num->_numero = atoi(numero);
                    strcpy(num->_nombre, nombre);
                    num->_par = atoi(par);
                    num->_impar = atoi(impar);
                    num->_primo = atoi(primo);

                    returnAux = pList->add(pList, num);

                    printf("%d - %s - %d - %d - %d\n", num->_numero, num->_nombre, num->_par, num->_impar, num->_primo);
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
    Enumeros* num = (Enumeros*) malloc(sizeof(Enumeros));

    if(num != NULL)
    {
        printf("\nIngrese numero: ");
        scanf("%i", &num->_numero);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(num->_nombre);
        num->_par = 0;
        num->_impar = 0;
        num->_primo = 0;

    }
    return num;
}


int lista_nuevoDato(ArrayList* pList)
{
    int returnAux = -1;

    Enumeros* num = lista_constructor();
    returnAux = pList->add(pList, num);

    return returnAux;
}


void lista_imprimirDatos(ArrayList* pList)
{
    int i;
    Enumeros* num;

    if(pList->isEmpty(pList) == 0)
    {
        for(i = 0; i < pList->size; i++)
        {
            num = (Enumeros*) pList->get(pList, i);
            printf("%d - %s - %d - %d - %d\n", num->_numero, num->_nombre, num->_par, num->_impar, num->_primo);
        }
    }
    else
    {
        printf("---------- Error el sistema esta vacio ---------\n");
    }
}


int lista_modificarDatos(ArrayList* pList, char msg[])
{
    int indice, valor, returnAux = -1;
    int flag = 0;
    void* pElement = NULL;
    Enumeros* num = NULL;

    if(pList->isEmpty(pList) == 0)
    {
        lista_imprimirDatos(pList);
        valor = lista_obtener(msg);
        do{
            num = (Enumeros*) lista_buscar(pList, valor);

            if(num != NULL)
            {
                printf("%d - %s \n", num->_numero,num->_nombre);

                indice = pList->indexOf(pList, num);
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
                printf("--------- Elemento no encontrado -----------\n");
            }
        }while(num != NULL);
    }

    return returnAux;

}


void* lista_buscar(ArrayList* pList, int valor)
{
    int i;
    Enumeros* num = NULL;

    for(i = 0; i <pList->size; i++)
    {
        num = (Enumeros*) pList->get(pList, i);

        if((num->_numero) == valor)
        {
            break;
        }
        else
        {
            num = NULL;
        }
    }
    return num;
}


int lista_obtener(char msg[])
{
    int valor;

    printf(msg);
    scanf("%d", &valor);

    return valor;
}


int lista_borrarDatos(ArrayList* pList, char msg[])
{
    int valor, returnAux = -1;
    Enumeros* num = NULL;

    if(pList->isEmpty(pList) == 0)
    {
        lista_imprimirDatos(pList);
        valor = lista_obtener(msg);

        num = (Enumeros*) lista_buscar(pList, valor);
        valor = pList->indexOf(pList, num);
        returnAux = pList->remove(pList, valor);
    }

    return returnAux;
}

int lista_comprobar(int numero)
{
    int returnAux = -1;
    int i, cont = 0;

    if(numero==0) //numeros ceros
    {
        returnAux = -2;
    }
    else if(numero%2==0) //El numero es par
    {
        returnAux = 0;
    }
    else if((numero%2 != 0))
    {
        for(i=1;i<=numero;i++){
            if(numero%i==0){
            cont++;
            }
        }
        if(cont==2){ //El numero es primo

            returnAux = -1;
        }
        else if(cont>2){ //El numero es impar
            returnAux = 1;
        }
    }

    return returnAux;
}

int lista_completar(ArrayList* pList)
{
    int result = -1;
    int cPar = 0, cImpar = 0, cPrimo = 0, cCero = 0;

    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            Enumeros* num = __nuevoNumero();
            num = (Enumeros*) pList->get(pList, i);

            if(num != NULL)
            {
                if(lista_comprobar(num->_numero) == 0)
                {
                    cPar++;
                    result = num->_par = 1;
                }
                else if(lista_comprobar(num->_numero) == 1)
                {
                    cImpar++;
                    result = num->_impar = 1;
                }
                else if(lista_comprobar(num->_numero) == -1)
                {
                    cPrimo++;
                    result = num->_primo = 1;
                }
                else if(lista_comprobar(num->_numero) == -2)
                {
                    cCero++;
                    result = num->_par = 1;
                }
            }
        }
                contPar = cPar;
                contImpar = cImpar;
                contPrimo = cPrimo;
                contCero = cCero;
    }

    return result;
}

void lista_informe()
{
    printf("La cantidad de numeros pares es: %i\n",contPar);

    printf("La cantidad de numeros impares es: %i\n",contImpar);

    printf("La cantidad de numeros primos es: %i\n",contPrimo);

    printf("La cantidad de numeros ceros es: %i\n",contCero);
}


int lista_generarListar(ArrayList* pList, ArrayList* pRep , ArrayList* pNoRep)
{
    int returnAux = -1;
    pRep->clear(pRep);
    pNoRep->clear(pNoRep);

    if(pList != NULL && pRep != NULL)
    {
        int i, j;

        for(i = 0; i < pList->len(pList); i++)
        {
            Enumeros* num = __nuevoNumero();
            num = (Enumeros*) pList->get(pList, i);

                    for(j = 0; j < pList->len(pList); j++)
                    {
                        Enumeros* numAux = __nuevoNumero();
                        numAux = (Enumeros*) pList->get(pList, j);

                        if(numAux != NULL)
                        {
                            if(num->_numero == 50)
                            {
                                returnAux = pRep->add(pRep, num);
                                break;
                            }
                            else if(num->_numero != 50)
                            {
                                returnAux = pNoRep->add(pNoRep, num);
                                break;
                            }
                        }
                    }
        }
    }

    return returnAux;
}


int lista_ordenar(Enumeros* pNum1, Enumeros* pNum2)
{
    if(pNum1->_numero > pNum2->_numero)
    {
        return 1;
    }
    if(pNum1->_numero < pNum2->_numero)
    {
        return -1;
    }
    return 0;
}


/*
int lista_ordenar(void* pPersonA,void* pPersonB)
{
    return strcmp(pPersonA, pPersonB);
}
*/
