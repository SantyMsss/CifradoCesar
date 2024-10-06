#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para transformar letra a número (A=0, B=1, ..., Z=25)
int letraANumero(char letra) {
    if (isupper(letra)) {
        return letra - 'A';
    } else if (islower(letra)) {
        return letra - 'a';
    }
    return -1; // Si no es letra, devuelve -1
}

// Función para transformar número a letra (0=A, 1=B, ..., 25=Z)
char numeroALetra(int numero, int esMayuscula) {
    if (esMayuscula) {
        return (char)(numero + 'A');
    } else {
        return (char)(numero + 'a');
    }
}

// Función para cifrar el texto usando f(p) = (p + 3) mod 26
void cifrarCesar(char mensaje[]) {
    for (int i = 0; i < strlen(mensaje); i++) {
        char caracter = mensaje[i];
        
        if (isalpha(caracter)) {
            int esMayuscula = isupper(caracter); // Verifica si es mayúscula
            int numero = letraANumero(caracter);
            
            if (numero != -1) {
                // Aplica f(p) = (p + 3) mod 26
                int nuevoNumero = (numero + 3) % 26;
                mensaje[i] = numeroALetra(nuevoNumero, esMayuscula);
            }
        }
    }
}

// Función para descifrar el texto usando f⁻¹(p) = (p - 3) mod 26
void descifrarCesar(char mensaje[]) {
    for (int i = 0; i < strlen(mensaje); i++) {
        char caracter = mensaje[i];
        
        if (isalpha(caracter)) {
            int esMayuscula = isupper(caracter); // Verifica si es mayúscula
            int numero = letraANumero(caracter);
            
            if (numero != -1) {
                // Aplica f⁻¹(p) = (p - 3) mod 26
                int nuevoNumero = (numero - 3 + 26) % 26; // +26 para evitar números negativos
                mensaje[i] = numeroALetra(nuevoNumero, esMayuscula);
            }
        }
    }
}

int main() {
    int opcion;
    char mensaje[100];

    do {
        // Muestra el menú
        printf("\n----- Menu Cifrado Cesar -----\n");
        printf("1. Ingresar y cifrar un mensaje\n");
        printf("2. Ingresar y descifrar un mensaje\n");
        printf("3. Salir\n");
        printf("\n Elige una opcion: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                // Opción para cifrar
                printf("\nIntroduce el mensaje a cifrar: ");
                fgets(mensaje, sizeof(mensaje), stdin);

                cifrarCesar(mensaje);

                printf("Mensaje cifrado: %s\n", mensaje);
                break;

            case 2:
                // Opción para descifrar
                printf("\nIntroduce el mensaje a descifrar: ");
                fgets(mensaje, sizeof(mensaje), stdin);

                descifrarCesar(mensaje);

                printf("Mensaje descifrado: %s\n", mensaje);
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }

    } while (opcion != 3);  // Se repetirá el menú hasta que el usuario elija salir

    return 0;
}
