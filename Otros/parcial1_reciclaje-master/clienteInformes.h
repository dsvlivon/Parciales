//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "clienteStruct.h"
#include "pedidoStruct.h"
//////////////////////////////////////////////////////////////
#define QTY_OPCIONES    10                /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */

/*
typedef struct
{
 int id;

 int idCliente;

 /*char string1[TEXT_SIZE];
 char string2[TEXT_SIZE];
 float float1;
 float float2;*//*
 int kilos;

 int kilosHDPE;
 int kilosLDPE;
 int kilosPP;
 int kilosBasura;

 int estado; //0 pendiente - 1 completado

 int isEmpty;
} ePedido;
*/

int msjCliente(int idMensaje);
int listarCliente(eCliente array[], int tamanio, ePedido arrayPedido[]);
int listarEncolumnadoCliente(eCliente array[], int tamanio);
int promediarVariableCliente(eCliente array[], int tamanio, float* pPromedio);
int compararVariablesConPromedioCliente(eCliente array[], int tamanio);
int imprimirCliente(eCliente array[], int tamanio, int idCliente);
