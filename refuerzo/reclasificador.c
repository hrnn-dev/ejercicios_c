#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*1. La estructura*/
struct Etiqueta {
	char id[30];
	char categoria[20];
};

/*2.PROTOTIPOS*/
void clasificar(struct Etiqueta *e);
void limpiarBuffer(void);
void solicitar_id(char *destino, int size);


/*3. El director (MAIN)*/
int main (void) {
	struct Etiqueta mi_envio;

	printf("====MÓDULO DE CLASIFICACIÓN ===");

	/*Solicita los datos con escudo anti basura*/
	solicitar_id(mi_envio.id, 30);

	printf("\nAnalizando paquete con ID: [%s]\n", mi_envio.id);

	/*Llamada a la función*/
	clasificar(&mi_envio);


	/*Impresión de resultado final*/
	printf("\n---RESULTADO---\n");
	printf("ID procesado: [%s]\n", mi_envio.id);
	printf("Categoria asignada:       %s\n", mi_envio.categoria);
	printf("-------------------------------------\n");

	return 0;
}

/*EL TALLER*/


//Escudo antibasura
void limpiarBuffer(void) {
	int c;
	while ((c = getchar()) !=  '\n' && c != EOF);
}

//Escudo contra entradas demasiado largas o vacías"
void solicitar_id(char *destino, int size) {
	int valido = 0;
	do {
		printf("Introduzca el ID del paquete (ej. VIP-101): ");

		if (fgets(destino, size, stdin)) {
		//Buscamos el salto de línea y lo borramos
		destino[strcspn(destino, "\n")] = '\0';

		//Validamos que la entrada no esté vacía,
		if (strlen(destino) == 0) {
			printf("[!] ERROR: El ID no puede estar vacío, intente nuevamente.\n");
		} else {
			valido = 1;
		}


		//Si el usuario escribe más de la cuenta, limpiamos
		if  (strlen(destino) == (size_t)size -1  && destino[size-2] != '\0') {

		limpiarBuffer();

		printf("[!]ADVERTENCIA: La entrada era demasiado larga y fue ajustada.\n");
		//Solo limpiamos si el buffer queda lleno sin el \n
		//Pero al usar strcspn arriba, este es un check extra
		}
	 }

  }while (!valido);

 }


//Lógica y protocolos de copia
void clasificar (struct Etiqueta*e) {
	
	/*Comparación estricta: Solo entra si es idéntico a "VIP-1"*/
	if (strcmp(e->id, "VIP-1") == 0) {
	
		//Asegura el  límite de 19 y cierre manual
		strncpy(e->categoria, "PRIORIDAD_ALTA", 19);
		e->categoria[19] = '\0';
	} else {
		//Bloque else para cualquier otro caso
		strncpy(e->categoria, "ESTÁNDAR", 19);
		e->categoria[19] =  '\0';

	}

}
