#include "trabajo.h"
/** \brief Multiplica dos numeros
 *
 * \param Acepta un numero
 * \param Acepta un numero
 * \return retorna la multiplicacion de ambos numeros
 *
 */

//Calcula la multiplicacion de dos numeros. (a * b)
int multiplicacion(int a, int b)
{
    int mult;
    mult=a * b;
    return mult;
}
//Calcula la resta de dos numeros. (a - b)
int restar(int a, int b)
{
    int resta;
    resta = a - b;
    return resta;
}
//Calcula la suma de dos numeros. (a + b)
int sumar(int a, int b)
{
    int suma;
    suma=a + b;
    return suma;
}
//Calcula la division de dos numeros. (a / b)
int dividir(int a, int b)
{
    int divi;
    divi=a / b;
    return divi;
}
//Calcula el factorial de un numero. (a)
int factorial(int a)
{
    int i, fact=1;
    for (i=1 ; i<=a ; i++){
        fact=fact*i;}
    return fact;
}
