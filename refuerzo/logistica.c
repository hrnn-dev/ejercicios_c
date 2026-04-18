#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*1. LOS PLANOS DEL INVENTARIO*/
struct Articulo {
	char nombre[50];
	int cantidad;
	float precio;
};

/*2. LOS PROTOTIPOS*/
void limpiarBuffer(void);
void mostrarInventario(struct Articulo *art);
void registrarArticulo(struct Articulo *art);
void compararInversion(struct Articulo *a, struct Articulo *b);

/*3. EL DIRECTOR (MAIN)*/
int main(void) {
	/*Declaramos dos unidades independientes*/
	struct Articulo art1, art2;

	printf("=====SISTEMA DE LOGÍSTICA v2.0====\n");


	/*Registro del primer asistente*/
	printf("\n---REGISTRO DEL PRIMER ARTÍCULO---\n");
	registrarArticulo(&art1);

	/*Registro del segundo asistente*/
	printf("\n---REGISTRO DEL SEGUNDO ARTÍCULO---\n");
	registrarArticulo(&art2);

	/*LA COMPARACIÓN: El nuevo taller*/
	compararInversion (&art1, &art2);


	return 0;
}

/*4. EL TALLER.*/

//registrarArticulo.
void registrarArticulo(struct Articulo *art){
	int nombreValido = 0;
	while (nombreValido == 0) {
		/*Solicita el nombre del artículo*/
		printf("Por favor, ingrese el nombre del artículo: ");
		fgets(art->nombre, 50, stdin);
		/*Limpieza del salto de línea*/
		art->nombre[strcspn(art->nombre,"\n")] = '\0';

		/*El Escudo*/
		for (int i = 0; art->nombre[i] != '\0'; i++) {
			if (isalpha(art->nombre[i])) {
				nombreValido = 1; //Si encontramos al menos una letra, es válido.
				break;             //nombreValido =1 lo valida.
			}
		}
		if (nombreValido  == 0) {
			printf("[!] ERROR: El nombre debe contener al menos una letra.\n");
		}
	}

	/*Solicita la cantidad (entero)*/
	int validacionCantidad = 0;
	while (validacionCantidad == 0) {
		printf("Por favor, ingrese la cantidad a adquirir: ");
		if (scanf("%d", &art->cantidad) != 1) {
			printf("[!] ERROR: Letras detectadas, ingrese un número entero.\n");
			limpiarBuffer();
		} else {
			validacionCantidad = 1; //Rompe el ciclo si ingresó un número
		}
	} 


//Pide el precio (Flotante)
int validacionPrecio = 0;
while (validacionPrecio == 0) {
	printf ("Por favor, ingrese el precio unitario: ");
	if (scanf("%f", &art->precio) != 1) {
		printf("[!] ERROR: Letras detectadas, ingrese un valor numético.\n");
		limpiarBuffer();
	} else {
		   validacionPrecio = 1; //Rompe el ciclo si ingresó un número

	}
}

	limpiarBuffer();
}

//compararInversion
void compararInversion(struct Articulo *a, struct Articulo *b) {
	/*1. Cálculos de inversión*/
	float artA = a->cantidad * a->precio;
	float artB = b->cantidad * b->precio;

	/*2. Lógica de comparación*/
	if (artA > artB) {
		printf(">> La mejor inversión es: %s\n", a->nombre);
		printf(">> Diferencia: $%.2f\n", artA - artB);

	} else if  (artA < artB) {
		printf(">>La mejor inversión es: %s\n", b->nombre);
		printf(">>Diferencia: $%.2f\n", artB - artA);
	}
	else {
		printf(">>EMPATE: Ambos artículos tienen la misma inversión total.\n");
	}
}

/*
//mostrarInventario
void mostrarInventario(struct Articulo *art) {
	printf("\n----REPORTE DE INVENTARIO---\n");
	printf("Producto: %s\n", art->nombre);
	printf("Cantidad disponible: %d unidades\n", art->cantidad);
	printf("Precio unitario: $%.2f\n", art->precio);
	printf("------------------------------------------------------\n");
}
*/

//limpiarBuffer
void limpiarBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

