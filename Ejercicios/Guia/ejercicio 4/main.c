#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int res;

    printf("Ingrese el primer numero ");
    scanf("%i",&num1);

    printf("Ingrese el segundo numero ");
    scanf("%i",&num2);

    res=num1-num2;

    if (res>0){
        printf("El resultado es:%i\nEl numero es positivo",res);
    }else if(res<0){
        printf("El resultado es:%i\nEl numero es negativo",res);
    }else
        printf("El resultado es 0");

    system("pause");
    system("cls");

    return 0;
}
