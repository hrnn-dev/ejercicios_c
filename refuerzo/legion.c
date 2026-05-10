#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>


#define CAP_INICIAL 2L
#define BUFFER_LECTURA 64
#define MAX_CAPACIDAD 1000000L //Escudo ajustable contra agotamiento de RAM

typedef enum { ERR =0, SOLDADO =1, CABO =2, SARGENTO =3}Rango;

/*1. LA ESTRUCTURA*/

typedef struct {
 int id;
 Rango rango;
 } Soldado;

 typedef struct {
 	Soldado *tropas;
 	long contador;
 	long capacidad;
 } Batallon;

 /*2.LOS PROTOTIPOS*/
 Batallon* solicitarMemoria(void);
 int registrarSoldado(Batallon *b);
 void desplegarBatallon(const Batallon *b);
 int expandirEjercito(Batallon *b);
 void limpiezaObligatoria(Batallon *b);
 long preguntarTamanoBatallon(const char *prompt);
 void limpiarBuffer(char *buffer);
 Rango validacionRango(char *entrada);
 const char* rangoATexto (Rango r);

 /*3.EL DIRECTOR(MAIN)*/
int main (void) {
	Batallon *mi_batallon = solicitarMemoria();

	//Verificación de integridad inicial
	if(mi_batallon == NULL) {
		fprintf(stderr, "[!] ERROR CRÍTICO: No se pudo inicializar el sistema.\n");
		return EXIT_FAILURE;
	}

	long opcion = 0;

	printf("====SISTEMA DE GESTION DE BATALLONES  'LEGION' v1.0===\n");

	while (opcion !=3) {
		printf("\n1.Registrar Soldado | 2. Ver Reporte | 3. Salir\n");
		opcion = preguntarTamanoBatallon (">> Seleccione comando: ");

		//Si preguntarTamanoBatallon detecta EOF devolveremos -1 para salir.
		if (opcion == -1 || opcion == 3) {
			if (opcion == -1) printf("\n[!] Entrada cerrada. Saliendo...\n");
			break;
		}

		if (opcion ==1) {
			if (registrarSoldado(mi_batallon) != 0) {
				printf("[!] Operación abortada por falta de recursos.\n");
			}
		}
		else if (opcion == 2) desplegarBatallon(mi_batallon);
	}

	limpiezaObligatoria(mi_batallon);
	return EXIT_SUCCESS;
}

/*4. EL TALLER*/

//solicitarMemoria
Batallon* solicitarMemoria(void) {
	Batallon *b = malloc(sizeof(Batallon));
	if (b == NULL){
		return NULL;
	}

	/*Acá uso CAP_INICIAL como variable macro. Si quiero cambiar el inicio a 10 , solo 
	edito el define inicial*/

	b->capacidad = CAP_INICIAL;
	b->contador = 0;
	b->tropas = calloc((size_t)b->capacidad, sizeof(Soldado));

	if (b->tropas == NULL) {
		free(b);
		return NULL;
	}
	return b;
}

//registrarSoldado
int registrarSoldado(Batallon *b) {
	if (b->contador >= b->capacidad) {
		if (expandirEjercito(b) != 0) return -1; //Retorno de error controlado.
	}

	char bufferTemporal[BUFFER_LECTURA];
	Rango rangoDetectado = ERR;

	while (rangoDetectado == ERR) {
		printf("Ingrese Rango (Soldado, Cabo, Sargento): ");
		if (fgets(bufferTemporal, sizeof(bufferTemporal), stdin)) {
			limpiarBuffer(bufferTemporal);
			rangoDetectado = validacionRango(bufferTemporal);

			if (rangoDetectado ==ERR) {
				printf("[!] RANGO NO AUTORIZADO. Intente nuevamente.\n");
			}
		} else {
			//Salida de emergencia si fgets devuelve NULL
			printf("\n[!] INTERRUPCIÓN DETECTADA EN REGISTRO.\n");
			return -1;
		}
	}

		Soldado *s = &b->tropas[b->contador];
		s->id = (int)(b->contador +101);
		s->rango = rangoDetectado;

		b->contador++;
		printf("[SISTEMA]> ID %d registrado como %s.\n", s->id, rangoATexto(s->rango));
		return 0;
}

//validacionRango
Rango validacionRango(char *entrada) {
	for (int i =0; entrada[i]; i++)
		entrada[i] = (char)toupper((unsigned char)entrada[i]);
	if (strcmp(entrada, "SOLDADO") == 0) return SOLDADO;
	if (strcmp(entrada, "CABO") ==0) return CABO;
	if (strcmp(entrada, "SARGENTO") == 0) return SARGENTO;

	return ERR;
}

//rangoATexto
const char* rangoATexto(Rango r) {
	switch (r) {
	case SOLDADO:
	return "SOLDADO";

	case CABO:
	return "CABO";

	case SARGENTO:
	return "SARGENTO";

	default:
	return "DESCONOCIDO";

	}
}

//expandirEjercito
int expandirEjercito(Batallon *b) {
	if(b->capacidad >= MAX_CAPACIDAD) return -1;


	long nuevaCap = b->capacidad * 2;
	if (nuevaCap > MAX_CAPACIDAD) nuevaCap = MAX_CAPACIDAD;

	Soldado *temp = realloc (b->tropas, (size_t)nuevaCap *sizeof(Soldado));
	if(temp == NULL) return -1;

	memset(temp + b->capacidad, 0, (size_t)(nuevaCap -b->capacidad) * sizeof(Soldado));

	b->tropas = temp;
	b->capacidad = nuevaCap;
	printf("[LOGISTICA]: Capacidad ampliada a %ld.\n", nuevaCap);
	return 0;
}

//desplegarBatallon
void desplegarBatallon(const Batallon *b) {
	if (b->contador == 0) {
		printf("\n[!] Batallón vacío");
		return;
	}
	printf("\n===REPORTE DE EFECTIVOS===\n");
	for (long i = 0; i < b->contador; i++) {
		printf("[%02ld] ID:%-5d | Rango: %s\n",
				i, b->tropas[i].id, rangoATexto(b->tropas[i].rango));
	}
}

//preguntarTamanoBatallon
long preguntarTamanoBatallon(const char *prompt){
	char entrada[BUFFER_LECTURA];
	char *ptrFinal;
	long valor;

	while(1) {
		printf("%s", prompt);
			if (!fgets(entrada, sizeof(entrada), stdin)) {
			//Le retornamos al main un código que entienda como "salir"
			return -1;
		}
		limpiarBuffer(entrada);

		errno = 0;
		valor = strtol(entrada, &ptrFinal, 10);
		if (ptrFinal != entrada && *ptrFinal == '\0' && errno == 0)
			return valor;
		printf("[!] ERROR: Comando numérico no válido.\n");
			}
}

//limpiarBuffer
void limpiarBuffer (char *buffer) {
	char *p = strchr(buffer, '\n');
	if(p) *p = '\0';
	else {
		int c;
		while ((c = getchar()) !='\n' && c != EOF);
	}
}

//limpiezaObligatoria
void limpiezaObligatoria (Batallon *b) {
	if (b != NULL) {
		if (b->tropas != NULL) free (b->tropas);
		free(b);
		printf("\n[SISTEMA]: Memoria higienizada y recursos liberados.\n");
	}
}
