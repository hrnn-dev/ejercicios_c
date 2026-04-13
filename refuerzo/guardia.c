#include <stdio.h>

//1. Prototipo
int verificarAcceso (int edad);

int main(void) {
int edadUsuario = 0;

	printf("-----VIP  CLUB  HERNAN----\n");
	printf("Documento de identidad. Ingrese su edad en años: ");



//2. Escudo antibasura
	if(scanf("%d", &edadUsuario) != 1) {
	printf("[!] Entrada no reconocida. SIguiente en la fila.\n");
	return 1;
	}

//3. LLAMADA DE LA FUNCION (ANIDADA EN IF)
	if( verificarAcceso(edadUsuario)  ==  1) {
		printf("\n[SISTEMA] Acceso concedido. Bienvenido a la pista.\n");
	} else {
		printf("\n[SISTEMA]Acceso denegado. Vuelve a casa ,  niño\n");
	}

	return 0;
}

//4.LA DEFINICIÓN: La lógica del guardia.
int verificarAcceso(int edad) {
	if(edad >=18) {
	//En el instante que C lee un 'return' abandona la función
	//Ningún código debajo de esa  línea se ejecutará si se cumple el  if
	return 1;
 } else {
 	return 0;
 }

}
