#include <stdio.h>
#include <stdlib.h> //Incluyo funciones de gestión de memoria (malloc, calloc, realloc)
#include <string.h>
#include <stdbool.h> //Incluyo funciones de dato booleano (true/false) nativos

#define BUFFER_TAMANO_INICIAL 256 //tamaño inicial del bloque de lectura intermedio
#define INDICE_CAPACIDAD_INICIAL 4 //Capacidad inicial del índice de líneas

//Defino una estructura para unificar y proteger el estado del almacenamiento
typedef struct {
	char **lineas;//Puntero bidimensional que almacena el arreglo dinámico de cadenas
	int cantidad; //contador de líneas válidas almacenadas actualmente
	int capacidad;//Límite físico actual de punterios en el índice
} registroArchivo; //Nombra el tipo de estructura como registroArchivo


/*EL PROTOTIPO PRINCIPAL*/
void procesar_archivo_dinamico(const char *ruta);

/*Los planos del taller (sub-funciones)  ocultas de la lógica del main: Avisan al taller
que estas funciones existen abajo*/
bool registro_inicializar(registroArchivo *reg); //Declara el constructor del objeto registro
bool registro_insertar(registroArchivo *reg, const char *linea); /*Declara el método
para insertar cadenas en el objeto*/
void registro_mostrar(const registroArchivo *reg); /*Declara el método para imprimir
las cadenas guardadas*/
void registro_liberar(registroArchivo *reg); /*Declara el destructor que sanitiza la
memoria*/


/*EL DIRECTOR (MAIN)*/
int main (void) {
	const char *archivo_prueba = "datos/servidores.txt";

	printf("---Iniciando Operación: Niebla de Guerra---\n");

	//Llamo directamente a la función desde la"dermis"
	procesar_archivo_dinamico(archivo_prueba);

	printf("---Operación finalizada---\n");

	return EXIT_SUCCESS;
}

/*EL TALLER  (DEFINICION DE FUNCIONES)*/

//procesar_archivo_dinamico
void procesar_archivo_dinamico(const char *ruta) {
	//Implementación de escudo Anti-Null para evitar fallos de segmentación tempranos.
	if (ruta == NULL) {
		fprintf(stderr, "[-]ERROR: RUTA INVÁLIDA (NULL).\n");
		return; //Aborta la función por ausencia de ruta segura
	}

	FILE *archivo = fopen(ruta, "r");
	if (archivo == NULL) {
		fprintf(stderr, "[-] ERROR: No se pudo abrir '%s'.\n", ruta);
		return; //Aborta la función por ausencia de archivo de origen
	}

	registroArchivo registro;
	if (!registro_inicializar(&registro)) {
		fclose(archivo);
		return;
	}

	printf("[+] Estructura encapsulada preparada. Extrayendo...\n");


	char *linea_buffer = NULL; /*Puntero acumulador para reconstruir líneas de cualquier
	longitud*/
	size_t capacidad_linea = 0; /*Registra cuántos caracteres se van acumulando en la 
	línea actual*/
	char buffer_transito[BUFFER_TAMANO_INICIAL];/*Mide la longitud del fragmento leído 
	en esta iteración*/

	while (fgets(buffer_transito, sizeof(buffer_transito), archivo)) {
		size_t len_fragmento = strlen(buffer_transito);

		//Intenta redimensionar el acumulador.
		char *temp_linea = realloc(linea_buffer, capacidad_linea + len_fragmento +1);

		//Escudo: Verifica si la RAM se saturó durante la expansión
		if (temp_linea == NULL) {
			fprintf(stderr, "[-]ERROR: Memoria insuficiente.\n");
			free(linea_buffer); //Libera el acumulador parcial para evitar fuga
			linea_buffer = NULL; //Reinicia el puntero a un estado seguro
			capacidad_linea = 0;//Reinicia el tamaño acumulado a cero.
			continue; /*Salta el fragmento pero mantiene el programa en ejecución*/
		}
		linea_buffer = temp_linea; /*Actualiza el acumulador oficial con la nueva
		dirección segura*/

		if (capacidad_linea == 0) {/*Comprueba si es el primer fragmento de una línea*/
			strcpy(linea_buffer, buffer_transito); /*Copia el fargmento directamente al
			inicio del acumulador*/
		} else {
			strcat(linea_buffer, buffer_transito); /*Concatena el nuevo fragmento al
			final del acumulador*/
		}
		capacidad_linea += len_fragmento;

		if (linea_buffer[capacidad_linea - 1] != '\n' && !feof(archivo)) {
			continue; //Fuerza al ciclo a seguir leyendo el siguiente fragmento
		}

		linea_buffer[strcspn(linea_buffer, "\r\n")] =0; /*Localiza y elimina limpiamente
		los saltos de linea*/

		if (!registro_insertar(&registro, linea_buffer)) {/*Inserta la línea en el objeto
		y valida el éxito de la operación*/
			fprintf(stderr, "[-] Abortando por fallo en índice.\n");
			free(linea_buffer); //Libera la línea que no se pudo enlazar.
			linea_buffer = NULL; //Sanitiza el puntero.
			break;
		}

		free(linea_buffer); /*Libera la copia temporal local tras haber sido clonada por
		el objeto*/
		linea_buffer = NULL; //Limpia el puntero preparándolo para el siguiente fragmento
		capacidad_linea = 0; //Restablece el contador
	}

	free(linea_buffer); /*Escudo de salida: Limpia remanentes en caso de terminación abr
	rupta o EOF*/
	fclose(archivo);

	registro_mostrar(&registro); /*Envía el objeto a la función encargada de  imprimir*/
	registro_liberar(&registro); /*Envía el  objeto al destructor para liberar y saniti
	zar la RAM*/
}

	//---APÉNDICE DEL  TALLER: SUBFUNCIONES  INTERNAS---

	bool registro_inicializar(registroArchivo *reg){/*Define el constructor del objeto
	registro*/
	//Escudo:Evita operar sobre una dirección de estructura inválida.
		if (reg == NULL) return false;

		reg->capacidad = INDICE_CAPACIDAD_INICIAL;
		reg ->cantidad = 0; //Declara que el objeto nace completamente vacío de registros
		reg ->lineas =  malloc(reg->capacidad *sizeof(char *)); /*Reserva espacio de 
		memoria para el arreglo de punteros*/

		if (reg->lineas == NULL) return false; /*Escudo: Si malloc falla, retorna falso
		impidiendo el uso del  objeto*/
		return true; //Retorna verdadero confirmando creación exitosa de contenedor
	}

	bool registro_insertar(registroArchivo *reg, const char *linea) {
		//Escudo: Bloquea parámetros inválidos antes de acceder a ellos
		if (reg == NULL || linea == NULL) return  false;


		if (reg->cantidad >= reg->capacidad) {
			int nueva_capacidad = reg->capacidad *2;
			char **nuevo_indice = realloc(reg->lineas, nueva_capacidad * sizeof(char *));
			if (nuevo_indice ==  NULL) return false;
			reg->lineas = nuevo_indice;
			reg->capacidad = nueva_capacidad;
		}

		reg->lineas[reg->cantidad] = strdup(linea);
		//Escudo: valida si strdup se quedó sin memoria para el clon
		if (reg->lineas[reg->cantidad] == NULL) return false;

		reg->cantidad ++;
		return true;
	}

	void registro_mostrar(const registroArchivo *reg) {
		if (reg == NULL || reg->cantidad == 0) return; /*Escudo: No procesa si el registro
		no existe o está vacío*/

		printf("\n[+] Extracción completada. Lineas en objeto: %d\n", reg->cantidad);
		for (int i= 0; i < reg->cantidad; i++) {
			printf("     Fila[%d]: %s\n", i, reg->lineas[i]);
		}
	}


	void registro_liberar(registroArchivo *reg) {
		if (reg == NULL || reg->lineas ==  NULL) return;

		for (int i = 0; i < reg->cantidad; i++) {
			if (reg->lineas[i] != NULL) {
				free(reg->lineas[i]);
				reg->lineas[i] = NULL; //Elimina el puntero colgante colocando NULL
			}
		}
		free(reg->lineas);
		reg->lineas = NULL; /*Escudo: Invalida el punterio maestro para evitar lecturas
		fantasma*/
		reg->cantidad = 0;
		reg->capacidad =0;

		printf("\n[+] Objeto destruido. Memoria sanitizada.\n");
	}




