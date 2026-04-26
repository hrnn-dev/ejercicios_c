#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Paquete {
	char estado[20];
};


int main (void) {
	/*Creamos una instancia de nuestro paquete*/
	struct Paquete mi_paquete;

	printf("=== MÓDULO DE REASIGNACIÓN ===\n");
	printf("Aplicando protocolo de copiado seguro\n");



	//-------------------------------------------------------------------
	// LA MANIOBRA DE LAS DOS LÍNEAS (Regla de copiado seguro de strncpy)
	//--------------------------------------------------------------------

	//Paso 1: Copiamos con límite estricto (19 para dejar espacio al carácter nulo, libre
	strncpy(mi_paquete.estado, "EN BODEGA", 19);

	//Paso 2: Forzamos el cerrojo de seguridad en la posición 19
	mi_paquete.estado[19] ='\0';

	//Comprobación de integridad.
	printf("\n[ÉXITO]: El estado del paquete es ahora: %s\n", mi_paquete.estado);

	return 0;

}
