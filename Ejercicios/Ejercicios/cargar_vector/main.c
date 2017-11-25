#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int vector[10];
    int i;

    for(i=9;i>=0;i--)
    {
        printf("Ingrese 10 numeros\n");
        scanf("%i",&vector[i]);
    }
    for(i=0;i<10;i++)
    {
        printf("%i\n",vector[i]);
    }


*/
    int vector[10];
    int i=9;
    int cont=0;

    while(cont<10)
    {
        printf("Ingrese 10 numeros\n");
        scanf("%i",&vector[i]);
        cont++;
        i--;
    }

    for(i=0;i<10;i++)
        {
            printf("%i\n",vector[i]);
        }

    return 0;
}
