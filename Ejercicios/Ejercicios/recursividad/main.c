
#include <stdio.h>

int suma(int x);
int main()
{
    int num,res;
    printf("\nIngrese numero: ");
    scanf("%d",&num);
    res=suma(num);
    printf("\nla suma es: %i",res);
    return 0;
}

int suma(int x)
{
    if(x == 1){
        return 1;
    }else{
        return x + suma(x-1);
    }
}

