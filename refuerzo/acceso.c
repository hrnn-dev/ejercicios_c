#include <stdio.h>

int main(void){
int edad = 0;
int clave = 0;


printf("\n========================================\n");
printf("        SISTEMA DE AUTENTICACIÓN ARCH     \n");
printf("\n========================================\n");

printf("Por favor introduce tu edad: ");
scanf("%d", &edad);
printf("Por favor introduce tu clave: ");
scanf("%d", &clave);

if(edad >= 18 && clave == 1234) {
	printf("Acceso concedido.\n");
	} else {
	printf ("Acceso  Denegado.\n");
	}
 return 0;
}


