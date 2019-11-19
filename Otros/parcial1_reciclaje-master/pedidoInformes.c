//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "pedidoInformes.h"
//////////////////////////////////////////////////////////////

int msjPedido(int idMensaje)
{
    if(idMensaje<0) //Si el idMensaje es negativo entonces se trata de un error
    {
        printf("\a");   // Por eso hacemos un ruidito
    }
    switch(idMensaje) /** Negativos para errores. 0 Adios*/
    {
        case 1:
            printf(" Hecho!\n");
            break;
        case -1: // Sin entes dados de alta
            printf("\n ERROR - No hay ningun %s dado de alta (opcion 1)\n",ENTIDAD2);
            break;
        case -2: // Acción no valida
            printf("\n ERROR - Accion no valida (entre 1 y %d)\n",QTY_OPCIONES);
            break;
        case -5: // No existe id
            printf("\n No existe este ID\n");
            break;
        case -999: // Error desconocido o generico
            printf("\n ERROR - Algo salio mal!\n");
            break;
        default:   // Si se ingresa un idMensaje inexistente se da un salto de linea
            printf("\n");
    }
    printf("=========================================================\n");
    return 0;
}

int imprimirPedido(ePedido array[], int tamanio, int idCliente)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0 && idCliente >=1)
    {
        if(array[idCliente].estado==0 && array[idCliente].isEmpty==0)
        {
            printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos: %d\n  Estado: %d\n",
            array[idCliente].id, array[idCliente].idCliente, array[idCliente].kilos, array[idCliente].estado);
        }
        else if(array[idCliente].estado==1)
        {
            printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos HDPE: %d\n  Kilos LDPE: %d\n  Kilos PP: %d\n  Kilos de basura: %d\n",
                array[idCliente].id, array[idCliente].idCliente, array[idCliente].kilosHDPE, array[idCliente].kilosLDPE, array[idCliente].kilosPP, array[idCliente].kilosBasura);
        }
    }
    return retorno;
}

int listarPedido(ePedido array[], int tamanio, int estadoBuscado)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {

                if(array[i].estado!=estadoBuscado)
                {
                    continue;
                }
                else
                {
                    if(estadoBuscado==0)
                    {
                        printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos: %d\n  Estado: %d\n",
                        array[i].id, array[i].idCliente, array[i].kilos, array[i].estado);
                    }
                    else if(estadoBuscado==1)
                    {
                        printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos HDPE: %d\n  Kilos LDPE: %d\n  Kilos PP: %d\n  Kilos de basura: %d\n",
                        array[i].id, array[i].idCliente, array[i].kilosHDPE, array[i].kilosLDPE, array[i].kilosPP, array[i].kilosBasura);
                    }
                    retorno=0;
                }
            }
        }
        printf("\n");
    }
    return retorno;
}

int listarEncolumnadoPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int columnaMostrada=0;

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(columnaMostrada==0)
                {
                    printf("  ID\t\tString1\t\tString2\t\tFloat1\t\tFloat2\t\tInt1\t\tInt2\n");
                    columnaMostrada=1;
                }

                /**     Podemos hacerlo en un solo printf, pero me gusta más con varios, además si hay variables que no se usan
                puedo simplemente comentar la línea en lugar de tener que modificar TODO el unico printf

                OPCION 1
                //printf("  %d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%f\t\t%f\n",array[i].id, array[i].string1, array[i].string2, array[i].int1, array[i].int2, array[i].float1, array[i].float2);

                OPCION 2 AGUANTE ESTA :)
                printf("  %d\t\t",array[i].id);
                printf("  %s\t\t",array[i].string1);
                printf("  %s\t\t",array[i].string2);
                printf("  %f\t\t",array[i].float1);
                printf("  %f\t\t",array[i].float2);
                printf("  %d\t\t",array[i].int1);
                printf("  %d\t\t",array[i].int2);
                printf("\n");
                */

                printf("  %d\t\t",array[i].id);
                printf("  %d\t\t",array[i].idCliente);
                printf("  %d\t\t",array[i].kilos);
                printf("  %d\t\t",array[i].estado);
                /*printf("  %f\t\t",array[i].float2);
                printf("  %d\t\t",array[i].int1);
                printf("  %d\t\t",array[i].int2);*/
                printf("\n");

            }
        }
        retorno=0;
    }
    return retorno;
}




int calcularPedidosCliente(ePedido array[], int tamanio, int idCliente,int* cantidadPedidos, int estadoBuscado)
{
    int retorno=-1;
    *cantidadPedidos=0;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==0)
            {
                if(array[i].estado==estadoBuscado)
                {
                    if(array[i].idCliente==idCliente)
                    {
                        *cantidadPedidos+=1;
                    }
                }

            }
        }
        printf("\n");
    }
    return retorno;
}


/** FUNCION GENÉRICA

            Estaba harto de escribir siempre lo mismo en las funciones asi que
        esta funcion comentada la utilizo para realizar copy-paste y crear funciones nuevas
        ya con la validacion, el for y el retorno hechos.


int funcionGenerica(eEntidad array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {


            }
        }
        retorno=0;
    }
    return retorno;
}

*/
