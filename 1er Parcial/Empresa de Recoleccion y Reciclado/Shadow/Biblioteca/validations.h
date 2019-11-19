/*
 * validations.h
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
/** getInt
* \brief Solicita al usuario un entero y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int getInt(int *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** getFloat
* \brief Solicita al usuario un decimal y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
float getFloat(float *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** getChar
* \brief Solicita al usuario un string y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
char getChar(char *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** isNumeric
* \brief Verifica si el valor recibido contiene solo numeros
/*
 * validations.h
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
/** getInt
* \brief Solicita al usuario un entero y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int getInt(int *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** getFloat
* \brief Solicita al usuario un decimal y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
float getFloat(float *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** getChar
* \brief Solicita al usuario un string y lo valída mediante las funciones IS
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
char getChar(char *pResult ,char *pMsg, char *pMsgFail, int min, int max, int try);
/** isNumeric
* \brief Verifica si el valor recibido contiene solo numeros
* \param str Array con la cadena a ser analizada
* \return 1 si contiene numeros del '0' al '9' por orden ASCII y 0 si no
*/
int isNumeric(char aux[]);
/** isDecimal
* \brief Verifica si el valor recibido contiene telefonos
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo numeros, espacios, un + y un guion.
*/
int isDecimal(char aux[]);
/** isLetter
* \brief Verifica si el valor recibido contiene letras
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo ' ' y/o letras y 0 si no
*/
int isLetter(char aux[]);
/** isAlphaNumeric
* \brief Verifica si el valor recibido contiene solo letras y números
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
*/
int isAlphaNumeric(char aux[]);
/** isTelephone
* \brief Verifica si el valor recibido contiene telefonos
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo numeros, espacios, un + y un guion.
*/
int isTelephone(char aux[]);
