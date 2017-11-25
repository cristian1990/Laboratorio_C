#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int res;

    printf("ingrese un numero");
    scanf("%i",&num1);

    if(num1>0){
    res=num1*num1;
    printf("El cuadrado del numero es %i\n",res);
    }else
    printf("ERROR Ingrese un numero mayor a 0");
    system("pause");
    system("cls");
    return 0;
}
