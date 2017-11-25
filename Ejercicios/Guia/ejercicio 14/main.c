#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;
    int acum=0;

    while(num<99){
            num=num+3;
            acum+=num;
    printf("\n%i",num);

    }
    printf("\nLa suma de los numeros es: %i",acum);
    return 0;
}
