#include <stdio.h>
#include <stdlib.h>

// 1. Prototipo (Le avisa al compilador que esta función existe más abajo)
int es_mayor_de_edad(int edad);

// 2. Función Principal
int main(void) {
    // Inicializamos a 0 para matar la "basura" de la RAM
    int age = 0;

    printf("--- KERNEL TERMUX ---\n");
    printf("Por favor, escribe tu edad en años:  ");

    // 3. El Escudo: validamos que el usuario ingrese un número real
    if (scanf("%d", &age) != 1) {
        printf("\n[ ERROR FATAL ] Inyección de texto detectada.\n");
        return 1; // Aborta la misión si meten letras
    }

    // 4. Tu lógica de llamada a la función (¡Intacta!)
    if (es_mayor_de_edad(age) == 1) {
        printf("\n[ ACCESO CONCEDIDO ] ¡Bienvenido!\n");
    } else {
        printf("\n[ ACCESO DENEGADO ] Menor de edad.\n");
    }

    return 0;
}

// 5. Definición lógica (El motor de tu función)
int es_mayor_de_edad(int edad) {
    if (edad >= 18) {
        return 1; // Verdadero
    } else {
        return 0; // Falso
    }
}
