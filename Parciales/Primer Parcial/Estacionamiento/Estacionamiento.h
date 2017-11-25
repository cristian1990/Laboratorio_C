
#define CANT_AUTO 100
#define CANT_LUGAR 10

typedef struct{
int idProfesor;
int estado; // 1.activo - 0.Inactivo
}Estacionamiento;

typedef struct{
char patente[51];
char marca[51];
char modelo[51];
int idProfesor;
int estado; // 1.activo - 0.Inactivo
int estadoEst; //1.estacionado - 0 no estacionado
}Autos;


void administrarAutos(Autos autoArray[]);
void establecerEstadoAuto(Autos autoArray[], int arrayLargo, int valor);
void ordenarAutoArrayPorMarca(Autos autoArray[],int largoArray);
int encontrarAutoPorId(Autos autoArray[],int largoArray, int idProf);
int encontrarLugarVacioAuto(Autos autoArray[],int largoArray);
void mostrarArrayAuto(Autos autoArray[], int largoArray);
void establecerValoresAuto(Autos autoArray[], int indiceLugarLibre, char patenteAux[], char marcaAux[], char modeloAux[], int idProfAux);

void administrarEstacionamiento(Estacionamiento estacionamientoArray[], Autos autoArray[]);
void establecerEstadoEstacionamiento(Estacionamiento estacionamientoArray[],int largoArray,int valor);
int encontrarLugarVacioEstacionamiento(Estacionamiento estacionamientoArray[],int largoArray);
int encontrarprofesorPorId(Estacionamiento estacionamientoArray[],int largoArray, int idProf);
void establecerValoresEstacionamiento(Estacionamiento estacionamientoArray[], int indiceLugarLibre, int idProfAux);
void mostrarArrayEstacionamiento(Estacionamiento estacionamientoArray[], int largoArray);






