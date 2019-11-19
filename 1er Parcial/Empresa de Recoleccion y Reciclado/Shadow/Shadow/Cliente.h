/*******************************************************************
*Programa:ABM Empresa de recoleccion y residuos
*Objetivo: desarrollo de abm
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
typedef struct{
    int companyId;
    char company[51];
    char cuit[51];
    char adress[51];
    char location[51];
    int isEmpty;
} Client;
///////////////////////////////////////////////////////////////////////////  Client
/** initClient
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initClient(Client c_Array[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addClient
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int addClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// ADD
/** modifClient
*\brief modifica los datos de los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int modifClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// MODIF
/** removeClient
*\brief Realiza la baja logica de los datos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int removeClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// REMOVE
/** findIdClient
*\brief Pide un valor 'numerico' para recorrer el array, buscarlo y validar su disponibilidad
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int findIdClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// FIDC
/** printClient
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int printClient(Client c_Array[],int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** searchForEmptyClient
*\brief Recorre el array buscando el primer valor de posicion libre (0) disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int searchForEmptyClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// SFE
/** searchForOccurrenceClient
*\brief Recorre el array buscando valores de posicion ocupadas
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int searchForOccurrenceClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
/** sortClient
*\brief Realiza uno o más ordenamientos segun un determinado criterio
*\param size indica la longitud del array
*\return 0 en caso afirmativo y -1 por negativo
*/
int sortClient(Client c_Array[], int size);
/////////////////////////////////////////////////////////////////////////  SORT
/** findCuitClient
*\brief Pide un valor string en formato "xx-xxxxxxxx-x" para recorrer el array, buscarlo y validar su existencia
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return en caso afirmativo retorna la posicion del valor validado y -1 en caso negativo
*/
int findCuitClient(Client c_Array[], int size);
