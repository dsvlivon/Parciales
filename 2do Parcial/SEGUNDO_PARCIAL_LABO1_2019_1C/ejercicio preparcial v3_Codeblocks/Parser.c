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
#include "parser.h"
#include "Venta.h"
////////////////////////////////////////////////////////////////////////////////// PARSER CSV
int parser_ElementFromText(FILE* pFile ,LinkedList* this){
    int auxReturn = -1;
    int r= 0;
    int counter=0;
    char var1[50],var3[50],var2[50],var4[50],var5[50],var6[50];
    Element* auxPelement =NULL;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
        if(r==6)
        {
            auxPelement = element_newParametros(var1,var2,var3,var4,var5,var6);
            if(auxPelement!=NULL)
            {
                ll_add(this,auxPelement);
                counter++;
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
