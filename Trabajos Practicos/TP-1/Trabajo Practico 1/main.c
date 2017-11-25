#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"

int main()
{
    int num1;
    int num2;
    int suma, resta, mult, fact, divi;
    char seguir='s';
    int opcion=0;
    int flagPrimera = 0;
    int flagSegunda = 0;

    while(seguir=='s')
    {
        //system("CLS");
        while(flagPrimera == 0 && flagSegunda ==0)
        {
            printf("1- Ingresar 1er operando (A=X)\n");
            printf("2- Ingresar 2do operando (B=Y)\n");
            break;
        }
        while(flagPrimera == 1 && flagSegunda ==0)
        {
            printf("1- Ingresar 1er operando (A=%i)\n",num1);
            printf("2- Ingresar 2do operando (B=Y)\n");
            break;
        }
        while(flagPrimera == 0 && flagSegunda ==1)
        {
            printf("1- Ingresar 1er operando (A=X)\n");
            printf("2- Ingresar 2do operando (B=%i)\n",num2);
            break;
        }
        while(flagPrimera == 1 && flagSegunda ==1)
        {
            printf("1- Ingresar 1er operando (A=%i)\n",num1);
            printf("2- Ingresar 2do operando (B=%i)\n",num2);
            break;
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            printf("Ingrese el numero: ");
            scanf("%i",&num1);
            flagPrimera++;
            system("cls");
            system("pause");
                break;
            case 2:

            printf("Ingrese el numero: ");
            scanf("%i",&num2);
            flagSegunda++;
            system("cls");
            system("pause");
                break;
            case 3:
                suma=sumar(num1,num2);
                printf("La suma es: %i\n\n",suma);
                break;
            case 4:
                resta=restar(num1,num2);
                printf("La resta es: %i\n\n",resta);
                break;
            case 5:
                if (num2!=0)
                {
                divi=dividir(num1,num2);
                printf("La division es: %i\n\n",divi);
                } else{
                    printf("No se puede dividir por 0 introduzca otro numero\n");
                    }
                break;
            case 6:
                mult=multiplicacion(num1,num2);
                printf("La multiplicacion es: %i\n\n",mult);
                break;
            case 7:
                fact=factorial(num1);
                printf("El factorial es: %i\n\n",fact);
                break;
            case 8:
                suma=sumar(num1,num2);
                printf("La suma es: %i\n\n",suma);
                resta=restar(num1,num2);
                printf("La resta es: %i\n\n",resta);
                divi=dividir(num1,num2);
                printf("La division es: %i\n\n",divi);
                mult=multiplicacion(num1,num2);
                printf("La multiplicacion es: %i\n\n",mult);
                break;
            case 9:
                seguir = 'n';
                break;
        }
        //system("PAUSE");
    }
    return 0;
}
