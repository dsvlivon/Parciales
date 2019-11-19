#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "functions.h"
#include "validation.h"
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.4 del 06 enero de 2016
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#define MSG_GET_START "\nQue desea hacer?: "
#define MSG_GET_NUMBER "\nIngrese un operando: "
#define MSG_GET_CALC "\nCalculando todas las operaciones. "
#define MSG_FAIL_OPTION "Opcion invalida."
#define MSG_FAIL_CALC "Debe ingresar ambos operandos primero!."
#define MSG_FAIL_ENDTRY "\nSe quedo sin intentos.\n"
#define MSG_FAIL_NUMBER "Operando invalido. "
#define MSG_END_GOODBYE "<<Gracias por su tiempo. Saliendo.>>"
#define TRY_LIMIT 4

float menu()
{
    //declaracion de la funcion gerenciadora
    float opA=0, opB=0;
    float add=0, substract=0;
    float divide=0, multiply=0;
    float factorialA=0, factorialB=0;
    int option, fail=1, limit=TRY_LIMIT;
    int flagA=1, flagB=1;


    do
    {
        system ("cls");
        if(flagA==0)
        {
            printf("\n1) Ingrese el 1er operando: (%.2f)",opA);
        }
        else
        {
            printf("\n1) Ingrese el 1er operando: X");
        }
        if(flagB==0)
        {
             printf("\n2) Ingrese el 2do operando: (%.2f)",opB);
        }
        else
        {
            printf("\n1) Ingrese el 1er operando: Y");
        }
        printf("\n3) Calcular todas las operaciones: ");
        printf("\n4) Informe de los resultados: ");
        printf("\n5) Salir. \n");
        //print de menu principalsystem("cls");
        printf(MSG_GET_START);
        scanf("%d",&option);
        fflush(stdin); //__fpurge para Linux
        //pregunta master que asigna valor al menu
        switch(option)
        {
        case 1:
            flagA = getFloat(&opA, limit, MSG_GET_NUMBER, MSG_FAIL_NUMBER);
            if(fail==-2)
            {
                printf(MSG_FAIL_ENDTRY);
            }
            break;
        case 2:
            flagB = getFloat(&opB, limit,  MSG_GET_NUMBER, MSG_FAIL_NUMBER);
            if(fail==-2)
            {
                printf(MSG_FAIL_ENDTRY);
            }
            break;
        case 3:
            if(flagA==0 && flagB==0)
            {
                printf(MSG_GET_CALC);
                add = getAdd(opA,opB);
                substract = getSubstract(opA,opB);
                multiply = getMultiply(opA,opB);
                divide = getDivide(opA,opB);
                factorialA = getFactorial(opA);
                factorialB = getFactorial(opB);
            }
            else
            {
                printf(MSG_FAIL_CALC);
            }
            break;
        case 4:
            if(flagA==0 && flagB==0)
            {
                printf("\nEl resultado de A+B es: %.2f",add);
                printf("\nEl resultado de A-B es: %.2f",substract);
                printf("\nEl resultado de A/B es: %.2f",divide);
                printf("\nEl resultado de A*B es: %.2f",multiply);
                printf("\nEl factorial de A es: %.2f",factorialA);
                printf("\nEl factorial de B es: %.2f\n",factorialB);
            }
                else
            {
                printf(MSG_FAIL_CALC);
            }
            break;
        case 5:
            printf(MSG_END_GOODBYE);
            break;
        default:
            printf(MSG_FAIL_OPTION);
            fail=-1;
        }
        system("pause");
    }
    while (option != 5);

    return fail;
}//funcionamiento del menu
