
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	char nombre[51];
	int cuit;
	char direccion[51];
	char localidad[51];
	int id;
	int isEmpty; // *Activo == (1) || *Inactivo == (0)

}Cliente;

void initCliente(Cliente list[], int len,int value);

int buscarLugarLibre(Cliente list[],int len);

int buscarId(Cliente list[],int len,int code);




#endif /* CLIENTE_H_ */
