//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
#include "ABM.h"
#include "utn.h"
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

int mostrarMenu(eCliente* arrayCliente[QTY_ENTIDADES],ePedido* arrayPedido[QTY_ENTIDADES2],int* contadorId)
{
    //////////////////////////////////////////////////////////////
    /**     Podemos hacerlo en un solo printf, pero me gusta más con varios, además si hay variables que no se usan
                    puedo simplemente comentar la línea en lugar de tener que modificar TODO el unico printf */


    printf("  1) Alta de %s\n  2) Modificar %s\n  3) Baja de %s\n\n",
            ENTIDAD,ENTIDAD,ENTIDAD);

    printf("  4) Crear %s de recoleccion\n  5) Procesar residuos\n\n",
           ENTIDAD2);


    printf("  6) Imprimir %ss\n  7) Imprimir %ss pendientes\n  8) Imprimir %ss procesados\n\n", //Se agrega 's' para volver plural la entidad
            ENTIDAD,ENTIDAD2,ENTIDAD2);


    printf("  %d) Salir\n",QTY_OPCIONES);

    int accion=0;
    utn_getUnsignedInt("\n-Ingrese el numero de la accion que desea realizar: ","",1,TEXT_SIZE,1,QTY_OPCIONES,0,&accion);
    //////////////////////////////////////////////////////////////
        switch(accion)
        {
            //////////////////////////////////////////////////////////////
                        /** OPCIONES DE ENTIDAD 1*/
            //////////////////////////////////////////////////////////////
            case 1: //  Alta
                printf("\n");
                if((altaCliente(arrayCliente,QTY_ENTIDADES,&contadorId))==0)
                {
                    msjCliente(1);
                }
                else
                {
                    msjCliente(-999);
                }
                break;
            case 2: // Modificar
                if(buscarEmptyCliente(arrayCliente,QTY_ENTIDADES,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    printf("\n");

                    if((modificarCliente(arrayCliente,QTY_ENTIDADES))==0)
                    {
                        msjCliente(1);
                    }
                    else
                    {
                        msjCliente(-999);
                    }
                }
                else
                {
                    msjCliente(-1);
                }
                break;
            case 3: // Baja

                if((buscarEmptyCliente(arrayCliente,QTY_ENTIDADES,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    printf("\n");
                    if((bajaCliente(arrayCliente,QTY_ENTIDADES))==0)
                    {
                        msjCliente(1);
                    }
                    else
                    {
                        msjCliente(-999);
                    }
                }
                else
                {
                    msjCliente(-1);
                }
                break;

            //////////////////////////////////////////////////////////////
                        /** OPCIONES DE ENTIDAD 2*/
            //////////////////////////////////////////////////////////////

            case 4: // Pedido de recoleccion
                printf("\n");
                if((buscarEmptyCliente(arrayCliente,QTY_ENTIDADES,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    if((altaPedido(arrayPedido,QTY_ENTIDADES2,&contadorId))==0)
                    {
                        msjPedido(1);
                    }
                    else
                    {
                        msjPedido(-999);
                    }
                }
                else
                {
                    msjCliente(-1);
                }
                break;

            case 5: //  Procesar residuos

                if(buscarEmptyPedido(arrayPedido,QTY_ENTIDADES2,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    if((listarPedido(arrayPedido,QTY_ENTIDADES2,0))==0)
                    {

                        if((procesarPedido(arrayPedido,QTY_ENTIDADES2))==0)
                        {
                            msjPedido(1);
                        }
                        else
                        {
                            msjPedido(-999);
                        }
                    }
                    else
                    {
                        msjPedido(-999);
                    }

                }
                else
                {
                msjCliente(-1);
                }
                break;

            //////////////////////////////////////////////////////////////
            /** OPCIONES DE IMPRESIONES SIMPLES (DE UNA UNICA ENTIDAD)*/
            //////////////////////////////////////////////////////////////

            case 6: // Imprimir clientes

                if(buscarEmptyCliente(arrayCliente,QTY_ENTIDADES,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    if((listarCliente(arrayCliente,QTY_ENTIDADES,arrayPedido))==0)
                    {
                        msjCliente(1);
                    }
                    else
                    {
                        msjCliente(-1);
                    }
                }
                break;

            case 7: // Imprimir pedidos pendientes

                if(buscarEmptyPedido(arrayPedido,QTY_ENTIDADES2,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    if((listarPedido(arrayPedido,QTY_ENTIDADES2,0))==0)
                    {
                        msjPedido(1);
                    }
                    else
                    {
                        msjPedido(-1);
                    }
                }
                break;

            case 8: // Imprimir pedidos procesados

                if(buscarEmptyPedido(arrayPedido,QTY_ENTIDADES2,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    if((listarPedido(arrayPedido,QTY_ENTIDADES2,1))==0)
                    {
                        msjPedido(1);
                    }
                    else
                    {
                        msjPedido(-1);
                    }
                }

                break;



            //////////////////////////////////////////////////////////////
            /** OPCIONES DE IMPRESIONES COMPLEJAS (DE MAS DE UNA ENTIDAD)*/
            //////////////////////////////////////////////////////////////

            /*case 9:
                if((listarPedidosDeCliente(arrayCliente,QTY_ENTIDADES2))==0)
                {
                    msjRelacion(1);
                }
                else
                {
                    msjRelacion(-999);
                }

                break;*/


            case QTY_OPCIONES: //Salir
                printf("\n\n\t   Adios!\n\n");
                return 0;
                break;
        }

    printf("\n");
    mostrarMenu(arrayCliente,arrayPedido,contadorId);

    return 0; // Nunca se va a ejecutar esta instrucción
}
