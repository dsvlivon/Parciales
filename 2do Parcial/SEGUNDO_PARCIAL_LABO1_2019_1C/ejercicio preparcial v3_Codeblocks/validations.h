/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
////////////////////////////////////////////////////////////////////////////////// GIT
/** getInput
* \brief Solicita al usuario un string y lo valída mediante las funciones IS enrutadas por un moderador
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \param mode es el moderador que enruta que validacion se pide
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int getInput(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try, int mode);
////////////////////////////////////////////////////////////////////////////////// (0) IsNumeric
/** isNumeric
* \brief Verifica si el valor recibido contiene numeros reales
* \param str Array con la cadena a ser analizada
* \return 1 si contiene numeros del '0' al '9' por orden ASCII y 0 si no
*/
int isNumeric(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (1) isOnlyNumber
/** isOnlyNumber
* \brief Verifica si el valor recibido q contiene solo numeros entre 0 y 9
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo numeros, -1 si no
*/
int isOnlyNumber(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (2) isDecimal
/** isDecimal
* \brief Verifica si el valor recibido contiene flotantes
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo numeros, espacios, un + y un guion.
*/
int isDecimal(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (3) isLetter
/** isLetter
* \brief Verifica si el valor recibido contiene letras y simbolos
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo ' ' y/o letras y -1 si no
*/
int isLetter(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (x) isAlphaNumeric
/** isAlphaNumeric
* \brief Verifica si el valor recibido contiene solo letras, números y un grupo de excepciones
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo espacio o letras y números, y -1 si no lo es
*/
int isDate(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (4) isDate
/** isDate
* \brief Verifica si el valor recibido contiene numeros y la excepcion '/'
* \param str Array con la cadena a ser analizada
* \return 0 si la validacion esta ok, y -1 si no lo es
*/
int isAlphaNumeric(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (5) isAnswer
/** isAnswer
* \brief Verifica si el valor recibido q contiene como confirmacion solo (y,Y)
* \param str Array con la cadena a ser analizada y el largo de la cadena
* \return 0 si contiene solo (y,Y)
*/
int isAnswer(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (6) isGender
/** isGender
* \brief Verifica si el valor recibido q contiene como sexo solo (f,F) y (m,M)
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo (y,Y)
*/
int isGender(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (7) isTelephone
/** isTelephone
* \brief Verifica si el valor recibido contiene telefonos
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo numeros, espacios, un + y un guion.
*/
int isTelephone(char aux[]);
////////////////////////////////////////////////////////////////////////////////// (8) isCuit
/** isCuit
* \brief Verifica si el valor recibido contiene telefonos
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo numeros, espacios, un + y un guion.
*/
int isCuit(char aux[]);
