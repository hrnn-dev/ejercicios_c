#include <stdio.h>

//1. El prototipo.
int  mostrarMenu(void);



int  main(void) {

int opcion = 0;


printf("****************************\n");
printf("\n   SELECTOR DE HERNAN     \n");
printf("****************************\n");

//2. LLAMADA:  Llamamos a  la  función sin  pasarle nada en los paréntesis.
	opcion  = mostrarMenu();

//3. RESPUESTA
	printf("\n[MAIN] Recibida la orden número: %d\n", opcion);
	printf("\n[MAIN] Procediendo con la ejecución...\n");

	return 0;
}


//4.DEFINICIÓN.
int  mostrarMenu(void) {
int opcion_local = 0;
	printf("\n****MENU PRINCIPAL***\n");

	printf("Por favor elige una opción:  \n");
	printf("1. Iniciar.\n");
	printf("2. Cargar.\n");
	printf("3. Salir.\n");

//5. El escudo antibasura.
if(scanf("%d", &opcion_local) != 1) {
	return 0; //Si el  usuariomete una letra, devolvemos  0 como  error.
}
//6. Aquí  envías  el dato capturado  de vuelta al main
	return opcion_local;
}
