#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, max;

    printf("ingrese primer numero: ");
    scanf("%i",&num1);

    printf("ingrese segundo numero: ");
    scanf("%i",&num2);

    printf("ingrese tercer numero: ");
    scanf("%i",&num3);

    if(num1>num2 && num1>num3){
        max=num1;
    }else if(num2>num1 && num2>num3){
        max=num2;
    }else {
        max=num3;
    }

    printf("\nel numero maximo es: %i\n",max);

    return 0;
}
