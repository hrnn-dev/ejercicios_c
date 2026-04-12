#include <stdio.h>

//1. El prototipo: "Promesa de que devolveré un float"
float calcularIVA(float precio);

int main(void) {
float montoOriginal  =  0.0;
float impuestoCalculado = 0.0;
float total = 0.0;

printf("=======CALCULADORA FISCAL DE HERNAN v1.0========\n");

printf("Ingrese el precio base del producto: ");

//2. El escudo antibasura
if (scanf("%f", &montoOriginal) != 1) {
	printf("[!] ERROR: Ingrese un monto numérico válido.\n");
	return 1;
}

//3. LA LLAMADA: Capturamos el vómito de la función en una variable.
	impuestoCalculado = calcularIVA(montoOriginal);

	total = montoOriginal  + impuestoCalculado;


//4.  SALIDA
	printf("\nDetalle de la  Operación:\n");
	printf(">Precio Base: %.2f\n", montoOriginal);
	printf(">IVA (13%%):   %.2f\n", impuestoCalculado);
	printf("> Total final %.2f\n", total);

	return 0;
}

//5. DEFINICIOÓN: La fábrica de cálculos.
float calcularIVA(float precio) {
	//Aquí opera y ocurre la magia del return
	 return precio * 0.13f;

}
