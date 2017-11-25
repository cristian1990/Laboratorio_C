#include <stdio.h>
#include <string.h>
int main()
{
    int cant;
    printf("Ingrese cantidad de nombres a ingresar: ");
    scanf("%i",&cant);
    char nombres[cant][20],aux[20];
    int i,j;
    int comp;

    for(i=0;i<cant;i++)
    {
        printf("Ingrese un nombre: \n");
        scanf("%s",nombres[i]);
    }

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            comp = strcmp( nombres[j], nombres[j+1] );
            if(comp > 0)
            {
                strcpy(aux,nombres[j]);
                strcpy(nombres[j],nombres[j+1]);
                strcpy(nombres[j+1],aux);
            }
        }
    }
    printf("Los nombres ordenados alfabeticamente son: \n");
    for(i=0;i<cant;i++)
    {
        printf("%i.- %s \n",i+1,nombres[i]);
    }
}
