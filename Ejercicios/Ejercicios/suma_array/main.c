#include <stdio.h>
#include <stdlib.h>

int sumar(int vec[]);

int main()
{
    int suma;
    int vector[5]= { 1, 2, 3, 4, 5};
	suma = sumar(vector);
	printf("La suma es: %d ", suma);
	return 0;
}

int sumar(int vec[])
{
    int i, total=0;
    for ( i = 0; i < 5; i++ ) {
      total += vec[i];
   }
	return total;
}
