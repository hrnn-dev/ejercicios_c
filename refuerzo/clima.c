#include <stdio.h>
#include <string.h>


int main(void) {
char clima;


printf("\n=====MONITOR DE CLIMA DIARIO====\n");

printf("Por favor ingrese una letra (S-Soleado, N-Nublado, L-Lluvia, T-Tormenta)\n");
scanf("%c", &clima);

	switch(clima) {
	case 'S':
	case 's':
	printf("Póngase bloqueador solar y use gafas.\n");
	break;

	case 'N':
	case 'n':
	printf("Día gris, pero no se preocupe por lluvia.\n");
	break;

	case 'L':
	case 'l':
	printf("Lleve paraguas y conduzca con cuidado.\n");
	break;

	case 'T':
	case 't':
	printf("¡Peligro! Quédese bajo techo.\n");
	break;

	default:
	printf("Código de clima no reconocido.\n");
	}

	return 0;

}
