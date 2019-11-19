//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
#include "clienteInformes.h"
//////////////////////////////////////////////////////////////

int msjCliente(int idMensaje)
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
            printf("\n ERROR - No hay ningun %s dado de alta (opcion 1)\n",ENTIDAD);
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

int imprimirCliente(eCliente array[], int tamanio, int idCliente)
{
    int retorno=-1;
        if(array!=NULL && tamanio>=0 && idCliente>=1)
        {
            printf("\n  ID: %d\n  Nombre de la empresa: %s\n  Direccion y localidad: %s\n  Cuit: %d\n",
                    array[idCliente].id, array[idCliente].nombreEmpresa, array[idCliente].direccionYLocalidad, array[idCliente].cuit);
            retorno=0;
        }
    return retorno;
}

int listarCliente(eCliente array[], int tamanio, ePedido arrayPedido[])
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int cantidadPedidosSinProcesar=0;
        for(int i=0;i<tamanio;i++)
        {
            //printf("array[%d].id: %d\n",i,array[i].id);
            if(array[i].isEmpty==0)
            {
                calcularPedidosCliente(arrayPedido,tamanio,array[i].id,&cantidadPedidosSinProcesar,0);
                printf("\n  ID: %d\n  Nombre de la empresa: %s\n  Direccion y localidad: %s\n  Cuit: %d\n  Cantidad de pedidos sin procesar: %d\n",
                        array[i].id, array[i].nombreEmpresa, array[i].direccionYLocalidad, array[i].cuit, cantidadPedidosSinProcesar);
            }
        }
        printf("\n");
        retorno=0;
    }
    return retorno;
}

int listarEncolumnadoCliente(eCliente array[], int tamanio)
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
                printf("  %s\t\t",array[i].nombreEmpresa);
                printf("  %s\t\t",array[i].direccionYLocalidad);
                //printf("  %f\t\t",array[i].float1);
                //printf("  %f\t\t",array[i].float2);
                printf("  %d\t\t",array[i].cuit);
                //printf("  %d\t\t",array[i].int2);
                printf("\n");

            }
        }
        retorno=0;
    }
    return retorno;
}

int ordenarPorVariableCliente(eCliente array[], int tamanio) //Pueden ser mas de una variable
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int bufferId;
        char bufferString1[TEXT_SIZE];
        char bufferString2[TEXT_SIZE];
        //float bufferFloat1;
        //float bufferFloat2;
        int bufferInt1;
        //int bufferInt2;
        int bufferIsEmpty;

        int j;

        int i;
        for(i=1;i<tamanio;i++)
        {
            bufferId=array[i].id;
            strncpy(bufferString1,array[i].nombreEmpresa,TEXT_SIZE);
            strncpy(bufferString2,array[i].direccionYLocalidad,TEXT_SIZE);
            //bufferFloat1=array[i].float1;
            //bufferFloat2=array[i].float2;
            bufferInt1=array[i].cuit;
            //bufferInt2=array[i].int2;
            bufferIsEmpty=array[i].isEmpty;

            j=i-1;

            while ((j >= 0) && strcmp(bufferString1,array[j].nombreEmpresa)<0 && bufferInt1<array[j].cuit)   //Si tiene mas de un criterio se lo agrego, Ej.  && bufferInt1<array[j].int1
            {                                                                      //buffer < campo ascendente   buffer > campo descendente
                array[j + 1].id=array[j].id;
                strncpy(array[j + 1].nombreEmpresa,array[j].nombreEmpresa,TEXT_SIZE);
                strncpy(array[j + 1].direccionYLocalidad,array[j].direccionYLocalidad,TEXT_SIZE);
                //array[j + 1].float1=array[j].float1;
                //array[j + 1].float2=array[j].float2;
                array[j + 1].cuit=array[j].cuit;
                //array[j + 1].int2=array[j].int2;
                array[j + 1].isEmpty=array[j].isEmpty;

                j--;
            }
            array[j + 1].id=bufferId;
            strncpy(array[j + 1].nombreEmpresa,bufferString1,TEXT_SIZE);
            strncpy(array[j + 1].direccionYLocalidad,bufferString2,TEXT_SIZE);
            //array[j + 1].float1=bufferFloat1;
            //array[j + 1].float1=bufferFloat1;
            array[j + 1].cuit=bufferInt1;
            //array[j + 1].int1=bufferInt1;
            array[j + 1].isEmpty=bufferIsEmpty;
        }
        retorno=0;
    }
    return retorno;
}

int promediarVariableCliente(eCliente array[], int tamanio, float* pPromedio)
{
    /** Reemplazar Int1 por nuestra variable a promediar (si es float hay que cambiar también los %d por %f en los printf */

    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int suma=0;
        int cantidad=0;
        float promedio=0;

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                cantidad++;
                suma+=array[i].cuit;

            }
        }

        promedio=suma/cantidad;
        *pPromedio=promedio;

        printf("  El total de Int1 es: %d\n  La cantidad de Int1 es: %d\n  El promedio de Int1 es: %f\n",suma,cantidad,promedio);

        retorno=0;
    }
    return retorno;
}

int compararVariablesConPromedioCliente(eCliente array[], int tamanio)
{
        /** Reemplazar Int1 por nuestra variable a promediar (si es float hay que cambiar también los %d por %f en los printf */

    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        float promedio=0;
        int menor=0;
        int igual=0;
        int mayor=0;

        if((promediarVariableCliente(array,tamanio,&promedio))==0)
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
                    if(array[i].cuit>promedio)
                    {
                        menor++;
                    }
                    else if(array[i].cuit==promedio)
                    {
                        igual++;
                    }
                    else if(array[i].cuit<promedio)
                    {
                        mayor++;
                    }
                }
            }
            printf("  La cantidad de Int1 menor al promedio es: %d\n  La cantidad de Int1 igual al promedio es: %d\n  La cantidad de Int1 mayor al promedio es: %d\n",menor,igual,mayor);
            retorno=0;
        }
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
