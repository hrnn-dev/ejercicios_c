#include <stdio.h>

int main(void) {
    //MÉTODO A: Automático (El compilador añade el \0 por ti)
    //"Arch" tiene 4 letras, C reserva 5 espacios automáticamente.
    char sistema[] = "Arch";

    //MÉTODO MANUAL (Nosotros controlamos la memoria)
    //Queremos escribir "C" (1 letra), por la regla "N + 1" necesitamos 2 espacios (1+1).
    char lenguaje[2];
    lenguaje[0] = 'C';
    lenguaje[1] = '\0'; //Si borro esta línea veré "basura en la terminal"

    printf("---REPORTE DE ENTORNO---\n");
    printf("Sistema Operativo: %s\n", sistema);

    //¿Cuánto miden realmente en memoria?
    printf("\n----TAMAÑOS REALES(Bytes)----\n");
    printf("Tamaño de 'sistema': %ld\n", sizeof(sistema)); //Debería dar 5
    printf("Tamaño de 'lenguaje': %ld\n", sizeof(lenguaje)); //Debería dar 2

    return 0;
}
