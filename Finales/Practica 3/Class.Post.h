#include "ArrayList.h"

//Class for post type
typedef struct
{
  int _id_mensaje;
  int _id_usuario_p;
  int _popularidad_p;
  char _mensaje[100000];
}EPost;

//Metodos for class

EPost* __newPost();

int bundle_parserPosts(ArrayList* pList, char file_name[]);

void bundle_loopPost(ArrayList* pList);
