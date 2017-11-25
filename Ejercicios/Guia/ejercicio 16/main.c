#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%i",&num);

    if (num>=0){
            printf("El numero es positivo\n");
    }else{
            printf("El numero es negativo\n");
    }

    return 0;
}
