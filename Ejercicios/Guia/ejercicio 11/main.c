#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;

    while(num<100){
        num++;
        if(num%2==0){
            printf("\n%i",num);
        }
    }


    return 0;
}
