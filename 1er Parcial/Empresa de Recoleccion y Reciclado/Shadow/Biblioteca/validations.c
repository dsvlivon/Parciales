/*
 * validations.c
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

#define TRY 2

int getInt(int *pResult ,char *pMsg,char *pMsgFail,int min,int max, int try){
	int auxReturn = -1;
	int buffer, j;
	char input[50];

	if(pResult!= NULL || (max>min) || try>0 )
	{
		printf("%s",pMsg);
		for(j=0;j<try;j++)
		{
			fgets(input, sizeof(input), stdin);
			auxReturn = isNumeric(input);
            if(auxReturn == 0)
            {
                buffer = atoi(input);

                if(buffer >= min && buffer <= max)
                {
                    *pResult = buffer;
                    break;
                }
            }
            else
            {
                printf("%s",pMsgFail);
                printf("\n%s",pMsg);
                auxReturn = -1;
            }
        }
        if(auxReturn!=0)
        {
            printf("Sin Reintentos.");
        }
    }
	return auxReturn;
}
/////////////////////////////////////////////////////////////////////////////////////
int getFloat(float *pResult, char *pMsg, char *pMsgFail, int min, int max, int try){
	int auxReturn = 99;
	float buffer;
	int j;
	char input[50];

	if(pResult!= NULL || (max>min) || try>0 )
	{
		printf("%s",pMsg);
		for(j=0;j<try;j++)
		{
			fgets(input, sizeof(input), stdin);
            auxReturn = isDecimal(input);
            printf(" input X%s: ",input);
            if(auxReturn == 0)
            {
                buffer = atof(input);

                if(buffer >= min && buffer <= max)
                {
                    *pResult = buffer;
                    printf(" buffer X%f: ",buffer);
                    break;
                }
            }
            else
            {
                printf("%s",pMsgFail);
                printf("\n%s",pMsg);
            }
        }
        if(auxReturn!=0)
        {
            printf("Sin Reintentos.");
        }
    }
	return auxReturn;
}
//////////////////////////////////////////////////////////////////////////////////
char getChar(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try){
    int auxReturn = -1;
	char buffer;
	int j;
	char input[50];

	if(pResult!= NULL || (max>min) || try>0 )
	{
        printf("%s", pMsg);
		for(j=0;j<try;j++)
		{
            fgets (input, sizeof(input), stdin);

			auxReturn = isLetter(input);
			if(auxReturn == 0)
			{
				buffer = atof(input);
				*pResult = buffer;
			}
			else if(auxReturn==-1)
			{
				printf("%s. %s",pMsg, pMsgFail);
			}
			if(j == try && auxReturn == -1)
        	{
         		printf(" Sin reintentos.");
        	}
		}
	}
	return auxReturn;
}
/////////////////////////
int isNumeric(char aux[]){
    int i, length, auxReturn=0;

    length = strlen(aux);
    for(i=0;i<length-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9') && aux[i] != '-') //filtro numerico
        {
			auxReturn = -1;
            break;
		}
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
    }
    return auxReturn;
}
/////////////////////////
int isDecimal(char aux[]){
    int i, length, auxReturn=0;

    length = strlen(aux);
    for(i=0;i<length-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9' )&& aux[i]!= ',' && aux[i]!= '.' && aux[i]!= '-')
		{
            auxReturn = -1;
            break;
        }
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
		if(aux[i]==',')
        {
            aux[i]='.';
        }
    }
    return auxReturn;
}
////////////////////////
int isLetter(char aux[]){
 	int i, length, auxReturn=0;

	length=strlen(aux);
	for(i=0;i<length-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
			if(aux[i] != ' ') //excepciones
			{
				auxReturn = -1;
       			break;
			//i++;
			}
   		}
	}
   return auxReturn;
}
//////////////////////////////
int isAlphaNumeric(char aux[]){
  	int i, length, auxReturn=0;

	length=strlen(aux);
	for(i=0;i<length-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
	{
	   	if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
			auxReturn = -1;
		}
		else if(aux[i] < '0' || aux[i] > '9') //filtro numerico
		{
			auxReturn = -1;
		}
		else if((aux[i] != ' ') && (aux[i] != ',') && (aux[i] != '.')) //excepciones
		{
			auxReturn = -1;
			//i++;
		}
		break;
	}
   return auxReturn;
}
///////////////////////////
int isTelephone(char aux[]){
   	int i, length, auxReturn=0;
 	int symbolCounter=0;

	length=strlen(aux);
	for(i=0;i<length-1;i++)
   	{
		if((aux[i] < '0' || aux[i] > '9') && (aux[i] != ' '|| aux[i] != '-' || aux[i] != '+'))
		{
			auxReturn=-1;
			break;//i++;
		}
		if(symbolCounter >2)
		{
			if(aux[i] == '-' && i!=0)
			{
				symbolCounter ++;
			}
			if(aux[0] == '+' )
			{
				symbolCounter ++;
			}
			auxReturn = -1;
		}
    }
    return auxReturn;
}