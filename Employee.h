#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacio en memoria para un empleado
 *  \param  no tiene
 *  \return Employee* un puntero a un espacio reservado para cargar un nuevo empleado
 */
Employee* employee_new();

/** \brief Valida los elementos que contiene un empleado y los carga en una variable Employee
 * \param idStr char* id del empleado.
 * \param nombreStr char* nombre
 * \param horasTrabajadasStr char* horas trabajadas
 * \param sueldo char* sueldo del empleado..
 * \return Employee* pAuxEmployee, devuelve - NULL si alguno de los parametros de la funcion es NULL.
 *                                 devuelve - puntero al empleado si valido sus elementos.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief Libera el espacio reservado en memoria para un empleado.
 * \param Employee* this puntero al empleado
 * \return int retorno -1 si this NULL,
 *                       0 si logro liberar el espacio reservado.
 */
void employee_delete();
/** \brief Valida el elemento id del Empleado y lo carga en la estructura
 * \param this Employee* puntero al empleado
 * \param id id del Empleado
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el id de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado int* id de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 */
int employee_getId(Employee* this,int* id);

/** \brief Valida el elemento nombre del Empleado y lo settea
 * \param this Employee* puntero al empleado.
 * \param nombre char* nombre del Empleado.
 * \return int retorno -1 si no pudo validar el nombre.
 *                      0 si pudo validar y cargar el nombre.
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado char* nombre de Employee
 * \return int retorno -1 si this es NULL o nombre es NULL,
 *                      0 si se obtuvo el nombre.
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Verifica el elemento horasTrabajadas del Empleado y lo settea
 * \param this Employee* puntero al empleado
 * \param horasTrabajadas horasTrabajadas del Empleado.
 * \return int retorno -1 si no pudo validar la/las horasTrabajadas.
 *                      0 si pudo validar y cargar la/las horasTrabajadas.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtiene las horasTrabajadas de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado int* horasTrabajadas de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo las horasTrabajadas.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Valida el elemento sueldo del Empleado y lo settea
 * \param this Employee* puntero al empleado
 * \param sueldo sueldo del Empleado.
 * \return int retorno -1 si no pudo validar el sueldo.
 *                      0 si pudo validar y cargar el sueldo.
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado int* sueldo de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el sueldo.
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Valida el elemento id string del Empleado y lo carga en la estructura Employee.
 * \param this Employee* puntero al empleado.
 * \param id char* id del Empleado.
 * \return int retorno -1 si no pudo validar el id.
 *                      0 si pudo validar y cargar el id.
 */
int employee_setIdStr(Employee* this, char* id);

/** \brief Obtiene el id de tipo string de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el ID.
 */
int employee_getIdStr(Employee* this, char* resultado);
/** \brief Valida el elemento horasTrabajadas del Empleado de tipo string y lo settea.
 * \param this Employee* puntero al empleado.
 * \param horasTrabajadas char* horasTrabajadas del Empleado.
 * \return int retorno -1 si no pudo validar la/las horasTrabajadas.
 *                      0 si pudo validar y cargar la/las horasTrabajadas .
 */
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
/** \brief Obtiene las horasTrabajadas de tipo string de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo la/las HorasTrabajadas.
 */
int employee_getHorasTrabajadasStr(Employee* this,char* resultado);

/** \brief Valida el elemento sueldo del ip Empleado y lo settea
 * \param this Employee* puntero al empleado.
 * \param sueldo char* sueldo
 * \return int retorno -1 si no pudo validar el sueldo.
 *                      0 si pudo validar y cargar el sueldo.
 */
int employee_setSueldoStr(Employee* this,char* sueldo);

/** \brief Obtiene el sueldo de tipo string de un empleado.
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el sueldo.
 */
int employee_getSueldoStr(Employee* this,char* resultado);

/** \brief Recorre la lista de empleados, busca el id maximo y lo incrementa en uno al retornarlo
 * \param LinkedList* pArrayEmployee puntero al array de empleados.
 * \return retunr el id maximo incrementado en uno.
 */
int employee_lastId(LinkedList* pArrayListEmplyee);

/** \brief busca la posicion en la que se encuentra un ID que solicita por parametro.
* \param LinkedList* pArrayEmployee puntero al array de empleados.
* \param posicionId int* puntero al ID a buscar.
* \return int retorno -1 si pArrayEmployee NULL, si pEmployee es NULL, o el ID a buscar no existe en la lista.
*                      0 si encontro el ID buscado, y como parametro por referencia la posicion del mismo.
*/
int Employee_findById(LinkedList* pArrayListEmployee, int *posicionId, int id);
/** \brief Compara entre dos nombres de la lista de empleados.
 * \param this1 void* primer empleado.
 * \param this2 void* segundo empleado
 * \return int retorno: -1 si el segundo nombre es el mayor,
 *                       1 si el primer nombre es el mayor,
 *                       0 si son iguales.
 */
int employee_compararPorNombre(void* this1, void* this2);


#endif // employee_H_INCLUDED
