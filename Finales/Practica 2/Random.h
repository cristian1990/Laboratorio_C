#include "ArrayList.h"

typedef struct
{
  char _id[100];
  int _dni;
  int _tramite;
  int _estado;
}ETramite;

ETramite* __reserved();

int bundle_alta(char msg[], ArrayList* pList,char turno[], int type);

void bundle_loop(ArrayList* pList);

void bundle_loop2(ArrayList* pList);

int bundle_resolved(ArrayList* pList, ArrayList* pResolved);

int bundle_order(ETramite* pTramite1, ETramite* pTramite2);
