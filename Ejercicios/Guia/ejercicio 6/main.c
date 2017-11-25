#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contP=0;
    int cont=0;
    int contN=0;
    while(cont<5){
    cont++;
    printf("Ingrese un numero ");
    scanf("%i",&num);
        if(num<0){
        contN++;
        }else
        contP++;
}
printf("Los numeros positivos son:%i\nLos numeros negativos son:%i",contP, contN);


    return 0;
}
