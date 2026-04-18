#include <stdio.h>
#include <string.h>

/*---STRUCT (NIVEL 9): Estos son "los planos del expediente"*/
//Le enseñamos al compilador cómo es nuestro nuevo "Maletín"
struct Estudiante {
	char nombre[30];
	float notas[5];
	float promedio;
	float max; //Nuevo compartimento
	float min; //Nuevo compartimento
};

//1. LOS NUEVOS PROTOTIPOS
void limpiarBuffer(void);
void pedirNotas(struct Estudiante *exp); //El asterisco (*) son las coordenadas GPS
void calcularPromedio(struct Estudiante *exp);
void obtenerMaxima(struct Estudiante *exp);
void obtenerMinima (struct Estudiante *exp);

//2. EL DIRECTOR (main)
int main(void) {
	//Fabricamos UN maletín físico llamado "expediente1" basado en los planos
	struct Estudiante expediente1;


	printf("===SISTEMA DE AUDITORÍA NIVEL 9 (STRUCTS) ===\n");
	//Usamos el punto (.) para abrir el maletín y guardar el nombre en su compartimiento
	printf("Ingrese el nombre completo del estudiante: ");
	fgets(expediente1.nombre, 30, stdin);

	//Limpiamos el salto de línea dentro del maletín.
	expediente1.nombre[strcspn(expediente1.nombre, "\n")] = '\0';

	//Verificación táctica: Imprimimos para asegurar que entró a la caja.
	printf("[SISTEMA] Expediente creado exitosamente para %s\n", expediente1.nombre);

	//Enviamos las coordenadas GPS del maletín al Taller.
	pedirNotas(&expediente1);
	//Enviamos el GPS al Taller matemático.
	calcularPromedio(&expediente1);

	//Enviamos el maletín a todos los talleres para que lo llenen.
	calcularPromedio(&expediente1);
	obtenerMaxima(&expediente1);
	obtenerMinima(&expediente1);

	int opcion = 0;
	//Restauramos el panel interactivo
	do{
		printf("\n---EXPEDIENTE DE: %s ---\n", expediente1.nombre);
		printf("1. Ver promedio final\n");
		printf("2. Ver calificación máxima\n");
		printf("3. Ver calificación mínima\n");
		printf("4. Salir.\n");

		//El escudo antibasura de nuevo
		if (scanf("%d", &opcion) !=1) {
			printf("[!] ERROR: Letras detectadas. Limpiando.\n");
			limpiarBuffer();
			opcion = 0;
			continue;
		}

		switch(opcion) {
		case 1:
		//Leemos usando el punto (.) porque estamos en el main
		printf("\n[RESULTADO] Promedio: %.2f\n", expediente1.promedio);
		break;

		case 2:
		printf("\n[RESULTADO] Nota más alta: %.2f\n", expediente1.max);
		break;

		case 3:
		printf("\n[RESULTADO] Nota más baja: %.2f\n", expediente1.min);
		break;

		case 4:
		printf("\n[SISTEMA] Cerrando expediente...\n");
		break;

		default:
		printf("\n[ERROR]: Comando no reconocido.\n");
		break;

	}
} while (opcion != 4);

	return 0;
}

//3. EL TALLER: Definición de funciones.


//pedirNotas
void pedirNotas(struct Estudiante *exp) {
	int i = 0;
	printf("\n===== REGISTRO DE CALIFICACIONES ===\n");
	for (i = 0; i < 5; i++) {
		do{
			//Usamos la flecha para leer el nombre.
			printf("Ingrese la nota del examen %d de %s: ", i +1, exp ->nombre);

			//Usamos la flecha para guardar en el arreglo de notas
			if (scanf("%f", &exp->notas[i]) != 1) {
				printf("[!]ERROR: Letras detectadas. Limpiando.\n");
				limpiarBuffer();
				exp->notas[i] = -1.0;
			} else if (exp->notas[i] > 10 || exp->notas[i] < 0) {
				printf("[!]ERROR: Rango inválido.\n");
			}
		} while (exp->notas[i] > 10 || exp->notas[i] < 0);
	}
	printf("[SISTEMA] Notas ingresadas con éxito en el maletín.\n");

  }

//calcularPromedio
void calcularPromedio(struct Estudiante *exp) {
	int i = 0;
	float suma = 0.0;

	for (i = 0; i < 5; i++) {
		//Leemos cada nota a distancia usando la flecha
		suma += exp->notas[i];
	}

	//¡La Magia! Guardamos el resultado directamente en el compartimento del maletín
	exp->promedio = suma /5.0;
}

//obtenerMaxima
 void obtenerMaxima(struct Estudiante *exp) {
 	int i = 0;
 	exp->max = exp->notas[0]; //Asumimos que la primera es la mayor.
 	for (i = 1; i < 5; i++) {
 		if (exp->notas[i] > exp->max) {
 			exp->max = exp->notas[i]; //Actualizamos el récord
 		}
 	}
 }

//obtenerMinima
void obtenerMinima(struct Estudiante *exp) {
	int i = 0;
	exp->min = exp->notas[0]; //Asumimos que la primera es la menor
	for (i = 1; i < 5; i++) {
		if (exp->notas[i] < exp->min) {
		exp->min = exp->notas[i];//Actualizamos el récord.
		}
	}
}

  //limpiarBuffer
  void limpiarBuffer(void) {
  	int c;
  	while ((c = getchar()) != '\n' && c != EOF);
  }
