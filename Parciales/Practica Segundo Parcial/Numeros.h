
typedef struct
{
  int _numero;
  char _nombre[50];
  int _par;
  int _impar;
  int _primo;

}Enumeros;

Enumeros* __nuevoNumero();

void* lista_constructor();

int lista_CargarDatos(ArrayList* pList, char nArchivo[]);

int lista_nuevoDato(ArrayList* pList);

void lista_imprimirDatos(ArrayList* pList);

int lista_modificarDatos(ArrayList* pList, char msg[]);

void* lista_buscar(ArrayList* pList, int valor);

int lista_obtener(char msg[]);

int lista_borrarDatos(ArrayList* pList, char msg[]);

int lista_comprobar(int numero);

int lista_completar(ArrayList* pList);

void lista_informe();

int lista_generarListar(ArrayList* pList, ArrayList* pRep,ArrayList* pNoRep);

int lista_ordenar(Enumeros* pNum1, Enumeros* pNum2);
