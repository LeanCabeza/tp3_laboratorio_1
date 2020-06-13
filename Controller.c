#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "r");
        if(pFileAux !=NULL)
        {
            if(!parser_EmployeeFromText(pFileAux, pArrayListEmployee))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "rb");
        if(pFileAux !=NULL)
        {
            if(!parser_EmployeeFromBinary(pFileAux, pArrayListEmployee))
            {
                printf("\tCARGA EXITOSA!\n");
                retorno = 0;
            }
        }
    }
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pAuxEmpleado = employee_new();
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajas;
    int bufferSueldo;


    if(pAuxEmpleado!= NULL && pArrayListEmployee != NULL)
    {
    	/* Se pone (!)getString , debido a que retorna 0 y al negarlo hago que sea un numero distinto de 0 que daria un "TRUE BOOLEANO" ,
    	 * Si el resultado eso da 1 & 1 & 1 , entonces ejecutara lo que esta dentro del IF .
    	 */
        if(!utn_getString(bufferNombre, "Ingrese Nombre: ", "Error al ingresar nombre. Reintente. ", 1, 128, 2) &&
                !utn_getNumero(&bufferHorasTrabajas, "Ingrese cantidad de horas trabajas: ", "Error al ingresar horas. Reintente ", 0,100000,2) &&
                !utn_getNumero(&bufferSueldo, "Ingrese sueldo: ", "Error al ingresar sueldo. Reintente.", 1,100000,2))
        {

            employee_setNombre(pAuxEmpleado, bufferNombre);
            employee_setHorasTrabajadas(pAuxEmpleado, bufferHorasTrabajas);
            employee_setSueldo(pAuxEmpleado, bufferSueldo);
            bufferId = employee_lastId(pArrayListEmployee);
            employee_setId(pAuxEmpleado, bufferId);

            ll_add(pArrayListEmployee, pAuxEmpleado);
            retorno=0;
            printf("\tCARGA EXITOSA!\n");
        }
        else
        {
            employee_delete(pAuxEmpleado);
        }
    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferId;
    int posId;
    Employee* pAuxEmployee = NULL;
    int opcion;
    char bufferNombre[1000];
    int BufferHorasTrabajadas;
    int bufferSueldo;

    if(pArrayListEmployee != NULL)
    {
        if(!utn_getNumero(&bufferId,"Ingrese un ID a modificar: ", "Error al ingresar ID. Reintente", 0, ll_len(pArrayListEmployee),2))
        {
            if(!Employee_findById(pArrayListEmployee, &posId, bufferId))
            {
                pAuxEmployee = ll_get(pArrayListEmployee, posId);
                if(pAuxEmployee!= NULL)
                {
                        if (!utn_getNumero(&opcion, "Ingrese opcion a modificar:\n 1-Nombre.\n "
                        											   "2-Horas trabajadas.\n "
                        											   "3-Sueldo.\n "
                        											   "4-Salir de modificacion.\n",
																	   "Error. Debe ingresar una opcion valida", 1,4,2))
                        	{
								switch(opcion)
								{
								case 1:
									if (!utn_getString(bufferNombre,"Ingrese nuevo nombre del empleado: \n","Error, nombre no valido.\n",2,1000,2))
									{
										employee_setNombre(pAuxEmployee,bufferNombre);
										printf("\nSe modifico el nombre.\n");
										retorno=0;
									}
									else
										printf ("\nError modificar el nombre.\n");
									break;

								case 2:
									if (!utn_getNumero(&BufferHorasTrabajadas,"Ingrese nuevas horas trabajadas del empleado: \n","Error, horas no validas.\n",2,1000,2))
									{
										employee_setHorasTrabajadas(pAuxEmployee,BufferHorasTrabajadas);
										printf("\nSe modificaron las horas trabajadas.\n");
										retorno=0;
									}
									else
										printf ("\nError al modificar las horas trabajadas.\n");
									break;
								case 3:
									if (!utn_getNumero(&bufferSueldo,"Ingrese nuevo sueldo del empleado: \n","Error, sueldo no valido.\n",2,1000000,2))
									{
										employee_setSueldo(pAuxEmployee,bufferSueldo);
										printf("\nSe modifico el sueldo.\n");
										retorno=0;
									}
									else
										printf ("\nError al modificar sueldo.\n");
									break;
								case 4:
									break;

								}
							}
            }
        }
      }
    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferId;
    int posId;
    Employee* pAuxEmployee = NULL;

    if(pArrayListEmployee!= NULL)
    {
        if(!utn_getNumero(&bufferId,"Ingrese un ID a borrar: ", "Error al ingresar ID. Reintente", 0, ll_len(pArrayListEmployee),2))
        {
            if(!Employee_findById(pArrayListEmployee, &posId, bufferId))
            {
            	/*
            	 * ll_pop
      	  	  	  	Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
					de la lista. Verificando que el puntero this sea distinto de NULL y que index sea positivo e
					inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
					retorna el elemento.
            	 */
                pAuxEmployee = ll_pop(pArrayListEmployee, posId);
                if(pAuxEmployee!= NULL)
                {
                    employee_delete(pAuxEmployee);
                    printf("\nEMPLEADO DADO DE BAJA.\n\n");
                    retorno = 0;
                }
            }
        }

    }
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* pEmployee = NULL;
    char bufferId[1000];
    char bufferNombre[1000];
    char BufferHorasTrabajadas[1000];
    char bufferSueldo[100000];

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
    	/*ll_get
			Retorna un puntero al elemento que se encuentra en el índice especificado.
     	 */
        pEmployee = ll_get(pArrayListEmployee, i);//guardar un puntero a empleado
        if(pEmployee != NULL)
        {
            if(!employee_getIdStr(pEmployee, bufferId) &&
                    !employee_getNombre(pEmployee, bufferNombre) &&
                    !employee_getHorasTrabajadasStr(pEmployee, BufferHorasTrabajadas)&&
                    !employee_getSueldoStr(pEmployee, bufferSueldo))
            {
                printf("%s  %s  %sHrs  $%s\n", bufferId,bufferNombre, BufferHorasTrabajadas, bufferSueldo);
                ret = 0;
            }
        }

    }
    return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;

    if(pArrayListEmployee != NULL)
    {
    	/*
    	 * Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
			de determinar que elemento es mas grande que otro y si se debe ordenar de manera
			ascendente o descendente. Verificando que tanto el puntero this como el puntero a la funcion
			pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).
    	 */
        ll_sort(pArrayListEmployee, employee_compararPorNombre, 1);
        ret=0;
    }
    return ret;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    Employee * pEmployee = NULL;
    char bufferId[1000];
    char bufferNombre[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[100000];

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            for(int i =0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(!employee_getIdStr(pEmployee, bufferId) &&
                        !employee_getNombre(pEmployee,bufferNombre) &&
                        !employee_getHorasTrabajadasStr(pEmployee, bufferHorasTrabajadas) &&
                        !employee_getSueldoStr(pEmployee, bufferSueldo))
                {
                    fprintf(pFileAux, "%s, %s, %s, %s\n", bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    ret = 0;
                }
                else
                {
                    employee_delete(pEmployee);
                }
            }
        }
        fclose(pFileAux);
    }
    return ret;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    Employee * pEmployee = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "wb");
        if(pFileAux != NULL)
        {
            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee != NULL)
                {
                    fwrite(pEmployee, sizeof(Employee), 1, pFileAux);//pEmployee es lo apuntado por el puntero, su contenido.
                }
            }
            ret = 0;
            fclose(pFileAux);
        }
    }
    return ret;
}



