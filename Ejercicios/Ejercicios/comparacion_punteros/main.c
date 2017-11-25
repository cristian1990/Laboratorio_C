#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    /*
//MANERA 1
    int* punteroB;
    int* punteroA;
    int auxiliarD, auxiliarC;
    punteroA = &auxiliarC; // Obtenemos la posición de memoria de 'auxiliarC'
    punteroB = &auxiliarD; // Obtenemos la posición de memoria de 'auxiliarD'

    printf("A %p\n",&auxiliarC);
    printf("B %p\n",&auxiliarD);

    if (punteroA<punteroB)
    printf("El puntero A apunta a una direccion mas baja que puntero B\n");
    else if (punteroA>punteroB)
    printf("El puntero B apunta a una direccion mas baja que puntero A\n");

//MANERA 2
    int* punteroA;
    int* punteroB;
    int auxC = 10;
    int auxD = 20;

    punteroA =&auxC;
    punteroB =&auxD;

    if(punteroA>punteroB)
    {
        printf("El valor del puntero A es mayor");
    }else
    {
        printf("El valor del puntero B es mayor");
    }

    */
//MANERA 3

    char* punteroA;
    char* punteroB;
    char auxC[]="Carlos";
    char auxD[]="Carlo";
    int comp;

    punteroA = &auxC;
    punteroB = &auxD;

    comp = strcmp(punteroA,punteroB);

    if(comp==0)
    {
        printf("El valor de los punteros es el mismo");
    }else
    {
        printf("El valor no es el mismo");
    }

    return 0;
}
