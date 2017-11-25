#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "utn.h"


int main()
{
	EMovie peliculas[CANT];
	char seguir='s';
	char guardar= 's';
	int i;

		for( i=0; i<CANT; i++)
		peliculas[i].idPelicula=0;

	if(cargarDesdeArchivo(peliculas))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");


	system("cls");
	do
	{
		switch(menu())
		{
			case '1':
				system("cls");
				alta(peliculas);
				break;
			case '2':
				system("cls");
				baja(peliculas);
				break;
			case '3':
				system("cls");
				modificar(peliculas);
				break;
			case '4':
                system("cls");
                crearHtml(peliculas);
                break;
            case '5':
				system("cls");
				listar(peliculas);
				break;
			case '6':

				printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar=='s' || guardar=='S')
				{
					if(guardarEnArchivo(peliculas))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
				break;

		}
	}while(seguir=='s');
	printf("\n");
	system("pause");
}

