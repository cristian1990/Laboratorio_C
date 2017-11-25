#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5];
    int i, max, min;

    for(i=0;i<5;i++){
    printf("ingrese un numero: ");
    scanf("%i",&vector[i]);
    }
    min = vector[0];
    max = vector[0];

    for(i=0;i<5;i++){
        if(vector[i]>max){
            max=vector[i];
        }
    }
    for(i=0;i<5;i++){
        if(vector[i]<min){
            min=vector[i];
        }
    }
    printf("El maximo es: %i",max);
    printf("El minimo es: %i",min);

    return 0;
}
