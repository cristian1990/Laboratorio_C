#include "ArrayList.h"

//Class for user
typedef struct
{
  int _id_usuario_u;
  char _nick_name[50];
  int _popularidad_u;
}EUser;

//Metodos for class

EUser* __newUser();

int bundle_parserUsers(ArrayList* pList, char file_name[]);

void bundle_loop(ArrayList* pList);
