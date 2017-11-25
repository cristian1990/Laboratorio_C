#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    printf("Ingrese un numero: ");
    scanf("%i",&num);

    for(i=1;i<=num;i++){
    printf("%i\n",i);
    }
    return 0;
}
