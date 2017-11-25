#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    int superficie;

    printf("Ingrese base ");
    scanf("%i",&base);

    printf("Ingrese altura ");
    scanf("%i",&altura);

    superficie=(base*(altura/2));

    printf("La suerficie es: %i",superficie);

    return 0;
}
