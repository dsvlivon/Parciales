//////////////////////////////////////////////////////////////
#include "pedidoABM.h"
#include "relacionInformes.h"
//////////////////////////////////////////////////////////////
#define QTY_OPCIONES    10                /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */
//////////////////////////////////////////////////////////////

int msjPedido(int idMensaje);
int listarPedido(ePedido array[], int tamanio, int estadoBuscado);
int listarEncolumnadoPedido(ePedido array[], int tamanio);
int promediarVariablePedido(ePedido array[], int tamanio, float* pPromedio);
int calcularPedidosCliente(ePedido array[], int tamanio, int idCliente,int* cantidadPedidos, int estadoBuscado);
//int calcularPedidosCliente(ePedido array[], int tamanio, int idCliente,int* cantidadPedidos,int estadoBuscado);
//int compararVariablesConPromedioEntidad2(eEntidad2 array[], int tamanio);

