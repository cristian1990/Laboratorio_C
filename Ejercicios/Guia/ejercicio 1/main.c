#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    float res;
    printf("un numero para num1: " );
    scanf("%i",&num1);

    printf("un numero para num2: " );
    scanf("%i",&num2);

    printf("un numero para num3: " );
    scanf("%i",&num3);

    printf("un numero para num4: " );
    scanf("%i",&num4);

    printf("un numero para num5: " );
    scanf("%i",&num5);

    res=(num1+num2+num3+num4+num5)/5;

    printf("El promedio es: %f ",res);
    return 0;
}
