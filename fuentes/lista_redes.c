#include <stdio.h> //Biblioteca estándar para entrada y salida de datos.
#include <stdlib.h> //Biblioteca estándar para gestión de memoria dinámica (malloc, realloc)
#include <string.h>  //Biblioteca para manipulación de cadenas de texto

/*---1. DEFINICIÓN DE ESTRUCTURAS---*/

/*Definición del eslabón base de la lista enlazada*/
typedef struct Nodo {
	char *registro_ip; //Puntero dinámico para almacenar la cadena de la  dirección IP
	struct Nodo *siguiente; //Enlace apuntador hacia el siguiente nodo
} Nodo;

/*Estructura de control que encapsula el estado de la lista de rastreo.*/
typedef struct {
 	Nodo *cabeza; //Puntero maestro al primer elemento de la estructura.
	int cantidad_nodos; //Contador entero del total de elementos registrados.
}listaRastreo;

/*---2. LOS PROTOTIPOS---*/
void inicializar_lista(listaRastreo *lista); //Configura el estado inicial de la lista.
Nodo* crear_nodo(const char *ip);//Asigna memoria y construye un nodo aislado.
int insertar_final(listaRastreo *lista, const char *ip);/*Gestiona la inseción y la vali
dación en la cadena*/
int buscar_ip(const listaRastreo *lista, const char *ip_objetivo);/*Examina la memoria en
busca de una ip específica*/
int eliminar_ip(listaRastreo *lista, const char *ip); //Permite el escudo de extirpación
void liberar_lista(listaRastreo *lista); /*Libera de forma recursiva toda la memoria 
dinámica ocupada*/

/*3.---EL DIRECTOR(MAIN)---*/
int main(void) {
	listaRastreo mi_radar;

	printf("---Iniciando sistema NERV v2.0 (Rastreo y Extirpación)---\n");
	inicializar_lista(&mi_radar);

	//FASe 1:  Inserción de amenazas
	printf("\n--Fase 1: Poblando  la RAM---\n");

	//ESCUDO ANTIBASURA: Validamos que la inserción  no falle  por falta de  memoria  .
	if (!insertar_final(&mi_radar, "192.168.1.105") ||
		!insertar_final(&mi_radar, "10.0.0.4")       ||
		!insertar_final(&mi_radar, "172.16.0.8")) {
		fprintf(stderr, "[X] ERROR CRÍTICO: Fallo de memoria al poblar la RAM. Abortar.\n");
		liberar_lista(&mi_radar);
		return EXIT_FAILURE;
	}

	//FASE 2: Diagnóstico Pre-Ops.
	printf("\n---Fase 2: Diagnóstico de Rastreo---\n");
	if (buscar_ip(&mi_radar, "10.0.0.4")) {
		printf("[!] ALERTA: IP 10.0.0.4 bajo vigilancia activa.\n");
	} else {
		printf("[!] IP 10.0.0.4 no registrada en el sistema.\n");
	}

	//FASE 3: Extirpación quirúrgica.
	printf("\n---Fase 3: Secuencia de Extirpación Quirúrgica---\n");

	//ESCUDO AANTIBASURA: Validamos el éxito o fallo de cada extirpación.
	if (!eliminar_ip(&mi_radar, "192.168.1.200")) {
		printf("[i] INFO: IP 192.168.1.200 no encontrada (Caso fantasma controlado).\n");
	}

	if (eliminar_ip(&mi_radar, "10.0.0.4")) {
		printf("[+] ÉXITO: IP 10.0.0.4 extirpada (Caso Medio/Bypass).\n");
	} else {
		printf("[X]ALERTA: Fallo al eliminar IP 10.0.0.4.\n");
	}

	if (eliminar_ip(&mi_radar, "192.168.1.105")) {
		printf("[+] ÉXITO: IP 192.168.1.105 extirpada (Caso Cabeza/Paciente cero).\n");
	} else {
		printf("[X] ALERTA: Fallo al eliminar IP 192.168.1.105.\n");
	}

	//Fase4: Verificación post Op.
	printf("\n---Fase 4: Diagnóstico táctico post-operatorio---\n");
	if (buscar_ip(&mi_radar, "10.0.0.4")) {
		printf("[!] FALLO CRÍTICO: IP 10.0.0.4 sigue en el radar.\n");
	} else {
		printf("[i] ÉXITO: IP 10.0.0.4 ya no existe en el sistema.\n");
	}
	if (buscar_ip(&mi_radar, "172.16.0.8")) {
		printf("[+] CONFIRMADO: IP 172.16.0.8 sigue intacta y sistema estable.\n");
	}

	//FASE 5: Limpieza Terminal
	printf("\n--Fase 5: Finalizando Sistema NERV---\n");
	liberar_lista(&mi_radar);

	return EXIT_SUCCESS;
}
/*4.---MÉDULA: EL TALLER DE IMPLEMENTACIÓN---*/

//Configura los valores iniciales por defecto de la estructura de control.
void inicializar_lista(listaRastreo *lista) {
	//Escudo antibasura: Evita fallos de segmentación si el puntero de control es nulo
	if (lista == NULL) return;
	lista ->cabeza = NULL; //Inicializa la cabeza apuntando a la nada.
	lista->cantidad_nodos = 0; //Reinicia el contador de nodos a cero.
}

/*Fabrica un nodo independiente, validando la integridad de los datos de entrada*/
Nodo *crear_nodo(const char *ip) {
	//Escudo antibasura: Si la cadena IP de entrada es nula, aborta la creación.
	if (ip == NULL) return NULL;

	//Asignación de MEMORIA: Fabricamos el contenedor en el Heap.
	Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
	if (nuevo_nodo == NULL) {
		perror("Fallo crítico de memoria en RAM");
		exit(EXIT_FAILURE);
	}

	//Duplica la dena IP en la memoria dinámica de forma segura.
	nuevo_nodo->registro_ip = strdup(ip);

	//Escudo de memoria: Valida si falló el duplicado de la cadena IP.
	if (nuevo_nodo->registro_ip == NULL) {
		free(nuevo_nodo); //Libera el nodo previamente reservado.
		return NULL;
	}

	nuevo_nodo->siguiente = NULL; //Garantiza que el nuevo nodo apunte a la nada.
	return nuevo_nodo;
}

//Inserta de forma segura un nuevo elemento al final de la cadena de bloques.
int insertar_final(listaRastreo *lista, const char *ip) {
	//Escudo antibasura: Cancela la operación si el radar o la IP son nulos
	if (lista == NULL || ip == NULL) return 0;

	Nodo *nuevo_nodo = crear_nodo(ip); /*Invoca al taller para fabricar el nodo con los 
	datos limpios*/
	//Escudo antibasura: Si falló la creación del nodo, detiene el proceso.
	if (nuevo_nodo == NULL) return 0;


	//Evaluación del caso base: Comprueba si la lista se encuentra vacía.
	if(lista->cabeza == NULL) {
		lista->cabeza = nuevo_nodo; //Asigna el nuevo nodo como el primer elemento de lista
	//Caso general: La lista ya contiene uno o más nodos en su estructura.4
	} else {
		Nodo *actual = lista->cabeza; /*Declara un puntero temporal de navegación 
		apuntando al inicio*/
		//Ciclo de exploración: Avanza mientras exista un nodo posterior.
		while (actual->siguiente != NULL) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevo_nodo; /*Enlaza el último nodo existente con el recién fabricado*/
	}

	lista->cantidad_nodos++; //Incrementa en una unidad el registro de nodos
	printf("[+] IP %s enlazada. Total en rastro: %d\n", ip, lista->cantidad_nodos);

	return 1; //ESCUDO: Retorna éxito para que el main sepa que la RAM se pobló bien.
}


//Busca una IP en la lista de forma secuencial, utilizando escudos de protección.
int buscar_ip(const listaRastreo *lista, const char *ip_objetivo) {
	//Escudo antibasura: Si los punteros de entrada apuntan a la nada, aborta.
	if (lista == NULL || ip_objetivo == NULL) return 0;
	//Escudo estructural: Si la lista carece de elementos, finaliza la búsqueda.
	if (lista->cabeza == NULL) return 0;


	//Instancia un puntero de navegación situado en el nodo inicial.
	Nodo *actual = lista->cabeza;

	//Ciclo de exploración: Recorre cada eslabón hasta encontrar el final.
	while (actual !=NULL) {
		if (actual->registro_ip !=NULL && strcmp(actual->registro_ip, ip_objetivo) == 0) {
			//Retorna verdadero al confirmar la coincidencia de texto.
			return 1;
		}
		actual = actual->siguiente; /*Desplaza el puntero de navegación hacia el siguiente 
		nodo de la estructura*/
	}

	return 0; //Retorna falso si concluye el recorrido de la lista sin hallar la IP
}

//Implementación de extirpación quirúrgica con soporte para el escudo.
int eliminar_ip(listaRastreo *lista, const char *ip) {
	//Escudo antibasura: Valida punteros antes de operar.
	if (lista == NULL || lista ->cabeza == NULL || ip == NULL) return 0;

	Nodo *actual = lista->cabeza;
	Nodo *anterior = NULL;

	while (actual != NULL) {
		if (actual -> registro_ip != NULL && strcmp(actual->registro_ip, ip) == 0) {
			if (anterior == NULL) {
				lista->cabeza = actual->siguiente; //Caso cabeza
			} else {
				anterior->siguiente = actual->siguiente; //Caso medio
			}
			free(actual->registro_ip); //Libera la cadena dinámica asignada por strdup
			free(actual); //Libera el nodo contenedor.
			lista->cantidad_nodos--; //Sincroniza el contador general.
			return 1; //Escudo recibe confirmación de éxito.
		}
		anterior = actual;
		actual = actual->siguiente;
	}
	return 0; //Escudo recibe señal de IP inexistente.
}

//Realiza el barrido estructural liberando cada bloque de memoria asignado.
void liberar_lista(listaRastreo *lista) {
	//Escudo antibasura: Cancela si la lista ya existe o está vacía.
	if (lista == NULL || lista->cabeza == NULL) return;
	//Establece el puntero de navegación al inicio de la lista.
	Nodo *actual = lista->cabeza;
	//Declara un puntero auxiliar para guardar el rastro de la cadena.
	Nodo *siguiente_nodo = NULL;

	//Ciclo de vaciado: Se ejecuta hasta procesar el último nodo de la lista.
	while (actual != NULL) {
		siguiente_nodo = actual->siguiente;/*Resguarda la dirección del siguiente nodo
		antes de destruir el actual*/
		free(actual->registro_ip); /*Libera la memoria reservada dinámicamente para la 
		cadena IP*/
		free(actual); //Libera la memoria del contenedor actual
		actual = siguiente_nodo;
	}

	lista->cabeza = NULL; /*Asegura la cabeza de la estructura volviendo a apuntar a NULL
	*/
	lista->cantidad_nodos = 0; //Restablece el contador global de nodoa a cero.
	printf("[-] Memoria liberada. Radar limpio.\n");
}

