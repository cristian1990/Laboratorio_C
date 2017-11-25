#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int res;

    printf("Ingrese el primer numero: ");
    scanf("%i",&num1);

    printf("Ingrese otro numero: ");
    scanf("%i",&num2);

    res=num1+num2;

    printf("La suma de los numeros es:%i",res);

    return 0;
}
