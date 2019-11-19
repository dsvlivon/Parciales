/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en una LinkedList de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "validations.h"
#define FAIL_DATA "\n\nNO HAY DATOS HABILITADOS. \n"


int menu()
{
    int auxReturn = 1;
    int option = 0;
    char aux[50];
    int flag=0;
    ///////////////////////////////

    ///////////////////////////////
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
               "\n2) Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
               "\n3) Alta de empleado."
               "\n4) Modificar datos de empleado."
               "\n5) Baja de empleado."
               "\n6) Listar empleados."
               "\n7) Ordenar empleados."
               "\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)."
               "\n9) Guardar los datos de los empleados en el archivo data.bin (modo binario)."
               "\n10) SALIR.");
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
                    printf("\n//////////////////////////////////////////////\n");
                    printf("\n///////YA SE CARGO UNA BASE DE DATOS//////////\n");
                }
                else
                {
                	if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
                	    {
                	        // Calcular sueldos
                	        printf("Calculando sueldos de empleados\n");
                	        al_map(listaEmpleados,em_calcularSueldo);

                	        // Generar archivo de salida
                	        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
                	        {
                	            printf("Archivo generado correctamente\n");
                	        }
                	        else
                	            printf("Error generando archivo\n");
                	    }
                	    else
                	        printf("Error leyendo empleados\n");


                	    return 0;
                	}
        		}
                flag = 1;
            break;
            case 2://printf("En proceso... ");
                if(flag==1)
                {
                    printf("\n//////////////////////////////////////////////\n");
                    printf("////////////////    ALERTA     ///////////////");
                    printf("\n//////////////////////////////////////////////\n");
                    printf("\n///////YA SE CARGO UNA BASE DE DATOS//////////\n");
                    if(getInput(aux, "\n\nDesea borrar la base de datos actual? Y/N: ","\nLa Baja no se realizo.",0,2,1,5)==0)
                    {
                        controller_deleteLinkedList(pArrayListEmployee);
                        if(getInput(aux, "\n\nDesea carga una nueva base de datos? Y/N: ","\nLa Carga no se realizo.",0,2,1,5)==0)
                        {
                            controller_loadFromBinary("data2.bin",pArrayListEmployee);
                        }
                    }
                }
                else
                    controller_loadFromBinary("data2.bin",pArrayListEmployee);
                flag = 1;
            break;
            case 3: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_addEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_editEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_removeEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 6: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_listEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 7: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_sortEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 8: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_saveAsText("data2.csv", pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 9: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_saveAsBinary("data2.bin", pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 10:
                printf("\n///////////////////////\n");
                printf("SALIENDO... ");
                printf("\n///////////////////////\n");
            break;
            default: printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=10);
    return auxReturn;
}
