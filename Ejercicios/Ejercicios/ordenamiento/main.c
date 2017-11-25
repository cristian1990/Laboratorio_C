#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 3
int main()
{
    int i, j,comp;
    char nombre[CANT][20];
    char nombreAux[20];

    for(i=0; i<CANT; i++){
        printf("Ingrese nombre: ");
        gets(nombre[i]);
    }
    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            comp = strcmp(nombre[i],nombre[j]);
            if(comp<0){
                strcpy(nombreAux,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],nombreAux);
            }
        }
    }
    for(i=0;i<CANT;i++){
        printf("Nombre: %s\n",nombre[i]);
    }
    return 0;
}
