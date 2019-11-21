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
int controller_loadFromText(char* path , LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// LOAD BIN
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// EDIT
/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editElement(LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// REMOVE
/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeElement(LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// LIST
/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 int controller_listElement(LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// SORT
/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortElement(LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// SAVE CSV
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* this);
////////////////////////////////////////////////////////////////////////////////// SAVE BIN
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_findElementById(LinkedList* this, int id);
////////////////////////////////////////////////////////////////////////////////// FIND ID
/** \brief Elimina la lista de la memoria
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_deleteLinkedList(LinkedList* this);

int controller_generarInforme(char* path , LinkedList* this);


