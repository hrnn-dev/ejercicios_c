#include <stdio.h>
#include <string.h>

int main(void) {
    char servidor[16];

    printf("Por favor ingrese el nombre del servidor: ");
    fgets(servidor, sizeof(servidor), stdin);
    servidor[strcspn(servidor, "\n")] = '\0';

    char distro[26];

    printf("Por favor ingrese el nombre de su distribución Linux preferida: ");
    fgets(distro, sizeof(distro), stdin);
    distro[strcspn(distro, "\n")] = '\0';

    
    printf("Servidor: %s | OS: %s\n", servidor, distro);

    return 0;
}
