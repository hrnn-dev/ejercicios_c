#include <stdio.h>
#include <stdlib.h>

//1. Prototipo
int calcular_area(int base, int altura);


int main(void) {

//2. Definimos variables locales
    int a;
    int b;

//3. Pedimos el valor de la base
    printf("Ingresa el valor de la base:  ");
    scanf("%d", &a);
//4. Pedimos el valor de la altura
    printf("Ingresa el valor de la altura:  ");
    scanf("%d", &b);

//5. Llamamos a la función.
    int area = calcular_area(a, b);

//6. Imprimimos el resultado.
     printf("El área resultante es:%d\n", area);

    return 0;
}

//7. Definición de la función.
int calcular_area(int base, int altura) {
	int area = base * altura;
    return area;
}
