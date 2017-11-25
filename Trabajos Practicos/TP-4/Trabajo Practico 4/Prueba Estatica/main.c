#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


void printArrayListEmployee(ArrayList* lista)
{
  int i=0;
  for(i=0;i<lista->len(lista);i++)
  {
      Employee* pAux = lista->get(lista,i);
      printf("%d) ",i);
      printEmployee(pAux);
  }
}

int main()
{
     // Genero personas para usar en el ArrayList
    Employee* p0 = newEmployee(14, "JUAN1" ,"LOPEZ", 8500.22,5);
    Employee* p1 = newEmployee(14, "JUAN2" ,"LOPEZ", 9000.22,5);
    Employee* p2 = newEmployee(14, "JUAN3" ,"LOPEZ", 11000.22,5);
    Employee* p3 = newEmployee(14, "JUAN4" ,"LOPEZ", 7500.22,5);

    printEmployee(p0);
    printEmployee(p1);
    printEmployee(p2);
    printEmployee(p3);
    //__________________________________________


    printf("\r\nCargo ArraList...\r\n");
    ArrayList* lista = al_newArrayList();
    lista->add(lista,p0);
    lista->add(lista,p1);
    lista->add(lista,p2);
    al_add(lista,p3); // forma no orientada a objetos
    printArrayListEmployee(lista);

    printf("\r\nRemuevo index 2\r\n");
    lista->remove(lista,2);
    printArrayListEmployee(lista);

    printf("\r\nContiene p0 ?\r\n");
    if(lista->contains(lista,p0))
        printf("SI");
    else
        printf("NO");

    printf("\r\nContiene p2 ?\r\n");
    if(lista->contains(lista,p2))
        printf("SI");
    else
        printf("NO");

    printf("\r\nAgrego p2 en la posicion 1\r\n");
    lista->set(lista,1,p2); // vuelvo a agregar p2
    printArrayListEmployee(lista);


    printf("\r\nClonamos array\r\n");
    ArrayList* lista2 = lista->clone(lista);
    printf("Lista original:%p\r\n",lista);
    printArrayListEmployee(lista);


    printf("Lista Clonada:%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,1);
    printf("Lista Clonada Ordenada por Edad (UP):%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,0);
    printf("Lista Clonada Ordenada por Edad (DOWN):%p\r\n",lista2);
    printArrayListEmployee(lista);

    printf("\r\nlista clonada contiene lista?:");
    if(lista->containsAll(lista,lista2))
        printf("SI");
    else
        printf("NO");


    printf("\r\n\r\nPosicion de p2:");
    int index = lista->indexOf(lista,p2);
    printf("%d\r\n",index);
    printf("\r\nPosicion de p1:");
    index = lista->indexOf(lista,p1);
    printf("%d\r\n",index);


    printf("\r\n\r\nHacemos push de p1 en la posicion 1\r\n");
    lista->push(lista,1,p1);
    printArrayListEmployee(lista);


    printf("\r\nObtenemos sub-lista de 1 a 2\r\n");
    ArrayList* subLista = lista->subList(lista,1,2);
    printArrayListEmployee(subLista);


    printf("\r\n\r\nHacemos pop de p1 en la posicion 1\r\n");
    Employee* p1Aux = lista->pop(lista,1);
    printf("Elemento pop(): %s\r\n",p1Aux->name);
    printArrayListEmployee(lista);


    printf("\r\nClear array\r\n");
    lista->clear(lista);
    printArrayListEmployee(lista);

    printf("\r\nEsta vacio?\r\n");
    if(lista->isEmpty(lista))
        printf("SI");
    else
        printf("NO");

    // Test expansion/contraccion del size
    printf("\r\n\r\nTest size\r\n");
    int j;
    for(j=0; j<1100; j++)
    {
      Employee* pAux = malloc(sizeof(Employee));
      sprintf(pAux->name,"Juan %d",j);
      pAux->salary=j;
      lista->add(lista,pAux);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    for(j=0; j<1100; j++)
    {
      lista->pop(lista,0);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    //____________________________________

    printf("\r\nLibero memoria y termino\r\n");
    free(p0);
    free(p1);
    free(p2);
    free(p3);
    lista->deleteArrayList(lista);
    lista2->deleteArrayList(lista2);

    system("PAUSE");
    return 0;
}
