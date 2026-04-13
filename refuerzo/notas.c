#include <stdio.h>

int main(void) {

    //1. Definimos el arreglo de 5 calificaciones.
     float calificaciones [5];
     float suma = 0.0;
     float promedio = 0.0;
     int i = 0;

printf("\n=====REGISTRO DE CALIFICACIONES======\n");

     //2. Blucle1: Llenar el arreglo.
     for (i = 0; i <5 ; i++) {
	printf("Ingrese la nota del examen: %d ", i+1);
        scanf("%f", &calificaciones[i]);
	}

     //3. Bucle2: Procesar los datos.
	for (i =0; i < 5; i++) {
	//Suma acumulativa   
	 suma += calificaciones[i];
         }

       promedio = suma / 5;

	printf("\n[RESULTADO] El promedio final es: %.2f\n", promedio);
	return 0;
} 
