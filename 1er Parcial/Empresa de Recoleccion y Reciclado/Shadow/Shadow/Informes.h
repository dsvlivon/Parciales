/*******************************************************************
*Programa:ABM Empresa de recoleccion y residuos
*Objetivo: desarrollo de abm
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
////////////////////////////////////////////////////////////////////////// PPenC
/** PrintPendigClient
*\brief Imprime una lista de clientes con pedidos pendientes y su cantidad
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void printPendingClient(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// PPenC
/** PrintPendigClient
*\brief Imprime una lista de pedidos con datos del cliente y la cantidad total a recoger
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void printPendingOrders(Order o_Array[], Client c_Array[]);
///////////////////////////////////////////////////////////////////////// PProO
/** printProcessedOrders
*\brief Imprime una lista de pedidos con datos del cliente y las cantidades de tipos de plasticos
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void printProcessedOrders(Order o_Array[], Client c_Array[]);
////////////////////////////////////////////////////////////////////////// (1)A
/** clientWithMorePendings (1)A
*\brief recorre ambos array, clientes y pedidos buscando clientes con pedidos pendientes. Evalua mayor cantidad de pendientes.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientWithMorePendings(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (2)B
/** clientWithMoreCompleted (2)B
*\brief recorre ambos array, clientes y pedidos buscando clientes con pedidos completados. Evalua mayor cantidad de completados.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientWithMoreCompleted(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (3)C
/** clientWithMoreOrders (3)C
*\brief recorre ambos array, clientes y pedidos buscando clientes con alta de pedidos. Evalua mayor cantidad de pedidos.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientWithMoreOrders(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (4)D
/** clientRecycledMore (4)D
*\brief recorre ambos array, clientes y pedidos buscando clientes con pedidos procesados. Evalua mayor acumulado de hdpe+ldpe+pp.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientRecycledMore(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (5)E
/** clientRecycledLess (5)E
*\brief recorre ambos array, clientes y pedidos buscando clientes con pedidos procesados. Evalua menor acumulado de hdpe+ldpe+pp.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientRecycledLess(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (6)F
/** clientOverThousand (6)F
*\brief recorre ambos array, buscando clientes con pedidos procesados. Cuenta los cliente cuyo acumulado hdpe+ldpe+pp superan los 1000kg.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientOverThousand(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (7)G
/** clientUnderHundred (7)G
*\brief recorre ambos array, buscando clientes con pedidos procesados. Cuenta los cliente cuyo acumulado hdpe+ldpe+pp NO superan los 100kg.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void clientUnderHundred(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (8)H
/** completedOrders (8)H
*\brief recorre ambos array, clientes y pedidos buscando clientes con pedidos procesadoss y calcula el % de lo realizado.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void completedOrders(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (9)I
/** ordersByLocation (9)I
*\brief Solicita el ingreso de una localidad, luego recorre ambos array buscando dicho valor y un estado y lista la informacion por localidad.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void ordersByLocation(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (10)J
/** ppAverageByClient (10)J
*\brief recorre ambos array, evalua las cantidades procesados y los clientes de procedencia y, calcula el promedio.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void ppAverageByClient(Client c_Array[], Order o_Array[]);
////////////////////////////////////////////////////////////////////////// (11)K
/** plasticTypeByClient (11)K
*\brief Solicita el ingreso de un CUIT, si el valor es validado pide ingresar un tipo de plastico, luego recorre ambos array buscando ambos valores y lista la informacion.
*\param Array propio de la estructura de pedidos
*\param Array propio de la estructura de clientes
*\return void
*/
void plasticTypeByClient(Client c_Array[], Order o_Array[]);

