#include <stdio.h>

/* Prototipo de la función: El contrato */
float calcular_impuesto(float monto, float tasa);

int main(void) {
    int opcion = 0;
    float salario = 0.0;
    float impuesto_final = 0.0;

    /* INICIO DEL BUCLE INMORTAL (Fase 4) */
    do {
        printf("\n--- SISTEMA TRIBUTARIO ARCH v3.0 ---");
        printf("\n1. Calcular ISR (Tramos de 10%% y 20%%)");
        printf("\n2. Calcular IVA (16%% fijo)");
        printf("\n3. Salir");
        printf("\nSeleccione una opcion: ");
        
        /* Escudo de scanf: Validamos que sea un número */
        if (scanf("%d", &opcion) != 1) {
            printf("\n[ERROR] Entrada invalida. Por favor, use numeros.\n");
            while (getchar() != '\n'); // Limpia el búfer para evitar bucle infinito
            continue; 
        }

        /* Solo entramos al switch si el usuario no eligió Salir (3) */
        if (opcion != 3) {
            switch (opcion) {
                case 1:
                    printf("\n[ISR] Ingrese su salario bruto mensual: ");
                    scanf("%f", &salario);
                    
                    if (salario > 1000) {
                        impuesto_final = calcular_impuesto(salario, 0.20);
                    } else {
                        impuesto_final = calcular_impuesto(salario, 0.10);
                    }
                    printf("\n   RESULTADO ISR: $%.2f", impuesto_final);
                    break;

                case 2:
                    printf("\n[IVA] Ingrese el monto de la factura: ");
                    scanf("%f", &salario);
                    impuesto_final = calcular_impuesto(salario, 0.16);
                    printf("\n   RESULTADO IVA: $%.2f", impuesto_final);
                    break;

                default:
                    printf("\n[!] Opcion no reconocida. Intente de nuevo.");
                    break;
            }
            printf("\n===================================\n");
        }

    } while (opcion != 3); /* LA TRAMPA MORTAL: Requiere punto y coma */

    printf("\nSaliendo del sistema... Operacion finalizada con exito.\n");

    return 0;
} /* CIERRE DEL MAIN: La caja grande se cierra aquí */

/* DEFINICIÓN DE LA FUNCIÓN: 
   Vive fuera del main, en el espacio global del archivo.
*/
float calcular_impuesto(float monto, float tasa) {
    return monto * tasa;
}
