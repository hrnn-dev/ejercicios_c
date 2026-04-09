#include <stdio.h>
#include <stdlib.h>

//Definicion del prototipo
int obtener_maximo(int a, int b);

int main() {
    //Declarar variables
	int valor1;
	int valor2;
	//2. Pedir y capturar el primer dato
	printf("Ingresa el primer número entero:  ");
	scanf("%d", &valor1);

	//3. Pedir y capturar el segundo dato
	printf("Ingresa el segundo número entero:  ");
	scanf("%d", &valor2);

//Llamar a la función pasandole las 2 variables
	int resultado =obtener_maximo(valor1, valor2);
	printf("El número mayor es:%d\n", resultado);

	return 0;
}

// 3. Definición de la función (El Especialista)
int obtener_maximo(int a, int b) {
    if (a > b) {
        return a; // Si 'a' es más grande, devolvemos 'a'
    } else {
        return b; // Si no, obligatoriamente 'b' es más grande (o son iguales)
    }
}
