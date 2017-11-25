#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "utn.h"

  /**
 * \brief menu de seleccion
 * \param autoArray Es el array en el cual buscar
 * \return c
 *
 */
char menu()
{       char c;
	system("cls");
	printf("MENU\n1. AGREGAR PELICULA\n2. BORRAR PELICULA\n3. MODIFICAR PELICULA\n4. GENERAR PAGINA\n5. LISTADO DE PELICULAS\n6. SALIR\n");
	printf("\nElija una opcion: ");
	c=getche();
	return c;
}


 /**
 * \brief buscar el primer lugar no utilizado en el array
 * \param lasPeliculas Es el array en el cual buscar
 * \return Retorna un indice de lugar libre
 *
 */
int buscarLibre(EMovie lasPeliculas[])
{
	int index=-1;
	int i;
	for( i=0; i < CANT; i++)
	   if(lasPeliculas[i].idPelicula==0){
		index=i;
		break;
	   }
	return index;
}



  /**
 * \brief Agrega una pelicula
 * \param lasPeliculas Es el array en el cual buscar
 * \return -
 *
 */
void alta(EMovie lasPeliculas[])
{
	int index, i;
	int durAux, punAux;
	int idPelicula;
	int encontro=0;
	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(lasPeliculas);
	if(index!=-1)//si hay lugar:
	{

		printf("INGRESO DE DATOS:\n");
		printf("Ingrese id Pelicula: ");
		scanf("%d", &idPelicula);
		/*Buscamos si el legajo ya existe*/
		for(i=0; i<CANT; i++)
		{
			if(idPelicula==lasPeliculas[i].idPelicula)
			{
				encontro=1;//encontro en true
				break;
			}
		}
		if(!encontro)//entra si encontro==0
		{
			lasPeliculas[index].idPelicula=idPelicula;
			printf("Ingrese Titulo: ");
			fflush(stdin);
			gets(lasPeliculas[index].titulo);
			printf("Ingrese genero: ");
			fflush(stdin);
			gets(lasPeliculas[index].genero);
			printf("Ingrese duracion: ");
			scanf("%i", &durAux);
			lasPeliculas[index].duracion=durAux;
			printf("Ingrese descripcion: ");
			fflush(stdin);
			gets(lasPeliculas[index].descripcion);
			printf("Ingrese puntaje: ");
			scanf("%i", &punAux);
			lasPeliculas[index].puntaje=punAux;
			printf("Ingrese link de la imagen: ");
			fflush(stdin);
			gets(lasPeliculas[index].linkImagen);
			system("cls");
		}
		else
		{
			printf("­­El id de pelicula ingresado ya existe!!");
			getch();
		}
	}
	else
	{
		printf("No queda espacio");
		getch();
	}
}


 /**
 * \brief Imprime en pantalla las peliculas
 * \param lasPeliculas Es el array en el cual buscar
 * \return -
 *
 */
void toString(EMovie* unaPelicula)
{
	printf("\nID: %i\nTITULO: %s\nGENERO: %s\nPUNTAJE: %i\nDURACION: %i\nDESCRIPCION: %s\n\n\n", unaPelicula->idPelicula, unaPelicula->titulo, unaPelicula->genero, unaPelicula->puntaje, unaPelicula->duracion, unaPelicula->descripcion);
}


void listar(EMovie *lasPeliculas)
{
	int i,j;
	EMovie auxPeliculas;

	for(i=0; i<CANT-1;i++)
	{
		for(j=i+1; j<CANT; j++)
		{
			if(strcmp(lasPeliculas[i].titulo,lasPeliculas[j].titulo)>0)
			{
				auxPeliculas=lasPeliculas[i];
				lasPeliculas[i]=lasPeliculas[j];
				lasPeliculas[j]=auxPeliculas;
			}
		}
	}

	printf("\n--- LISTADO DE PELICULAS ---\n\n");
	for(i=0; i<CANT; i++)
	{
		if(lasPeliculas[i].idPelicula!=0)
		   toString((lasPeliculas + i));
	}
	getch();
}



  /**
 * \brief Borra una pelicula
 * \param lasPeliculas Es el array en el cual buscar
 * \return 0 cuando borra pelicula
 *
 */
void baja(EMovie* lasPeliculas)
{
	int idPelicula, flag=0,i;
	char opcion;
	printf("Ingrese id pelicula a dar de baja: ");
	scanf("%d", &idPelicula);
	for(i=0; i<CANT; i++)
	{
		if(idPelicula==lasPeliculas[i].idPelicula)
		{
			printf("Pelicula a eliminar:\n");

			toString((lasPeliculas + i));

			printf("\nId encontrado. Seguro desea dar de baja S/N?");
			opcion=getche();

			if(opcion=='s' || opcion=='S')
			{
				lasPeliculas[i].idPelicula=0;
				printf("­­Pelicula eliminada!!");
			}
			else
			{
				printf("La pelicula no fue eliminada!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Id pelicula inexistente");
		getch();
	}
}

  /**
 * \brief Modifica una pelicula
 * \param lasPeliculas Es el array en el cual buscar
 * \return -
 *
 */
void modificar(EMovie* lasPeliculas)
{
	int IdPelicula, flag=0,i;
	int durAux;
	int punAux;
	char auxTitulo[50];
	char auxGenero[50];
	char auxDescripcion[400];
	char opcion;
	system("cls");
	printf("Ingrese id de pelicula a modificar: ");
	scanf("%d",& IdPelicula);
	for( i=0; i<CANT; i++)
	{
		if(IdPelicula==lasPeliculas[i].idPelicula)
		{
			printf("Datos encontrados:\n");

			toString((lasPeliculas + i));

            fflush(stdin);
			printf("\nIngrese el nuevo titulo: ");
			gets(auxTitulo);
			fflush(stdin);
			printf("\nIngrese el nuevo genero: ");
			gets(auxGenero);
			fflush(stdin);
			printf("\nIngrese la nueva descripcion: ");
			gets(auxDescripcion);
			fflush(stdin);
			printf("\nIngrese la nueva duracion: ");
			scanf("%i", &durAux);
			printf("\nIngrese el nuevo puntaje: ");
			scanf("%i", &punAux);
			printf("Esta seguro que desea modificar S/N? ");
			opcion=getche();
			if(opcion=='s' || opcion=='S')
			{
			    strcpy(lasPeliculas[i].titulo,auxTitulo);
			    strcpy(lasPeliculas[i].genero,auxGenero);
                strcpy(lasPeliculas[i].descripcion,auxDescripcion);
				lasPeliculas[i].duracion=durAux;
				lasPeliculas[i].puntaje=punAux;

				printf("Registro modificado");
			}
			else
			{
				printf("El registro no fue modificado");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Id pelicula inexistente");
		getch();
	}
}

  /**
 * \brief Guarda en el datos archivo.bin
 * \param x Es el array en el cual buscar
 * \return 0 cuando borra pelicula
 *
 */
int guardarEnArchivo(EMovie * x)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),CANT,f);

	fclose(f);

	return 0;
}


  /**
 * \brief Carga datos desde el archivo.bin
 * \param x Es el array en el cual buscar
 * \return -
 *
 */
int cargarDesdeArchivo(EMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(x,sizeof(EMovie),CANT,f);
    }

	fclose(f);
	return 0;

}


  /**
 * \brief Crea un archivo de salida HTML
 * \param x Es el array en el cual buscar
 * \return -
 *
 */
void crearHtml(EMovie *x)
{
     int i;
     FILE *f;

     f=fopen("pagina.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
         for(i=0; i<CANT; i++)
         {
                  if(x[i].idPelicula != 0)
                  {
                  fprintf(f,"<article class='col-md-3 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Genero:%s</li> <li>Puntaje:%i</li> <li>Duracion:%i</li> </ul> <p>%s</p> </article>",x[i].linkImagen, x[i].titulo, x[i].genero, x[i].puntaje, x[i].duracion, x[i].descripcion);
                  }
         }
         fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    }

      fclose(f);

      printf("Listado creado con exito\n");
      system("pause");
}


