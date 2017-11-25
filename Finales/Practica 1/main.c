#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    int result;
    char option[10], optionC, value[50];
    ArrayList* destinatarios = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* listaDepurada = al_newArrayList();

    while(optionC != 'n')
    {
        printf("1 - Cargar destinatarios\n");
        printf("2 - Cargar lista negra\n");
        printf("3 - Depurar\n");
        printf("4 - Listar\n");
        printf("5 - Salir\n");
        printf("opcion: ");
        scanf("%s", option);

        switch(atoi(option))
        {
        case 1:
            printf("Ingrese el nombre del archivo: ");
            fflush(stdin);
            gets(value);

            if(al_cargar(destinatarios, value) == 0)
            {
                printf("Datos cargados\n");
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 2:
            printf("Ingrese el nombre del archivo: ");
            fflush(stdin);
            gets(value);

            if(al_cargarBlackList(destinatarios,listaNegra,value) == 0)
            {
                printf("Datos cargados\n");
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 3:
            if(al_depurar(destinatarios, listaNegra, listaDepurada) == 0)
            {
                printf("Datos depurados\n");
            }
            else
            {
                printf("Error al depurar los archivos");
            }
            /*al_show(destinatarios);
            printf("%d\n", destinatarios->size);*/
            break;
        case 4:
            al_show(listaDepurada);
            printf("%d\n", listaDepurada->size);
            break;
        case 5:
            optionC = 'n';
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
