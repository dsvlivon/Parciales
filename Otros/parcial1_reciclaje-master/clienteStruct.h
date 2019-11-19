//////////////////////////////////////////////////////////////
#define ENTIDAD         "cliente"         /** Reemplazamos 'entidad' por el nombre de nuestro ente (Recomiendo primer letra minus) */
#define QTY_ENTIDADES   100                /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
//////////////////////////////////////////////////////////////
#define TEXT_SIZE 51
//////////////////////////////////////////////////////////////

typedef struct
{
 int id;

 char nombreEmpresa[TEXT_SIZE];
 char direccionYLocalidad[TEXT_SIZE];
 //char localidad[TEXT_SIZE];
 //float float2;
 int cuit;
 //int int2;

 int isEmpty;

} eCliente;
