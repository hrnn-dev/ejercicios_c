#include <stdio.h>

int main(void) {
    //Reservamos el espacio para 10 caracteres
    char nombre[10];

    //Solicitamos el nombre (máximo 9 letras)
    printf("Dime tu nombre (max 9 letras):  ");
    

    //DATO DE VITAL IMPORTANCIA: "scanf" añade el '\0' al final AUTOMÁTICAMENTE.
    scanf("%s", nombre);


    printf("\nHola, %s! He guardado tu nombre en un arreglo de %ld bytes.\n", nombre, sizeof(nombre));

    return 0;
}
