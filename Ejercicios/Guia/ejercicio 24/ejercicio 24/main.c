#include <stdio.h>
#include <stdlib.h>

int main()
{

    int peso, contMenor=0, contMayor=0;
    char seguir='s';

    while(seguir!='n'){
    printf("Ingrese peso: ");
    scanf("%i",&peso);

    if(peso<=80){
        contMenor++;
    } else{
        contMayor++;
    }
    fflush(stdin);
    printf("Desea seguir?");
    scanf("%c",&seguir);

    }
    printf("\nlos empleados que pesan menos de 80 kg son: %i",contMenor);
    printf("\nlos empleados que pesan mas de 80 kg son: %i\n",contMayor);



    return 0;
}
