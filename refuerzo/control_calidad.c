#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*1. LOS PLANOS DEL INVENTARIO*/
struct Articulo {
	char nombre[50];
	int cantidad;
	float precio;
	int estado;
};

/*2. LOS PROTOTIPOS*/
void limpiarBuffer(void);
void mostrarInventario(struct Articulo *art);
void registrarArticulo(struct Articulo *art);
void evaluarCalidad(struct Articulo *art);
void aplicarImpuesto (struct Articulo *art);
void mostrarReporte (struct Articulo *art);

/*3. EL DIRECTOR (MAIN)*/
int main(void) {
	/*Declaramos un artículo*/
	struct Articulo art1;

	printf("=====SISTEMA DE LOGÍSTICA v2.1====\n");


	/*Registro del artículo*/
	printf("\n---REGISTRO DEL PRIMER ARTÍCULO---\n");
	registrarArticulo(&art1);

	/*EL CALCULADOR DE IMPUESTO*/
	aplicarImpuesto(&art1);

	/*EL SENSOR DE CALIDAD*/
	evaluarCalidad (&art1);

	/*Imprime el resultado final*/
	mostrarReporte (&art1); 

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
		printf("Por favor, ingrese la cantidad disponible en stock: ");
		if (scanf("%d", &art->cantidad) != 1) {
			printf("[!] ERROR: Letras detectadas, ingrese un número entero.\n");
			limpiarBuffer();
		} else if(art->cantidad < 0) {
			printf("[!] Error: El stock no puede ser negativo.\n");
			/*No cambiamos la  variable a 1, así que el ciclo se repite*/
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
	} else if (art->precio < 0) {
		printf("[!] ERROR: El precio no puede ser negativo.\n");
	} else {
		   validacionPrecio = 1; //Rompe el ciclo si ingresó un número

	}
}

	limpiarBuffer();
}

//aplicarImpuesto
void aplicarImpuesto(struct Articulo *art) {
	float tasa = 0.15;
	/*Nueva fórmula: Precio = Precio * 1.15f*/
	art->precio = art->precio + (art->precio * tasa);

	printf("[SISTEMA]: Se ha aplicado un impuesto del 15%%.\n");
	printf("[SISTEMA]: Nuevo precio calculado: $%.2f\n", art->precio);
}


//evaluarCalidad
void evaluarCalidad(struct Articulo *art) {
/*Regla: Precio > 5000 y Stock <2 es peligroso*/
	if (art->precio > 5000 || art->cantidad <2) {
		art->estado =  0; /*ESTADO CRÍTICO*/
	} else {
		art->estado = 1; /*Estado ÓPTIMO*/
	}
}

//mostrarReporte
void mostrarReporte(struct Articulo *art) {
	printf("\n===================================\n");
	printf("    REPORTE DE CONTROL DE CALIDAD   \n");
	printf("\n=====================================\n");
	printf("Artículo: %s\n", art->nombre);
	printf("Stock: %d unidades\n", art->cantidad);
	printf("Precio: $%.2f (Final)\n", art->precio);

	/*Aquí el reporte decide qué imprimir de acuerdo al estado*/
	if (art->estado == 0) {
		printf("ESTADO:  [¡¡¡RIESGO!!!]\n");

		/*El reporte deduce los problemas INDEPENDIENTEMENTE*/
		if (art->precio > 5000){
			printf("AVISO  :Reconsidere su inversión (Precio Elevado).\n");
		}


		 if (art->cantidad <2) {

 			printf("AVISO: Reposición inmediata requerida (Stock bajo).\n");
 		}
    }
    else {
		   /*AQUÍ ESTÁ EL ALTOPARLANTE PARA EL ESTADO 1(ÓPTIMO)*/ 
			printf("ESTADO:[ÓPTIMO]\n"); 
			printf("AVISO: El estado es ÓPTIMO, considere su inversión.\n");
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

