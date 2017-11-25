#include <stdio.h>
#include <stdlib.h>

FILE *archivo;

int main()
{
    int c;
    char direccion[]="C:\\Users\\cristian\\Desktop\\REPASANDO\\Archivos\\agregar_texto_a_TXT\\archivo.txt";

    archivo = fopen(direccion,"at"); //at = add text (agregar texto despues de lo que tengoi)

    if(archivo == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }

    while((c=getchar())!=EOF)
    {
        fputc(c,archivo);
    }
    fclose(archivo);

    return 0;
}
