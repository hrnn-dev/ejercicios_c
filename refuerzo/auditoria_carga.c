#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*1. LA ESTRUCTURA DE DATOS*/
struct Envio {
	char id_rastreo[30];
	float peso;
	int prioridad;
	float costo_base;
	int riesgo; /*0: Seguro, 1: Vigilancia especial*/
};

/*2. LOS PROTOTIPOS (Las Herramientas del taller)*/
void limpiarBuffer(void);
void registrarEnvio(struct Envio *e);
void calcularCosto(struct Envio *e);
void analizarRiesgo(struct Envio *e);
void mostrarReporte(struct Envio *e);


/*3. EL DIRECTOR (MAIN)*/
int main(void) {
	struct Envio envio1;



	printf("======SISTEMA DE AUDITORIA DE CARGA CRÍTICA======\n");

	/*Registro del envío*/
	registrarEnvio(&envio1);

	/*Cálculo del costo*/
	calcularCosto(&envio1);

	/*Análisis de riesgo*/
	analizarRiesgo(&envio1);

	/*Impresión del reporte*/
	mostrarReporte(&envio1);

	printf("[PROCESO FINALIZADO]\n");

	return 0;
}

/*4. EL TALLER (DEFINICIÓN DE LAS FUNCIONES)*/

//registrarEnvio
void registrarEnvio(struct Envio *e) {
	int valido = 0;
	while (valido == 0) {
		printf("Por favor digite el ID de Rastreo (Ej. MED-99): ");
		fgets(e->id_rastreo, 30, stdin);

		/*Eliminación del salto de línea*/
		e->id_rastreo[strcspn(e->id_rastreo, "\n")] = '\0';

		/*Conteo de caracteres: garantiza que id_rastreo sea > 0*/
		if (strlen(e->id_rastreo) > 0) {
			valido =1;
		} else {
			printf("[!!]ERROR: Por favor digite el número de rastreo.\n");
		}
	}

//Registro del peso
int pesoValido = 0;
while (pesoValido == 0) {
	printf("Por favor, ingrese el peso de la carga (Kg):   ");
	if (scanf("%f", &e->peso) != 1) {
		printf("[!!] ERROR: Entrada inválida. Ingrese el peso en números.\n");
		limpiarBuffer();
	} else if (e->peso <= 0) {
		printf("[!!]ERROR: El peso del envío debe ser mayor a 0.0 Kg.\n");
	} else {
		pesoValido = 1;
	}
  }

//Registro de prioridad.
int priorValid = 0;
while (priorValid == 0) {
	printf("Seleccione la prioridad de su envío : 1. Crítica 2. Alta 3. Normal ");
	if (scanf("%d", &e->prioridad) != 1) {
		printf("[!!]ERROR: Opción inválida, intente nuevamente.\n");
		limpiarBuffer();
	}else if (e->prioridad <1 || e->prioridad >3) {
		printf("[!!] ERROR: Opción inválida, intente nuevamente.\n");
	} else {
		priorValid = 1;
	}
 }

 limpiarBuffer(); /*Limpiamos para correcta ejecución de la siguiente función*/
 printf("\n[SISTEMA]: Datos registrados correctamente.\n");
}

//limpiarBuffer
void limpiarBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

//calcularCosto
void calcularCosto(struct Envio *e) {
	float tasa = 14.0;
	float recargo = 0.0f;

	//1. Costo base.
	e->costo_base = e-> peso * tasa;

	//Recargo por prioridad.
	if (e->prioridad ==1) { //Crítica
		 recargo = e->costo_base * 0.20f;

	} else if (e->prioridad ==2) { //Alta
	    recargo = e->costo_base *0.15f;

	} else { //Normal
		recargo = 0.0f;
	}

	e->costo_base += recargo;

	//Acá es donde quiero probar el operador ternario.
	const char* nombreP = (e->prioridad ==1) ? "CRÍTICA" : (e->prioridad ==2) ? "ALTA" : "NORMAL";
	printf("[SISTEMA]: Su prioridad es %s, se aplica un recargo de: $%.2f\n", nombreP, recargo);
	printf("[SISTEMA]: Costo final calculado: $%.2f\n", e->costo_base);

}

//analizarRiesgo
void analizarRiesgo(struct Envio *e) {
	/*Lógica: Riesgo es 1 si el costo >1000 , o si la prioridad es 1.
	De lo contrario, es 0.
	*/
	e->riesgo = (e->costo_base > 1000.0f || e->prioridad == 1) ? 1: 0;

	if (e->riesgo ==1) {
		printf("[SISTEMA]: ALTA SENSIBILIDAD DETECTADA. Protocolo de riesgo activado.\n");
	} else {
		printf("[SISTEMA]: Cargo bajo parámetros de seguridad estándar.\n");
	}
}

//mostrarReporte: La interfaz de salida profesional.
void mostrarReporte(struct Envio *e) {
	printf("\n===============================================\n");
	printf("     RECIBO DE AUDITORIA DE CARGA                \n");
	printf("==================================================\n");
	printf(" ID DE RASTREO: %s\n", e->id_rastreo);
	printf(" PESO TOTAL  : %.2f Kg\n  ", e->peso);

	/*Ternario anidado para imprimir el nombre de la prioridad*/
	printf("PRIORIDAD    : %s\n ",
		(e->prioridad == 1) ? "CRÍTICA" :
		(e->prioridad == 2) ? "ALTA" : "NORMAL");

	printf(" COSTO FINAL   :  $%.2f\n ", e->costo_base);
	printf("-----------------------------------------------------\n");

	/*El veredicto de seguridad */
	if (e->riesgo == 1) {
		printf("ESTADO: [!] RIESGO ELEVADO\n");
		printf("AVISO: REQUIERE ESCOLTA ARMADA INMEDIATA.\n");
	} else {
		printf("ESTADO: [OK] SEGURO\n");
		printf("AVISO: Proceder con despacho estándar.\n");
	}
	printf("===========================================\n\n");
}
