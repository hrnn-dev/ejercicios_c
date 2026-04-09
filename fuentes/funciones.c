
#include <stdio.h>
#include <stdlib.h>
//1. Prototipo
int es_par(int numero);

//2. Punto de entrada
int main(void){
    //1. Declarar la variable local.
    int valor;


    //2.Pedir y capturar el dato
    printf("Ingresa un número entero:  ");
    scanf("%d", &valor);

    //3. Evaluar llamando la función
    if (es_par(valor) == 1) {
	printf("%d es par.\n", valor);
    } else {
	printf("%d es impar.\n", valor);
    }
    return 0;
}

//3.Definición: Donde vivirá la lógica.
int es_par(int numero) {
    if (numero %2 == 0) {
	return 1;
    } else {
        return 0;
    }
}
