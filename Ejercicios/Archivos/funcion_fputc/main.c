#include <stdio.h>
#include <stdlib.h>

//funcion fputs para introducir caracteres en un archivo de texto (txt)

FILE *archivo;

int main()
{
    int c; //caracter
    char direccion[] = "C:\\Users\\cristian\\Desktop\\REPASANDO\\Archivos\\funcion_fputc\\archivo.txt";

    archivo = fopen(direccion,"wt"); //modo (wt) crea y excribe texto

    if(archivo == NULL)
    {
        printf("Error al crear archivo");
        return 1; //porque finalizo con errores (no se pudo crear el archivo)
    }

    while((c = getchar()) !=EOF) //pide caracter mientras no sea el final del archivo
    {
        fputc(c,archivo);
    }
    fclose(archivo);

    return 0; //finalizo correctamente
}
