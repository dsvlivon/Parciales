/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Venta.h"
#include "validations.h"
#define FAIL_INIT "\n\nNO HAY DATOS HABILITADOS. \n"
#define FAIL_ADD "\n\nNO SE PUEDE CREAR EL EMPLEADO CON DATOS ERRONES. \n"

////////////////////////////////////////////////////////////////////////////////// LOAD CSV
int controller_loadFromText(char* path , LinkedList* this){
    int auxReturn =-1;
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "r");

    if(pFileTxt != NULL)
    {
        if(parser_ElementFromText(pFileTxt , this)==0)
        {
            auxReturn=0;
        }
    }
    return auxReturn;
}


////////////////////////////////////////////////////////////////////////////////// DELETE LL
int controller_deleteLinkedList(LinkedList* this){
    int auxReturn=-1;
    //Employee* pxEmployee=NULL;

    if(this!= NULL)
    {
        ll_clear(this);
        printf("\n////////SE ELIMINO LA BASE DE DATOS///////////\n");
        auxReturn=0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// LIST
int controller_listElement(LinkedList* this){
    int auxReturn=-1;
    int xLen,i;
    int auxId, auxQty, auxPrice;
    char auxType[50], auxDate[50], auxCuit[50];
    Element* auxPelement=NULL;

    if(this != NULL)
    {
        xLen=ll_len(this);
        for(i=0;i<xLen;i++)
        {
            auxPelement=(Element*)ll_get(this,i);
            element_getId(auxPelement,&auxId);
            element_getQty(auxPelement,&auxQty);
            element_getPrice(auxPelement,&auxPrice);

            element_getType(auxPelement,auxType);
            element_getCuit(auxPelement,auxCuit);
            element_getDate(auxPelement,auxDate);

            printf("Id: %d      Cantidad: %d      Precio Un.: %d        Tipo: %s        Cuit: %s        Fecha: %s\n",auxId,auxQty,auxPrice,auxType, auxCuit, auxDate);
        }
        auxReturn = 0;
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SORT
int controller_sortElement(LinkedList* this){

    int auxReturn = -1;

    if(this!= NULL)
    {
        ll_sort(this, element_sortByQty,1);
    }
        else
        printf(FAIL_INIT);
  return auxReturn;
}


/*
Luego deberá generar un archivo “informes.txt” con el siguiente formato:
********************
Informe de ventas
********************
- Cantidad de fotos reveladas totales: XX
- Cantidad de ventas por un monto mayor a $150: XX
- Cantidad de ventas por un monto mayor a $300: XX
- Cantidad de fotos polaroids reveladas: XX
********************
Los tipos de fotos son los siguientes:
4R_10x15
5R_13x18
6R_15x20
8R_20x25
POLAROID_11x9
POLAROID_10x10
*/

////////////////////////////////////////////////////////////////////////////////// SAVE CSV
int controller_saveAsText(char* path , LinkedList* this){
    int auxReturn =0;
    int i,xLen=0;
    int auxId, auxQty, auxPrice;
    char auxType[50], auxDate[50], auxCuit[50];
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "w");
    Element* auxPelement=NULL;

    if(this!=NULL)
    {
        if(pFileTxt != NULL)
        {
            xLen = ll_len(this);
            for(i=0; i<xLen;i++)
            {
                auxPelement = ll_get(this,i);
                //fwrite(pe, sizeof(Employee),1,pFileTxt);
                element_getId(auxPelement,&auxId);
                element_getQty(auxPelement,&auxQty);
                element_getPrice(auxPelement,&auxPrice);

                element_getType(auxPelement,auxType);
                element_getCuit(auxPelement,auxCuit);
                element_getDate(auxPelement,auxDate);
                fprintf(pFileTxt,"%d,%d,%d,%s,%s,%s\n",auxId,auxQty,auxPrice,auxType, auxCuit, auxDate);
            }
        }
        else
            auxReturn = -1;
        fclose(pFileTxt);
        printf("\n/////////////////////////////////////\n");
        if(auxReturn==0)
        {
            printf("EL ARCHIVO SE GUARDO CON EXITO.");
            printf("\nSe guardaron : %d registros de ventas.", xLen);
        }
        else
        {
            printf("EL ARCHIVO NO SE PUDO GUARDAR.");
        }
        printf("\n/////////////////////////////////////\n");
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}

////////////////////////////////////////////////////////////////////////////////// FIND ID
int controller_findElementById(LinkedList* this, int id){
    int auxReturn = -1;
    int i,auxId,xLen;
    Element* auxPelement=NULL;

    if(this!= NULL)
    {
        xLen = ll_len(this);
        auxReturn = -2;
        for(i=0; i<xLen; i++)
        {
            auxPelement= (Element*)ll_get(this,i);

            if(auxPelement!= NULL)
            {
                if(element_getId(auxPelement,&auxId) == 0)
                {
                    if(auxId == id)
                    {
                        auxReturn = i;
                        break;
                    }
                }
            }
        }
    }
    return auxReturn;
}

int controller_generarInforme(char* path , LinkedList* this){
    int auxReturn =-1;
    //int i,xLen=0;
    //int auxId, auxQty, auxPrice;
    //char auxType[50], auxDate[50], auxCuit[50];
    int counter=0;

    int counter150=0;
    int counter300=0;
    int counterPol=0;
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "w");
    //Element* auxPelement=NULL;

    if(this!=NULL)
    {
        if(pFileTxt != NULL)
        {
            counter = ll_count(this, criterio_Qty);
            counter150 = ll_count(this, criterio_Price);
            counter300 = ll_count(this, criterio_Price2);
            counterPol = ll_count(this, criterio_Type);

            //fprintf(pFileTxt,"%d,%d,%d,%s,%s,%s\n",auxId,auxQty,auxPrice,auxType, auxCuit, auxDate);

            fprintf(pFileTxt,"********************\n""Informe de ventas\n""********************\n");
            fprintf(pFileTxt,"- Cantidad de fotos reveladas totales: %d\n", counter);
            fprintf(pFileTxt,"- Cantidad de ventas por un monto mayor a $150: %d\n", counter150);
            fprintf(pFileTxt,"- Cantidad de ventas por un monto mayor a $300: %d\n", counter300);
            fprintf(pFileTxt,"- Cantidad de fotos polaroids reveladas: %d\n", counterPol);
            fprintf(pFileTxt,"********************\n");
            auxReturn=0;
        }
        else
            auxReturn = -1;
        fclose(pFileTxt);
        printf("\n/////////////////////////////////////\n");
        if(auxReturn==0)
        {
            printf("EL ARCHIVO SE GUARDO CON EXITO.");
        }
        else
        {
            printf("EL ARCHIVO NO SE PUDO GUARDAR.");
        }
        printf("\n/////////////////////////////////////\n");
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}


/*
////////////////////////////////////////////////////////////////////////////////// ADD
int controller_addElement(LinkedList* this){
        int auxReturn=-1;
        Element* auxPelement=NULL;
        //char aux[50];
        //int var1="-1";
        char var2[50],var3[50],var4[50],var5[50],var6[50];

        if(this!=NULL)
        {
            //printf("\nMENU ORDENAMIENTO: \n1) Ordenar por Nombre. \n2) Ordenar por sueldo. \n3) Ordenar por Horas trabajadas.");
            printf("\nALTA DE EMPLEADO.");
            printf("\n/////////////////////////////////////\n");
            if(getInput(var2, "\nIngrese el nombre: ","\nIngreso invalido!",0,50,2,3) == 0)
            {
                //strcpy(var2, aux);
                //var1 = atoi(aux);
                auxReturn = 0;
            }
            else
                printf(FAIL_ADD);
            if(auxReturn==0)
            {
               auxReturn = getInput(var3, "\nIngrese las Horas Trabajadas: ","\nIngreso invalido!",0,1100,2,1);
            }
             else
                printf(FAIL_ADD);
            if(auxReturn==0)
            {
                auxReturn= getInput(var4, "\nIngrese el sueldo: ","\nIngreso invalido!",0,999999,2,1);
                //strcpy(var4, aux);
            }
             else
                printf(FAIL_ADD);
            printf("\n/////////////////////////////////////\n");
            if(auxReturn==0)
            {
                //printf("Nombre: %s\n", var2);
                //printf("Horas: %s\n", var3);
                //jonprintf("Sueldo: %s\n", var4);
                auxPelement = element_newParametros("-1",var2,var3,var4,var5,var6);
                if(auxPelement!=NULL)
                {
                   ll_add(this, auxPelement);
                }
            }
            else
                printf(FAIL_ADD);
        }
   return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// EDIT
int controller_editElement(LinkedList* this){
    int auxReturn=-1;
    Element* auxPelement=NULL;
    char aux[50];
    char auxDate[50],auxType[50],auxCuit[50];
    int auxId, auxPrice,auxQty;
    int pIndex;
    int flag=0;
    int option=0;

    if(this!=NULL)
    {
        printf("\nMENU MODIFICACION DE EMPLEADO.");
        printf("\n/////////////////////////////////////\n");
        if(getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",0,9999,2,1) == 0)
        {
            auxId=atoi(aux);
            pIndex = controller_findElementById(this,auxId);
            if(pIndex>=0)
            {
                auxPelement = (Element*)ll_get(this,pIndex);

                if(auxPelement != NULL)
                {
                    flag = 1;
                }
            }
            else
            {
                printf("\nID no disponible.\n");
            }
        }
        if(flag==1)
        {
            element_getQty(auxPelement,&auxQty);
            element_getPrice(auxPelement,&auxPrice);

            element_getDate(auxPelement,auxDate);
            element_getCuit(auxPelement,auxCuit);
            element_getType(auxPelement,auxType);

            printf("\n1) Modificar Nombre: %s\n2) Modificar Sueldo: %d\n3) Modificar Horas Trabajadas: %d", auxNombre, auxSueldo, auxHoras);
            auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,3,2,1);
            if(auxReturn == 0)
            {
                option = atoi(aux);
                if(option==1)
                {
                    if(getInput(aux, "\n\nIngrese el nombre: ","\nIngreso invalido!",0,50,2,3) == 0)
                    {
                        strcpy(auxNombre, aux);
                        element_setNombre(auxPelement, auxNombre);
                    }
                }
                if(option==2)
                {
                    if(getInput(aux, "\n\nIngrese el sueldo: ","\nIngreso invalido!",0,999999,2,1) == 0)
                    {
                        auxSueldo = atoi(aux);
                        element_setSueldo(auxPelement,auxSueldo);
                    }
                }
                 if(option==3)
                {
                    if(getInput(aux, "\n\nIngrese las Horas Trabajadas: ","\nIngreso invalido!",0,1100,2,1) == 0)
                    {
                        auxHoras  = atoi(aux);
                        element_setHorasTrabajadas(auxPelement, auxHoras);
                    }
                }
            }
            else
                printf("No se pudo modificar el campo.\n");
            printf("\n/////////////////////////////////////\n");
        }
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// REMOVE
int controller_removeElement(LinkedList* this){
    int auxReturn=-1;
    int pIndex,auxId;
    char aux[50];
    char auxNombre[50];
    Element* auxPelement=NULL;

    if(this!=NULL)
    {
        printf("\nMENU BAJA DE EMPLEADO: \n");
        if(getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",0,9999,2,1) == 0)
        {
            auxId=atoi(aux);
            pIndex = controller_findElementById(this,auxId);
            if(pIndex>=0)
            {
                auxPelement=(Element*)ll_get(this,pIndex);
                element_getNombre(auxPelement,auxNombre);
                printf("\n////////////////////////////////////\n");
                printf("\nEmpleado ID Nro.: %d", auxId);
                printf("\nEmpleado Nombre: %s\n", auxNombre);
                //printf("\nEmpleado: %s\n", *(pArrayListEmployee+pIndex);
                if(getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5)==0)
                {
                    printf("Baja en curso ...\n");
                    if(ll_remove(this, pIndex)==0)
                    {
                        auxReturn=0;
                        printf("Se realizo la baja con exito.");
                    }
                }
                else
                {
                    printf("No se pudo realizar la baja.");
                }
                printf("\n////////////////////////////////////\n");
            }
        }
    }

    return auxReturn;
}*/
