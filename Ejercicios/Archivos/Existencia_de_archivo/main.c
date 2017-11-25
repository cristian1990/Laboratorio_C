#include <stdio.h>
#include <stdlib.h>

//Funcion fopen para determinar si existe un archivo o no

FILE *fd;  //puntero a archivo  -- puntero fd del tipo archivo

int main()
{
    char direccion[] = "C:\\Users\\cristian\\Desktop\\REPASANDO\\Archivos\\Existencia_de_archivo\\hola.txt";
    fd = fopen(direccion,"r"); //r = read (leer)

    if(fd == NULL) //si archivo no existe
    {
        printf("El archivo no existe");
    }
    else
    {
        printf("Se encontro el archivo\n");
        printf("\nUbicacion: %s\n",direccion);
    }


    return 0;
}
