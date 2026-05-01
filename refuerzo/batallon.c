#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* --- 1. EL PLANO --- */
typedef enum { INACTIVO = 0, ACTIVO = 1 } Estado;

struct Etiqueta {
    int id;
    Estado estado;
};

/* --- 2. LOS PROTOTIPOS --- */
long preguntarTamanoBatallon(void);
struct Etiqueta* solicitarMemoria(long cantidad);
void desplegarBatallon(struct Etiqueta *m, long cantidad);
void limpiezaObligatoria(struct Etiqueta *m);
void limpiarBuffer(char *str);

/* --- 3. EL DIRECTOR (MAIN) --- */
int main(void) {
    struct Etiqueta *mi_batallon = NULL;
    long cantidad_tropas = 0;

    printf("==== SISTEMA DE GESTION DE BATALLONES v1.0 ===\n");

    cantidad_tropas = preguntarTamanoBatallon();
    mi_batallon = solicitarMemoria(cantidad_tropas);
    desplegarBatallon(mi_batallon, cantidad_tropas);
    limpiezaObligatoria(mi_batallon);

    return 0;
}

/* --- 4. EL TALLER --- */

long preguntarTamanoBatallon(void) {
    char entrada[128];
    char *ptrFinal;
    long valor;

    while(1) {
        printf("\n---> Ingrese la cantidad de etiquetas (1-100000): ");
        if (!fgets(entrada, sizeof(entrada), stdin)) continue;

        limpiarBuffer(entrada);
        errno = 0;
        valor = strtol(entrada, &ptrFinal, 10);

        if (ptrFinal == entrada || *ptrFinal != '\0') {
            printf("[!] ERROR: Ingrese un valor numérico válido.\n");
        } else if (errno == ERANGE || valor < 1 || valor > 100000) {
            printf("[!] ERROR: Cantidad fuera de rango operativo.\n");
        } else {
            return valor;
        }
    }
}

struct Etiqueta* solicitarMemoria(long cantidad) {
    struct Etiqueta *m = calloc((size_t)cantidad, sizeof(struct Etiqueta));
    if (m == NULL) {
        fprintf(stderr," [!] ERROR CRÍTICO: El sistema ha denegado la memoria.\n");
        exit(EXIT_FAILURE);
    }
    printf("[SISTEMA]: %ld bloques asignados e higienizados.\n", cantidad);
    return m;
}

void desplegarBatallon(struct Etiqueta *m, long cantidad) {
    printf("\n--- INICIANDO CONFIGURACION Y DESPLIEGUE ---\n");
    for (long i = 0; i < cantidad; i++) {
        // Regresamos al acceso mediante puntero 'actual' que es más robusto con const
        struct Etiqueta *actual = &m[i];
        actual->id = (int)(i + 1) * 100;
        actual->estado = ACTIVO;

        printf("[%04ld] ID: %-5d | Estado: %s\n",
                i, actual->id, (actual->estado == ACTIVO) ? "ACTIVO" : "INACTIVO");
    }
    printf("--- DESPLIEGUE COMPLETADO ---\n");
}

void limpiezaObligatoria(struct Etiqueta *m) {
    if (m != NULL) {
        free(m);
        printf("\n[SISTEMA]: Batallón desmovilizado. Memoria liberada correctamente.\n");
    }
}

void limpiarBuffer(char *buffer) {
    char *p = strchr(buffer, '\n');
    if (p) {
        *p = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

