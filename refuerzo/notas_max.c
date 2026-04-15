#include <stdio.h>

//1. Definir el arreglo de 5 calificaciones.
int main (void) {
    float calificaciones[5];
    float suma =0.0;
    float promedio =0.0;
    int i = 0;
    int opcion = 0;

printf( "\n====Registro de calificaciones===\n");
//2. Bucle 1: Llenar el arreglo.
    for (i =0; i <5; i++) {
	printf("Ingrese la nota del examen: %d ", i + 1);
	scanf ("%f" , &calificaciones[i]);
      }


//3. Bucle 2: Procesar los datos.
    for (i  =0; i <5; i++) {
     //suma acumulativa   
    suma += calificaciones [i]; 
   }
    promedio = suma / 5;

//4. El radar escanea el arreglo (desde el 1 hasta el 4)
float max = calificaciones[0];
float min = calificaciones[0]; 

for ( i = 1; i <5; i++) {
    if (calificaciones[i] > max) {
	max = calificaciones [i]; //Actualizamos el récord de la más alta.
     }
     if (calificaciones[i] < min) {
        min = calificaciones [i]; //Actualizamos el récor de la más baja
     }
}
 
//Interfaz de usuario.
printf("\n----PANEL DE TELEMETRÍA---\n");
printf ("\n1. Ver Promedio final");
printf ("\n2. Ver calificación máxima");
printf ("\n3. Ver Calificación mínima");
printf ("\n4. Salir");
printf("\nSeleccione una opción:  ");
scanf("%d", &opcion);

	switch(opcion) {
	case 1:
	printf("\n[RESULTADO] El promedio final es: %.2f\n", promedio);
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
	printf("\n[!] ERROR: Opción no válida.\n");
	break;
}
    return 0;
}
