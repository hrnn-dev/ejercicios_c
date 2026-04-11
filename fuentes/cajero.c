#include <stdio.h>

/**
 * PROYECTO: Cajero Automático 
 * OBJETIVO: Implementar lógica de transacciones con escudo anti-errores.
 */

int main(void) {
    // Definición de variables con precisión decimal
    float saldo = 1000.00;
    float monto = 0.0;
    int opcion = 0;

    do {
        // --- INTERFAZ DE USUARIO ---
        printf("\n===============================\n");
        printf("   BANCO CENTRAL DE HERNAN    \n");
        printf("===============================\n");
        printf("1. Consultar Saldo\n");
        printf("2. Retirar Efectivo\n");
        printf("3. Depositar Efectivo\n");
        printf("4. Salir\n");
        printf("-------------------------------\n");
        printf("Seleccione una opción: ");

        // --- INICIA EL ESCUDO ANTIBASURA ---
        if (scanf("%d", &opcion) != 1) {
            printf("\n[!] ERROR: Por favor ingrese un número múltiplo de 5.\n");
            while (getchar() != '\n'); // Limpia el buffer de letras o simbolos
            continue; // Reinicia el bucle aún sin ejecutar el switch
        }

        // ---  INICIO DEL SWITCH PARA TRANSACCIONES---
        switch (opcion) {
            case 1:
                printf("\nSu saldo disponible: $%.2f\n", saldo);
                break;

            case 2:
                printf("\n[RETIRO] Ingrese monto a retirar: $");
                if (scanf("%f", &monto) != 1) {
                    printf("[!] Error. Por favor ingrese un número múltiplo de 5.\n");
                    while (getchar() != '\n');
                    break;
                }

                // Lógica de seguridad para retiros
                if (monto <= 0) {
                    printf("[!] Ingrese un número múltiplo de 5.\n");
                } else if (monto > saldo) {
                    printf("Fondos insuficientes (Saldo: $%.2f).\n", saldo);
                } else {
                    saldo -= monto;
                    printf("Procesando retiro, retire su efectivo. Su nuevo saldo es $%.2f\n",                    saldo);
                }
                break;

            case 3:
                printf("\nIngrese monto a depositar: $");
                if (scanf("%f", &monto) != 1) {
                    printf("[!] Error: Ingrese un valor numerico.\n");
                    while (getchar() != '\n');
                    break;
                }

                // Lógica de seguridad para depósitos
                if (monto <= 0) {
                    printf("[!] Denegado: No se pueden depositar montos nulos o negativos.\n");
                } else {
                    saldo += monto;
                    printf("[OK] Deposito exitoso. Nuevo saldo: $%.2f\n", saldo);
                }
                break;

            case 4:
                printf("\nCerrando sesión y saliendo. Gracias por su preferencia.\n");
                break;

            default:
                printf("\n[!] Opción inválida, por favor verifique nuevamente las opciones.\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
