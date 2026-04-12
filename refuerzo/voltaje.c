#include <stdio.h>

int main(void) {
int voltaje;

printf("\n=====================================\n");
printf("    VERIFICADOR DE VOLTAJE DE HERNAN    \n");
printf("\n--------------------------------------\n");

printf ("Por favor introduzca el voltaje de su caja térmica: ");
	scanf("%d", &voltaje);

	//LOGICA DE EVALUACION
	if (voltaje < 100) {
		printf("[!] ALERTA: Bajo voltaje. Equipos en riesgo.\n");
		} else if (voltaje >= 110 && voltaje <= 220) {
			printf("[OK] Voltaje seguro. Operación normal.\n");
			} else {
			printf("[!] PELIGRO: SOBRECARGA. Desconecte de inmediato.\n");
			}

			return 0;

}
