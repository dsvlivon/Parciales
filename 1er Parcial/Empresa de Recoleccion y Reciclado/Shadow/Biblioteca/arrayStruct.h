/*******************************************************************
*Programa: Shadow ABM
*Objetivo: Prearmado de ABM para uso generico
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/

typedef struct{
    int id;
    char name[51];
    char lName[51];
    char xxx[51];
    char yyy[51];
    float salary;
    float kg;
    float mt;
    int sector;
    int zzz;
    int www;
    int isEmpty;
} Element;
////////////////////
/** initElement
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initElement(Element array[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addElement
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int addElement(Element array[], int size);
/////////////////////////////////////////////////////////////////////////// ADD
/** modifElement
*\brief modifica los datos de los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int ModifElement(Element array[], int size);
/////////////////////////////////////////////////////////////////////////// MODIF
/** removeElement
*\brief Realiza la baja logica de los datos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int removeElement(Element array[], int size);
/////////////////////////////////////////////////////////////////////////// REMOVE
/** findId
*\brief Pide un valor para recorrer el array, buscarlo y validar su disponibilidad
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param auxId es el valor a comparar en la busqueda
*\return void
*/
int finId(Element array[], int size, int *auxId);
/////////////////////////////////////////////////////////////////////////// FID
/** printElement
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int printElement(Element array[],int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** searchForEmpty
*\brief Recorre el array buscando el primer valor de posicion libre disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param position devuelve la posicion libre en cuestion
*\return void
*/
int searchForEmpty(Element array[], int size, int* position);
/////////////////////////////////////////////////////////////////////////// SFE
/** searchForOccurrence
*\brief Recorre el array buscando valores de posicion ocupadas
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int searchForOccurrence(Element array[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
/** sortElement
*\brief Realiza uno o más ordenamientos segun un determinado criterio
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param pOrder recibe un valor numerico que determina el criterio para ordenar
*\return void
*/
int sortElement(Element array[], int size, int pOrder);
/////////////////////////////////////////////////////////////////////////// SORT
/** informA
*\brief Realiza un informe de datos cruzados especificos.
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int informA(Element array[], int size);
/////////////////////////////////////////////////////////////////////////// INFA
