#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"





int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	char buffer[4][20];

	Employee *pEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"[^\n]\n");
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		    //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]); Para ver lo que va cargando

			pEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

			if(pEmpleado != NULL)
			{
				if(!ll_add(pArrayListEmployee,pEmpleado))
				{
					ret = 0;
				}
			}
		}
	}
	fclose(pFile);
	return ret;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee auxEmployee;
    Employee* pEmployee= NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            fread(&auxEmployee, sizeof(Employee), 1, pFile);

            if(!employee_setId(pEmployee, auxEmployee.id) &&
                    !employee_setNombre(pEmployee, auxEmployee.nombre) &&
                    !employee_setHorasTrabajadas(pEmployee, auxEmployee.horasTrabajadas) &&
                    !employee_setSueldo(pEmployee, auxEmployee.sueldo))
            {
                fread(&auxEmployee, sizeof(Employee), 1, pFile);
                if(pEmployee!= NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                    ret = 0;
                }

            }
            else
            {
                employee_delete(pEmployee);
            }

        }
        fclose(pFile);
        free(pArrayListEmployee);
    }
    return ret;
}



