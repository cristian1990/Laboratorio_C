typedef struct
{
    char name[30];
    char email[50];
}EPersona;

int al_cargar(ArrayList* pList,char value[]);
void al_show(ArrayList* pList);
int al_depurar(ArrayList* destinatarios, ArrayList* listaNegra, ArrayList* listaDepurada);
int al_cargarBlackList(ArrayList* destinatarios, ArrayList* listaNegra, char value[]);
