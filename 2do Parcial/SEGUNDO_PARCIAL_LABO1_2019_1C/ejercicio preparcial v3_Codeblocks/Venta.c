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
#include "Venta.h"
#include "validations.h"
////////////////////////////////////////////////////////////////////////////////// Element New
Element* element_new(){

    Element* this = (Element*) malloc(sizeof(Element));
    if( this != NULL)
    {
        this->ID_Venta = 0;
        strcpy(this->Fecha_Venta, "");
        strcpy(this->Tipo_Foto, "");
        this->Cantidad = 0;
        this->Precio_Unitario = 0;
        strcpy(this->CUIT_Cliente, "");
    }
    return this;
}
////////////////////////////////////////////////////////////////////////////////// Element NewPARAMETROS
Element* element_newParametros(char* ID_Venta,char* Fecha_Venta,char* Tipo_Foto, char* Cantidad, char* Precio_Unitario, char* CUIT_Cliente){

    Element* this;
    int flag=-1;
    int auxId,auxQty,auxPrice;
    char auxDate[50], auxPicType[50], auxCuit[50];
    //int//ID_Venta;Precio_Unitario;Cantidad
    //char//Tipo_Foto;Fecha_Venta;CUIT_Cliente
    if (ID_Venta != NULL && Cantidad != NULL && Precio_Unitario != NULL && Fecha_Venta != NULL && Tipo_Foto!=NULL && CUIT_Cliente!= NULL)
    {
        this  = element_new();
        if(this != NULL)
        {
            if(isOnlyNumber(ID_Venta)==0)
            {
                auxId = atoi(ID_Venta);
                flag = element_setId(this, auxId);
            }
            if(flag==0)
            {
                if(isNumeric(Precio_Unitario)==0)
                {
                    auxPrice = atoi(Precio_Unitario);
                    flag = element_setPrice(this, auxPrice);
                }
            }
            if(flag==0)
            {
                if(isNumeric(Cantidad)==0)
                {
                    auxQty= atoi(Cantidad);
                    flag = element_setQty(this, auxQty);
                }
            }
            //Fecha_Venta;Tipo_Foto;CUIT_Cliente
            if(flag==0)
            {
                if(isAlphaNumeric(Tipo_Foto)==0)
                {
                    strcpy(auxPicType, Tipo_Foto);
                    flag = element_setType(this, auxPicType);
                }
            }
            if(flag==0)
            {
                if(isDate(Fecha_Venta)==0)
                {
                    strcpy(auxDate, Fecha_Venta);
                    flag = element_setDate(this, auxDate);
                }
            }
            if(flag==0)
            {
                if(isCuit(CUIT_Cliente)==0)
                {
                    strcpy(auxCuit, CUIT_Cliente);
                    flag = element_setCuit(this, auxCuit);
                }
            }
        }
        else
            printf("sale x This != NULL");
        if(flag!=0)
        {
            free(this);
            this = NULL;
            printf("Datos corruptos.");
        }
    }
    return this;
}
////////////////////////////////////////////////////////////////////////////////// SET int
int element_setId(Element* this,int buffer){

    int auxReturn = -1;
    static int idGenerator=-1;

    if( this != NULL && buffer==-1)
    {
        idGenerator++;
        //id=idGenerator;
        this->ID_Venta = idGenerator;
        auxReturn = 0;
    }
    else if(buffer>idGenerator)
    {
        idGenerator=buffer;
        this->ID_Venta=idGenerator;
        auxReturn=0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET int
int element_getId(Element* this,int* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        *buffer = this->ID_Venta;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET int
int element_setPrice(Element* this,int buffer){
    int auxReturn = -1;

    if( this != NULL && buffer >= 0)
    {
        this->Precio_Unitario = buffer;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET int
int element_getPrice(Element* this,int* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        *buffer = this->Precio_Unitario;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET int
int element_setQty(Element* this,int buffer){
    int auxReturn = -1;

    if( this != NULL && buffer >= 0)
    {
        this->Cantidad = buffer;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET int
int element_getQty(Element* this,int* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        *buffer = this->Cantidad;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Char
int element_setType(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL)
    {
        strcpy(this->Tipo_Foto, buffer);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Char
int element_getType(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        strcpy(buffer, this->Tipo_Foto);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Char
int element_setDate(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL)
    {
        strcpy(this->Fecha_Venta, buffer);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Char
int element_getDate(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        strcpy(buffer, this->Fecha_Venta);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Char
int element_setCuit(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL)
    {
        strcpy(this->CUIT_Cliente, buffer);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Char
int element_getCuit(Element* this,char* buffer){
    int auxReturn = -1;

    if( this != NULL && buffer != NULL )
    {
        strcpy(buffer, this->CUIT_Cliente);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SORT Salary
int element_sortByQty(void*arg1, void* arg2){
    int auxReturn=0;
    Element* p1=NULL;
    Element* p2=NULL;

    if(arg1!=NULL && arg2!=NULL)
    {
        p1 = (Element*)arg1;
        p2= (Element*)arg2;
        if(p1->Cantidad > p2->Cantidad)
        {
            auxReturn=1;
        }
        else if(p1->Cantidad < p2->Cantidad)
        {
            auxReturn=-1;
        }
        else
            auxReturn=0;
    }
    return auxReturn;
}

/*void element_calcularSueldo(void* p){
    Element* buffer=NULL;
    int salary=0, extras1=0, extras2=0;
    int hs=0;
    if(p!=NULL)
    {
    	buffer = (Element*)p;
    	hs = buffer->horasTrabajadas;

        if(hs<=120)
        {
            salary = hs*180;                                    //99*180 = 14760
        }
        else if(hs>120 && hs<=160)
		{
            salary=(hs-120)*240 + (120*180);//extras1 = 16     //136-120=16/16*240=3840+21600 = 25440
			//auxReturn=0;
		}
		else if(hs>160) // si hs = 175
        {
            extras2 =hs-160;// 15
            extras1 =hs-extras2-120; // 175-15-120=40
            salary=(extras2*350)+(extras1*240)+(120*180);       //(15*350=5250)+(40*240=9600)+21600=36450
        }
        //21600+9600+28000=59200
        //31200+(350*54)=50100 arriba de 214hs deberia entrar en el filter
		buffer->sueldo = salary;
    }
 }*/

int criterio_Qty(void* p){
    int test, sample;
    int auxReturn=0;//-1;
    Element* buffer = NULL;
    /////////////
    sample=0;
    /////////////

    buffer = (Element*)p;
    test = buffer->ID_Venta;
    if(test>=sample)
    {
    	auxReturn=buffer->Cantidad;
    }
    return auxReturn;
}

int criterio_Type(void* p){
    char sample1[50]={"POLAROID_11x9"};
    char sample2[50]={"POLAROID_10x10"};
    char test[50];
    int auxReturn=0;//-1;
    Element* buffer = NULL;
    /////////////
    //sample=10;
    /////////////

    buffer = (Element*)p;
    strcpy(test,buffer->Tipo_Foto);
    if(strcmp(test,sample1)==0 || strcmp(test,sample2)==0 )
    {
    	auxReturn=1;
    }
    return auxReturn;
}
int criterio_Price(void* p){
    int test, sample;
    int auxReturn=0;//-1;
    Element* buffer = NULL;
    /////////////
    sample=150;
    /////////////

    buffer = (Element*)p;
    test = buffer->Precio_Unitario;
    if(test>sample)
    {
    	auxReturn=1;
    }
    return auxReturn;
}
int criterio_Price2(void* p){
    int test, sample;
    int auxReturn=0;//-1;
    Element* buffer = NULL;
    /////////////
    sample=300;
    /////////////

    buffer = (Element*)p;
    test = buffer->Precio_Unitario;
    if(test>sample)
    {
    	auxReturn=1;
    }
    return auxReturn;
}
