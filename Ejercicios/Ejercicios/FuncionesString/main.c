#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char contrasena[20];
    char adv1[] = "contrasenia";
    char adv2[] = " incorrecta\n";
    char cCorrecta[20];
    int cLetras;
    printf("\nIngrese la contrasenia: ");
    gets(contrasena);
    if(strcmp(contrasena,"1234")==0){
        strcpy(cCorrecta,"contrasenia correcta\n");
        printf("%s",cCorrecta);
    }
    else{
        cLetras = strlen(contrasena);
    }if(cLetras>5 || cLetras<=3){
        strcat(adv1,adv2);
        printf("%s",adv1);
    }
    return 0;
}
