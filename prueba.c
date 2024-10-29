#include <stdio.h>
#include <string.h>       // Añade esta línea para que strcpy funcione
#include "cifrador.h"     // Incluye el encabezado de tu biblioteca

int main() {
    char mensaje[] = "HELLO";
    int desplazamiento = 3;
    int numLineas = 3;

    // Prueba de cifrado César
    printf("Mensaje original: %s\n", mensaje);
    cifrarCesar(mensaje, desplazamiento);
    printf("Mensaje cifrado (César): %s\n", mensaje);
    descifrarCesar(mensaje, desplazamiento);
    printf("Mensaje descifrado (César): %s\n", mensaje);

    // Prueba de cifrado Escítala
    strcpy(mensaje, "HELLO");
    cifrarEscitala(mensaje, numLineas);
    printf("Mensaje cifrado (Escítala): %s\n", mensaje);
    descifrarEscitala(mensaje, numLineas);
    printf("Mensaje descifrado (Escítala): %s\n", mensaje);

    // Información de los programadores
    mostrarInfoProgramadores();

    return 0;
}

