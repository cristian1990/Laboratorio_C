/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses
*/

#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList{
    int size; //indica la sig pocision del array disponible para cargar
    void **pElements; //puntero a vector de punteros a void
    int reservedSize; //tama�o total del array pElements, esta var es la que se incrementa

    int     (*add)(); //añade un nuevo elemento al array pElements
    int     (*len)(); //retorna la cantidad de datos cargados (size)
    int     (*contains)(); //retorna si encontro el puntero(que se le pasa como argumento) dentro de pElements
    int     (*set)(); // inserta un puntero en el index pasado como parametro
    int     (*remove)(); // elimina del arraylist un elemento de forma fisica y logica
    int     (*clear)(); //reinisia el puntero pElements de forma logica y con resizeDown de forma fisica
    int     (*push)(); // llama al expand y luego hace un set insertando en el index que se le pasa como parametro si el index es igual al reserved size llama a la funcion add
    int     (*indexOf)(); //retorna la hubicacion de un puntero(que se le pasa como argumento) dentro de pElements
    int     (*isEmpty)(); //retorna si pElements esta vacio o no
    void*   (*get)(); //retorna el puntero en la pocision que se le pasa como argumento
    void*   (*pop)(); //???????????? llamo al contract toma la referecnocia hace un get del dato toma un auxiliar llama al remove y llama al contract y resie...dodoe
    int     (*containsAll)(); // Compara dos array list y devuelve 1 si son iguales 0 si no lo son y -1 si los punteros son NULL o falla la operacion
    int     (*sort)(); // ordena el la estructura en base a los paramtros pasados por la funcion de forma ascendente o desendente
    struct ArrayList* (* clone)(); // Clona el arraylist, NO ASIGA EL PUNTERO A OTRO sino que cada elemento del arraylist lo asigna a otro array
    struct ArrayList* (*subList)(); // crea un nuevo arraylist asigandole desde a donde a donde carga el subpuntero
    int     (*deleteArrayList)(); //libera el arrayList

}typedef ArrayList;
#endif

/*/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void);
/*
	Crea y retorna un nuevo ArrayList. Es el constructor, ya que en él daremos valores iniciales a
	las variables y asignaremos las funciones a sus punteros.

	Ejemplo uso:
		ArrayList* lista;
		lista = al_newArrayList();


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement);
/*
	Agrega un elemento al final de ArrayList. Verificando que tanto el puntero pList como pElement
	sean distintos de NULL. Si la verificación falla la función retorna (-1) y si tiene éxito (0).

	Ejemplo uso:
		Persona auxPersona;
		r = lista->add(lista,&auxPersona);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList);
/*
	Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL. Si la verificación
	falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).

	Ejemplo uso:
		r = lista->deleteArrayList(lista);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList);
/*
	Retorna el tamaño del ArrayList. Verificando que el puntero pList sea distinto de NULL. Si la
	verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.

	Ejemplo uso:
		longitud = lista->len(lista);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index);
/*
	Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
	puntero pList sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
	verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.

	Ejemplo uso:
		Persona* elemento;
		elemento = (Persona*)lista->get(lista,5);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement);
/*
	Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
	puntero pList como pElement sean distintos de NULL. Si la verificación falla la función retorna
	(-1) , si encuentra el elemento (1) y si no lo encuentra (0).

	Ejemplo uso:
		if(lista->contains(lista,&auxPersona))
		printf (“SI”);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement);
/*
	Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
	pList como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del
	array. Si la verificación falla la función retorna (-1) y si tiene éxito (0).

	Ejemplo uso:
		Persona auxPersona;
		r = lista->set(lista,4,&auxPersona);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index);
/*
	Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero pList
	sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
	falla la función retorna (-1) y si tiene éxito (0).

	Ejemplo uso:
		r = lista->remove(lista,5);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList);
/*
	Borra todos los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL.
	Si la verificación falla la función retorna (-1) y si tiene éxito (0).

	Ejemplo uso:
		r = lista->clear(lista);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList);
/*
	Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero pList sea
	distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
	nuevo array.

	Ejemplo uso:
		ArrayList* arrayClon;
		arrayClon = lista->clone(lista);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement);
/*
	Desplaza los elementos e inserta en la posición index. Verificando que tanto el puntero pList
	como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del array.
	Si la verificación falla la función retorna (-1) y si tiene éxito (0).

	Ejemplo uso:
		Persona auxPersona;
		r = lista->set(lista,6,&auxPersona);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement);
/*
	Retorna el índice de la primera aparición de un elemento (element) en el ArrayList. Verificando
	que tanto el puntero pList como pElement sean distintos de NULL. Si la verificación falla o no
	encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.

	Ejemplo uso:
		r = lista->indexOf(lista,&auxPersona))


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList);
/*
	Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero pList sea
	distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
	elementos (0).

	Ejemplo uso:
		if(lista->isEmpty(lista))
		printf (“Esta vacío”);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index);
/*
	Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
	de la lista. Verificando que el puntero pList sea distinto de NULL y que index sea positivo e
	inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
	retorna el elemento.

	Ejemplo uso:
		Persona* elemento;
		elemento = (Persona*)lista->pop(lista,5);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to);
/*
	Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero pList
	sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
	del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo

	Ejemplo uso:
		Persona* elemento;
		elemento = (Persona*)lista->pop(lista,5);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2);
/*
	Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
	puntero pList como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
	elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna (1).

	Ejemplo uso:
		if(lista->containsAll(lista_A,lista_B)))
		printf (“Contienen los mismos elementos”);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order);
/*
	Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
	de determinar que elemento es mas grande que otro y si se debe ordenar de manera
	ascendente o descendente. Verificando que tanto el puntero pList como el puntero a la funcion
	pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).

	Ejemplo de uso
		r = lista->sort(lista, comparePersonas,1);


/////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList);

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index);

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index);


// ------------------------------------ //
// -------- Private function ---------- //
// ------------------------------------ //


/*////////////////-------------------////////////////////////-----------------------///////////////////////*/


/** \brief  Aumenta en memoria el tamano del arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int resizeUp(ArrayList* pList);


/*////////////////-------------------////////////////////////-----------------------///////////////////////*/

/** \brief  Expande en +1 el arrayList a partir de una posicion
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index);


/*////////////////-------------------////////////////////////-----------------------//////////////////////*/


/** \brief  "Contrae" Elimina un elemento del arrayList de forma logica y fisica liberando espacio en memoria si es necesario
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index);


/*////////////////-------------------////////////////////////-----------------------//////////////////////*/


/** \brief  Evalua si es necesario liberar espacio libre del arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int resizeDown(ArrayList* pList);


/*////////////////-------------------////////////////////////-----------------------//////////////////////*/
