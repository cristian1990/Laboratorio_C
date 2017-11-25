
typedef struct
{
  char _letra[10];
  char _nombre[22];
  int _vocal;
  int _consonante;

}Eletras;

Eletras* __nuevaLetra();

void* lista_constructor();

int lista_CargarDatos(ArrayList* pList, char nArchivo[]);

int lista_nuevoDato(ArrayList* pList);

void lista_imprimirDatos(ArrayList* pList);

int lista_modificarDatos(ArrayList* pList, char msg[]);

void* lista_buscarLetra(ArrayList* pList, char value[]);

int lista_borrarDatos(ArrayList* pList, char msg[]);

int lista_completar(ArrayList* pList);

int lista_ordenar(void* pLetraA,void* pLetraB);

