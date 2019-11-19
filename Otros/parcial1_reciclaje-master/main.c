/**

                Las bibliotecas gen�ricas que us� en este parcial o TP se encuentran
        en una carpeta llamada "bibliotecas - Julian Cerizola" dentro de la carpeta
        de este mismo proyecto.

*/
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "ABM.h"
//////////////////////////////////////////////////////////////
#define TITULO_PRUEBA   "Parcial Nro 1"     /** Reemplazamos 'Parcial de prueba' por el nombre que le queramos dar a nuestro parcial o TP */
#define ALUMNO          "Julian Cerizola"   /** Reemplazamos 'Julian Cerizola' por el nombre del alumno que est� entregando esta prueba */
#define DIVISION        "1ro E - UTN FRA"   /** Reemplazamos '1ro E - UTN FRA' por la division del alumno en cuesti�n */
//////////////////////////////////////////////////////////////

int main()
{   // Notar que hay un \a            y un coraz�n <3
    printf("\a\t   Bienvenide!\n\n\t%s\n\t%s\n\t%s <3\n=========================================================\n",TITULO_PRUEBA,ALUMNO,DIVISION);

    eCliente arrayCliente[QTY_ENTIDADES];    // Creamos nuestro array de entidades cuyo tama�o es QTY_ENTIDADES
    ePedido arrayPedido[QTY_ENTIDADES2];    // Creamos nuestro array de entidades2 cuyo tama�o es QTY_ENTIDADES2

    inicializarCliente(arrayCliente,QTY_ENTIDADES); // Colocamos todos los isEmpty de nuestras entidades en 1
    inicializarPedido(arrayPedido,QTY_ENTIDADES2); // Colocamos todos los isEmpty de nuestras entidades2 en 1

    mostrarMenu(arrayCliente,arrayPedido,1); // No es necesario pasar el tama�o del array como parametro
    return 0;
}

