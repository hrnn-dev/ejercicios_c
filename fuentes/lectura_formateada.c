#include <stdio.h>
#include <stdlib.h>

/*LOS PROTOTIPOS*/
void cargar_configuracion(const char *nombre_archivo);

/*EL DIRECTOR (MAIN)*/
int main (void) {
	const char *ruta_archivo = "datos/configuracion.txt";

	printf("----Extrayendo variables de configuración---\n");
	cargar_configuracion(ruta_archivo);
	printf("---Proceso finalizado---\n");

	return EXIT_SUCCESS;
}

/*EL TALLER (DEFINICION DE FUNCIONES)*/
void cargar_configuracion(const char *nombre_archivo) {
	FILE *archivo = fopen(nombre_archivo, "r");

	//Validacion inicial
	if (archivo == NULL) {
		fprintf(stderr, "Error: No se pudo abrir '/%s'.\n", nombre_archivo);
		return ;
	}

	//Variables donde almacenaremos los datos extraídos
	int id_servidor = 0;
	int max_conexiones = 0;
	char linea[128];
	int lecturas_correctas = 0;

	/*Usaré sscanf para leer línea por línea de forma segura*/
	while (fgets(linea, sizeof(linea), archivo)) {
		//Usaré sscanf para devolver el número de variables asignadas con éxito.
		if (sscanf(linea, "Servidor_ID: %d", &id_servidor) ==1) {
				lecturas_correctas++;
		} else if (sscanf(linea,"Conexiones_Maximas: %d", &max_conexiones) == 1) {
				lecturas_correctas ++;
			}

			//Si ya tenemos ambos valores, pasamos el break
			if (lecturas_correctas ==2) {
				break;
			}
		}

	fclose (archivo);
	//Validamos que encontramos ambos parámetros.
	if (lecturas_correctas < 2) {
		fprintf(stderr, "Error: archivo de configuración incompleto o corrupto.\n");
		return;
	}

	//Demostramos que son variables numéricas reales haciendo una operación matemática.
	printf("Configuración cargada en memoria RAM:\n");
	printf("-ID del Servidor: %d\n", id_servidor);
	printf("- Conexiones Máximas permitidas: %d\n", max_conexiones);
	printf("-El doble de las conexiones sería: %d\n", max_conexiones *2);
}
