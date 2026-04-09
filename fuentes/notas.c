#include <stdio.h>
#include <stdlib.h>

//1. Prototipo.
int es_nota_aprobatoria(int nota);


//2.Inicio de función principal.
int main(void) {
    //3. Declaración del arreglo de enteros (4 espacios contiguos)
    int calificaciones[4];

//4. Asignación manual de las notas:
calificaciones[0] = 8;
calificaciones[1] = 5;
calificaciones[2] = 10;
calificaciones[3] = 4;

printf("---REPORTE DE CALIFICACIONES:---\n");

//5. El bucle "for" comienza en 0, avanza de 1 en 1, se detiene antes del 4
    for (int i = 0; i <4; i++) {

 
         //"i" representa el índice actual (0,1,2,3)
         // calificaciones[i] extrae el valor guardado en ese casillero exacto

	printf("Índice %d | Nota:%d -> ", i, calificaciones[i]);

//6. EVALUACIÓN LÓGICA (Tu turno)
    // Llama a tu función aprobatoria enviándole calificaciones[i]
   // Usa un if/else. si devuelve 1, imprime "Aprobado\n". Si devuelve 0, imprime "Reprobado\n".

	
	if (es_nota_aprobatoria(calificaciones[i]) ==1) {
	printf("Aprobado.\n");
	} else {
	printf("Reprobado.\n");
	}

  }
	return 0;

}

//7. DEFINICION DEL ESPECIALISTA// Si la nota es igual a 6, retorna 1
// Si la nota es menor a 6, retorna 0
int es_nota_aprobatoria(int nota) {
	if (nota >=6) {
	    return 1;
	} else {
	    return 0;
	}
}
