#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pi;
    int radio;
    float longitud;
    float area;
    pi=3.141592;

    printf("Ingrese radio ");
    scanf("%i",&radio);

    longitud=2*pi*radio;
    area=pi*radio*radio;

    printf("La longitud de la circunferencia es: %f\nEl area es: %f ",longitud,area);




    return 0;
}
