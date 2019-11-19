/*******************************************************************
*Programa:ABM Empresa de recoleccion y residuos
*Objetivo: desarrollo de abm
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
typedef struct{
    int orderId;
    int companyId;
    int kg;
    int status;
    int hdpe;
    int ldpe;
    int pp;
    int isEmpty;
} Order;
///////////////////////////////////////////////////////////////////////////  Order
/** initOrder
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initOrder(Order o_Array[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addOrder
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int addOrder(Order o_Array[],int size, int *auxCcode);
/////////////////////////////////////////////////////////////////////////// ADD
/** printOrder
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int printOrder(Order o_Array[], int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** searchForEmptyOrder
*\brief Recorre el array buscando el primer valor de posicion libre disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int searchForEmptyOrder(Order o_Array[], int size);
/////////////////////////////////////////////////////////////////////////// SFE
/** findIdOrder
*\brief Pide un valor para recorrer el array, buscarlo y validar su existencia
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int findIdOrder(Order o_Array[], int size, int *auxId);
/////////////////////////////////////////////////////////////////////////// FIDC
/** processOrder
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param auxId se toma para hacer un match entre id de dos estructuras
*\return 0 en caso afirmativo y -1 por negativo
*/
int processOrder(Order o_Array[], int size);
/////////////////////////////////////////////////////////////////////////// PO
/** SearchForOccurrenceOrder
*\brief Recorre el array buscando valores de posicion ocupadas
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int searchForOccurrenceOrder(Order o_Array[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
/** orderIdGenerator
*\brief Crea un conteo progresivo
*\return contador
*/
int orderIdGenerator();
/////////////////////////////////////////////////////////////////////////// IDG
/** sort
*\brief Realiza uno o más ordenamientos segun un determinado criterio
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int sortOrder(Order o_Array[], int size);
/////////////////////////////////////////////////////////////////////////  SORT
/** contadorPedidosPendientes
*\brief A partir del ID, recorre el array buscando ese valor y una condicion, luego cuenta las ocurrencias.
*\param array es el array a ser recorrido
*\param auxCompanyID guarda el id de cliente
*\param puntero para modificar el valor del contador
*\return void
*/
void contadorPedidosPendientes(Order o_Array[], int auxCompanyId, int* counter);
/////////////////////////////////////////////////////////////////////////  OCCOUNTER
