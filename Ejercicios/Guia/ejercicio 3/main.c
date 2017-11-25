#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1;
    int num2;
    int res;
    int cua;

    printf("Introduzca un numero ");
    scanf("%i",&num1);

    printf("Introduzca otro numero ");
    scanf("%i",&num2);

    res=num1*num2;
    cua=num1*num1;

    printf("La multiplicacion es: %i\n",res);

    printf("El cuadrado del primer numero es: %i\n",cua);

    system("pause");
    system("cls");

    return 0;
}
