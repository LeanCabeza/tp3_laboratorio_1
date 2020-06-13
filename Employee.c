#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Reserva espacio en memoria para un empleado
 * \param void vacio
 * \return Employee* un puntero al espacio reservado para cargar un empleado
 */
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee = employee_new();
    Employee* retorno = NULL;

    if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(!employee_setIdStr(pEmployee, idStr) &&
                !employee_setNombre(pEmployee, nombreStr) &&
                !employee_setHorasTrabajadasStr(pEmployee, horasTrabajadasStr) &&
                !employee_setSueldoStr(pEmployee, sueldoStr))
        {
            retorno = pEmployee;
        }
        else
        {
            employee_delete(pEmployee);
        }
    }
    return retorno;
}


void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int employee_getId(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !validarNumero(id))
    {
        retorno = employee_setId(this,atoi(id));
    }
    return retorno;
}

int employee_getIdStr(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL && !validarNumero(horasTrabajadas))
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this,char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getHorasTrabajadas(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt); // Crea una cadena de texto segun el formato dado
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL && !validarNumero(sueldo))
    {
        retorno = employee_setSueldo(this,atoi(sueldo));

    }
    return retorno;
}

int employee_getSueldoStr(Employee* this,char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getSueldo(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    employee_getNombre((Employee*)this1, auxNombreA);
    employee_getNombre((Employee*)this2, auxNombreB);


    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}



int employee_lastId(LinkedList* pArrayListEmplyee)
{
    int IdAux;
    int IdMaximo;
    Employee* pEmployee;

    if(pArrayListEmplyee != NULL)
    {
        for(int i=0 ; i<ll_len(pArrayListEmplyee); i++)
        {
            pEmployee = ll_get(pArrayListEmplyee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &IdAux);
                if(IdAux > IdMaximo)
                {
                    IdMaximo = IdAux;
                }
                else
                {
                    continue;
                }
            }
        }

    }
    return IdMaximo+1;
}

int Employee_findById(LinkedList* pArrayListEmployee, int *posicionId, int id)
{
    int retorno = -1;
    int idAux;
    Employee *pEmployee = NULL;

    if(pArrayListEmployee != NULL && posicionId >= 0 && id >= 0)
    {
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}









