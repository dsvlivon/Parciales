//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
#define TEXT_SIZE 51
//////////////////////////////////////////////////////////////
#include "clienteStruct.h"

int inicializarCliente(eCliente array[], int tamanio);
int buscarEmptyCliente(eCliente array[], int tamanio, int* posicion, int isEmptyBuscado);
int buscarPorIdCliente(eCliente array[], int tamanio, int id, int* posicion);
int altaCliente(eCliente array[], int tamanio, int* idRecibido);
int modificarCliente(eCliente array[], int tamanio);
int bajaCliente(eCliente array[], int tamanio);
