/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListEmployee es NULL,
                    0 si logra cargar los datos.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListEmployee es NULL,
                    0 si logra cargar los datos.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Agrega un empleado a la linked List
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si no puede dar de alta un empleado por error en algun dato,
                    0 si logra dar de alta.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Edita datos de empleado
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si no puede editar un empleado por error en algun dato,
                    0 si logra editar un empleado.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si no puede eliminar un empleado,
                    0 si logra eliminar un empleado.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si no puede mostar toda la lista de los empleados,
                    0 si logra mostar toda la lista de los empleados.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si no puede ordenar la lista de los empleados,
                    0 si logra ordenar la lista de los empleados.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* puntero al archivo a guardar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int ret -1 si el puntero si no puede guardar los datos,
 *                  0 si logra guardar los datos.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.scv (modo binario).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int  ret -1 si el puntero si no puede guardar los datos,
 *                   0 si logra guardar los datos.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




