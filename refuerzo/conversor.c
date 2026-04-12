#include <stdio.h>

int main() {

//. Declaración de variables.
int opcion;
float valor;
float resultado;

do{
	printf("\n=====================================================\n");
	printf("\n   CONVERSOR  INTELIGENTE DE HERNAN                  \n");
	printf("\n=====================================================\n");

	printf("Podrás realizar conversiones entre temperatura y distancia\n");


	printf("Por favor elige entre las siguientes opciones:  \n");
	printf("1. Temperatura.\n");
	printf("2. Distancia.\n");
	printf("3. Salir.\n");

	//El if,  while y getchar son el  escudo antibasura
	if  (scanf("%d", &opcion) != 1) {
		printf("\n[!]ERROR, por favor escoge una opción válida\n");
		while (getchar() != '\n'){}
	   continue;
	}

		//INICIA EL SWITCH (EL SISTEMA DE CONVERSION)
		switch(opcion){

		case 1:
		printf("Ingrese el  valor de su temperatura en ºC.\n");
		if(scanf("%f", &valor) !=1) {
		   printf("[!]ERROR: Opción inválida, por favor ingrese un número.\n");
		   while(getchar() !='\n'){}
		   continue;
		 }  
		   resultado = (valor * 9.0f / 5.0f) + 32;
		   printf("El resultado es: %.2f ºF\n", resultado);
		  break;



		  case 2:
		  printf("Ingrese el valor de su distancia en Km.\n");
		  if(scanf("%f", &valor) != 1){
		  printf("[!]ERROR: Opción inválida, por favor ingrese un número.\n");
		  while (getchar() != '\n'){}
		  continue;
		 }

		  resultado = valor * 0.621371f;
		  printf("El resultado es: %.2f m\n", resultado);
		  break;

		  case 3:
		  printf("Cerrando conversor y saliendo. ¡Gracias!\n");
		  break;

		  default:
		  printf("\nOpción inválida. Por favor verifique nuevamente las opciones.\n");
		  break;
		}

	} while (opcion != 3); 

	return 0;
}   
 
