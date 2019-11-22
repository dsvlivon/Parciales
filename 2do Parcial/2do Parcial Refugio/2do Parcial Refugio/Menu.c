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
#include "Cachorro.h"
#define FAIL_DATA "\n\nNO HAY DATOS HABILITADOS. \n"

int menu()
{
    int auxReturn= 1;
    int option= 0;
    int counter=0;
    char aux[50];
    int flag=0;
    ///////////////////////////////
    LinkedList* lista= ll_newLinkedList();
    LinkedList* diasList;
    LinkedList* machosList;
    LinkedList* callejerosList;
    ///////////////////////////////
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n1) Cargar Archivo.""\n2) Imprimir Lista.""\n3) Filtrar Menores de 45 dias.""\n4) Filtrar Machos.""\n5) Generar listado de Callejeros." "\n6) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,6,2,1);
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
                {
                    if(controller_loadFromText("cachorros.csv",lista)==0)
                    {
                        flag = 1;
                    }
                }
            break;
            case 2: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_listEmployee(lista);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 3://printf("En proceso... ");
            if(flag==1)
                {
                    counter = ll_count(lista, criterio_dias);
                    printf("BUSQUEDA POR FILTRO: menores a 45 dias.\n\nResultado: %d coincidencias.\n", counter);
                    if(counter>0)
                    {
                        diasList = ll_filter(lista, criterio_dias);
                        if(controller_saveAsText("filter1.csv", diasList)==0)
                            printf("Se genero el arhivo: filter1.csv");

                        else
                        printf("No se pudo generar el archivo");
                    }
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
                if(flag==1)
                {
                    counter = ll_count(lista, criterio_machos);
                    printf("BUSQUEDA POR FILTRO: machos.\n\nResultado: %d coincidencias.\n", counter);
                    if(counter>0)
                    {
                        machosList = ll_filter(lista, criterio_machos);
                        if(controller_saveAsText("filter2.csv", machosList)==0)
                            printf("Se genero el arhivo: filter1.csv");

                        else
                            printf("No se pudo generar el archivo");
                    }
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
            if(flag==1)
                {
                    counter = ll_count(lista, criterio_callejeros);
                    printf("BUSQUEDA POR FILTRO: Callejeros.\n\nResultado: %d coincidencias.\n", counter);
                    if(counter>0)
                    {
                        callejerosList = ll_filter(lista, criterio_callejeros);
                        controller_listEmployee(callejerosList);
                    }
                }
                else
                    printf(FAIL_DATA);
            break;
            case 6:
                printf("\n///////////////////////\n");
                printf("////// SALIENDO ///////");
                printf("\n///////////////////////\n");
            break;
            case 7:

            break;
            default: printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=6);
    return auxReturn;
}
