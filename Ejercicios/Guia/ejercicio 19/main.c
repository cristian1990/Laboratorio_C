#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i , contS=0;
    printf("Ingrese un numero: ");
    scanf("%i",&num);
    for(i=0;i<=num;i++){
        contS+=i;
    }
    printf("\nLa suma es: %i\n",contS);

    return 0;
}
