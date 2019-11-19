//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "clienteABM.h"
//////////////////////////////////////////////////////////////

/** Inicializa las variables isEmpty,id y cuit*/
int inicializarCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        for(;tamanio>0;tamanio--)
        {
            array[tamanio-1].isEmpty=1;
            array[tamanio-1].id=tamanio;
            array[tamanio-1].cuit="";
        }
        retorno=0;
    }

    return retorno;
}

/** Busca un cliente por la variable isEmpty y lo devuelve si existe */
int buscarEmptyCliente(eCliente array[], int tamanio, int* posicion, int isEmptyBuscado) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0 && posicion!=NULL)
    {

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==isEmptyBuscado)
            {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

/** Busca un cliente por id y lo devuelve si existe*/
int buscarPorIdCliente(eCliente array[], int tamanio, int id, int* posicion)
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


int altaCliente(eCliente array[], int tamanio, int* idRecibido)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        if(buscarEmptyCliente(array,tamanio,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;

            /** Ingresamos las funciones correspondientes a nuestro caso en particular */

            utn_getTexto(" Ingrese nombre de la empresa: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].nombreEmpresa);
            utn_getTexto(" Ingrese direccion y localidad: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].direccionYLocalidad);
            //utn_getFloat(" Ingrese float1: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float1);
            //utn_getFloat(" Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float2);
            //utn_getCUIT(" Ingrese cuit: "," ERROR - Cuit invalido (11 numeros sin guiones)\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].cuit);
            utn_getUnsignedInt(" Ingrese cuit: "," ERROR - Cuit invalido (11 numeros sin guiones)\n",11,14,0,1,2,&array[*idRecibido].cuit);


            array[*idRecibido].id=*idRecibido+1;
            retorno=0;
        }
    }
    return retorno;
}

int modificarCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {

        int posicion;
        int id;
        int accion;

        utn_getUnsignedInt(" ID del Cliente a modificar: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id); // Modificar 'ENTIDAD'
        if(buscarPorIdCliente(array,tamanio,id,&posicion)==-0)
        {
            /** Creamos un menu correspondiente a nuestro caso en particular */


            do
            {
                /**     Podemos hacerlo en un solo printf, pero me gusta más con varios, además si hay variables que no se usan
                    puedo simplemente comentar la línea en lugar de tener que modificar TODO el unico printf

                    OPCION 1
                printf(" 1) STRING1: %s\n 2) STRING2: %s\n 3) FLOAT1: %f\n 4) FLOAT2: %f\n 5) INT1: %d\n 6) INT2: %d\n",
                array[posicion].string1,array[posicion].string2,array[posicion].float1,array[posicion].float2,array[posicion].int1,array[posicion].int2);

                    OPCION 2 AGUANTE ESTA :)
                printf("\n  1) STRING1: %s\n",array[posicion].string1);
                printf("  2) STRING2: %s\n",array[posicion].string2);
                printf("  3) FLOAT1: %f\n",array[posicion].float1);
                printf("  4) FLOAT2: %f\n",array[posicion].float2);
                printf("  5) INT1: %d\n",array[posicion].int1);
                printf("  6) INT2: %d\n",array[posicion].int2);
                printf("  7) idEntidad2: %d\n",array[posicion].idEntidad2);
                printf("\n  9) Volver\n");                           */

                printf("\n  1) Nombre de la empresa: %s\n",array[posicion].nombreEmpresa);
                printf("  2) Direccion y localidad: %s\n",array[posicion].direccionYLocalidad);
                //printf("  3) FLOAT1: %f\n",array[posicion].float1);
                //printf("  4) FLOAT2: %f\n",array[posicion].float2);
                printf("  3) Cuit: %d\n",array[posicion].cuit);
                //printf("  6) INT2: %d\n",array[posicion].int2);

                printf("\n  9) Volver\n");

                utn_getUnsignedInt("\n-Ingrese el numero de la variable que desea modificar: "," ERROR\n",1,2,1,9,2,&accion);

                switch(accion)
                {
                    case 1:
                        utn_getTexto("\n-Ingrese nombre de la empresa nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].nombreEmpresa);
                        break;
                    case 2:
                        utn_getTexto("\n-Ingrese direccion y localidad nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].direccionYLocalidad);
                        break;
                    /*case 3:
                        utn_getFloat("\n-Ingrese float1: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[posicion].float1);
                        break;
                    case 4:
                        utn_getFloat("\n-Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[posicion].float2);
                        break;*/
                    case 3:
                        utn_getUnsignedInt("\n-Ingrese cuit nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].cuit);
                        break;
                    /*case 6:
                        utn_getUnsignedInt("\n-Ingrese int2 nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].int2);
                        break;*/
                    case 9:
                        break;
                    default:
                        printf("\n ERROR - Accion no valida (entre 1 y 3 o 9 para volver)\n\n");
                }
            }
            while(accion!=1&&accion!=2&&accion!=3&&accion!=9);
            retorno=0;
        }
        else
        {
            msjCliente(-5);
        }
    }
    return retorno;
}

int bajaCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        int posicion;
        int id;

        utn_getUnsignedInt(" ID a dar de baja: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id);

        if(buscarPorIdCliente(array,tamanio,id,&posicion)==-1)
        {
            printf(" No existe este ID\n");
        }
        else
        {
            /** Realizamos una baja logica */

            strncpy(array[posicion].nombreEmpresa,"",TEXT_SIZE);
            strncpy(array[posicion].direccionYLocalidad,"",TEXT_SIZE);
            array[posicion].cuit=0;
            /*array[posicion].int2=0;
            array[posicion].float1=0;
            array[posicion].float2=0;*/

            array[posicion].id=0;
            array[posicion].isEmpty=1;

            retorno=0;
        }
    }
    return retorno;
}

