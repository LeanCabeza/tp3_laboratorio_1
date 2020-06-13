#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();
    char seguir='s';
    int opcion;
    int flag = 0;

    while (seguir=='s')
    {
        printf("\n------MENU------"
        	   "\n1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
        	   "\n2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
        	   "\n3- Alta de empleado"
        	   "\n4- Modificar datos de empleado"
        	   "\n5- Baja de empleado"
        	   "\n6- Listar empleados"
        	   "\n7- Ordenar empleados"
        	   "\n8- Guardar los datos de los empleados en el archivo data.csv (modo texto)."
        	   "\n9- Guardar los datos de los empleados en el archivo data.csv (modo binario)."
        	   "\n10-SALIR\n");

        if(!utn_getNumero(&opcion, "\nIngrese la Operacion que desea Realizar: ", "\nError opcion invalida , debe ser un numero entre 1 y 10. Reintente ", 0,10,5))
        {
			switch (opcion)
			{
			case 1:
				controller_loadFromText("data.csv",listaEmpleados);
				printf("\nSe cargo EXITOSAMENTE la lista de Empleados DATA CSV\n");
				flag = 1;
				break;

			case 2:
				controller_loadFromBinary("archivoBinario.bin", listaEmpleados);
				flag = 1;
				break;

			case 3:
				controller_addEmployee(listaEmpleados);
				flag = 1;
				break;

			case 4:
				if(flag ==1)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("\n Para poder editar empleados , primero tenes que tener empleados cargados.\n\n");
				}
				break;

			case 5:
				if(flag ==1)
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("\n Para poder borrar empleados , primero tenes que tener empleados cargados\n");
				}
				break;

			case 6:
				if(flag ==1)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\n Para poder listar empleados , primero tenes que tener empleados cargados \n");
				}
				break;

			case 7:
				if(flag ==1)
				{
					controller_sortEmployee(listaEmpleados);
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\n Para poder ordenar empleados , primero tenes que tener empleados cargados\n\n");
				}
				break;

			case 8:
			   if(flag == 1)
				{
					if(!controller_saveAsText("dataTXT.csv", listaEmpleados))
					{
						printf("\nLista guardada correctamente!! \n");
					}
					else
					{
						printf("ERROR , no fue posible guardar la lista\n\n");
					}
				}
				else
				{
					printf("\nPara poder guardar lista de empleados , primero tenes que tener empleados cargados\n\n");
				}
				break;

			case 9:
				if(flag == 1)
				{
					if(!controller_saveAsBinary("dataBIN.bin", listaEmpleados))
					{
						printf("\nLista guardada Correctamente! \n");
					}
					else
					{
						printf("ERROR , no fue posible guardar la lista\n\n");
					}
				}
				else
				{
					printf("\nPara poder guardar lista de empleados , primero tenes que tener empleados cargados\n\n");
				}
				break;

			case 10:
				printf("Hasta Pronto :D");
				seguir='n';
				break;
			}
        }
    }
    return 0;
}


