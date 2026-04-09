#include <stdio.h>
#include <stdlib.h>

//1. Prototipo
int es_mayor_de_edad(int edad);


//2. Definimos variables locales en main
int main(void) {
     int age;


//3. Pedimos edad al usuario.
     printf("Por favor, escribe tu edad en años:  ");
     scanf("%d", &age);
	if ( es_mayor_de_edad (age) == 1) {
	printf("Acceso concedido, ¡Bienvenido!\n");
   					} else {
        printf("Accedo denegado. Menor de edad.\n");
	}
	return 0;
}
//.4 Definicion lógica
int es_mayor_de_edad(int edad) {
	if (edad >=18) {
	    return 1; //Verdadero
	} else {
	   return 0; //Falso
	}
}


