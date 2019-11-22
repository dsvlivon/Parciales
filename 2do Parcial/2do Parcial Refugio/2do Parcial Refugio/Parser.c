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
#include "Cachorro.h"
////////////////////////////////////////////////////////////////////////////////// PARSER CSV
int parser_EmployeeFromText(FILE* pFile ,LinkedList* this){
    int auxReturn = -1;
    int r= 0;
    int employeeCount=0;
    char id[50],name[50],raza[50],reservado[50],genero[50],dias[50];
    Cachorro* aux =NULL;
                                                               //ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,dias, raza,reservado,genero);

                                                                                                //ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,dias, raza,reservado,genero);
        //printf("Id: %s      Nombre: %s      Raza:%s        Dias: %s      Genero:%s      Reservado:%s\n",id,name,dias, raza,reservado,genero);
        if(r==6)
        {
            aux = Cachorro_newParametros(id,name,raza,reservado,genero,dias);
            if(aux!=NULL)
            {
                ll_add(this,aux);
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
