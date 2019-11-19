#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct
{

	int idPedido;
	int tipoPlastico;
	int idCliente;
	float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int pedido; // 1 PENDIENTE && 0 COMPLETADO
	int isEmpty1; // *Activo == (1) || *Inactivo == (0)



}Recoleccion;


void initPedido(Recoleccion list[], int len,int value);
void initPedidosOneorCero(Recoleccion list[], int len,int value);
int buscarIdPedido(Recoleccion list[],int len,int code);

#endif /* PEDIDO_H_ */
