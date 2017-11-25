#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int calificacion;
}nota;

typedef struct{
    nota p_examen, rec_examen;
}parcial;

typedef struct{
    char nombre[15];
    parcial p_parcial , sparcial;
}materias;

typedef struct{
    char apellido[30];
    int legajo;
    materias materia;
}alumno;



int main()
{
    printf("Hello world!\n");
    return 0;
}
