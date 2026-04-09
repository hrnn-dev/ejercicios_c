#include <stdio.h>
#include <stdlib.h>

//1. Prototipo
int es_par(int cantidad);
;

int main(void) {

    //2. Declaración del arreglo.
	int inventario[6];

	//.3 Asignación manual de valores
	inventario[0] = 7;
	inventario[1] = 12;
	inventario[2] = 19;
	inventario[3] = 22;
	inventario[4] = 5;
	inventario[5] = 8;

printf("----REPORTE DE INVENTARIOS PARES E IMPARES.\n");

//4. Llamamos la función en el bucle for
	for(int i =0; i < 6; i++) {
	printf("inventario %d | numero %d ->", i, inventario[i]);

	if (es_par(inventario[i]) == 1){
	printf("Stock equilibrado\n");
	} else {
	printf("!Stock impar, reabastecer\n");	
	}
     } 
    return 0;
}

//5.Definición del especialista
int es_par(int cantidad){
	if(cantidad % 2 == 0){
	return 1;
	} else {
	return 0;
	}
}

