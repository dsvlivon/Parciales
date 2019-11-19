/*
 * arrayFunctions.h
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
#include "validations.h"
#include "arrayFunctions.h"
#include "profile.h"

#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAIL -1


int initArrayInt(int *pArray , int limit, int value)
{
	int auxReturn = -1;
	int i;
	if(pArray != NULL && limit > 0)
	{
		for(i=0;i<limit;i++)
		{
			pArray[i]=value;
		}
		auxReturn = 0;
	}
	return auxReturn;
}
////////////////////////////////////////////
int printArrayInt(int *pArray , int limit)
{
	int auxReturn = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limit > 0)
	{
		for(i=0;i<limit;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		int auxReturn = 0;
	}
	return auxReturn;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getArrayInt(int *pArray,int limit,char *pMsg,char *pMsgFail,int min,int max,int try)
{
	int auxReturn = -1;
	int buffer;
	int i=0;
	char answer;
	printf("\nDEBUG\n");
	if(pArray != NULL && limit > 0)
	{
		do
		{

			if(	getInt(	&buffer, pMsg, pMsgFail, min, max, try) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limit)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			fflush(stdin); // __fpurge(stdin)
			scanf("%c",&answer);
		}while(answer != 'n');
		auxReturn = i;
	}
	return auxReturn ;
}
//////////////////////////////////////////////////////////
int minMaxArrayInt(int* pArray,int limit,int* minus,int* maximus)
{
    int min=*minus;
    int max=*maximus;
    int i;

    for (i=0; i<limit; i++)
    {
        if(i==0)
	{
            min=pArray[i];
            max=pArray[i];
        }
        else
        {
            if (pArray[i]<min)
	    {
                min=pArray[i];
            }
            if (pArray[i]>max)
	    {
                max=pArray[i];
            }
        }
    }
    *minus = min;
    *maximus = max;

   return 0;
}
//////////////////////////////////////////////////
int addArrayInt(int* pArray,int limit,int* result)
{
    int res=0;
    int i;

    for (i=0; i<limit; i++)
    {
        res=res+pArray[i] ;
    }

    *result = res;

   return 0;
}
////////////////////////////////////////////////////////
int averageArrayInt(int* pArray,int limit,int* resultAv)//promedio
{
    int res=0;
    int i;

    for (i=0; i<limit; i++)
    {
        res=res+pArray[i] ;
    }

    *resultadoAv = res/limit;

   return 0;
}
///////////////////////////////////////////
int orderArrayInt(int *pArray, int limit)
{
    int i, aux, flag=-1;
    int* arrayAux = pArray;


    while(flag==-1)
    {
        flag=0;
        for(i=0; i<(limit-1);i++)
        {
           if(arrayAux[i]>arrayAux[i+1])
	   {
		aux = arrayAux[i];
            	arrayAux[i]=arrayAux[i+1];
            	arrayAux[i+1]=aux;
            	flag=-1;
           }
        }

    }
    pArray = arrayAux;
    return 0;
}
