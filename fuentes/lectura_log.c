#include <stdio.h>
#include <stdlib.h>

/*LOS PROTOTIPOS*/
void leer_mostrar_archivo(const char *nombre_archivo);

/*EL DIRECTOR(MAIN)*/
int main(void) {
	//Apuntamos al archivo que acabas de crear en el directorio raiz
	const char *ruta_archivo ="datos/reporte_tactico.txt";

	printf("---Iniciando la lectura secuencial del disco---\n\n");

	leer_mostrar_archivo(ruta_archivo);

	printf("\n---Proceso finalizado---\n");

	return EXIT_SUCCESS;
}

/*EL TALLER(DEFINICION DE FUNCIONES)*/
void leer_mostrar_archivo(const char *nombre_archivo) {
	//Apertuta en modo lectura ('r')
	FILE *archivo = fopen(nombre_archivo, "r");

	//Validación de seguridad
	if (archivo == NULL) {
		fprintf(stderr, "Error: no se pudo abrir el archivo '%s'. Verifique la ruta.\n", nombre_archivo);
	return;
	}

	//Declaración del búfer temporal
	char buffer_linea[256];

	//Bucle de lectura.
	//fgets lee hasta encontrar un '\n', hasta llenar el búfer (255 chars + '\0')
	//o hasta llegar al final del archivo (EOF). Devuelve NULL al terminar.
	while (fgets(buffer_linea, sizeof(buffer_linea), archivo) != NULL) {
		printf("%s", buffer_linea);
	}

	//Cierre del archivo.
	fclose(archivo);

}
