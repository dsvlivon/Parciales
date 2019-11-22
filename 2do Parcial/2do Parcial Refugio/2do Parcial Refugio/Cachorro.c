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
#include "Cachorro.h"
#include "validations.h"
////////////////////////////////////////////////////////////////////////////////// SET ID
int employee_setId(Cachorro* this,int id){

    int auxReturn = -1;

	if(this != NULL)
	{
		this->id = id;
		auxReturn = 0;
	}
	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET ID
int employee_getId(Cachorro* this,int* id){
    int auxReturn = -1;

    if(this != NULL && id != NULL)
	{
		*id = this->id;
		auxReturn = 0;
	}

	return auxReturn;
}

int employee_setDias(Cachorro* this,int dias){
     int auxReturn = -1;

	if(this != NULL)
	{
		this->dias = dias;
		auxReturn = 0;
	}
	return auxReturn;
}


int employee_getDias(Cachorro* this,int* dias){
   int auxReturn = -1;

    if(this != NULL && dias != NULL)
	{
		*dias = this->dias;
		auxReturn = 0;
	}

	return auxReturn;
}

int employee_setNombre(Cachorro* this,char* nombre){
    int auxReturn = -1;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Name
int employee_getNombre(Cachorro* this,char* nombre){
    int auxReturn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Hours
int employee_setRaza(Cachorro* this,char* raza){
    int auxReturn = -1;

	if(this != NULL)
	{
		strcpy(this->raza, raza);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Hours
int employee_getRaza(Cachorro* this,char* raza){
    int auxReturn = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->raza);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Hours
int employee_setGenero(Cachorro* this,char* genero){
    int auxReturn = -1;

	if(this != NULL)
	{
		strcpy(this->genero, genero);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Hours
int employee_getGenero(Cachorro* this,char* genero){
    int auxReturn = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(genero, this->genero);
		auxReturn = 0;
	}

	return auxReturn;
}

////////////////////////////////////////////////////////////////////////////////// SET Salary
int employee_setReservado(Cachorro* this,char* reservado){
    int auxReturn = -1;

	if(this != NULL)
	{
		strcpy(this->reservado, reservado);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Salary
int employee_getReservado(Cachorro* this,char* reservado){
    int auxReturn = -1;

	if(this != NULL && reservado != NULL)
	{
		strcpy(reservado, this->reservado);
		auxReturn = 0;
	}

	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// Employee New
Cachorro* employee_new(){

    Cachorro* this = (Cachorro*) malloc(sizeof(Cachorro));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->raza, "");
        strcpy(this->reservado, "");
        strcpy(this->genero, "");
        this->dias = 0;
    }
    return this;
}
////////////////////////////////////////////////////////////////////////////////// Employee NewPARAMETROS
Cachorro* Cachorro_newParametros(char* idStr,char* nombreStr,char* razaStr, char* reservadoStr, char* generoStr, char* diasStr){

    Cachorro* this;
    int flag=-1;

    if (idStr != NULL && nombreStr != NULL && razaStr!= NULL && reservadoStr != NULL && generoStr != NULL && diasStr!=NULL)
    {
        this  = employee_new();
        if(this != NULL)
        {
                employee_setId(this, atoi(idStr));

                employee_setNombre(this, nombreStr);

                employee_setRaza(this, razaStr);

                employee_setGenero(this, generoStr);

                employee_setReservado(this, reservadoStr);

                employee_setDias(this, atoi(diasStr));
                flag = 0;
                printf("Id: %s      Nombre: %s      Raza:%s        Dias: %s      Genero:%s      Reservado:%s\n",idStr,nombreStr,diasStr, razaStr,reservadoStr,generoStr);
        }

        if(flag!=0)
        {
            free(this);
            this = NULL;
            printf("Datos corruptos.");
        }
    }
    return this;
}

int criterio_dias(void* p)
{
    int test, sample;
    int flag=0;//-1;
    Cachorro* buffer = NULL;
    /////////////
    sample=45;
    /////////////

    buffer = (Cachorro*)p;
    test = buffer->dias;
    if(test<sample)
    {
    	flag=1;
    }
    return flag;
}

int criterio_machos(void* p)
{
    int returnAux = -1;
	Cachorro* auxP;
	auxP = (Cachorro*) p;

	if(strcmp(auxP->genero,"H") == 0)
	{
		returnAux = 1;
	}

	return returnAux;
}
int criterio_callejeros(void* p)
{
    int returnAux = -1;
	Cachorro* auxP;
	auxP = (Cachorro*) p;

	if(strcmp(auxP->raza,"Callejero") == 0)
	{
		returnAux = 1;
	}

	return returnAux;
}
