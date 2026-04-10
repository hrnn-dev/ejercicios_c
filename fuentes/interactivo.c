#include <stdio.h>

int main(void) {
    //Reservammos 20 bytes; 19 para letras + 1 obligatorio para el '\0'
    char nombre[20];

   //Preguntamos al usuario por su nombre.
   printf("¿Cómo te llamas, habitante de Arch? ");


    //Nuestro escudo térmico: fgets
    //Parámetros: Dónde guardar, Cuánto es el límite máximo, De dónde leer
    fgets(nombre, sizeof(nombre), stdin);


    printf("\n---ACCESO CONCEDIDO---\n");
    printf("Bienvenido, %s", nombre);
    printf("Tu nombre ocupa %zu bytes en este bloque.\n", sizeof(nombre));

    return 0;
}
