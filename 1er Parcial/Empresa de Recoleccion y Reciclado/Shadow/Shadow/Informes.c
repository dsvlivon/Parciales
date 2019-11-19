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
#include "Pedidos.h"
////////////////////////
#define QTY_CLIENT 100
#define QTY_ORDER 1000
////////////////////////////////////////////////////////////////////////// PPenC
void printPendingClient(Client c_Array[], Order o_Array[]){
	int i,j;
	int c_index,o_index;
	int oCounter = 0;
	int auxCompanyId;
	int flag = -1;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		sortClient(c_Array, QTY_CLIENT);
		printf("\nLISTADO DE CLIENTES CON PEDIDOS PENDIENTES: \n");
		for (i = 0; i < QTY_ORDER; i++)
		{
			auxCompanyId = o_Array[i].companyId;
			if (o_Array[i].isEmpty == 1 && o_Array[i].status == 0)
			{
				o_index = i;
				for(j = 0; j < QTY_CLIENT; j++)
				{
					if(c_Array[j].companyId == auxCompanyId)
					{
							oCounter++;
							c_index = j;
							break;
					}
				}
				if(o_Array[o_index].companyId != o_Array[o_index+1].companyId)
				{
					printf("\nNro.Cliente: %d", o_Array[o_index].companyId);
					printf("\nCliente: %s", c_Array[c_index].company);
					printf("\nDireccion: %s", c_Array[c_index].adress);
					printf("\nLocalidad: %s", c_Array[c_index].location);
					printf("\nCuit: %s",c_Array[c_index].cuit);
					printf("\nCant. Pedidos Pendientes: %d", oCounter);
					printf("\n///////////////////////////////////////////\n");
					flag = 0;
					oCounter = 0;
				}
			}
		}
		if(flag != 0)
		{
			printf("PEDIDOS AL DIA.\n");
		}
	}
}
////////////////////////////////////////////////////////////////////////// PPenO
void printPendingOrders(Order o_Array[], Client c_Array[]){
	int i,j;
	int auxCompanyId;
	int c_index,o_index;
	int flag = -1;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		printf("\nLISTADO DE PEDIDOS PENDIENTES: \n");
		for (i = 0; i < QTY_ORDER; i++)
		{
			if (o_Array[i].isEmpty == 1 && o_Array[i].status == 0)
			{
				auxCompanyId = o_Array[i].companyId;
				o_index=i;
				for(j = 0; j < QTY_CLIENT; j++)
				{
					if(c_Array[j].companyId == auxCompanyId)
					{
						c_index = j;
						flag = 0;
						break;
					}
				}
				if(flag == 0)
				{
					printf("\nNro.Pedido: %d", o_Array[o_index].orderId);
					printf("\nCuit Cliente: %s",c_Array[c_index].cuit);
					printf("\nDireccion Cliente: %s", c_Array[c_index].adress);
					printf("\nKGs a recolectar: %d", o_Array[o_index].kg);
					printf("\n///////////////////////////////////////////\n");
				}

			}
		}
		if(flag != 0)
		{
			printf("PEDIDOS AL DIA.\n");
		}
	}
}
////////////////////////////////////////////////////////////////////////// PProO
void printProcessedOrders(Order o_Array[], Client c_Array[]){
	int i,j;
	int auxCompanyId;
	int c_index,o_index;
	int flag = -1;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		printf("\nLISTADO DE PEDIDOS PENDIENTES: \n");
		for (i = 0; i < QTY_ORDER; i++)
		{
			if (o_Array[i].isEmpty == 1 && o_Array[i].status == 1)
			{
				auxCompanyId = o_Array[i].companyId;
				o_index=i;
				for(j = 0; j < QTY_CLIENT; j++)
				{
					if(c_Array[j].companyId == auxCompanyId)
					{
						c_index = j;
						flag = 0;
						break;
					}
				}
				if(flag == 0)
				{
					printf("\nNro.Pedido: %d", o_Array[o_index].orderId);
					printf("\nCuit Cliente: %s",c_Array[c_index].cuit);
					printf("\nDireccion Cliente: %s", c_Array[c_index].adress);
					printf("\nKGs tipo LDPE: %d", o_Array[o_index].ldpe);
					printf("\nKGs tipo LDPE: %d", o_Array[o_index].hdpe);
					printf("\nKGs tipo LDPE: %d", o_Array[o_index].pp);
					printf("\n///////////////////////////////////////////\n");
				}
			}
		}
		if(flag != 0)
		{
			printf("NO HAY PEDIDOS COMPLETADOS.\n");
		}
	}
}
////////////////////////////////////////////////////////////////////////// (1)A
void clientWithMorePendings(Client c_Array[], Order o_Array[]){
    int j,i;
    int maxId;
	int oCounter = 0,max = 0;
    int flag = 0;
    int auxCompanyId;
	/////////////////////////////////////////////
    if(c_Array!=NULL && o_Array!=NULL)
    {
    	for(i=0;i<QTY_CLIENT;i++)
		{
			if(c_Array[i].isEmpty== 1)
			{
				auxCompanyId = c_Array[i].companyId;
				for(j=0;j<QTY_ORDER;j++)
				{
					if(auxCompanyId == o_Array[j].companyId && o_Array[j].isEmpty==1 && o_Array[j].status==0)
					{
						oCounter++;
					}
				}
				if(flag==0 || oCounter>max)
				{
					max = oCounter;
					maxId = i;
					flag=1;
				}
				oCounter=0;
			}
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("\EL CLIENTE CON MAS PEDIDOS PENDIENTES ES: %s",c_Array[maxId].company);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.");
		}
		printf("\n///////////////////////////////////////////\n");
	}
}
////////////////////////////////////////////////////////////////////////// (2)B
void clientWithMoreCompleted(Client c_Array[], Order o_Array[]){
    int j,i;
    int maxId;
	int oCounter = 0,max = 0;
    int flag = 0;
    int auxCompanyId;
	/////////////////////////////////////////////
    if(c_Array != NULL && o_Array != NULL)
    {
    	for(i=0;i<QTY_CLIENT;i++)
		{
			if(c_Array[i].isEmpty== 1)
			{
				auxCompanyId = c_Array[i].companyId;
				for(j=0;j<QTY_ORDER;j++)
				{
					if(auxCompanyId == o_Array[j].companyId && o_Array[j].isEmpty == 1 && o_Array[j].status == 1)
					{
						oCounter++;
					}
				}
				if(flag==0 || oCounter>max)
				{
					max = oCounter;
					maxId = i;
					flag=1;
				}
				oCounter=0;
			}
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("\EL CLIENTE CON MAS PEDIDOS PENDIENTES ES: %s",c_Array[maxId].company);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.");
		}
		printf("\n///////////////////////////////////////////\n");
	}
}
////////////////////////////////////////////////////////////////////////// (3)C
void clientWithMoreOrders(Client c_Array[], Order o_Array[]){
    int j,i;
    int maxId;
	int oCounter = 0, max = 0;
    int flag = 0;
    int auxCompanyId;
	/////////////////////////////////////////////
    if(c_Array!=NULL && o_Array!=NULL)
    {
    	for(i=0;i<QTY_CLIENT;i++)
		{
			if(c_Array[i].isEmpty != 1)
				continue;
			if(c_Array[i].isEmpty == 1)
			{
				auxCompanyId = c_Array[i].companyId;
				for(j=0;j<QTY_ORDER;j++)
				{
					if(auxCompanyId == o_Array[j].companyId && o_Array[j].isEmpty==1)
					{
						oCounter++;
					}
				}
				if(flag==0 || oCounter>max)
				{
					max = oCounter;
					maxId = i;
					flag=1;
				}
				oCounter=0;
			}
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("\EL CLIENTE CON MAS PEDIDOS PENDIENTES ES: %s",c_Array[maxId].company);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.");
		}
		printf("\n///////////////////////////////////////////\n");
	}
}
////////////////////////////////////////////////////////////////////////// (4)D
void clientRecycledMore(Client c_Array[], Order o_Array[]){
    int i,j;
	int auxCompanyId;
	int buffer=0;
	int auxBuffer=0;
	int flag = 0;
	int max = 0;
	int maxId;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		//sortClient(c_Array,QTY_CLIENT);
		for(i = 0; i < QTY_CLIENT; i++)
		{
			if(c_Array[i].isEmpty != 1)
				continue;
			if(c_Array[i].isEmpty == 1)
			{
				auxCompanyId = c_Array[i].companyId;
			}
			for (j = 0; j < QTY_ORDER; j++)
			{
				if (o_Array[j].isEmpty == 1 && o_Array[j].status == 1 && o_Array[j].companyId == auxCompanyId)
				{
					auxBuffer=o_Array[j].hdpe+o_Array[j].ldpe+o_Array[j].pp;
					buffer+= auxBuffer;
				}
			}
			if(flag==0 || buffer>max)
			{
				max = buffer;
				maxId = i;
				flag=1;
			}
			buffer=0;
			auxBuffer=0;
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("EL CLIETE QUE MAS RECICLO ES: %s", c_Array[maxId].company);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.\n");
		}
		printf("\n///////////////////////////////////////////\n");

	}
}
////////////////////////////////////////////////////////////////////////// (5)E
void clientRecycledLess(Client c_Array[], Order o_Array[]){
    int i,j;
	int auxCompanyId;
	int buffer=0;
	int auxBuffer=0;
	int flag = 0,flagB=0;
	int min = 0;
	int minId;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		sortClient(c_Array,QTY_CLIENT);
		for(i = 0; i < QTY_CLIENT; i++)
		{
			if(c_Array[i].isEmpty != 1)
				continue;
			if(c_Array[i].isEmpty == 1)
			{
				auxCompanyId = c_Array[i].companyId;
			}
			for (j = 0; j < QTY_ORDER; j++)
			{
				if (o_Array[j].isEmpty == 1 && o_Array[j].status == 0 && o_Array[j].companyId == auxCompanyId)
					continue;
				if (o_Array[j].isEmpty == 1 && o_Array[j].status == 1 && o_Array[j].companyId == auxCompanyId)
				{
					auxBuffer=o_Array[j].hdpe+o_Array[j].ldpe+o_Array[j].pp;
					buffer+= auxBuffer;
					flagB=1;
				}
			}
			if(flagB==1)
			{
				if(flag==0 || buffer<min)
				{
					min = buffer;
					minId = i;
					flag=1;
				}
			}
			buffer=0;
			auxBuffer=0;
			flagB=0;
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("EL CLIETE QUE MAS RECICLO ES: %s", c_Array[minId].company);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.\n");
		}
		printf("\n///////////////////////////////////////////\n");

	}
}
////////////////////////////////////////////////////////////////////////// (6)F
void clientOverThousand(Client c_Array[], Order o_Array[]){
	int i,j;
	int auxCompanyId;
	int kBuffer=0;
	int pCounter=0;
	int flag = 0;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		//sortClient(c_Array,QTY_CLIENT);
		for(i = 0; i < QTY_CLIENT; i++)
		{
			if(c_Array[i].isEmpty != 1)
				continue;
			if(c_Array[i].isEmpty == 1)
			{
				auxCompanyId = c_Array[i].companyId;
			}
			for (j = 0; j < QTY_ORDER; j++)
			{
				if (o_Array[j].isEmpty == 1 && o_Array[j].status == 1 && o_Array[j].companyId == auxCompanyId)
				{
					kBuffer+= o_Array[j].kg;
				}
			}
			if(kBuffer>1000)
			{
				pCounter++;
				flag = 1;
			}
			kBuffer=0;
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("CLIENTES QUE RECICLARON MAS DE 1000kgs: %d", pCounter);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.\n");
		}
		printf("\n///////////////////////////////////////////\n");
		pCounter=0;
	}
}
////////////////////////////////////////////////////////////////////////// (7)G
void clientUnderHundred(Client c_Array[], Order o_Array[]){
	int i,j;
	int auxCompanyId;
	int hBuffer=0;
	int pCounter=0;
	int flag = 0;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		//sortClient(c_Array,QTY_CLIENT);
		for(i = 0; i < QTY_CLIENT; i++)
		{
			if(c_Array[i].isEmpty != 1)
				continue;
			if(c_Array[i].isEmpty == 1)
			{
				auxCompanyId = c_Array[i].companyId;
			}
			for (j = 0; j < QTY_ORDER; j++)
			{
				if (o_Array[j].isEmpty == 1 && o_Array[j].status == 1 && o_Array[j].companyId == auxCompanyId)
				{
					hBuffer+= o_Array[j].kg;
				}
			}
			if(hBuffer<100 && hBuffer>0)
			{
				pCounter++;
				flag = 1;
			}
			hBuffer=0;
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("CLIENTES QUE RECICLARON MENOS DE 100kgs: %d", pCounter);
		}
		else
		{
			printf("NO HAY DATOS RELEVANTES.\n");
		}
		printf("\n///////////////////////////////////////////\n");
		pCounter=0;
	}
}
////////////////////////////////////////////////////////////////////////// (8)H
void completedOrders(Client c_Array[], Order o_Array[]){
	int i,j;
	int auxCompanyId;
	int c_index,o_index;
	float buffer;
	int total;
	int flag = -1;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		printf("\nLISTADO DE PEDIDOS COMPLETADOS: \n");
		for (i = 0; i < QTY_ORDER; i++)
		{
			if (o_Array[i].isEmpty == 1 && o_Array[i].status == 1)
			{
				auxCompanyId = o_Array[i].companyId;
				o_index=i;
				for(j = 0; j < QTY_CLIENT; j++)
				{
					if(c_Array[j].companyId == auxCompanyId)
					{
						c_index = j;
						flag = 0;
						break;
					}
				}
				if(flag == 0)
				{
					buffer = o_Array[o_index].ldpe+o_Array[o_index].hdpe+o_Array[o_index].pp;
					total = o_Array[o_index].kg;
					printf("\nNro.Pedido: %d", o_Array[o_index].orderId);
					printf("\nCliente: %s",c_Array[c_index].company);
					printf("\nCuit Cliente: %s",c_Array[c_index].cuit);
					printf("\nPorcentaje de plastico Reciclado: %%%.1f",(buffer*100)/total);
					printf("\n(Kgs Reciclado: %f) (Kgs Total: %d)", buffer,total);
					printf("\n///////////////////////////////////////////\n");
				}
			}
		}
		if(flag != 0)
		{
			printf("NO HAY PEDIDOS COMPLETADOS.\n");
		}
	}
}
////////////////////////////////////////////////////////////////////////// (9)I
void ordersByLocation(Client c_Array[], Order o_Array[]){
	int i,j;
    char aux[51];
    char auxLoc[51];
    int pCounter=0;
    int auxCompanyId=-1;
    int auxReturn=-1;
    int flag = 0;
    ///////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		printClient(c_Array, QTY_CLIENT);
		printf("\n///////////////////////////////////////////////////////////////////////////////////////////////////////\n");
		auxReturn = getInput(aux, "Ingrese la localidad: ","\nIngreso invalido!",0,50,2,3);
		if(auxReturn == 0)
		{
			strcpy(auxLoc,aux);
		}
		for(i=0;i<QTY_CLIENT;i++)
		{
			if(strcmp(c_Array[i].location,auxLoc)!=0)
				continue;
			if(strcmp(c_Array[i].location,auxLoc)==0)
			{
				auxCompanyId = c_Array[i].companyId;
				flag = 1;
				for(j=0;j<QTY_ORDER;j++)
				{
					if(o_Array[j].isEmpty==1 && o_Array[j].status==1)
						continue;
					if(o_Array[j].isEmpty==1 && o_Array[j].status==0 && o_Array[j].companyId==auxCompanyId)
					{
						pCounter++;
					}
				}
			}
		}
		printf("\n//////////////////////////////////////\n");
		if(flag==1)
		{
			printf("Localidad: %s\n",auxLoc);
			printf("Cant. de Pedidos Pendientes: %d",pCounter);
		}
		else
		{
			printf("Localidad No disponible.");
		}
			printf("\n//////////////////////////////////////\n");
		pCounter=0;
	}
}
////////////////////////////////////////////////////////////////////////// (10)J
void ppAverageByClient(Client c_Array[], Order o_Array[]){
	int i,j;
	float ppBuffer = 0;
	int ppCounter = 0;
	int auxCompanyId;
	int repeat=-1;
	int flag = 0;
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		//sortClient(c_Array, QTY_CLIENT);
		printf("\nPP PROCESADO PROMEDIO POR CLIENTE: \n");
		for (i = 0; i < QTY_ORDER; i++)
		{
			if (o_Array[i].isEmpty == 1 && o_Array[i].status == 1)
			{
				ppBuffer+=o_Array[i].pp;
				auxCompanyId = o_Array[i].companyId;
				if(auxCompanyId!=repeat)
				{
					for(j = 0; j < QTY_CLIENT; j++)
					{
						if(c_Array[j].companyId == auxCompanyId)
						{
								repeat = auxCompanyId;
								ppCounter++;
								flag=1;
								break;
						}
					}
				}
			}
		}
		printf("\n///////////////////////////////////////////\n");
		if(flag==1)
		{
			printf("Cant. PP promedio procesado: %.2f", ppBuffer/ppCounter);
		}
		if(flag == 0)
		{
			printf("NO HAY DATOS RELEVAN.\n");
		}
		printf("\n///////////////////////////////////////////\n");
		ppCounter = 0;
		ppBuffer = 0;
	}
}
////////////////////////////////////////////////////////////////////////// (11)K
void plasticTypeByClient(Client c_Array[], Order o_Array[]){
	int auxReturn=-1;
	int i,optionC;
	int c_index;
	int hdpeBuffer = 0;
	int ldpeBuffer = 0;
	int ppBuffer = 0;
	int auxCompanyId;
	int flag = -1;

	char aux[51];
	/////////////////////////////////////////////
	if(c_Array!=NULL && o_Array!=NULL)
	{
		printf("\nLISTADO DE PP PROCESADO PROMEDIO POR CLIENTE: \n");
		printClient(c_Array, QTY_CLIENT);
		printf("\n///////////////////////////////////////////////////////////////////////////////////////////////////////\n");
		c_index = findCuitClient(c_Array, QTY_CLIENT);
		if(c_index >= 0)
		/*
		{//SI QUIEREN PREGUNTAR TIPO DE PLASTICO IGUAL, AUNQUE NO HAYA PEDIDOS ESTO VA ACA
			printf("\n1)HDPE \n2)LDPE \n3)PP \n");
			auxReturn = getInput(aux, "Ingrese tipo de Plastico: ","\nIngreso invalido!",1,3,2,1);
			if(auxReturn == 0)
			{
				optionC = atoi(aux);
			}
		}
		if(auxReturn == 0)
		*/
		{
			auxCompanyId = c_Array[c_index].companyId;
			for(i = 0; i < QTY_ORDER; i++)
			{
				if(o_Array[i].companyId == auxCompanyId)
				{
					if (o_Array[i].isEmpty == 1 && o_Array[i].status == 1)
					{
						printf("\n1)HDPE \n2)LDPE \n3)PP \n");//Y ESTO SE VA
						auxReturn = getInput(aux, "Ingrese tipo de Plastico: ","\nIngreso invalido!",1,3,2,1);//Y ESTO SE VA
						if(auxReturn == 0)//Y ESTO SE VA
						{//Y ESTO SE VA
							optionC = atoi(aux);//Y ESTO SE VA
							hdpeBuffer+=o_Array[i].hdpe;
							ldpeBuffer+=o_Array[i].ldpe;
							ppBuffer+=o_Array[i].pp;
							flag=0;
						}//Y ESTO SE VA
					}
				}
			}
			printf("\n///////////////////////////////////////////\n");
			printf("Nro.Cliente: %d", c_Array[c_index].companyId);
			printf("\nCliente: %s", c_Array[c_index].company);
			if(flag==0)
			{
				if(optionC==1)
				{
					printf("\nCant. de HDPE Total Reciclado: %d", hdpeBuffer);
				}
				if(optionC==2)
				{
					printf("\nCant. de LDPE Total Reciclado: %d", ldpeBuffer);
				}
				if(optionC==3)
				{
					printf("\nCant. de PP Total Reciclado: %d", ppBuffer);
				}
			}
			else
			{
				printf("\nNO HAY DATOS RELEVANTES.");
			}
			printf("\n///////////////////////////////////////////\n");
			hdpeBuffer = 0;
			ldpeBuffer = 0;
			ppBuffer = 0;
		}
	}
}
