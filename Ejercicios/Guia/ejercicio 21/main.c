#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i;
    printf("ingrese un numero: ");
    scanf("%i",&num);

    for(i=0;i<=num;i+=3){
        printf("%i\n",i);
    }
    return 0;
}
