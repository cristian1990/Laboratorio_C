#include <stdio.h>
#include <stdlib.h>

//hacer un programa que cree un archivo de texto

FILE *pArchivo;

int main()
{
    char direccion[] = "C:\\Users\\cristian\\Desktop\\REPASANDO\\Crear_archivo_texto\\cristian.dat";

    pArchivo = fopen(direccion,"wb"); //w = write (escribir/crear)

    if(pArchivo == NULL)  // la carpeta no existe o no se puede crear el archivo por un error
    {
        printf("No se pudo crear el archivo");
    }
    else
    {
        printf("Se creo el archivo");
        printf("\nUbicacion: %s\n",direccion);
    }

    return 0;
}
