#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/* 1. EL PLANO */
typedef enum { INACTIVO = 0, ACTIVO = 1 } Estado;

struct Etiqueta {
    int id;
    Estado estado;
};

/* 2. PROTOTIPOS */
void pedirMemoria(struct Etiqueta **m);
void aseguraOperacion(struct Etiqueta *m);
void cambiarIdUsuario(struct Etiqueta *m);
void controlDanos(struct Etiqueta *m);
void limpiezaObligatoria(struct Etiqueta *m);
void limpiarBuffer(char *buffer);

/* 3. EL DIRECTOR (MAIN) */
int main(void) {
    struct Etiqueta *mi_paquete = NULL;

    pedirMemoria(&mi_paquete);
    controlDanos(mi_paquete);   // Informa si el sistema falla
    aseguraOperacion(mi_paquete); // Técnica y silenciosa

    cambiarIdUsuario(mi_paquete); // Interactúa e informa al usuario

    limpiezaObligatoria(mi_paquete); // Cierre formal
    return 0;
}

/* 4. EL TALLER */

void pedirMemoria(struct Etiqueta **m) {
    *m = malloc(sizeof(struct Etiqueta));
}

void aseguraOperacion(struct Etiqueta *m) {
    m->id = 0;
    m->estado = INACTIVO;
}

void cambiarIdUsuario(struct Etiqueta *m) {
    char buffer[64];
    char *ptrFinal;
    long valor;

    while (1) {
        printf("\n--> Introduzca el nuevo ID (Rango 1-1000): ");
        if (!fgets(buffer, sizeof(buffer), stdin)) continue;

        limpiarBuffer(buffer); // Limpia si el usuario escribió de más

        errno = 0;
        valor = strtol(buffer, &ptrFinal, 10);

        /* BATERÍA DE ESCUDOS ANTIBASURA (ESCUDO DE DAVID) */
        if (ptrFinal == buffer || (*ptrFinal != '\n' && *ptrFinal != '\0')) {
            printf("[!]ERROR: El valor introducido no es numérico.\n");
        } 
        else if (errno == ERANGE || valor < 1 || valor > 1000) {
            printf("[!] ERROR: El ID %ld está fuera del rango permitido (1-1000).\n", valor);
        } 
        else {
            m->id = (int)valor;
            m->estado = ACTIVO;
            printf("ÉXITO: El ID ha sido actualizado a %d.\n", m->id);
            break;
        }
    }
}

/* 5. BATERÍA DE SEGURIDAD (Infraestructura Final) */

void controlDanos(struct Etiqueta *m) {
    if (!m) {
        printf("[!] ERROR: El sistema ha negado la memoria (OS denegó la petición).\n");
        exit(EXIT_FAILURE);
    }
}

void limpiezaObligatoria(struct Etiqueta *m) {
    if (m) {
        free(m);
        printf("\n[SISTEMA]: Memoria liberada correctamente. Devuelvo las llaves al OS.\n");
    }
}

void limpiarBuffer(char *buffer) {
    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}
