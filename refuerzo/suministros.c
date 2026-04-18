#include<stdio.h>
#include<string.h>

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

/*3. EL DIRECTOR (MAIN)*/
int main(void) {
	struct Articulo inventario1;

	printf("=====SISTEMA DE INVENTARIO v1.0====\n");


    /*Enviamos las coordenadas al taller*/
	registrarArticulo(&inventario1);
	mostrarInventario(&inventario1);

	return 0;
}

/*4. EL TALLER.*/

//registrarArticulo.
void registrarArticulo(struct Articulo *art){
	/*Solicita el nombre del artículo*/
	printf("Por favor, ingrese el nombre del artículo: ");
	fgets(art->nombre, 50, stdin);
	//Limpieza del salto de línea
	art->nombre[strcspn(art->nombre,"\n")] = '\0';

	/*Solicita la cantidad (entero)*/
	int validacionCantidad = 0;
	while (validacionCantidad == 0) {
		printf("Por favor, ingrese la cantidad en stock: ");
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



//mostrarInventario
void mostrarInventario(struct Articulo *art) {
	printf("\n----REPORTE DE INVENTARIO---\n");
	printf("Producto: %s\n", art->nombre);
	printf("Cantidad disponible: %d unidades\n", art->cantidad);
	printf("Precio unitario: $%.2f\n", art->precio);
	printf("------------------------------------------------------\n");
}

//limpiarBuffer
void limpiarBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

