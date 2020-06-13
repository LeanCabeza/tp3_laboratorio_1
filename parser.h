
/**\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListEmployee LinkedList* puntero a array de empleados.
 * \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListEmployee es NULL,
                   0 si logro parsear con exito.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *  \param pFile FILE* puntero a archivo.
 *  \param pArrayListEmployee LinkedList* puntero a array de empleados.
 *  \return int ret -1 cuando pFile es NULL o pArrayListEmployee es NULL,
                    0 cuando logro parsear cone exito.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
