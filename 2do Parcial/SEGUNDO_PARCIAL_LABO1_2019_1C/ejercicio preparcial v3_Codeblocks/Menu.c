/*******************************************************************
*Programa:ejercicio pre-parcial
*Objetivo: Adaptar la linkedList desarrollada a un esqueleto ABM
*Version: 1.0 del 19/11/19
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "validations.h"
#include "Venta.h"
#define FAIL_DATA "\n\nNO HAY DATOS HABILITADOS. \n"

int menu()
{
    int auxReturn= 1;
    int option= 0;
    char aux[50];
    int flag=0;
    ///////////////////////////////
    LinkedList* list= ll_newLinkedList();
    //LinkedList* filterList;
    ///////////////////////////////
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n1) Cargar datos (modo texto)."
               "\n2) Listar Ventas."
               "\n3) Ordenar Ventas."
               "\n4) Generar informe."
               "\n5) Guardar datos (modo texto)."
               "\n0) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,10,2,1);
        if(auxReturn == 0)
        {
            option = atoi(aux);
        }
        fflush(stdin); //para windows
        //__fpurge(stdin); //para Linux
        switch(option)
        {
            case 1://printf("En proceso... ");
                if(flag==1)
                {
                    printf("\n//////////////////////////////////////////////\n");
                    printf("////////////////    ALERTA     ///////////////");
                    printf("\n///////YA SE CARGO UNA BASE DE DATOS//////////");
                    printf("\n//////////////////////////////////////////////\n");
                }
                else
                    if(controller_loadFromText("data.csv", list)==0)
                    {
                        flag = 1;
                    }
            break;
            case 2: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_listElement(list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 3: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_sortElement(list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_generarInforme("informes.txt", list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_saveAsText("data2.txt", list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 11:
                printf("\n///////////////////////\n");
                printf("////// SALIENDO ///////");
                printf("\n///////////////////////\n");
            break;
            default: printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=0);
    return auxReturn;
}


/*case 2: //printf("En proceso... ");
                if(flag==1)
                {
                    if(ll_map(list, element_calcularSueldo)==0)
                    {
                        printf("\nNOMINA ACTUALIZADA: \nListe para ver los cambios.\n\n");
                    }
                }
                else
                    printf(FAIL_DATA);
            break;
            case 3://printf("En proceso... ");
                if(flag==1)
                {
                    controller_addElement(list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_editElement(list);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_removeElement(list);
                }
                else
                    printf(FAIL_DATA);
            break;*/
