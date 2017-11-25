#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Numeros.h"
#include "utn.h"
#include "functions.h"

int main()
{
    char seguir = 's', nombreArchivo[100];
    int opcion;
    int flag = 0;
    ArrayList* pList = al_newArrayList();
    //ArrayList* pListClon = NULL;
    ArrayList* pRepetidos = al_newArrayList();
    //ArrayList* pSinRepetir = NULL;
    ArrayList* pNoRepetidos = al_newArrayList();


    while(seguir == 's')
    {
        system("CLS");
        printf("-----------------------------------------------------------------\n");
        printf("----------------------- Numeros Naturales -----------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                      1- Altas Numeros                         -\n");
        printf("-                      2- Modificar Numeros                     -\n");
        printf("-                      3- Eliminar Numero                       -\n");
        printf("-                      4- Completar                             -\n");
        printf("-                      5- Generar y listar                      -\n");
        printf("-                      6- Informar                              -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------------------- Silva cristian 1H --------\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:
                if (flag == 0){
                    if(pList->isEmpty(pList))
                    {
                        get_string("Ingrese el nombre de archivo: ", nombreArchivo);
                        if(lista_CargarDatos(pList, nombreArchivo) == 0)
                        {
                            printf("\nNumeros cargados!\n\n");
                            flag = 1;
                            break;
                        }
                        else
                        {
                            printf("A ocurrido un error.\n");
                        }
                    }
                }
                if(flag == 1){
                        if(lista_nuevoDato(pList) == 0){
                            printf("Carga exitosa!\n");
                        }else{
                            printf("Ups algo salio mal!\n");
                        }
                        break;
                }

        case 2:
                if(lista_modificarDatos(pList, "\n\nIngrese numero a modificar: ") == 0){
                    printf("Numero modificado\n");
                }else{
                    printf("Ups algo salio mal\n");
                }
                break;
        case 3:
                if(lista_borrarDatos(pList, "Ingrese el numero a eliminar\n") == 0){
                    printf("Numero eliminado\n");
                }else{
                    printf("Ups algo salio mal\n");
                }
                break;
        case 4:
        printf("Numero - Nombre - Par - Impar - Primo\n");
        lista_completar(pList);
        lista_imprimirDatos(pList);
        break;

        case 5:
/*
        pRepetidos = pList->clone(pList);
        pRepetidos->sort(pRepetidos, al_orderBy, 1);

        pSinRepetir = pList->clone(pList);
        pSinRepetir->sort(pSinRepetir, al_orderBy, 0);

        printf("\n-------Ascendente-------\n");
        lista_imprimirDatos(pRepetidos);
        printf("\n\n");
        printf("\n-------Descendente-------\n");
        lista_imprimirDatos(pSinRepetir);
*/
        pRepetidos->sort(pNoRepetidos, lista_ordenar, 1);
        pNoRepetidos->sort(pNoRepetidos, lista_ordenar, 1);

        lista_generarListar(pList, pRepetidos,pNoRepetidos);

        lista_imprimirDatos(pRepetidos);
        printf("\n\n");
        lista_imprimirDatos(pNoRepetidos);
        break;

        case 6:
        lista_informe();
        break;

        }
    system("PAUSE");
    }

    return 0;
}
