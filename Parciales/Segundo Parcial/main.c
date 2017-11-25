#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Letras.h"
#include "utn.h"
#include "functions.h"

int main()
{
    char seguir = 's', nombreArchivo[20];
    int opcion;
    int flag = 0;

    ArrayList* pList = al_newArrayList();
    ArrayList* pRepetidos = NULL;
    ArrayList* pSinRepetir = NULL;



    while(seguir == 's')
    {
        system("CLS");
        printf("-----------------------------------------------------------------\n");
        printf("------------------------ Programa Letras ------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                      1- Alta Letra                            -\n");
        printf("-                      2- Modificar Letras                      -\n");
        printf("-                      3- Eliminar Letra                        -\n");
        printf("-                      4- Completar                             -\n");
        printf("-                      5- Generar y listar                      -\n");
        printf("-                      6- Comprobar                             -\n");
        printf("-                      7- Salir                                 -\n");
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
                            printf("\nLetras cargadas!\n\n");
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
                            printf("A ocurrido un error.\n");
                        }
                        break;
                }

        case 2:
                if(lista_modificarDatos(pList, "\n\nIngrese letra a modificar: ") == 0){
                    printf("-letra modificada-\n\n");
                }else{
                    printf("A ocurrido un error.\n");
                }
               lista_imprimirDatos(pList);
                break;

        case 3:
                if(lista_borrarDatos(pList, "Ingrese letra a eliminar\n") == 0){
                    printf("letra eliminada\n");
                }else{
                    printf("A ocurrido un error.\n");
                }
                lista_imprimirDatos(pList);
                break;

        case 4:
                printf("letra - nombre - vocal - consonante\n");
                lista_completar(pList);
                lista_imprimirDatos(pList);
        break;

        case 5:
        pRepetidos = pList->clone(pList);
        pRepetidos->sort(pRepetidos, lista_ordenar, 1);

        pSinRepetir = pList->clone(pList);
        pSinRepetir->sort(pSinRepetir, lista_ordenar, 0);

        printf("\n-------Ascendente-------\n");
        lista_imprimirDatos(pRepetidos);
        printf("\n\n");
        printf("\n-------Descendente-------\n");
        lista_imprimirDatos(pSinRepetir);

        case 6:
        break;

        case 7:
            printf("Desea seguir? s/n \n");
            fflush(stdin);
            scanf("%c",&seguir);
        break;

    }
    system("PAUSE");
    }

    return 0;
}
