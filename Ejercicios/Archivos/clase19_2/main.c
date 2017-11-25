#include <stdio.h>

typedef struct{
		char nombre[31];
		int edad;
}a;

FILE  *bin;

int main (void)
{
	a persona;
	int cant;
	system("cls");
	if ((bin=fopen("bin.dat","rb"))==NULL)
	{
		printf("No se pudo abrir el archivo");
		exit(1);
	}
	while(!feof(bin))
	{
			cant=fread(&persona,sizeof(persona),1,bin);
			if(cant!=1)
			{
				if(feof(bin))
					break;
				else
				{
					printf("No leyo el ultimo registro");
					break;
				}
			}
			printf("\n%s\t%d",persona.nombre, persona.edad);
	}
	fclose(bin);
	getch();

	return 0;
}
