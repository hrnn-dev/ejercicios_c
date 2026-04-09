#include <stdio.h>
#include <stdlib.h>

//1. Prototipo
int es_congelacion(int grados);                                                                           //2. Inicio de la función principal.
int main(void) {
   //3. Declaración del arreglo:
        int temperaturas[5];

   //4. Asignación manual
        temperaturas[0] = 15;
        temperaturas[1] = -2;                                temperaturas[2] = 30;
        temperaturas[2] = 0;                                 temperaturas[4] = 5;
        temperaturas[3] = 39;
	temperaturas[4] =30;


printf("----REPORTE DE TEMPERATURA HOY----\n");


//5. El bucle for
    for (int i=0; i < 5; i++){
        printf("%d|temperaturas:%d ->",i,temperaturas[i]);


        if(es_congelacion(temperaturas[i]) == 1) {
        printf("¡Alerta de congelación!\n");
        } else {
        printf("Clima normal\n");
        }

    }

        return 0;
}

//.6 Definición del especialista
int es_congelacion(int grados){
        if (grados <= 0){
        return 1;
        } else {
        return 0;
        }
}

