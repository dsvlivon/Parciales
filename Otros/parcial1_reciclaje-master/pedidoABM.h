//////////////////////////////////////////////////////////////
#define ENTIDAD2         "pedido"         /** Reemplazamos 'entidad' por el nombre de nuestro ente (Recomiendo todo en minuscula) */
#define QTY_ENTIDADES2   1000             /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
//////////////////////////////////////////////////////////////
#define TEXT_SIZE 51
//////////////////////////////////////////////////////////////
#define QTY_ENTIDADES 100                 /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
//////////////////////////////////////////////////////////////
#include "pedidoStruct.h"
//////////////////////////////////////////////////////////////

int inicializarPedido(ePedido array[], int tamanio);
int buscarEmptyPedido(ePedido array[], int tamanio, int* posicion, int isEmptyBuscado);
int buscarPorIdPedido(ePedido array[], int tamanio, int id, int* posicion);
int altaPedido(ePedido array[], int tamanio, int* idRecibido);
int modificarPedido(ePedido array[], int tamanio);
int bajaPedido(ePedido array[], int tamanio);
int procesarPedido(ePedido array[], int tamanio);

