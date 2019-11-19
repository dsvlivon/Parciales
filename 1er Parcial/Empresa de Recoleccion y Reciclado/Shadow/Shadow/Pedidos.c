/*******************************************************************
*Programa:ABM Empresa de recoleccion y residuos
*Objetivo: Esqueleto para ABM generico
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "Pedidos.h"
////////////////////////
#define QTY_ORDER 1000
#define FAIL_ORMSG "Los Kgs. por tipo no puede superar los Kgs. totales.\n\n"
////////////////////////////////////////////////////////////////////////// INIT
void initOrder(Order o_Array[],int size){
    int i;

    if(o_Array!=NULL && size >0)
    {
        for(i=0; i<size-1; i++)
        {
            if(o_Array[i].kg == 0)
            {
                o_Array[i].isEmpty = 0;
                o_Array[i].status = -1;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmptyOrder(Order o_Array[], int size){
    int i;
    if(o_Array != NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(o_Array[i].isEmpty == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrenceOrder(Order o_Array[], int size){
    int i;
    if(o_Array!= NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(o_Array[i].isEmpty == 1)
            {
                return i;
            }
        }
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////  ADD
int addOrder(Order o_Array[], int size, int *auxCcode){
    int auxReturn = 0;
    int index = 0;
    ////////////
    int pCompanyId = -1;
    int pKg;
    ////////////
    char aux[51];
    ///////////////////////////
    if(o_Array!=NULL && size >0)
    {
        pCompanyId = *auxCcode;
        index = searchForEmptyOrder(o_Array, QTY_ORDER);
        if(index == -1)
        {
            printf("\n\nNO HAY DISPONIBILIDAD!!!\n");
        }
        else
        {
            /////////////////////////////////////
            if(auxReturn==0)
            {
                auxReturn = getInput(aux, "Ingrese los KGs a recoger: ","\nIngreso invalido!",0,9999,2,1);
                if(auxReturn == 0)
                {
                    pKg = atoi (aux);
                }
            }
            ///////////////////////////////////////////////////
            printf("\nEstado Pedido: PENDIENTE\n");
            printf("Alta Pedido Nro.%d: \n", index);
            ///////////////////////////////////////////////////
            if(searchForEmptyOrder(o_Array,size)<0)//BUSCA REPETIDOS
            {
                printf("\n\nEL CODIGO YA EXISTE!!!\n");
            }
            if(auxReturn == 0 && pCompanyId>=0)
            {
                o_Array[index].orderId = index;
                o_Array[index].companyId = pCompanyId;
                o_Array[index].kg = pKg;
                o_Array[index].status = 0;
                o_Array[index].isEmpty = 1;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  PO
int processOrder(Order o_Array[], int size){
    int index=0;
    char aux[51];
    int auxHdpe,auxLdpe,auxPp;
    int auxReturn = 0;
    int accum = 0;
    /////////////////////////////
    if(o_Array!=NULL && size >0)
    {
        printOrder(o_Array, QTY_ORDER);
        if(findIdOrder(o_Array, QTY_ORDER, &index)==0)
        {
            if(o_Array[index].status == 0)
            {
                printf("Nro. pedido: %d", index);
                if(getInput(aux,"\n\nIngrese la cantidad procesada de HDPE:","\nIngreso Invalido.",0,9999,2,1)==0)
                {
                    auxHdpe = atoi(aux);
                    accum = accum +auxHdpe;
                }
                else
                    auxReturn = -1;
                if(getInput(aux,"Ingrese la cantidad procesada de LPDE:","Ingreso Invalido.",0,9999,2,1)==0)
                {
                    auxLdpe = atoi(aux);
                    accum = accum + auxLdpe;
                }
                else
                    auxReturn = -1;
                if(getInput(aux,"Ingrese la cantidad procesada de PP:","Ingreso Invalido.",0,9999,2,1)==0)
                {
                    auxPp = atoi(aux);
                    accum = accum + auxPp;
                }
                else
                    auxReturn = -1;
                if(auxReturn == -1 || accum > o_Array[index].kg)
                {
                    printf(FAIL_ORMSG);
                    printf("\n//////////////////////////\nEstado Pedido: PENDIENTE\n//////////////////////////\n");
                }
                else
                {
                    o_Array[index].ldpe = auxLdpe;
                    o_Array[index].pp = auxPp;
                    o_Array[index].hdpe = auxHdpe;
                    o_Array[index].companyId = index;
                    o_Array[index].status = 1;
                    ///////////////////////////////////////
                    printf("\nTotal procesado: %d", accum);
                    printf("\nTotal Descarte: %d", o_Array[index].kg-accum);
                    printf("\nEstado Pedido: COMPLETADO\n");
                }
                auxReturn = 0;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  FID
int findIdOrder(Order o_Array[], int size, int *auxId){
    int auxReturn = 0;
    int i, index = 0;
    char aux[50];
    ////////////////////////////
    if(o_Array!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el Nro. de Pedido: ","\nIngreso invalido!",0,2000,2,1);
        if(auxReturn == 0)
        {
            index = atoi(aux);
            for(i=0;i<size-1;i++)
            {
                if(o_Array[i].orderId == index)
                {
                    *auxId = index;
                    break;
                }
            }
        }
        if(auxReturn==0 && *auxId != index)
        {
            printf("\nNro. de Pedido No disponible.");
            auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  PRINT
int printOrder(Order o_Array[],int size){
    int auxReturn=-1;
    int i;
    ///////////////////////////
    if(o_Array!=NULL && size>=0)
    {
        printf("Nro.Pedido\t  ID Empresa\t  Kg.Pedido\t  Status\t\n");
        for(i=0;i<size-1;i++)
        {
            if(o_Array[i].isEmpty == 1)
            {
                if(o_Array[i].status == 0)
                {
                    auxReturn=0;
                    printf("%d\t          %d\t            %d\t        Pendiente\n", o_Array[i].orderId, o_Array[i].companyId, o_Array[i].kg);
                }
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  IDG
int orderIdGenerator(){
    static int idCounter=500; // scoope local.
    idCounter++;
    return idCounter;
}
/////////////////////////////////////////////////////////////////////////  SORT
int sortOrder(Order o_Array[], int size){
    int auxReturn=-1;
    int i;
    ///////////////
    int pOrderId;
    int pCompanyId;
    int pKg;
    int pStatus;
    int pLdpe;
    int pPp;
    int pHdpe;
    int pIsEmpty;
    ///////////////////////////
    if(o_Array!=NULL && size>=0)
    {
            for(i=0;i<size-1;i++)
            {
                if(o_Array[i].isEmpty!=1)
                    continue;
                else if(o_Array[i].companyId > o_Array[i+1].companyId)
                {
                    pOrderId = o_Array[i].orderId;
                    pKg = o_Array[i].kg;
                    pStatus = o_Array[i].status;
                    pLdpe = o_Array[i].ldpe;
                    pPp = o_Array[i].pp;
                    pHdpe = o_Array[i].hdpe;
                    pIsEmpty = o_Array[i].isEmpty;
                    pCompanyId = o_Array[i].companyId;
                    ////////////////////////////////// swap X ascendente step 1
                    o_Array[i].orderId = o_Array[i+1].orderId;
                    o_Array[i].kg = o_Array[i+1].kg;
                    o_Array[i].status = o_Array[i+1].status;
                    o_Array[i].ldpe = o_Array[i+1].ldpe;
                    o_Array[i].pp = o_Array[i+1].pp;
                    o_Array[i].hdpe = o_Array[i+1].hdpe;
                    o_Array[i].isEmpty = o_Array[i+1].isEmpty;
                    o_Array[i].companyId = o_Array[i+1].companyId;
                    ////////////////////////////////// swap X ascendente step 2
                    o_Array[i].orderId = pOrderId;
                    o_Array[i].kg = pKg;
                    o_Array[i].status = pStatus;
                    o_Array[i].ldpe = pLdpe;
                    o_Array[i].pp = pPp;
                    o_Array[i].hdpe = pHdpe;
                    o_Array[i].isEmpty= pIsEmpty ;
                    o_Array[i].companyId = pCompanyId;
                    ////////////////////////////////// swap X ascendente step 3
                }
            }
        auxReturn=0;
    }
    return auxReturn;
}
/////////////
void contadorPedidosPendientes(Order o_Array[], int auxCompanyId, int* counter)
{
	int i;
	int oCounter = 0;
	if(o_Array != NULL)
	{
		for (i = 0; i < QTY_ORDER; i++)
		{
			if (auxCompanyId == o_Array[i].companyId && o_Array[i].status == 0)
			{
				oCounter++;
			}
		}
		*counter = oCounter;
	}

}
