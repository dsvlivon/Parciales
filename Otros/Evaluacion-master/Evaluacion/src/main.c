/*
 ============================================================================
 Name        : Evaluacion.c
 Author      : Barrios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"
#define QTY_CLIENTES 100
#define QTY_PEDIDOS 100
#define PENDIENTE 1
#define COMPLETADO 0


int main(void)
{
	// array de clientes
	Cliente arrayClientes[QTY_CLIENTES];

	// array pedidos
	Recoleccion arrayPedido[QTY_PEDIDOS];

	char nombreAux[51];
	char cuitAuxStr[51];
	int cuitAux;				//Auxiliares CLIENTE
	char direccionAux[51];
	char localidadAux[51];
	char idAuxStr[51];
	int idAux;

	char kilosAuxStr[51];
	float kilosAux; 	// Auxiliares RECOLECCION
	char tipoPlasticoAuxStr[51];
	int tipoPlasticoAux;
	char cantHDPEStr[51];
	float cantHDPEAux = 0;
	char cantLDPEStr[51];
	float cantLDPEAux = 0;
	char cantPPStr[51];
	float cantPPAux = 0;


	int espacioLibre;
	int encontrarEspacio;
	int opcion = 0;
	int i;

	// --- inicio el Array de empleados. Cargo todos los datos en 0. ---
	initCliente (arrayClientes,QTY_CLIENTES,0);
	initPedido (arrayPedido,QTY_PEDIDOS,0);
	initPedidosOneorCero(arrayPedido,QTY_PEDIDOS,-1);


	while(opcion != 9)
	{
		opcion = getInt("\n\n\n1 - ALTA CLIENTE \n2 - MODIFICAR DATOS CLIENTE\n3 - BAJAR CLIENTE\n4 - CREAR PEDIDO DE RECOLECCION\n5 - PROCESAR RESIDUOS\n6 - IMPRIMIR CLIENTES\n7 - IMPRIMIR PEDIDOS PENDIENTES\n8 - IMPRIMIR PEDIDOS PROCESADOS\n9 - SALIR\n\n\n");

		switch(opcion)
		{
		case 1: // --- ALTA ---

			                espacioLibre = buscarLugarLibre(arrayClientes,QTY_CLIENTES); // Busco si hay espacio libre.

			                if(espacioLibre == -1)
			                {
			                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
			                    break;
			                }

			                printf("\nALTA\n");

			                // --- Validaciones ---

			                if (!getStringNumeros("Ingrese el id: ",idAuxStr))
			                {
			                	printf ("El id debe ser numerico\n");
			                	break;
			                }
			                idAux = atoi(idAuxStr);

			                if(buscarId(arrayClientes,QTY_CLIENTES,idAux) != -1)
			                {
			                	printf("\n\nEL ID YA EXISTE!!!\n");
			                	break;
			                }


			                if (!getStringLetras("Ingrese el nombre: ",nombreAux))
			                {

			                printf ("El nombre debe estar compuesta solo por letras\n");
			                break;

			                }

			                if (!getStringNumeros("Ingrese el cuit: ",cuitAuxStr))
			                {
			                	printf ("El cuit debe ser numerico\n");
			                	break;
			                }
			                cuitAux = atoi(cuitAuxStr);

			                if (!getStringLetras("Ingrese la direccion: ",direccionAux))
			                {

			                	printf ("La direccion debe estar compuesta solo por letras\n");
			                	break;
			                }

			                if (!getStringLetras("Ingrese la localidad: ",localidadAux))
			                {

			                	printf ("La localidad debe estar compuesta solo por letras\n");
			                	break;
			                }



			                // --- Cargo los datos en los campos ---
			                arrayClientes[espacioLibre].id = idAux;
			                strcpy(arrayClientes[espacioLibre].nombre,nombreAux);
			                strcpy(arrayClientes[espacioLibre].direccion,direccionAux);
			                strcpy(arrayClientes[espacioLibre].localidad,localidadAux);
			                arrayClientes[espacioLibre].cuit = cuitAux;
			                arrayClientes[espacioLibre].isEmpty = 1;

			                break;

		case 2:

			if (!getStringNumeros("Ingrese el id a modificar: ",idAuxStr))
				            	{
				            		printf ("El id debe ser numerico\n");
				            		break;
				            	}
				            	idAux = atoi(idAuxStr);

				            	encontrarEspacio = buscarId(arrayClientes,QTY_CLIENTES,idAux);

				            	if(encontrarEspacio == -1)
				            	{
				            		printf("\n\nNO SE ENCUENTRA ESE ID\n");
				            		break;
				            	}

				            	if (!getStringLetras("Ingrese la nueva direccion: ",direccionAux))
				            	{
				            		printf ("La direccion debe estar compuesta solo por letras\n");
				            		break;
				            	}
				            	if (!getStringLetras("Ingrese la nueva localidad: ",localidadAux))
				            	{
				            		printf ("La localidad debe estar compuesta solo por letras\n");
				            		break;
				            	}

				            	// --- Le asigno la modificacion nueva. ---
				            	strcpy(arrayClientes[encontrarEspacio].direccion,direccionAux);
				            	strcpy(arrayClientes[encontrarEspacio].localidad,localidadAux);
				            	arrayClientes[encontrarEspacio].isEmpty = 1;
				            	break;


			case 3: // --- BAJA ---
				if (!getStringNumeros("Ingrese el id  a dar de baja: ",idAuxStr))
				{
					printf ("El id debe ser numerico\n");
					break;
				}
				idAux = atoi(idAuxStr);

				encontrarEspacio = buscarId(arrayClientes,QTY_CLIENTES,idAux);

				if(encontrarEspacio == -1)
				{
					printf("\n\nNO FUE POSIBLE ENCONTRAR ESE ID\n");
					break;
				}
				arrayClientes[encontrarEspacio].isEmpty = 0; // = 0 osea inactivo.

				break;



			case 4: // --- CREAR PEDIDO DE RECOLECCION ---

			//clientes impresos/listamiento:


				if (idAux == NULL)
				{
					printf ("DA UN ALTA LOCO");

				}

				else {

					printf("\nIdCliente - CUIT - DIRECCION - LOCALIDAD - NOMBRE\n");
					for(i=0;i < QTY_CLIENTES; i++)
					{
						if(arrayClientes[i].isEmpty != 0)
						{
							printf("%d - %d - %s - %s - %s\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayClientes[i].localidad,arrayClientes[i].nombre);
						}

					}


					 if (!getStringNumeros("Ingrese el id para generar un pedido: ",idAuxStr))
                    {
	        		 printf ("El id debe ser numerico\n");
					break;
                    }
                    idAux = atoi(idAuxStr);

                    encontrarEspacio = buscarId(arrayClientes,QTY_CLIENTES,idAux);

                    if(encontrarEspacio == -1)
                    {
	        		 printf("\n\nNO FUE POSIBLE ENCONTRAR ESE ID\n");
	        		 break;
                    }


					if (!getStringNumerosFlotantes("Ingrese la cantidad de kilos: ",kilosAuxStr))
					{
						printf ("La cantidad de kilos debe ser numerico\n");
						break;
					}
					kilosAux = atof(kilosAuxStr);


				arrayPedido[encontrarEspacio].kilo = kilosAux;
				arrayPedido[espacioLibre].pedido = 1;
				arrayPedido[espacioLibre].isEmpty1 = 1;


				if(( arrayPedido[espacioLibre].pedido = 1) == 1)
				{
					printf("EL PEDIDO ESTA PENDIENTE");

				}

				else
				{
					printf("EL PEDIDO ESTA COMPLETADO");

				}


                    }
				break;

				case 5: // --- PROCESAR RESIDUOS ---

            if (idAux == NULL)
				{
					printf ("DA DE ALTA LOCO");

					break;
				}

            else
            {
                printf("\nIdCliente - CUIT - DIRECCION - LOCALIDAD - NOMBRE - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");
					for(i=0;i < QTY_CLIENTES; i++)
					{
						if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == PENDIENTE)
						{
							printf("%d - %d - %s - %s - %s - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayClientes[i].localidad,arrayClientes[i].nombre,arrayPedido[i].pedido);
						}

					}

                     if (!getStringNumeros("Ingrese el id de un pedido: ",idAuxStr))
                    {
	        		 printf ("El id debe ser numerico\n");
					break;
                    }
                    idAux = atoi(idAuxStr);

                    encontrarEspacio = buscarId(arrayClientes,QTY_CLIENTES,idAux);

                    if(encontrarEspacio == -1)
                    {
	        		 printf("\n\nNO FUE POSIBLE ENCONTRAR ESE ID\n");
	        		 break;
                    }


                    if (!getStringNumeros("Ingrese el tipo de plastico:\n1- HDPE \n2- LDPE\n3- PP",tipoPlasticoAuxStr))
                        {
                            printf ("La opcion debe ser numerica\n");
                            break;
                        }
                        tipoPlasticoAux = atof(tipoPlasticoAuxStr);

                        if (tipoPlasticoAux == 1)
                        {
                            if (!getStringNumerosFlotantes("Ingrese la cantidad de HDPE: ",cantHDPEStr))
                            {
                                printf ("La cantidad de kilos debe ser numerico\n");
                                break;
                            }
                            cantHDPEAux = atof(cantHDPEStr);

                        }

                        else if (tipoPlasticoAux == 2)
                        {
                            if (!getStringNumerosFlotantes("Ingrese la cantidad de LDPE: ",cantLDPEStr))
                            {
                                printf ("La cantidad de kilos debe ser numerico\n");
                                break;
                            }
                            cantLDPEAux = atof(cantLDPEStr);

                        }


                        else if (tipoPlasticoAux == 3)
                        {
                           if (!getStringNumerosFlotantes("Ingrese la cantidad de PP: ",cantPPStr))
                            {
                                printf ("La cantidad de kilos debe ser numerico\n");
                                break;
                            }
                            cantPPAux = atof(cantPPStr);

                        }

                        else
                        {
                            printf("Ingrese un numero del 1 al 3.");
                            break;

                        }

                        arrayPedido[espacioLibre].HDPE = cantHDPEAux;
                        arrayPedido[espacioLibre].LDPE = cantLDPEAux;
                        arrayPedido[espacioLibre].PP = cantPPAux;
                        arrayPedido[espacioLibre].pedido = COMPLETADO;
                        arrayPedido[espacioLibre].isEmpty1 = 1;
                        if(( arrayPedido[espacioLibre].pedido == COMPLETADO))
                        {
                            printf("EL PEDIDO ESTA COMPLETADO");

                        }

                        else
                        {
                            printf("EL PEDIDO ESTA PENDIENTE");

                        }
                        break;

                    }

                case 6:

                    printf("\nIdCliente - CUIT - DIRECCION - LOCALIDAD - NOMBRE - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");

                      for(i=0;i<QTY_CLIENTES;i++)
                      {
                          if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == PENDIENTE)
                          {

                              printf("%d - %d - %s - %s - %s - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayClientes[i].localidad,arrayClientes[i].nombre,arrayPedido[i].pedido);

                          }


                      }

                    break;



                case 7:  // --- Imprimir Pedidos Pendientes ---

                      printf("\nIdCliente - CUIT - DIRECCION - CANTIDAD KG - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");

                      for(i=0;i<QTY_CLIENTES;i++)
                      {
                          if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == PENDIENTE)
                          {

                              printf("%d - %d - %s - %.2f - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayPedido[i].kilo,arrayPedido[i].pedido);

                          }


                      }
                      break;


                case 8:


                      printf("\nIdCliente - CUIT - DIRECCION - LOCALIDAD - NOMBRE - HDPE - LDPE - PP - PEDIDO(PENDIENTE = 1. COMPLETADO = 0)\n");

                      for(i=0;i<QTY_CLIENTES;i++)
                      {
                          if(arrayClientes[i].isEmpty == 1 && arrayPedido[i].pedido == COMPLETADO)
                          {

                              printf("%d - %d - %s - %s - %s - %.2f - %.2f - %.2f - %d\n",arrayClientes[i].id,arrayClientes[i].cuit,arrayClientes[i].direccion,arrayClientes[i].localidad,arrayClientes[i].nombre,arrayPedido[i].HDPE,arrayPedido[i].LDPE,arrayPedido[i].PP,arrayPedido[i].pedido);

                          }


                      }
                      break;




		} //switch


                    }//while



return 0;

            } // maim
