//////////////////////////////////////////////////////////////
#include "relacionInformes.h"
//////////////////////////////////////////////////////////////

int msjRelacion(int idMensaje)
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
        case -999: // Error desconocido o generico
            printf("\n ERROR - Algo salio mal!\n");
            break;
        default:   // Si se ingresa un idMensaje inexistente se da un salto de linea
            printf("\n");
    }
    printf("=========================================================\n");
    return 0;
}


/*
int listarPedidosDeCliente(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int idCliente=0;
        utn_getUnsignedInt("-Ingrese el id del cliente: "," ERROR - ID invalido\n",1,TEXT_SIZE,1,QTY_ENTIDADES,2,&idCliente);

        for(int i=0;i<tamanio;i++)
        {
            if(array[i].idCliente==idCliente)
                {
                    imprimirPedido(array,tamanio,idCliente);
                    retorno=0;
                }
        }

    }
    return retorno;
}
*/
