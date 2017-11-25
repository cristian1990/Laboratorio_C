#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%i",&num);

    if (num%2==0){
        printf("El numero es par\n");
    }else {
        printf("El numero es impar\n");
    }


    return 0;
}
