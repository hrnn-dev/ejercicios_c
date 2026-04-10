#include <stdio.h>
#include <string.h>

int main(void) {
    //1.Definicion de arreglos (variables)
    char ssid[16];
    char pass[21];

    printf("---GESTOR DE REDES ARCH---\n");
    
    //Bloque 1: SSID
    printf("Ingrese el SSID (Max 15 caracteres: ) ");
    fgets(ssid, sizeof(ssid), stdin);
    ssid[strcspn(ssid, "\n")] ='\0'; //Cirugía estética
 
    //Bloque 2: PASSWORD
    printf("Ingrese la contrasña (Max 20 caracteres: ) ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    //Reporte final (Solo mostramos SSID por seguridad)
    printf("\n[OK] Intentando conexión a: %s... ¡Éxito!\n", ssid);
    printf("La clave de %zu bytes ha sido cifrada en RAM.\n", strlen(pass));

    return 0;
}

