#include <stdio.h>

//1.Prototipo
float calcular_impuesto(float monto);


int main(void) {
	//Definición de variables
	float salario = 0.0;
	float impuesto_final = 0.0;
	int opcion = 0;

	printf("---SISTEMA TRIBUTARIO ARCH v2.0---\n");
	printf("1. Calcular ISR (Tramos de 10%% y 20%%)\n");
	printf("2. Calcular IVA (16%% fijo)\n");
	printf("3. Salir\n");

	//El Escudo: Validamos que sea un número entero.
	if (scanf("%d", &opcion) != 1) {
	printf("[ERROR] Entrada inválida. Abortando...\n");
	return 1;
	}

	//---LOGICA DEL SELECTOR---
	switch(opcion) {
		case 1:
			printf("\n[ISR] Ingrese su salario bruto mensual: ");
			scanf("%f" , &salario);
			impuesto_final = calcular_impuesto(salario);
			break;


		case 2:
			printf("\[IVA] Ingrese el monto de la factura: ");
			scanf("%f" , &salario);
			impuesto_final = salario * 0.16;
			break;

		case 3:
			printf("Saliendo del sistema de impuestos.¡Adiós!\n");
			return 0;


			default:
			printf("[ERROR] La opción %d no es válida en este terminal.", opcion);
			return 1;
}
// ---FIN DEL SELECTOR---

//REPORTE DE RESULTADOS
printf("\n===================================");
printf("\n   RESULTADO: $%.2f", impuesto_final);
printf("\n====================================\n");

return 0;
}

//2.DEFINICION DEL MOTOR
float calcular_impuesto(float monto) {
	float tasa = 0.0;

	if (monto <1000.0) {
		tasa = 0.10;
	} else {
		tasa = 0.20;
	}
	return monto * tasa;
}
