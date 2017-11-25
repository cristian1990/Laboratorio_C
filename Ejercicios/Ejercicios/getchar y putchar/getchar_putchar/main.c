#include <stdio.h>
#include <stdlib.h>

//funcion getchar  lee caracter a caracter hasta llegar a EOF
//EOF final del archivo o cadena
//funcion putchar imprime caracter a caracter

int main()
{
    int c;

    while(EOF != (c=getchar())){//mientras no sea el final de la cadena que siga leyendo.
    putchar(c);
    }
    return 0;
}
