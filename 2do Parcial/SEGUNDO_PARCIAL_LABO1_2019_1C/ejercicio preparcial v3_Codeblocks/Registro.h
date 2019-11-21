#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Registro
{
  int ID_Venta;
  char Fecha_Venta[128];
  char Tipo_Foto[128];
  int Cantidad;
  int Precio_Unitario;
  char CUIT_Cliente[128];
};
typedef struct S_Registro Elemento;
//ID_Venta;Fecha_Venta;Tipo_Foto;Cantidad;Precio_Unitario;CUIT_Cliente

////////////////////////////////////////////////////////////////////////////////// Employee New
/** \brief Reserva un espacio de memoria para un Employee
 * \return this
 */
Elemento* element_new();
////////////////////////////////////////////////////////////////////////////////// Employee NewPARAMETROS
/** \brief Asigna valores a los campos de Employee
* \param idStr recibe un Id
* \param nombreStr recibe un nombre
* \param horasTrabajadasStr recibe un valor de horas
* \param suedloStr recibe un valor de sueldo
* \return this
*/
//ID_Venta;Fecha_Venta;Tipo_Foto;Cantidad;Precio_Unitario;CUIT_Cliente
Elemento* element_newParametros(char* ID_Venta,char* Fecha_Venta,char* Tipo_Foto, char* Cantidad, char* Precio_Unitario, char* CUIT_Cliente);
////////////////////////////////////////////////////////////////////////////////// SET ID
/** \brief Asigna un valor a un campo de Employee
* \param recibe un Id
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_setId(Elemento* this,int ID_Venta);
////////////////////////////////////////////////////////////////////////////////// GET ID
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_getId(Employee* this ,int* ID_Venta);
////////////////////////////////////////////////////////////////////////////////// SET Name
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_setNombre(Employee* this,char* Tipo_Foto);
////////////////////////////////////////////////////////////////////////////////// GET Name
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_getNombre(Employee* this,char* Tipo_Foto);
////////////////////////////////////////////////////////////////////////////////// SET Hours
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_setHorasTrabajadas(Employee* this,int Cantidad);
////////////////////////////////////////////////////////////////////////////////// GET Hours
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_getHorasTrabajadas(Employee* this,int* Cantidad);
////////////////////////////////////////////////////////////////////////////////// SET Salary
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_setSueldo(Employee* this,int sueldo);
////////////////////////////////////////////////////////////////////////////////// GET Salary
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_getSueldo(Employee* this,int* sueldo);
////////////////////////////////////////////////////////////////////////////////// SORT Salary
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_sortBySalary(void*arg1, void* arg2);
////////////////////////////////////////////////////////////////////////////////// SORT Hours
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_sortByWorkedHours(void*arg1, void* arg2);
////////////////////////////////////////////////////////////////////////////////// SORT Name
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int element_sortByName(void*arg1, void* arg2);

void element_calcularSueldo(void* p);
int criterio_salary(void* p);

#endif // EMPLEADO_H_INCLUDED
