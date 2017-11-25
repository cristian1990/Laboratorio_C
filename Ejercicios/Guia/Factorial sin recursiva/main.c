#include <stdio.h>
#include <stdlib.h>

int factorial(int num, int res, int i);

int main()
{
    int num;
    int res;
    res=factorial(res);
    printf("El factorial es: %i\n",res);
    return 0;
}
int factorial(int res)
{
    int num=5;
    int res=1;
    int i;
    for(i=1;i<=num;i++){
    res=res*i;
return res;
}
