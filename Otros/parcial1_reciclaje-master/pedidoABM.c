//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "pedidoABM.h"
//////////////////////////////////////////////////////////////

int inicializarPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        for(;tamanio>0;tamanio--)
        {
            array[tamanio-1].isEmpty=1;
            array[tamanio-1].id=tamanio;
            array[tamanio-1].idCliente=0;
        }
        retorno=0;
    }

    return retorno;
}

int buscarEmptyPedido(ePedido array[], int tamanio, int* posicion, int isEmptyBuscado) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;


    if(array!=NULL && tamanio>=0 && posicion!=NULL)
    {

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==isEmptyBuscado)
            {
                //printf("i=%d",i);
                //printf("pos %d",i);
                *posicion=i;
                //printf("pos %d",i);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int buscarPorIdPedido(ePedido array[], int tamanio, int id, int* posicion)
{
    int retorno=-1;

    if(array!= NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            } else if(array[i].id==id) {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int altaPedido(ePedido array[], int tamanio, int* idRecibido)
{

    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        if(buscarEmptyPedido(array,tamanio,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;

            /** Ingresamos las funciones correspondientes a nuestro caso en particular */

            /*utn_getName(" Ingrese string1: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].string1);
            utn_getTexto(" Ingrese string2: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].string2);
            utn_getFloat(" Ingrese float1: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float1);
            utn_getFloat(" Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float2);*/
            utn_getUnsignedInt(" Ingrese id del cliente: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].idCliente);
            //printf("id cliente: %d",array[*idRecibido].idCliente);
            utn_getUnsignedInt(" Ingrese kilos: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].kilos);
            array[*idRecibido].estado=0;
            //utn_getUnsignedInt(" Ingrese idEntidad: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].idEntidad);


            array[*idRecibido].id=*idRecibido+1;
            retorno=0;
        }
    }
    return retorno;
}

int procesarPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        int idProcesado=1;
        utn_getUnsignedInt("\n-Ingrese id del pedido a procesar: "," ERROR\n",0,TEXT_SIZE,0,QTY_ENTIDADES,0,&idProcesado);

        idProcesado--; //Menos uno porque el id siempre es +1 que el indice del array

        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polietileno de alta densidad: "," ERROR\n",0,TEXT_SIZE,0,QTY_ENTIDADES,0,&array[idProcesado].kilosHDPE);
        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polietileno de baja densidad: "," ERROR\n",0,TEXT_SIZE,0,QTY_ENTIDADES,0,&array[idProcesado].kilosLDPE);
        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polipropileno: "," ERROR\n",0,TEXT_SIZE,0,QTY_ENTIDADES,0,&array[idProcesado].kilosPP);

        array[idProcesado].estado=1;
        array[idProcesado].isEmpty=0;

        /*printf("\nid: %d",array[idProcesado].idCliente);
        printf("\nid proc: %d",idProcesado);
        printf("\nid cliente: %d",array[idProcesado].idCliente);*/

        array[idProcesado].kilosBasura = (array[idProcesado].kilos) - (array[idProcesado].kilosHDPE) - (array[idProcesado].kilosLDPE) - (array[idProcesado].kilosPP);

        printf("\n");

        retorno=0;

    }
    return retorno;

}

