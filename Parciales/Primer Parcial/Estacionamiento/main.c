#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estacionamiento.h"
#include "utn.h"

void administrarAutos(Autos autoArray[]);
void administrarEstacionamiento(Estacionamiento estacionamientoArray[], Autos autoArray[]);
void listarAutosEstacionados(Autos arrayAuto[], int largoArrayAuto);
void listarAutosMarca(Estacionamiento estacionamientoArray[], int largoArray, Autos autoArray[], int largoArrayAuto);
void listarAutosFueraEstacionamiento(Autos autoArray[], int largoArray);

int main()
{
    //array de autos
    Autos autoArray[CANT_AUTO];
    establecerEstadoAuto(autoArray , CANT_AUTO , 0);
    //..................................

    //array de estacionamiento
    Estacionamiento estacionamientoArray[CANT_LUGAR];
    establecerEstadoEstacionamiento(estacionamientoArray , CANT_LUGAR , 0);

    //alta de datos para testing
    establecerValoresAuto(autoArray,0,"AAA 485","FIAT","MOBI",1);
    establecerValoresAuto(autoArray,1,"BBB 215","FORD","FOCUS",2);
    establecerValoresAuto(autoArray,2,"CCC 875","PEUGEOT","PREMIUM",3);
    establecerValoresAuto(autoArray,3,"DDD 232","OTRO","LINEA",4);
    establecerValoresAuto(autoArray,4,"EEE 215","FIAT","PALIO",5);
    establecerValoresAuto(autoArray,5,"FFF 987","FORD","FIESTA",6);
    establecerValoresAuto(autoArray,6,"GGG 233","PEUGEOT","ELEGANT",7);
    establecerValoresAuto(autoArray,7,"HHH 447","OTRO","GALAXY",8);
    establecerValoresAuto(autoArray,8,"EEE 959","FIAT","PUNTO",9);
    establecerValoresAuto(autoArray,9,"FFF 745","FORD","ECO SPORT",10);


    //................................

    int opcion = 0;

    while(opcion != 4)
    {
        system("CLS");
        printf("\n----------- MENU PRINCIPAL ----------");
        opcion = obtenerInt("\n1 - ABM AUTOS \n2 - ABM ESTACIONAMIENTO \n3 - SALIR\n\n\n");
        switch(opcion)
        {
            case 1: //ABM AUTOS
                administrarAutos(autoArray);
                break;

            case 2: //ABM ESTACIONAMIENTO
                administrarEstacionamiento(estacionamientoArray, autoArray);
                break;

        }

    }

    return 0;
}


 void administrarAutos(Autos autoArray[])
 {
     //variables auxiliares
     char patenteAux[51];
     char marcaAux[51];
     char modeloAux[51];
     int idProfAux;
     int bandera = 0;
     //..........................

     int indiceLugarLibre;
     int indiceEncontrado;
     int opcion = 0;

     while(opcion != 5)
     {
         system("CLS");
         printf("\n----------- ABM AUTOS ----------");
         opcion = obtenerInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION \n4 - LISTAR \n5 - REGRESAR\n\n\n");

         switch(opcion)
         {
            case 1: //ALTA AUTO

                indiceLugarLibre = encontrarLugarVacioAuto(autoArray , CANT_AUTO);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    obtenerChar("\n\nENTER (para continuar)");
                    break;
                }

                idProfAux = obtenerIntValido("Ingrese el id del profesor: " , "El id del profesor debe ser numerico", 1, 100);
                if(encontrarAutoPorId(autoArray , CANT_AUTO , idProfAux) != -1)
                {
                    printf("\n\nEL ID YA EXISTE!!!\n");
                    obtenerChar("\n\nENTER (para continuar");
                    break;
                }

                obtenerStringValidoAlfanumerico("Ingrese la patente: " , "Caracteres no validos en la patente\n" , patenteAux);

                obtenerStringValidoAlfanumerico("Ingrese la marca: " , "Caracteres no validos en la marca\n" , marcaAux);

                obtenerStringValidoAlfanumerico("Ingrese el modelo: " , "Caracteres no validos en el modelo\n" , modeloAux);

                establecerValoresAuto(autoArray , indiceLugarLibre , patenteAux , marcaAux , modeloAux , idProfAux);
                bandera = 1;

                printf("\nDatos cargados!!!\n\n");
                system("PAUSE");

                break;


                case 2: //BAJA AUTO

                if (bandera == 1){
                idProfAux = obtenerIntValido("Ingrese el id del profesor a dar de baja: " , "El id debe ser numerico" ,1,100);
                indiceEncontrado = encontrarAutoPorId(autoArray , CANT_AUTO , idProfAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    obtenerChar("\n\nENTER (para continuar)");
                    break;
                }
                autoArray[indiceEncontrado].estado = 0;

                printf("\n\nDado de baja!!!\n\n");
                system("PAUSE");
                break;
                }
                else{
                    printf("\nPrimero Ingrese un auto!\n");
                    system("PAUSE");
                    break;
                    }



            case 3: //MODIFICAR DATOS
                if (bandera == 1){
                idProfAux = obtenerIntValido("ingrese el id del profesor a modificar: " , "El id debe ser numerico", 1,100);
                indiceEncontrado = encontrarAutoPorId(autoArray , CANT_AUTO , idProfAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    obtenerChar("\n\nENTER (para continuar)");
                    break;
                }

                idProfAux = obtenerIntValido("Ingrese el nuevo id del profesor: " , "El id del profesor debe ser numerico", 1, 100);
                if(encontrarAutoPorId(autoArray , CANT_AUTO , idProfAux) != -1)
                {
                    printf("\n\nEL ID YA EXISTE!!!\n");
                    obtenerChar("\n\nENTER (para continuar");
                    break;
                }

                obtenerStringValidoAlfanumerico("Ingrese la patente: " , "Caracteres no validos en la patente\n" , patenteAux);

                obtenerStringValidoAlfanumerico("Ingrese la marca: " , "Caracteres no validos en la marca\n" , marcaAux);

                obtenerStringValidoAlfanumerico("Ingrese el modelo: " , "Caracteres no validos en el modelo\n" , modeloAux);

                establecerValoresAuto(autoArray , indiceLugarLibre , patenteAux , marcaAux , modeloAux , idProfAux);

                printf("\nDatos modificados!!!\n\n");
                }
                else{
                    printf("\nPrimero Ingrese un auto!\n");
                    system("PAUSE");
                    break;
                    }
                system("PAUSE");

                break;

                case 4: //LISTAR
                if (bandera == 1){
                system("CLS");
                printf(" \n------ AUTOS HABILITADOS PARA ESTACIONAR ------\n");
                ordenarAutoArrayPorMarca(autoArray ,CANT_AUTO);
                mostrarArrayAuto(autoArray , CANT_AUTO);
                obtenerChar("\n\nENTER (para continuar)");
                }else{
                    printf("\nPrimero Ingrese un auto!\n");
                    system("PAUSE");
                    break;
                    }
                system("PAUSE");

                break;

         }
     }
 }



void administrarEstacionamiento(Estacionamiento estacionamientoArray[], Autos autoArray[])
{

    //alta de datos para testing
    establecerValoresAuto(autoArray,0,"AAA 485","FIAT","MOBI",1);
    establecerValoresAuto(autoArray,1,"BBB 215","FORD","FOCUS",2);
    establecerValoresAuto(autoArray,2,"CCC 875","PEUGEOT","PREMIUM",3);
    establecerValoresAuto(autoArray,3,"DDD 232","OTRO","LINEA",4);
    establecerValoresAuto(autoArray,4,"EEE 215","FIAT","PALIO",5);
    establecerValoresAuto(autoArray,5,"FFF 987","FORD","FIESTA",6);
    establecerValoresAuto(autoArray,6,"GGG 233","PEUGEOT","ELEGANT",7);
    establecerValoresAuto(autoArray,7,"HHH 447","OTRO","GALAXY",8);
    establecerValoresAuto(autoArray,8,"EEE 959","FIAT","PUNTO",9);
    establecerValoresAuto(autoArray,9,"FFF 745","FORD","ECO SPORT",10);

    //................................

    //variables auxiliares
    int idProfAux;
    int horaEntAux;
    int horaSalAux;
    int resHora;
    int profeSinLugar = 0;
    //................................

    int indiceLugarLibre;
    int indiceEncontrado;
    int flag = 0;
    int opcion = 0;

    while(opcion != 4)
    {
        system("CLS");
        printf("\n-------- AMB ESTACIONAMIENTO --------"); //INGRESO, EGRESO, INFORMAR
        opcion = obtenerInt("\n1 - INGRESO \n2 - EGRESO \n3 - INFORMAR \n4 - REGRESAR\n\n\n");
        switch(opcion)
        {
           case 1: //INGRESO

                idProfAux = obtenerIntValido("Ingrese el id del profesor: " , "El id del profesor debe ser numerico",1,100);

                indiceLugarLibre = encontrarLugarVacioEstacionamiento(estacionamientoArray , CANT_LUGAR);
                if(indiceLugarLibre == -1)
                {
                   printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                   profeSinLugar = idProfAux;
                   flag = 1;
                   obtenerChar("\n\nENTER (para continuar)");
                   break;
                }


                indiceEncontrado = encontrarAutoPorId(autoArray , CANT_AUTO , idProfAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    obtenerChar("\n\nENTER (para continuar)");
                    break;
                }


               if(encontrarprofesorPorId(estacionamientoArray , CANT_LUGAR , idProfAux) != -1)
               {
                   printf("\n\nEL CODIGO YA EXISTE!!!\n");
                   obtenerChar("\n\nENTER (para continuar)");
                   break;
               }
               horaEntAux = obtenerIntValido("Ingrese la hora de entrada entre 8 a 22hs.: " , "La hora debe ser numerica",8,22);

               establecerValoresEstacionamiento(estacionamientoArray , indiceLugarLibre , idProfAux);
               autoArray[indiceEncontrado].estadoEst = 1;

               printf("\nAuto ingresado!!!\n\n");
               system("PAUSE");

               break;

            case 2: //EGRESO

                idProfAux = obtenerIntValido("Ingrese el codigo del profesor: " , "El id debe ser numerico", 1,100);
                indiceEncontrado = encontrarprofesorPorId(estacionamientoArray , CANT_LUGAR , idProfAux);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    obtenerChar("\n\nENTER (para continuar)");
                    break;
                }
                horaSalAux = obtenerIntValido("Ingrese la hora de salida 8 a 22 hs.: " , "la hora debe ser numerica", 8,22);
                estacionamientoArray[indiceEncontrado].estado = 0;
                autoArray[indiceEncontrado].estadoEst = 0;
                resHora = (horaSalAux - horaEntAux);

                printf("\nAuto egresado!!!\n");

                switch(resHora){
                case 5:
                    printf("Debe pagar $100\n\n");
                    break;
                case 6:
                    printf("Debe pagar $200\n\n");
                    break;
                case 7:
                    printf("Debe pagar $300\n\n");
                    break;
                case 8:
                    printf("Debe pagar $400\n\n");
                    break;
                case 9:
                    printf("Debe pagar $500\n\n");
                    break;
                case 10:
                    printf("Debe pagar $600\n\n");
                    break;
                case 11:
                    printf("Debe pagar $700\n\n");
                    break;
                case 12:
                    printf("Debe pagar $800\n\n");
                    break;
                case 13:
                    printf("Debe pagar $900\n\n");
                    break;
                case 14:
                    printf("Debe pagar $1000\n\n");
                    break;
                default:
                    printf("No de pagar\n\n");
                }

                if(flag == 1)
                {
                    printf("El id del profesor sin lugar es: %i\n\n",profeSinLugar);
                }
                flag = 0;
                system("PAUSE");

                break;

            case 3: //INFORMAR
                system("CLS");
                printf(" \n\n------ AUTOS ESTACIONADOS ------\n");
                listarAutosEstacionados(autoArray, CANT_AUTO);
                printf(" \n\n------ AUTOS ESTACIONADOS MARCA FIAT ------\n");
                listarAutosMarca(estacionamientoArray , CANT_LUGAR, autoArray, CANT_AUTO);
                printf(" \n\n------ AUTOS FUERA DEL ESTACIONAMIENTO ------\n");
                listarAutosFueraEstacionamiento(autoArray , CANT_AUTO);
                printf(" \n------ AUTOS HABILITADOS PARA ESTACIONAR ------\n");
                ordenarAutoArrayPorMarca(autoArray ,CANT_AUTO);
                mostrarArrayAuto(autoArray , CANT_AUTO);

                obtenerChar("\n\nENTER (para continuar)");
                break;

        }

    }
}

 void listarAutosEstacionados(Autos autoArray[], int largoArray)
 {


     int i;
     printf("\n| PATENTE |      MARCA      |    MODELO   | ID PROFESOR |");
     for(i=0; i<largoArray; i++)
     {
         if(autoArray[i].estado!=0)
         {
             if(autoArray[i].estadoEst !=0)
             {
                printf("\n| %6s | %-15s | %11s | %11i |",autoArray[i].patente, autoArray[i].marca, autoArray[i].modelo, autoArray[i].idProfesor);
             }

         }
     }
 }


    /**
 * \brief Muestra los autos de la marca FIAT por pantalla
 * \param estacionamientoArray Es el array de estacionamiento
 * \param largoArray Indica la longitud del array
 * \return -
 *
 */

 void listarAutosMarca(Estacionamiento estacionamientoArray[], int largoArray, Autos autoArray[], int largoArrayAuto)
 {

    //alta de datos para testing
    establecerValoresAuto(autoArray,0,"AAA 485","FIAT","MOBI",1);
    establecerValoresAuto(autoArray,1,"BBB 215","FORD","FOCUS",2);
    establecerValoresAuto(autoArray,2,"CCC 875","PEUGEOT","PREMIUM",3);
    establecerValoresAuto(autoArray,3,"DDD 232","OTRO","LINEA",4);
    establecerValoresAuto(autoArray,4,"EEE 215","FIAT","PALIO",5);
    establecerValoresAuto(autoArray,5,"FFF 987","FORD","FIESTA",6);
    establecerValoresAuto(autoArray,6,"GGG 233","PEUGEOT","ELEGANT",7);
    establecerValoresAuto(autoArray,7,"HHH 447","OTRO","GALAXY",8);
    establecerValoresAuto(autoArray,8,"EEE 959","FIAT","PUNTO",9);
    establecerValoresAuto(autoArray,9,"FFF 745","FORD","ECO SPORT",10);

    //................................

     int i;
     int profIdAux;
     int indiceEncontrado;
     printf("\n| PATENTE |      MARCA      |    MODELO   | ID PROFESOR |");
     for(i=0; i<largoArray; i++)
     {
         if(estacionamientoArray[i].estado != 0)
         {
             profIdAux = estacionamientoArray[i].idProfesor;
             indiceEncontrado = encontrarAutoPorId(autoArray , CANT_AUTO , profIdAux);
             if(indiceEncontrado == -1)
             {
                 printf("\n\nNO HAY AUTOS ESTACIONADOS DE ESA MARCA\n");
                 obtenerChar("\n\nENTER (para continuar)");
                 break;
             }
             if(strcmp(autoArray[indiceEncontrado].marca , "FIAT") == 0)
             {
                 printf("\n| %6s | %-15s | %11s | %11i |",autoArray[indiceEncontrado].patente, autoArray[indiceEncontrado].marca, autoArray[indiceEncontrado].modelo, autoArray[indiceEncontrado].idProfesor);
             }

         }

     }

 }


  /**
 * \brief Muestra los autos fuera del estacionamiento
 * \param autoArray Es el array de autos
 * \param largoArray Indica la longitud del array
 * \return -
 *
 */
 void listarAutosFueraEstacionamiento(Autos autoArray[], int largoArray)
 {

     int i;
     printf("\n| PATENTE |      MARCA      |    MODELO   | ID PROFESOR |");
     for(i=0; i<largoArray; i++)
     {
         if(autoArray[i].estado!=0)
         {
             if(autoArray[i].estadoEst !=1)
             {
                printf("\n| %6s | %-15s | %11s | %11i |",autoArray[i].patente, autoArray[i].marca, autoArray[i].modelo, autoArray[i].idProfesor);
             }
         }
     }
 }


