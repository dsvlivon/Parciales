#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "validation.h"
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.4 del 06 enero de 2016
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#define MSG_FAIL_DIVIDE " (No se puede dividir por 0)."
#define MSG_FAIL_FACTORIAL "\n(El factorial tomara numeros enteros naturales)."

float getAdd(float a, float b)
{
    float add;
    add = a+b;
    return add;
}

float getSubstract(float a, float b)
{
    float substract;

    substract = a-b;
    return substract;
}

float getMultiply(float a, float b)
{
    float multiply;
    multiply = a*b;
    return multiply;
}

float getDivide(float a, float b)
{
    float divide;

    if(b==0)
    {
        printf(MSG_FAIL_DIVIDE);
        divide = 0;
    }
    else
    {
        divide = a/b;
    }
    return divide;
}

float getFactorial (float x)
{
    float factorial = 1;
    int j,k;

    k=x;
    if(x<0 ||k<x)
    {
        printf(MSG_FAIL_FACTORIAL);
        factorial=0;
    }
    else if(x==0 || x==1)
    {
        factorial=1;
    }
    else
    {
        for(j=1; j<=x; j++)
        {
        factorial *= j;
        }
    }
    return factorial;
}
