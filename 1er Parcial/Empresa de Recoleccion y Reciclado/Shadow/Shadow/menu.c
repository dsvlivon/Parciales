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
#include "menu.h"
#include "validations.h"
#include "Cliente.h"
#include "Pedidos.h"
#include "Informes.h"
////////////////////////
#define QTY_CLIENT 100
#define QTY_ORDER 1000
#define FAIL_INITCLT "\n\nNO HAY CLIENTES HABILITADOS. \n"
#define FAIL_INITORD "\n\nNO HAY PEDIDOS HABILITADOS. \n"
////////////
 int menuX()
 {
    Client clientArray[QTY_CLIENT]={
    {0,"Telefonica","30-11223344-5","Lima 1234","CABA",1},
    {1,"DATASOFT","30-44556677-6","Corrientes 2547","CABA",1},
    {2,"NESTLE","30-88995521-9","Cucha Cucha","LANUS",1},
    {3,"TERRABUSI","30-56781423-5","Rocha 784","QUILMES",1},
    {4,"DIA","31-54581253-3","Mitre 750","AVELLANEDA",1},
    {5,"QUILMES","30-51485759-6","Rocha 741","QUILMES",1}
    };
    Order orderArray[QTY_ORDER]={
    {0,0,1000,1,200,145,230,1},
    {1,0,800,1,210,45,30,1},//CLIENTE 0 PROC 2
    {2,1,100,0,0,0,0,1},
    {3,1,300,0,0,0,0,1},//CLIENE 1 PEND 2
    {4,2,1500,1,500,150,270,1},//CLIENTE 2 PROC 1
    {5,3,750,1,100,50,70,1},//CLIENTE 3 PROC 1
    {6,0,200,0,0,0,0,1},// CLIENTE 4 PEND 1
    {7,4,30,1,10,5,3,1},// CLIENTE 4 PROC 1
    {8,5,456,0,0,0,0,1},// CLIENTE 5 PEND 1
    };
    ////////////////////////////////////////////
    int auxReturn=-1;
    int optionA = 0;
    int optionB = 0;
    int value = 0;
    char aux[50];
    //int pCcode;

    //initOrder(orderArray,QTY_ORDER);//Seteo de array inicial
    //initClient(clientArray,QTY_CLIENT);//Seteo de array inicial
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n0) MENU INFORMES.\n1) Alta de Cliente.\n2) Modificar datos de cliente.\n3) Baja de Cliente. \n4) Crear pedido de recoleccion. \n5) Procesar residuos. \n6) Imprimir clientes. \n7) Imprimir pedidos pendientes. \n8) Imprimir pedidos procesados. \n9) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",0,9,2,1);
        if(auxReturn == 0)
        {
            optionA = atoi(aux);
        }
        fflush(stdin); //__fpurge(stdin) para Linux
        switch(optionA)
        {
            case 0:
                do{
                    system ("cls");
                    printf("\nMENU INFORMES: \n");
                    /////////////////////////////////////
                    sortClient(clientArray,QTY_CLIENT);
                    sortOrder(orderArray, QTY_ORDER);
                    printf("\n1)Cliente con mas pedidos pendientes: \n2)Cliente con mas pedidos completados: \n3)Clientes con mas pedidos\n4)Cliente que reciclo mas kilos: \n5)Cliente que reciclo menos: \n6)Cantidad de clientes que reciclaron mas de 1000kgs: ");
                    printf("\n7)Cantidad de clientes que reciclaron menos de 100kgs: \n8)Imprimir los pedidos completados: \n9)Pedidos pendientes por localidad: \n10)Cantidad de kgs de PP reciclado promedio por cliente: \n11)Informar tipo de Plastico por cliente: ");
                    printf("\n0)VOLVER.\n");
                    auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",0,11,2,1);
                    if(auxReturn == 0){
                        optionB= atoi(aux);
                    }
                    fflush(stdin); //__fpurge(stdin) para Linux
                    switch(optionB)
                    {
                        case 1:clientWithMorePendings(clientArray, orderArray);
                            break;
                        case 2:clientWithMoreCompleted(clientArray, orderArray);
                            break;
                        case 3:clientWithMoreOrders(clientArray, orderArray);
                            break;
                        case 4:clientRecycledMore(clientArray, orderArray);
                            break;
                        case 5:clientRecycledLess(clientArray, orderArray);
                            break;
                        case 6: clientOverThousand(clientArray, orderArray);
                            break;
                        case 7:clientUnderHundred(clientArray, orderArray);
                            break;
                        case 8: completedOrders(clientArray, orderArray);
                            break;
                        case 9: ordersByLocation(clientArray, orderArray);
                            break;
                        case 10: ppAverageByClient(clientArray, orderArray);
                            break;
                        case 11: plasticTypeByClient(clientArray, orderArray);
                            break;
                        case 0:
                            printf("Volviendo...");
                            break;;
                    }
                    system("pause");
                }while (optionB!=0);
            break;
            //////////
            case 1:
                addClient(clientArray, QTY_CLIENT);
            break;
            //////////
            case 2:
                if(searchForOccurrenceClient(clientArray,QTY_CLIENT)>=0)
                {
                    modifClient(clientArray, QTY_CLIENT);
                }
                else
                {
                    printf(FAIL_INITCLT);
                }
            break;
            //////////
            case 3:
                if(searchForOccurrenceClient(clientArray,QTY_CLIENT)>=0)
                {
                    removeClient(clientArray, QTY_CLIENT);
                }
                else
                {
                    printf(FAIL_INITCLT);
                }
            break;
            //////////
            case 4:
                if(searchForOccurrenceClient(clientArray,QTY_CLIENT)>=0)
                {
                    printClient(clientArray, QTY_CLIENT);
                    value = findIdClient(clientArray, QTY_CLIENT);
                    if(value>=0)
                    {
                        addOrder(orderArray, QTY_ORDER, &value);
                    }
                }
                else
                {
                    printf(FAIL_INITCLT);
                }
            break;
            //////////
            case 5:
                if(searchForOccurrenceOrder(orderArray,QTY_ORDER)>=0)
                {
                    processOrder(orderArray, QTY_ORDER);
                }
                else
                {
                    printf(FAIL_INITORD);
                }
            break;
            /////////
            case 6:
                if(searchForOccurrenceOrder(orderArray,QTY_ORDER)>=0)
                {
                    printPendingClient(clientArray, orderArray);
                }
                else
                {
                    printf(FAIL_INITORD);
                }
            break;
            ///////////
            case 7:
                if(searchForOccurrenceOrder(orderArray,QTY_ORDER)>=0)
                {
                    printPendingOrders(orderArray, clientArray);
                }
                else
                {
                    printf(FAIL_INITORD);
                }
            break;
            ///////////
            case 8:
                if(searchForOccurrenceOrder(orderArray,QTY_ORDER)>=0)
                {
                    printProcessedOrders(orderArray, clientArray);
                }
                else
                {
                    printf(FAIL_INITORD);
                }
            break;
            ///////////
            case 9:
                printf("Saliendo... ");
            break;
            default:
                printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (optionA !=9);
    return auxReturn;
}


