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
#include "Cliente.h"
////////////////////////
#define QTY_CLIENT 100
#define FAIL_IDMSG "No se puede completar un legajo con datos erroneos.\n\n"
////////////////////////////////////////////////////////////////////////// INIT
void initClient(Client c_Array[],int size){
    int i;

    if(c_Array!=NULL && size >0)
    {
        for(i=0; i<size-1; i++)
        {
            if(c_Array[i].company!=NULL)
                c_Array[i].isEmpty = 0;
        }
    }
}
/////////////////////////////////////////////////////////////////////////  ADD
int addClient(Client c_Array[], int size){
    int auxReturn = 0;
    int index = 0;
    ////////////////
    char aux[51];
    //////////////////
    if(c_Array!=NULL && size >0)
    {
        index = searchForEmptyClient(c_Array, QTY_CLIENT);
        if(index == -1)
        {
            printf("\n\nNO HAY DISPONIBILIDAD!!!\n");
        }
        else
        {
            if(getInput(aux, "Ingrese nombre de Empresa: ","\nIngreso invalido!",0,51,2,3)==0)
            {
                strcpy(c_Array[index].company, aux);
            }
            else
            {
                auxReturn=-1;
            }
            if(auxReturn==0)
            {
                if(getInput(aux, "Ingrese el cuit: ","\nIngreso invalido!",0,51,2,8)== 0)
                {
                    strcpy(c_Array[index].cuit, aux);
                }
                else
                {
                    auxReturn=-1;
                }
            }
            if(auxReturn==0)
            {
                if(getInput(aux, "Ingrese la direccion: ","\nIngreso invalido!",0,51,2,4)==0)
                {
                    strcpy(c_Array[index].adress, aux);
                }
                else
                {
                    auxReturn=-1;
                }
            }
            if(auxReturn == 0)
            {
                if(getInput(aux, "Ingrese la localidad: ","\nIngreso invalido!",0,50,2,3)==0)
                {
                    strcpy(c_Array[index].location, aux);
                }
                else
                {
                    auxReturn=-1;
                }
            }
            /////////////////////////////////////////////////////////////////
            if(searchForEmptyClient(c_Array,size)<0)//BUSCA REPETIDOS
            {
                printf("\n\nEL NRo. DE CLIENTE YA EXISTE!!!\n");
            }
            if(auxReturn == 0)
            {
                printf("\nAlta efectiva Cliente Nro.:%d \n", index);
                c_Array[index].companyId = index;
                c_Array[index].isEmpty = 1;
            }
            else
            {
                printf(FAIL_IDMSG);
            }
            //////////////////////////////////////////// testeo
            /*printf("\nAuxReturn: %d\n\n",  auxReturn);
            printf("freeSpotFlag: %d\n",  freeSpotFlag);
            printf("id empleado: %d\n", c_Array[freeSpot].id);
            printf("freeSpot: %d  isEmpty: %d\n", freeSpot, c_Array[freeSpot].isEmpty);
            printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, c_Array[freeSpot+1].isEmpty);*/
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmptyClient(Client c_Array[], int size){
    int i;
    int sfeCounter = 0;
    if(c_Array != NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(c_Array[i].isEmpty == 0)
            {
                sfeCounter++;
                return i;
            }
        }
    }
    return-1;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrenceClient(Client c_Array[], int size){
    int i;
    int sfoCounter = 0;
    if(c_Array!= NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(c_Array[i].isEmpty == 1)
            {
                sfoCounter++;
                return i;
            }
        }
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////  FID
int findIdClient(Client c_Array[], int size){
    int auxReturn = -1;
    int i, index = 0;
    char aux[50];
    ////////////////////////////
    if(c_Array!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el ID de cliente: ","\nIngreso invalido!",0,2000,2,1);
        if(auxReturn == 0)
        {
            index = atoi(aux);
            for(i=0;i<size-1;i++)
            {
                if(c_Array[i].companyId == index)
                {
                    return index;
                }
            }
            auxReturn=-1;
        }
        printf("\nId No disponible.");
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  FCUIT
int findCuitClient(Client c_Array[], int size){
    int auxReturn = -1;
    char auxCuit[51];
    int i, index = 0;
    char aux[50];
    ////////////////////////////
    if(c_Array!= NULL && size>=0)
    {
		auxReturn = getInput(aux, "Ingrese el Cuit del Cliente: ","\nIngreso invalido!",0,51,2,8);
        if(auxReturn == 0)
        {
			strcpy(auxCuit, aux);
            for(i=0;i<size-1;i++)
            {
				if(strcmp(c_Array[i].cuit,auxCuit)==0)
                {
                    index = i;
                    return index;
                }
            }
            auxReturn=-1;
        }
        printf("\nCuit No disponible.");
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  MODIF
int modifClient(Client c_Array[], int size){
    int auxReturn=-1;
    int option, index;
    char aux[51];

    if(c_Array!= NULL && size>=0)
    {
        printf("\nMODIFICACION CLIENTE: \n");
        printClient(c_Array, QTY_CLIENT);
        index = findIdClient(c_Array, QTY_CLIENT);
        if(index>=0)
        {
            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nCliente Nro.%d: \n", index);
                printf("\n1)Direccion: \n2)Localidad: \n3)VOLVER\n");
                auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                if(auxReturn == 0){
                    option= atoi(aux);
                }
                fflush(stdin); //__fpurge(stdin) para Linux
                switch(option)
                {
                    case 1:
                    auxReturn = getInput(aux, "Ingrese la direccion: ","\nIngreso invalido!",0,50,2,4);
                    if(auxReturn == 0)
                    {
                        strcpy(c_Array[index].adress,aux);
                    }
                    break;
                    case 2:
                    auxReturn = getInput(aux, "Ingrese la localidad: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(c_Array[index].location,aux);
                    }
                    break;
                    case 3:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=3);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  REMOVE
int removeClient(Client c_Array[], int size){
    int auxReturn = 0;
    int index;
    char aux[10];
    ////////////////////////////
    if(c_Array!= NULL && size>=0)
    {
        printf("\nBAJA CLIENTE: \n");
        printClient(c_Array, QTY_CLIENT);
        index = findIdClient(c_Array, QTY_CLIENT);
        if(index>=0)
        {
            printf("\nBaja Cliente Codigo Nro.%d: \n", index);
            printf("\nEmpresa: %s\n", c_Array[index].company);
            ///////////////////////////////////////////////////////////////////////////////////////
            if(getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5)==0)
            {
                printf("Baja en curso ...");
                c_Array[index].isEmpty = 0;
            }
            else
                auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  PRINT
int printClient(Client c_Array[],int size){
    int auxReturn=-1;
    int i;
    ///////////////////////////
    if(c_Array!=NULL && size>=0)
    {
        printf("ID\t         EMPRESA\t         CUIT\t              DIRECCION\t         LOCALIDAD\t\n");
        for(i=0;i<size-1;i++)
        {
            if(c_Array[i].isEmpty==1)
            {
                auxReturn=0;
                printf("\n%d\t         %s\t          %s\t         %s\t         %s\t", c_Array[i].companyId, c_Array[i].company, c_Array[i].cuit, c_Array[i].adress, c_Array[i].location);
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SORT
int sortClient(Client c_Array[], int size){
    int auxReturn=-1;
    int i;
    ///////////////
    int pCompanyId;
    char pCompany[51];
    char pCuit[51];
    char pAdress[51];
    char pLocation[51];
    int pIsEmpty;
    ///////////////////////////
    if(c_Array!=NULL && size>=0)
    {
            for(i=0;i<size-1;i++)
            {
                if(c_Array[i].isEmpty!=1)
                    continue;
                else if(c_Array[i].companyId > c_Array[i+1].companyId)
                {
                    pCompanyId = c_Array[i].companyId;
                    strcpy(pCompany, c_Array[i].company);
                    strcpy(pCuit, c_Array[i].cuit);
                    strcpy(pAdress, c_Array[i].adress);
                    strcpy(pLocation, c_Array[i].location);
                    pIsEmpty = c_Array[i].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    c_Array[i].companyId = c_Array[i+1].companyId;
                    strcpy(c_Array[i].company, c_Array[i+1].company);
                    strcpy(c_Array[i].cuit, c_Array[i+1].cuit);
                    strcpy(c_Array[i].adress, c_Array[i+1].adress);
                    strcpy(c_Array[i].location, c_Array[i+1].location);
                    c_Array[i].isEmpty = c_Array[i+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    c_Array[i+1].companyId= pCompanyId;
                    strcpy(c_Array[i+1].company, pCompany);
                    strcpy(c_Array[i+1].cuit, pCuit);
                    strcpy(c_Array[i+1].adress, pAdress);
                    strcpy(c_Array[i+1].location, pLocation);
                    c_Array[i+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
            }
        auxReturn=0;
    }
    return auxReturn;
}
