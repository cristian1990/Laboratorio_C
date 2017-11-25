#include <stdio.h>
#include <stdlib.h>

int main()
{
int num=0;
int contImpar=0;

while(num<100){
    num++;
    if(num%2!=0){
    contImpar++;
    printf("\n%i",num);
    }
}

printf("\n\nLos numeros impares son: %i\n",contImpar);
    return 0;
}
