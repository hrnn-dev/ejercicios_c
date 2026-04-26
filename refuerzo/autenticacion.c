#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*LA ESTRUCTURA DE DATOS*/
struct Envio {
	char id_digit[30];
};


/*2..PROTOTIPOS*/
void registrarId(struct Envio *i);

/*Pasamos la cadena como un puntero char*/
void verificarAutenticacion(struct Envio *i);

/*Limpiador de Buffer
void limpiarBuffer(void); */



/*3.El director(MAIN)*/
int main(void) {
	struct Envio envio1;

	printf("===MÓDULO DE AUTENTIFICACIÓN DE CARGA===\n");

	/*Registro del ID*/
	registrarId(&envio1);

	/*verificamos la autentificación*/
	verificarAutenticacion(&envio1);

	return 0;
}


/*4. El taller*/

//Registrar ID
void registrarId(struct Envio *i) {
	int valido = 0;
	while (valido == 0) {
		printf("Por favor, ingrese el ID de rastreo: ");
		fgets (i->id_digit, 30, stdin);
		i->id_digit[strcspn(i->id_digit, "\n")] = '\0';
		/*Conteo de caracteres: garantiza que id_digit sea >0*/
		if (strlen(i->id_digit) > 0) {
			valido = 1;
		} else {
			printf("[!]ERROR: Por favor digite el número de rastreo.\n");
		}
	}
}
//Verificar autentificación
void verificarAutenticacion(struct Envio *i) {
	const char *id_secreto = "URGENTE-911";

	//strcmp compara el contenido de la memoria, no las direcciones.
	if (strcmp(i->id_digit, id_secreto) == 0) {
		printf("\n[ALERTA]: ID DE EMERGENCIA DETECTADO.\n");
		printf("Protocolo: Prioridad máxima forzada por código 911.\n");
	} else {
		printf("\n[SISTEMA]: ID verificado. Procesando bajo protocolo estándar.\n");
	}
}
