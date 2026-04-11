#include <stdio.h>

//1. El prototipo
    float calcular_impuesto(float monto);

int main(void) {
    
    //2. Definición de variables locales. 
    float salario = 0.0;
    float impuesto = 0.0;

    printf("---SISTEMA TRIBUTARIO ARCH---\n");
    printf("Ingrese su salario mensual bruto: ");

    //2. El Escudo: validación de entrada (asegura que el usuario ingrese una variable float)
    if(scanf("%f", &salario) !=1) {
	printf("[ERROR] Entrada inválida. Por favor use números.\n");
	return 1; //Salida con error
     }
	printf("[GRACIAS] Su salario bruto mensual es:$%.2f\n ", salario);
    

    //3. EL SALTO (Pass-by-value)
    //Copiamos el valor de 'salario' a la variable 'monto' de la función
      impuesto = calcular_impuesto(salario);

    //4. RESULTADOS
    printf("\n---REPORTE TRIBUTARIO---");
    printf("\nSalario Bruto: $%.2f", salario);
    printf("\nRetención (Impuesto): %.2f", impuesto);
    printf("\nSalario Neto: $%.2f\n", salario - impuesto);

    return 0;
}

   //4. DEFINICIÓN: El motor de cálculo
    float calcular_impuesto(float monto) {
    float tasa = 0.0;

    //Aplicamos lógica de tramos
    if (monto < 1000.0) {
	tasa = 0.10; //10%
     } else {
        tasa = 0.20; //20%
     }

   
     return monto * tasa;
}


































