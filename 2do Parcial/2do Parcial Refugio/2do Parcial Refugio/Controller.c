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
#include "Cachorro.h"
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
        if(parser_EmployeeFromText(pFileTxt , this)==0)
        {
            auxReturn=0;
        }
    }
    return auxReturn;
}

////////////////////////////////////////////////////////////////////////////////// LIST
int controller_listEmployee(LinkedList* this){
    int auxReturn=-1;
    int len,i;
    int auxId,auxDias;
    char auxName[50],auxRaza[50],auxGenero[50],auxReservado[50];

    Cachorro* auxEmployee=NULL;

    if(this != NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            auxEmployee=(Cachorro*)ll_get(this,i);

            employee_getId(auxEmployee,&auxId);
            employee_getDias(auxEmployee,&auxDias);

            employee_getNombre(auxEmployee,auxName);
            employee_getRaza(auxEmployee,auxRaza);
            employee_getGenero(auxEmployee,auxGenero);
            employee_getReservado(auxEmployee,auxReservado);

            printf("Id: %d      Nombre: %s      Raza:%s        Dias: %d      Genero:%s      Reservado:%s\n",auxId,auxName,auxRaza,auxDias, auxGenero, auxReservado);

        }
        auxReturn = 0;
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}

////////////////////////////////////////////////////////////////////////////////// SAVE CSV
int controller_saveAsText(char* path , LinkedList* this){
    int auxReturn =0;
    int i,xLen=0;
    int auxId,auxDias;
    char auxName[50],auxRaza[50],auxGenero[50],auxReservado[50];
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "w");
    Cachorro* auxEmployee=NULL;

    if(this!=NULL)
    {
        if(pFileTxt != NULL)
        {
            xLen = ll_len(this);
            for(i=0; i<xLen;i++)
            {
                auxEmployee = ll_get(this,i);
                //fwrite(pe, sizeof(Employee),1,pFileTxt);
            employee_getId(auxEmployee,&auxId);
            employee_getDias(auxEmployee,&auxDias);

            employee_getNombre(auxEmployee,auxName);
            employee_getRaza(auxEmployee,auxRaza);
            employee_getGenero(auxEmployee,auxGenero);
            employee_getReservado(auxEmployee,auxReservado);

              fprintf(pFileTxt,"%d,%s,%s,%d,%s,%s\n",auxId,auxName,auxRaza,auxDias, auxGenero, auxReservado);
            }
        }
        else
            auxReturn = -1;
        fclose(pFileTxt);
        printf("\n/////////////////////////////////////\n");
        if(auxReturn==0)
        {
            printf("EL ARCHIVO SE GUARDO CON EXITO.");
            printf("\nSe guardaron : %d Cachorros.", xLen);
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
int controller_findEmployeeById(LinkedList* this, int id){
    int auxReturn = -1;
    int i,auxId,len;
    Cachorro* pxEmployee=NULL;

    if( this != NULL)
    {
        len = ll_len(this);
        auxReturn = -2;
        for(i=0; i<len; i++)
        {
            pxEmployee= (Cachorro*)ll_get(this,i);

            if(pxEmployee != NULL)
            {
                if(employee_getId(pxEmployee,&auxId) == 0)
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




