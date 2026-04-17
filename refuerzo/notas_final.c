#include <stdio.h>

//---PROTOTIPOS DE MÓDULO (NIVEL 7)---
void pedirNotas(float arregloNotas[]);
float calcularPromedio(float arregloNotas[]);
float obtenerMaxima(float arregloNotas[]);
float obtenerMinima(float arregloNotas[]);
void limpiarBuffer(void); /* Este escudo garantizará que el usuario teclee un número y no
                             una letra al pedirle la nota*/ 


//---El director de la fábrica (MAIN)---
int main(void) {
	float calificaciones[5];
	int opcion = 0;
	float promedio = 0.0;


	//1. Delegamos el ingreso de notas llamando a la función pedirNotas
	pedirNotas(calificaciones);

	//2. Delegamos los cálculos matemáticos llamando a las respectivas funciones.
	promedio = calcularPromedio(calificaciones);
	float max = obtenerMaxima(calificaciones);
	float min = obtenerMinima(calificaciones);


	//3. Panel de telemetría.
	do {
		printf("\n---PANEL DE OPCIONES ---\n");
		printf("1. Ver promedio final\n");
		printf("2. Ver calificación máxima\n");
		printf("3. Ver calificación mínima\n");
		printf("4. Salir.\n");
		printf("Seleccione una opción:  ");

		//Implementaremos el escudo antibasura (actualizado a versión modular).
		if (scanf("%d", &opcion) !=1) { 
				printf("[!]ERROR: Letras detectadas. Sistema descontaminando.\n");
				limpiarBuffer(); //Activamos la aspiradora
				opcion = 0; //Reiniciamos la variable 'opcion'
				continue; /*Salta directo al inicio del do-while para mostrar el menú 
				            otra vez, esto es clave "Salta el switch y repite*/
			}


			switch(opcion) {
				case 1:
				printf("\n[RESULTADO] El promedio de las notas es: %.2f\n", promedio);
				break;

				case 2:
				printf("\n[RESULTADO] La nota más alta es: %.2f\n", max);
				break;

				case 3:
				printf("\n[RESULTADO] La nota más baja es: %.2f\n", min);
				break;

				case 4: 
				printf("\nSaliendo del sistema de auditoria...\n");
				break;

				default:
				printf("\n[!]ERROR: Comando no reconocido. Intente de nuevo.\n");
				break;
			}
		} while (opcion !=4);

		return 0;
}

//=================================================================================
//----TALLERES (DEFINICIÓN DE MÓDULOS)----
//=================================================================================

//Taller 1: pedirNotas
void pedirNotas(float arregloNotas[]) {
	int i = 0;
	printf("\n====REGISTRO DE CALIFICACIONES====\n");
	for (i = 0; i < 5; i++) {
		do {
			printf("Ingrese la nota del examen %d: ", i+1);
			if (scanf("%f", &arregloNotas[i]) !=1){
				printf("[!]ERROR: Entrada inválida detectada. Use solo números.\n");
				limpiarBuffer(); //Activamos la aspiradora
				arregloNotas[i] = -1.0; /*Forzamos un número inválido para que el bucle 
				                          repita*/
			} 
			//Si es un número pero fuera de rango
			else if (arregloNotas[i] > 10 || arregloNotas[i] < 0) {
				printf("[!]ERROR: Rango inválido, intente de nuevo.\n");
			}

		} while (arregloNotas[i] > 10 || arregloNotas[i] < 0);
	}
	printf("[SISTEMA] Notas ingresadas y validadas con éxito.\n");
}

//Taller 2: calcularPromedio
float calcularPromedio(float arregloNotas[]) {
	int i = 0;
	float suma = 0.0;

	for (i = 0; i < 5; i++) {
		suma += arregloNotas[i];
	}
	return suma / 5;
}

//Taller 3: obtenerMaxima
float obtenerMaxima(float arregloNotas[]) {
	int i = 0;
	float max = arregloNotas[0]; //Asumimos que la primera nota es la máxima

	for (i = 1; i < 5; i++) {
		if (arregloNotas[i] > max) {
			max = arregloNotas[i]; //Actualizamos el récord.
		}
	}
	return max;
}

//Taller 4: obtenerMinima
float obtenerMinima(float arregloNotas[]) {
	int i = 0;
	float min = arregloNotas[0]; //Asumimos que la primera nota es la mínima.
	for ( i = 1; i <5; i++) {
		if (arregloNotas[i] < min) {
			min = arregloNotas[i]; //Actualizamos el récord.
		}
	}
	return min;
}

//Taller 5: limpiarBuffer (La aspiradora).
void limpiarBuffer(void) {
	int c; /*Aspira caracteres hasta encontrar el 'Enter'(\n) o el final del archivo*/
	while ((c = getchar()) != '\n' && c != EOF);
}
