#include <stdio.h>

//PROTOTIPO
void miFuncion(void);

int main() {
	//VARIABLE LOCAL A MAIN
	int x = 10;

	printf("[MAIN] La variable 'x' es local y vale: %d\n", x);

	miFuncion();

	/*NOTA TÉCNICA: No intentamos acceder a variables de otras funciones.
	 Eso mantiene el programa estable y predecible*/
	 return 0;
}

void miFuncion(void) {
	//Variable local a mi función
	int y = 20;

	printf("[FUNCION] La variable 'y' es local y vale: %d\n", y);

	//Cada función tiene su proprio "Stack Frame" (Espacio en memoria)
}
