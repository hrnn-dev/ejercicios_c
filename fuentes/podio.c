#include <stdio.h>

int main(void) {
    //Regla N: Quiero 3 datos, pido 3 espacios.
    //Este ejecutable me permite guardar los puntajes de mis 3 mejore partidas en Tetris
    int puntajes[3];


    puntajes[0] = 500;
    puntajes[1] = 1200;
    puntajes[2] = 2500; //Regla N-1: El último índice es 2.

    printf("---RÉCORD DE PUNTOS---\n");
    printf("El primer lugar (índice 0) es: %d\n", puntajes[2]);
    printf("El segundo lugar (índice 1) es: %d\n", puntajes[1]);
    printf ("El último lugar (índice 2) es:  %d\n", puntajes[0]);
    //Dato de vital importancia: En Arch 64-bit, un int mide 4 bites. 4 * 3 = 12 bytes. 

 //sizeof nos dirá cuánto bytes ocupa el "edificio" completo.
    printf("Espacio total en la RAM: %zu bytes\n", sizeof(puntajes));
    return 0;
}
