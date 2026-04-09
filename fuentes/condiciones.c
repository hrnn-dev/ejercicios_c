#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. Declaración de la variable local
    int numero; 

    // 2. Imprimir el mensaje al usuario (stdout)
    printf("Por favor ingresa un número entero: "); 
    
    // 3. Capturar la entrada del usuario (stdin) y guardarla en la dirección de 'numero'
    scanf("%d", &numero);

    // 4. Lógica de control de flujo
    if (numero % 2 == 0) {
        printf("%d es par.\n", numero);
    } else {
        printf("%d es impar.\n", numero);
    }

    return 0;
}
