/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
////////////////////////////////////////////////////////////////////////////////// LOAD CSV
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
 int controller_listEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// SAVE BIN
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id);
////////////////////////////////////////////////////////////////////////////////// FIND ID
/** \brief Elimina la lista de la memoria
 * \param pArrayListEmployee LinkedList*
 * \return int
 */



