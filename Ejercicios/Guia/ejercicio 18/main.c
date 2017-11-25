#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contN=0;
    int acumP=0;
    int mulN=1;

    while(contN<5){
        contN++;
        printf("Ingrese un numero: ");
        scanf("%i",&num);

        while(num==0){
            printf("Ingrese un numero distinto a 0: ");
                scanf("%i",&num);
        }
        if(num>=0){
        acumP+=num;
        }else{
        mulN*=num;
        }
    }
    printf("La suma de los positivos es: %i\n",acumP);
    printf("La multiplicacion de los negatiuvos es: %i\n",mulN);

    return 0;
}
