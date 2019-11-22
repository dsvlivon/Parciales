#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
struct S_Cachorro
{
  int id;
  char nombre[128];
  char raza[128];
  char reservado[128];
  char genero[128];
  int dias;
};
typedef struct S_Cachorro Cachorro;
////////////////////////////////////////////////////////////////////////////////// Employee New
/** \brief Reserva un espacio de memoria para un Employee
 * \return this
 */
Cachorro* employee_new();

Cachorro* Cachorro_newParametros(char* idStr,char* nombreStr,char* razaStr, char* reservadoStr, char* generoStr, char* diasStr);


int employee_setId(Cachorro* this,int id);
int employee_getId(Cachorro* this ,int* id);
int employee_setDias(Cachorro* this,int dias);
int employee_getDias(Cachorro* this ,int* dias);

int employee_setNombre(Cachorro* this,char* nombre);
int employee_getNombre(Cachorro* this,char* nombre);
int employee_setRaza(Cachorro* this,char* raza);
int employee_getRaza(Cachorro* this,char* raza);
int employee_setReservado(Cachorro* this,char* reservado);
int employee_getReservado(Cachorro* this,char* reservado);
int employee_setGenero(Cachorro* this,char* genero);
int employee_getGenero(Cachorro* this,char* genero);



int criterio_dias(void* p);
int criterio_machos(void* p);
int criterio_callejeros(void* p);


#endif // EMPLEADO_H_INCLUDED
