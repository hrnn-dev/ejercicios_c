#include <stdio.h>

//1. Prototipo: "Oye compilador, voy a usar una función que necesita un int
	void saludarUsuario(int id);


	int main(void) {
		int mi_id = 0;

		printf("------SISTEMA DE ACCESO DE HERNAN v1.0---\n");
		printf("Por favor, ingrese su número de identificación: ");


		//EL escudo antibasura.
		if (scanf("%d", &mi_id) != 1) {
			printf("[!] ERROR en la entrada de datos.\n");
			return 1;
		}

		//2. LLAMADA: Aquí enviamos el valor real a  la  función saludarUsuario(mi_id)
		saludarUsuario(mi_id);

		return 0;
	}

//3. DEFINICIÓN: Aquí recibimos el valor de la variable 'id'
void saludarUsuario(int id) {
	printf("\n[SISTEMA] Verificando credenciales...\n");
	printf("[SISTEMA] Bienvenido usuario número %d.\n", id);
	printf("Acceso  concedido.\n");
}
