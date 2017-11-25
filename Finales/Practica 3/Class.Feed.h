#include "ArrayList.h"

//Class for post type
typedef struct
{
  int _id_mensaje_f;
  char _mensaje_f[100000];
  int _popularidad_m_f;
  int _id_usuario_f;
  char _nick_name_f[50];
  int _popularidad_u_f;
}EFeed;

//Metodos for class

EFeed* __newFeed();

int bundle_controllerFeed(ArrayList* pList, ArrayList* pUsers, ArrayList* pPosts);

int bundle_generateFeed(ArrayList* pList);

void bundle_loopFeed(ArrayList* pList);

int bundle_orderBy(EFeed* feed1, EFeed* feed2);
