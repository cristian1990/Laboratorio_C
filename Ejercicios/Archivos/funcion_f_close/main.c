#include <stdio.h>
#include <stdlib.h>
//abrir 2 archivos de texto y luego cerrarlos con la funcion fclose()

FILE *archivo1, archivo2;

int main()
{
    archivo1 = fopen("C:\Users\cristian\Desktop\REPASANDO\Archivos\funcion_f_close\archivo.txt",a+); //modo (a+) : modifica, añade al final del archivo
    archivo2 = fopen("C:\Users\cristian\Desktop\REPASANDO\Archivos\funcion_f_close\archivo1.txt",a+);

    if(archivo1 == NULL || archivo2 == NULL)
    {
        printf("No se pudo comprobar los archivos");
    }
    else
    {
        printf("Si se pudieron comprobar los archivos");
    }

    //cerrar los archivos con fclose()

    fclose(archivo1); //cierra el archivo pero no permanece arbierto y la memoria del buffer no permanece llena
    fclose(archivo2);

    return 0;
}
