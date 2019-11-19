#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedido.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedido.h"

/**
 * \brief Inicializa el status en un array de empleados
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \param value Es el valor que se asignara a isEmpty
 * \return -
 *
 */
void initPedido(Recoleccion list[], int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        list[i].isEmpty1 = value;

    }
}


/**
 * \brief Inicializa el status en un array de empleados
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \param value Es el valor que se asignara a isEmpty
 * \return -
 *
 */
void initPedidosOneorCero(Recoleccion list[], int len,int value)
{
    int i;
    for(i=0;i < len; i++)
    {
        list[i].pedido = value;

    }
}


/**
 * \brief Busca la primer ocurrencia de un empleado mediante su id
 * \param list Es el array en el cual buscar
 * \param len Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarIdPedido(Recoleccion list[],int len,int code)
{
    int i;
    for(i=0;i < len; i++)
    {
        if(list[i].idPedido == code && list[i].pedido == 1)
        {
            return i;
        }
    }
    return -1;
}
