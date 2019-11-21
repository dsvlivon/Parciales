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
#include "Registro.h"
#define FAIL_DATA "\n\nNO HAY DATOS HABILITADOS. \n"

int menu()
{
    int auxReturn= 1;
    int option= 0;
    int counter=0;
    char aux[50];
    int flag=0;
    ///////////////////////////////
    LinkedList* listaEmpleados= ll_newLinkedList();
    LinkedList* filterList;
    ///////////////////////////////
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n1) Cargar datos (modo texto)."
               "\n2) Calcular Sueldos."
               "\n3) Alta de empleado."
               "\n4) Modificar empleado."
               "\n5) Baja de empleado."
               "\n6) Listar empleados."
               "\n7) Ordenar empleados."
               "\n8) Filtrar Lista."
               "\n9) Guardar datos (modo texto)."
               "\n10) Guardar datos filtrados (modo texto)."
               "\n11) SALIR.");
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
                    if(controller_loadFromText("data.csv", listaEmpleados)==0)
                    {
                        flag = 1;
                    }
            break;
            case 2: //printf("En proceso... ");
                if(flag==1)
                {
                    if(ll_map(listaEmpleados, em_calcularSueldo)==0)
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
                    controller_addEmployee(listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 6: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_listEmployee(listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 7: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 8: //printf("En proceso... ");
                if(flag==1)
                {
                    counter = ll_count(listaEmpleados, criterio_salary);
                    printf("BUSQUEDA POR FILTRO:\n\nResultado: %d coincidencias.\n", counter);
                    if(counter>0)
                    {
                        filterList = ll_filter(listaEmpleados, criterio_salary);
                        if(getInput(aux, "\nDesea Lista la busqueda? Y/N: \n\n","\nIngreso invalido.",0,2,1,5)==0)
                        {
                            controller_listEmployee(filterList);
                        }
                    }
                    //controller_filter(listaEmpleados, filterList);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 9: //printf("En proceso... ");
            if(flag==1)
                {
                    controller_saveAsText("data2.csv", listaEmpleados);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 10: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_saveAsText("filter.csv", filterList);
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
    }while (option !=11);
    return auxReturn;
}
