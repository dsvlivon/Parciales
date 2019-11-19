/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Empleado.h"

////////////////////////////////////////////////////////////////////////////////// PARSER CSV
int parser_parseEmpleados(FILE* pFile, LinkedList* listaEmpleados)
{
	int auxReturn = -1;
    int r= 0;
    int employeeCount=0;
    char var1[50],var3[50],var2[50],var4[50];
    Employee* pxEmployee =NULL;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            pxEmployee = employee_newParametros(var1,var2,var3,var4);
            if(pxEmployee!=NULL)
            {
                ll_add(listaEmpleados,pxEmployee);
                employeeCount++;
                auxReturn=0;
            }
            else
            {
                auxReturn=-1;
                break;
            }
        }
        else
        {
            auxReturn=-1;
            break;
        }
    }while(!feof(pFile));

    fclose(pFile);
    printf("\n////////////////////////\n");
    if(auxReturn==0)
    {
        printf("CARGA DE DATOS EXITOSA.");
        //printf("\nSe cargaron %d empleados.", employeeCount);
    }

    else
    {
        printf("CARGA DE DATOS FALLIDA.");
    }
    printf("\n////////////////////////\n");
    return auxReturn;
}

