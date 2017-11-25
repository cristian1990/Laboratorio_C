#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, aux;

    printf("Ingrese primer numero: ");
    scanf("%i",&num1);

    printf("Ingrese segundo numero: ");
    scanf("%i",&num2);

    aux=num1;
    num1=num2;
    num2=aux;

    printf("\nprimer numero: %i\n",num1);
    printf("segundo numero: %i\n",num2);

    return 0;
}
