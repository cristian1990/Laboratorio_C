#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 5

typedef struct
{
    int legajo;
    float sueldo;
    char nombre[30];
}Empleado;

Empleado* constructorPorDefecto();
Empleado* constructorParametizado(int, float, char[]);

void mostrarEmpleado(Empleado*);
void mostrarEtipo(Empleado* this);

int main()
{
    Empleado* vector[T];
    Empleado* p;
    int i;
    int legajo;
    float sueldo;

    char nombre[30];

    for(i=0; i<T;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        p=constructorParametizado(legajo, sueldo, nombre);

        vector[i] = p;
    }


    for(i=0; i<T;i++)
    {
        mostrarEtipo(vector[i]);
    }
    return 0;
}

Empleado* constructorPorDefecto()//constructor por defecto
{
    Empleado* empleado;
    empleado = (Empleado*) malloc(sizeof(Empleado));
    return empleado;
}

Empleado* constructorParametizado(int legajoAux, float sueldoAux, char nombreAux[])
{
    Empleado* empleado;
    empleado = constructorPorDefecto();
    empleado->legajo = legajoAux;
    empleado->sueldo = sueldoAux;
    strcpy(empleado->nombre,nombreAux);
    return empleado;
}

void mostrarEtipo(Empleado* this)
{
     printf("%d--%f--%s\n", this->legajo, this->sueldo, this->nombre);
}



