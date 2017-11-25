#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caracter;
    int seguir=0;
    int contA=0,contE=0,contI=0,contO=0,contU=0;


    while(seguir<5){
    seguir++;
    printf("\nIngrese el caracter: ");
    caracter = getche();

        if(caracter=='a'){
        contA++;
        }else if(caracter=='e'){
        contE++;
        }else if(caracter=='i'){
        contI++;
        }else if(caracter=='o'){
        contO++;
        }else if(caracter=='u'){
        contU++;
        }
}

printf("\n\nLas A ingresadas son: %i",contA);
printf("\nLas E ingresadas son: %i",contE);
printf("\nLas I ingresadas son: %i",contI);
printf("\nLas O ingresadas son: %i",contO);
printf("\nLas U ingresadas son: %i",contU);

    return 0;
}
