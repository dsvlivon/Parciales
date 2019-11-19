/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validations.h"
#include "arrayStruct.h"

#define QTY_EMPLOYEES 2000
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"

////////////////////////////////////////////////////////////////////////// INIT
void initElement(Element pArray[],int size){
    int i;

    {
        pArray[i].isEmpty=-1;/
    for(i=0; i<size; i++)/LIBRE=-1 // OCUPADO=0
    }
-}
/////////////////////////////////////////////////////////////////////////  ADD
int addElement(Element pArray[], int size){
    int auxReturn=0;
    int freeSpotFlag,freeSpot;
    ////////////
    char pName[50];
    char pLname[50];
    float pSalary;
    int pSector;
    ////////////
    char aux[50];

    freeSpotFlag = searchForEmpty(pArray, size ,&freeSpot);
    if(freeSpotFlag == 0)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
    }
    else if(freeSpotFlag == -1)
    {
        printf("\nAlta Legajo Nro.%d: \n", freeSpot);
        /////////////////////////////////////
        auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
        if(auxReturn == 0)
        {
            strcpy(pName,aux);
            //printf("El nombre validado es: %s\n", pName);
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
            if(auxReturn == 0)
            {
                strcpy(pLname,aux);
                //printf("El apellido validado es: %s\n", pLname);
            }
        }
        else
            {
                auxReturn=-1;
            }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
            if(auxReturn == 0)
            {
                pSalary = atof(aux);
                //printf("El sueldo validado es: $%.2f \n\n", pSalary);
            }
        }
        else
        {
            auxReturn=-1;
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
            if(auxReturn == 0)
            {
                pSector = atoi(aux);
                //printf("El sector validado es: %d \n\n", pSector);
            }
        }
         else
        {
            auxReturn=-1;
        }
        if(searchForEmpty(arrayEmployee,size,&freeSpot)== 0)
        {
            printf("\n\nEL LEGAJO YA EXISTE!!!\n");
        } //BUSCA REPETIDOS
        if(auxReturn == 0)
        {
            freeSpotFlag=0;
            pArray[freeSpot].id = freeSpot;
            strcpy(pArray[freeSpot].name,pName);
            strcpy(pArray[freeSpot].lName,pLname);
            pArray[freeSpot].salary = pSalary;
            pArray[freeSpot].sector = pSector;
            pArray[freeSpot].isEmpty=0;
        }
        //////////////////////////////////////////// testeo
        /*printf("\nAuxReturn: %d\n\n",  auxReturn);
        printf("freeSpotFlag: %d\n",  freeSpotFlag);
        printf("id empleado: %d\n", pArray[freeSpot].id);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot, pArray[freeSpot].isEmpty);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, pArray[freeSpot+1].isEmpty);*/
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmpty(Element pArray[], int size, int* position){
    int flag = 0;
    int i;
    if(pArray != NULL && size>=0 && position!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pArray[i].isEmpty == -1)
            {
                flag = pArray[i].isEmpty;
                *position = i;
                break;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  FID
int findId(Element pArray[], int size, int *auxId){
    int auxReturn=0;
    int i, value;
    char aux[50];

    if(pArray!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",0,2000,2,1);
        if(auxReturn == 0)
        {
            value= atoi(aux);
            for(i=0;i<size-1;i++)
            {
                if(pArray[i].isEmpty==-1)
                {
                    continue;
                }
                if(pArray[i].id==value)
                {
                    *auxId = value;
                    break;
                }
            }
            if(auxReturn==0 && *auxId!=value)
            {
                printf("\nId No disponible.");
                auxReturn=-1;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  MODIF
int ModifElement(Element pArray[], int size){
    int auxReturn=-1;
    int option, value;
    char aux[6];

    if(pArray!= NULL && size>=0)
    {
        printElement(pArray, QTY_ELEMENT);
        auxReturn=findId(pArray, QTY_ELEMENT, &value);
        if(auxReturn==0)
        {

            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nMENU MODIFICACIONES: \n\nLegajo Nro.%d: \n", value);
                printf("\n1)Nombre: %s\n2)Apellido: %s\n3)Sueldo: $%.2f\n4)Sector: %d\n5)VOLVER\n", pArray[value].name, pArray[value].lName, pArray[value].salary, pArray[value].sector);
                auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                if(auxReturn == 0){
                    option= atoi(aux);
                }
                fflush(stdin); //__fpurge para Linux
                switch(option)
                {
                    case 1:
                    auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(pArray[value].name,aux);
                    }
                    break;
                    case 2:
                    auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(pArray[value].lastName,aux);
                    }
                    break;
                    case 3:
                    auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
                    if(auxReturn == 0)
                    {
                        pArray[value].salary = atof(aux);
                    }
                    break;
                    case 4:
                    auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
                    if(auxReturn == 0)
                    {
                        pArray[value].sector = atoi(aux);
                    }
                    break;
                    case 5:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=5);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  REMOVE
int removeElement(Element pArray[], int size){
    int auxReturn=0;
    int value;
    char aux[10];
    char empty[50];

    if(pArray!= NULL && size>=0)
    {
        printElement(pArray, QTY_ELEMENT);
        auxReturn=findId(pArray, QTY_ELEMENT, &value);
        if(auxReturn==0)
        {
            printf("\nBaja Legajo Nro.%d: \n", value);
            printf("\nNombre: %s\nApellido: %s\nSueldo: $%.2f\nSector: %d", pArray[value].name, pArray[value].lName, pArray[value].salary, pArray[value].sector);
            ///////////////////////////////////////////////////////////////////////////////////////
            auxReturn = getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5);
            if(auxReturn==0)
            {
                printf("Baja en curso ...");
                strcpy(pArray[value].name, empty);
                strcpy(pArray[value].lName, empty);
                pArray[value].salary = 0;
                pArray[value].sector = 0;
                pArray[value].isEmpty = -1;
            }
            else
                auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrence(Element pArray[], int size){
    int flag = -1;
    int i;

    if(pArray!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pArray[i].isEmpty == -1)
                continue;
            else if(pArray[i].isEmpty == 0)
            {
                flag = pArray[i].isEmpty;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  PRINT
int printElement(Element pArray[],int size){
    int auxReturn=-1;
    int i;

    if(pArray!=NULL && size>=0)
    {
        printf("ID\t  APELLIDO\t  NOMBRE\t  SUELDO\t  SECTOR\t\n");
        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty==0)
            {
                auxReturn=0;
                printf("\n%d\t  %s\t  %s\t  %.2f\t  %d\t", pArray[i].id, pArray[i].lName, pArray[i].name, pArray[i].salary, pArray[i].sector);
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SORT
int sortElement(Element pArray[], int size, int pOrder){
    int auxReturn=-1;
    int i,j;

    int pId;
    char pName[50];
    char pLname[50];
    int pSector;
    float pSalary;
    int pIsEmpty;
    /////////////////////////////////
    if(arrayEmployee!=NULL && size>=0)
    {
        if(pOrder==1)
        {
            for(i=0;i<size-1;i++)
            {
                if(pArray[i].isEmpty!=0)
                    continue;
                else if(strcmp(pArray[i].lName,pArray[i+1].lName)>0)
                {
                    pId = pArray[i].id;
                    strcpy(pName, pArray[i].name);
                    strcpy(pLname, pArray[i].lName);
                    pSalary = pArray[i].salary;
                    pSector = pArray[i].sector;
                    pIsEmpty = pArray[i].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    pArray[i].id = pArray[i+1].id;
                    strcpy(pArray[i].name, pArray[i+1].name);
                    strcpy(pArray[i].lName, pArray[i+1].lName);
                    pArray[i].salary = pArray[i+1].salary;
                    pArray[i].sector = pArray[i+1].sector;
                    pArray[i].isEmpty = pArray[i+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    pArray[i+1].id= pId;
                    strcpy(pArray[i+1].name, pName);
                    strcpy(pArray[i+1].lName, pLname);
                    pArray[i+1].salary = pSalary;
                    pArray[i+1].sector = pSector;
                    pArray[i+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
                if(pArray[i].isEmpty!=0)
                    continue;
                else if(strcmp(pArray[i].lName, pArray[i+1].lName)==0)
                {
                    if(pArray[i].sector > pArray[i+1].sector)
                    {
                        pId = pArray[i].idEmployee;
                        strcpy(pName, pArray[i].name);
                        strcpy(pLname, pArray[i].lName);
                        pSalary = pArray[i].salary;
                        pSector = pArray[i].sector;
                        pIsEmpty = pArray[i].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 1
                        pArray[i].id = pArray[i+1].id;
                        strcpy(pArray[i].name, pArray[i+1].name);
                        strcpy(pArray[i].lName, pArray[i+1].lName);
                        pArray[i].salary = pArray[i+1].salary;
                        pArray[i].sector = pArray[i+1].sector;
                        pArray[i].isEmpty = pArray[i+1].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 2
                        pArray[i+1].id= pId;
                        strcpy(pArray[i+1].name, pName);
                        strcpy(pArray[i+1].lName, pLname);
                        pArray[i+1].salary = pSalary;
                        pArray[i+1].sector = pSector;
                        pArray[i+1].isEmpty = pIsEmpty;
                        ////////////////////////////////// swap Y ascendente step 3
                    }
                }
            }
        }
        if(pOrder==2)
        {
            for(j=0;j<size-1;j++)
            {
                if(pArray[j].isEmpty!=0)
                    continue;
                else if(strcmp(pArray[j].lName,pArray[j+1].lName)<0)
                {
                    pId = v[j].id;
                    strcpy(pName, pArray[j].name);
                    strcpy(pLname, pArray[j].lName);
                    pSalary = pArray[j].salary;
                    pSector = pArray[j].sector;
                    pIsEmpty = pArray[j].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    pArray[j].id = pArray[j+1].id;
                    strcpy(pArray[j].name, pArray[j+1].name);
                    strcpy(pArray[j].lName, pArray[j+1].lName);
                    pArray[j].salary = pArray[j+1].salary;
                    pArray[j].sector = pArray[j+1].sector;
                    pArray[j].isEmpty = pArray[j+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    pArray[j+1].id = pId;
                    strcpy(pArray[j+1].name, pName);
                    strcpy(pArray[j+1].lName, pLname);
                    pArray[j+1].salary = pSalary;
                    pArray[j+1].sector = pSector;
                    pArray[j+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
                if(pArray[j].isEmpty!=0)
                    continue;
                else if(strcmp(pArray[j].lName, pArray[j+1].lName)==0)
                {
                    if(pArray[j].sector < pArray[j+1].sector)
                    {
                        pId = pArray[j].id;
                        strcpy(pName, pArray[j].name);
                        strcpy(pLname, pArray[j].lName);
                        pSalary = pArray[j].salary;
                        pSector = pArray[j].sector;
                        pIsEmpty = pArray[j].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 1
                        pArray[j].id = pArray[j+1].id;
                        strcpy(pName, pArray[j].name);
                        strcpy(pLname, pArray[j].lastName);
                        pArray[j].salary = pArray[j+1].salary;
                        pArray[j].sector = pArray[j+1].sector;
                        pArray[j].isEmpty = pArray[j+1].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 2
                        pArray[j+1].id = pId;
                        strcpy(pArray[j+1].name, pName);
                        strcpy(pArray[j+1].lName, pLname);
                        pArray[j+1].salary = pSalary;
                        pArray[j+1].sector = pSector;
                        pArray[j+1].isEmpty = pIsEmpty;
                        ////////////////////////////////// swap Y ascendente step 3
                    }
                }
            }
        }
        auxReturn=0;
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  Inform A
int informA(Element pArray[], int size){
    int auxReturn = -1;
    int i;
    int eToken=0;
    int sToken=0;
    float sBuffer=0;

    if(pArray!= NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty == -1)
                continue;
            else if(pArray[i].isEmpty == 0)
            {
                eToken++;
                sBuffer = sBuffer + pArray[i].salary;
            }
        }

        printf("\n\nNOMINA SALARIAL: %.2f", sBuffer);
        printf("\nSUELDO PROMEDIO: %.2f", sBuffer/eToken);

        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty == 0 && pArray[i].salary > sBuffer/eToken)
            {
                sToken++;
            }
        }
        printf("\n\nEmpleados que superan el salario promedio: %d\n", sToken);
    }
    return auxReturn;
}
