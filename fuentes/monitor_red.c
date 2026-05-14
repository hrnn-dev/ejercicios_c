#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_TAMANO_INICIAL 256
#define INDICE_CAPACIDAD_INICIAL 4

/* El molde de datos */
typedef struct {
        char **lineas;
        int cantidad;
        int capacidad;
} registroArchivo;

/* LOS PROTOTIPOS */
bool cargar_archivo_dinamico(const char *ruta, registroArchivo *reg);
void analizar_amenazas(const registroArchivo *reg);
bool filtro_avanzado(const char *linea);
bool registro_inicializar(registroArchivo *reg);
bool registro_insertar(registroArchivo *reg, const char *linea);
void registro_liberar(registroArchivo *reg);
char *leer_linea_indeterminada(FILE *archivo);

/* EL DIRECTOR (MAIN) */
int main (void) {
        const char *ruta_logs = "datos/red_logs.txt";
        registroArchivo bitacora;

        printf("---Monitor de red v1.0---\n");

        if (!registro_inicializar(&bitacora)) {
                fprintf(stderr, "[-]ERROR CRÍTICO AL INICIALIZAR LA BITÁCORA.\n");
                return EXIT_FAILURE;
        }

        if (cargar_archivo_dinamico(ruta_logs, &bitacora)) {
                analizar_amenazas(&bitacora);
        } else {
                fprintf(stderr, "[-] Fallo en la extracción de logs.\n");
        }
        
        registro_liberar(&bitacora);

        printf("\n---Operación finalizada---\n");
        return EXIT_SUCCESS;
}

/* EL TALLER */

bool filtro_avanzado(const char *linea) {
        if (linea == NULL) return false;
        if (strstr(linea, "FAIL") != NULL) return true;
        if (strstr(linea, "CRITICAL") != NULL) return true;
        if(strstr(linea, "ATTACK") != NULL) return true;
        return false;
}

bool cargar_archivo_dinamico(const char *ruta, registroArchivo *reg) {
        if (ruta == NULL || reg == NULL) return false;

        FILE *archivo = fopen(ruta, "r");
        if (archivo == NULL) {
                fprintf(stderr, "[-] ERROR: No se pudo abrir '%s'.\n", ruta);
                return false;
        }

        printf("[+] Analizando y extrayendo logs de red de forma dinámica...\n");
        char *linea_dinamica = NULL;

        while ((linea_dinamica = leer_linea_indeterminada(archivo)) != NULL) {
                linea_dinamica[strcspn(linea_dinamica, "\r\n")] = 0;

                if (filtro_avanzado(linea_dinamica)) {
                        if (!registro_insertar(reg, linea_dinamica)) {
                                fprintf(stderr, "[-] Falla al insertar en memoria.\n");
                                free(linea_dinamica);
                                fclose(archivo);
                                return false;
                        }
                }
                free(linea_dinamica);
        }

        fclose(archivo);
        return true;
}

void analizar_amenazas(const registroArchivo *reg) {
        if (reg == NULL || reg->lineas == NULL) return;

        printf("\n[+] Analisis forense sobre registros filtrados (%d alertas en RAM).\n", reg->cantidad);
        int amenazas_detectadas = 0;
        char ip_sospechosa[50];

        for (int i = 0; i < reg->cantidad; i++) {
                if (reg->lineas[i] == NULL) continue;

                if (sscanf(reg->lineas[i], "%49s", ip_sospechosa) == 1) {
                        printf("    [!]DETECCION CRITICA -> Registro: %s\n", reg->lineas[i]);
                        amenazas_detectadas++;
                }
        }

        if (amenazas_detectadas == 0) {
                printf("   [+]Ninguna amenaza detectada en los logs procesados.\n");
        } else {
                printf("   [!]Resumen: %d incidentes listos para respuesta automatica.\n", amenazas_detectadas);
        }
}

char *leer_linea_indeterminada(FILE *archivo) {
        if (archivo == NULL) return NULL;
        int capacidad_buffer = BUFFER_TAMANO_INICIAL;
        int posicion = 0;
        char *buffer = malloc(capacidad_buffer * sizeof(char));
        if (buffer == NULL) return NULL;

        int caracter;
        while ((caracter = fgetc(archivo)) != EOF) {
                if (caracter == '\n') break;

                if (posicion >= capacidad_buffer - 1) {
                        capacidad_buffer *= 2;
                        char *nuevo_buffer = realloc(buffer, capacidad_buffer * sizeof(char));
                        if (nuevo_buffer == NULL) {
                                free(buffer);
                                return NULL;
                        }
                        buffer = nuevo_buffer;
                }
                buffer[posicion++] = (char)caracter;
        }

        if (posicion == 0 && caracter == EOF) {
                free(buffer);
                return NULL;
        }

        buffer[posicion] = '\0';
        return buffer;
}

bool registro_inicializar(registroArchivo *reg) {
        if (reg == NULL) return false;
        reg->capacidad = INDICE_CAPACIDAD_INICIAL;
        reg->cantidad = 0;
        reg->lineas = malloc(reg->capacidad * sizeof(char *));
        if (reg->lineas == NULL) return false;
        return true;
}

bool registro_insertar(registroArchivo *reg, const char *linea) {
        if (reg == NULL || linea == NULL) return false;
        if (reg->cantidad >= reg->capacidad) {
                int nueva_capacidad = reg->capacidad * 2;
                char **nuevo_indice = realloc(reg->lineas, nueva_capacidad * sizeof(char *));
                if (nuevo_indice == NULL) return false;
                reg->lineas = nuevo_indice;
                reg->capacidad = nueva_capacidad;
        }
        reg->lineas[reg->cantidad] = strdup(linea);
        if (reg->lineas[reg->cantidad] == NULL) return false;
        reg->cantidad++;
        return true;
}

void registro_liberar(registroArchivo *reg) {
        if (reg == NULL || reg->lineas == NULL) return;
        for (int i = 0; i < reg->cantidad; i++) {
                if (reg->lineas[i] != NULL) {
                        free(reg->lineas[i]);
                        reg->lineas[i] = NULL;
                }
        }
        free(reg->lineas);
        reg->lineas = NULL;
        reg->cantidad = 0;
        reg->capacidad = 0;
        printf("[+] Objetivo destruido. Memoria sanitizada.\n");
}
