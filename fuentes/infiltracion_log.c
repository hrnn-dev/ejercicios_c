#include <stdio.h>
#include <stdlib.h>

/*1. LOS PROTOTIPOS*/
void registrar_datos(const char *nombre_archivo);

/*2. EL DIRECTOR (MAIN)*/
int main(void) {
	const char *ruta_archivo = "./reporte_tactico.txt";


	printf("----Iniciando el proceso de escritura estructurado---\n");

	/*Invocamos la función delegado la creación y la estructura*/
	registrar_datos(ruta_archivo);

	printf("----Proceso finalizado en el main---\n");

	return EXIT_SUCCESS;
}

/*3. EL TALLER (LAS FUNCIONES)*/

/*registrar_datos: Abre un archivo en modo escritura ("w"), inyecta cadenas de texto y 
datos formateados, y cierra el flujo.
Parámetros: nombre_archivo (Ruta del archivo a crear o sobreescribir)*/

void registrar_datos(const char *nombre_archivo){
	//1. Apertura en modo escritura ("w).
	FILE *archivo = fopen(nombre_archivo, "w");

	//2. Escudo de validación inicial.
	if (archivo == NULL) {
		fprintf(stderr, "Error: No se pudo crear el archivo '%s'.\n", nombre_archivo);
		return;
	}

	//3. Escritura de datos estáticos con fputs.
	fputs("----REPORTE DE SISTEMAS---\n", archivo);
	fputs ("Estado de la red: Asegurada.\n", archivo);

	//4. Escritura de datos formateados con fprintf
	int escuadrones_desplegados = 4;
	int blindaje_activo = 100;

	fprintf(archivo, "Escuadrones en posición: %d\n", escuadrones_desplegados);
	fprintf(archivo, "Integridad del blindaje: %d%%\n", blindaje_activo);
	fprintf(archivo, "Directiva finalizada: Éxito.\n");

	//5. Cierre del archivo para liberar los recursos del S.O.
	fclose(archivo);

	printf("[+] Archivo '%s' generado y guardado correctamente en el disco.\n", nombre_archivo);
}
