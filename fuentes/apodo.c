#include <stdio.h>

int main(void) {
    //REGLA N + 1: "TETRI" tiene 5 letras. Reservamos 6 espacios.
    char apodo[6];

    apodo[0] = 'T';
    apodo[1] = 'E';
    apodo[2] = 'T';
    apodo[3] = 'R';
    apodo[4] = 'I';
    apodo[5] ='\0';

    printf("---TU IDENTIDAD EN ARCH---\n");
    printf("Apodo: %s\n", apodo);

    //sizeof nos dirá cuánto bytes ocupa el "edificio" completo.
    printf("Espacio total en la RAM: %zu bytes\n", sizeof(apodo));

    return 0;
}
