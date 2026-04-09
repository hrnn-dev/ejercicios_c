#include <stdio.h>

void funcion_secreta() {
    printf("\n[ALERTA] ¡Has accedido a la funcion secreta mediante un desbordamiento!\n");
}

int main() {
    char buffer[8]; // Reservamos solo 8 bytes
    printf("Introduce un texto (intenta romperlo): ");
    
    // %s en scanf es vulnerable porque no limita el tamaño de entrada
    scanf("%s", buffer); 
    
    printf("Contenido del buffer: %s\n", buffer);
    return 0;
}
