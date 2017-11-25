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
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}

