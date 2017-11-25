#include <stdio.h>
#include <stdlib.h>

//Tomar un archivo txt creado, y con la funcion fgets() leer todo su contenido
// fgetc(puntero_archivo);

FILE *archivo;

int main()
{
    int caracter;
    archivo = fopen("bin.dat","rb"); // r = read text (leer texto)

    if(archivo == NULL)
    {
        printf("No se pudo leer el archivo");
        return 1;
    }
    while((caracter=fgetc(archivo)) != EOF)
    {
            printf("%c",caracter);
    }

    fclose(archivo);
    return 0;
}
