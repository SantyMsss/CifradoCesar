#include <stdio.h> 
#include <string.h>
#include <ctype.h>

/*
Cifrador base desarrollado por Santiago Martinez Serna, Laura Sofia Toro Garcia y Santiago Alejandro Santacruz
Para la asignatura de Matematicas Discretas 1
Presentado a Docente: Ing. Andres Fernando Velasco
 */

// transformar letra a número (A=0, B=1, ..., Z=25)
int letraANumero(char letra) {
    if (isupper(letra)) {
        return letra - 'A';
    } else if (islower(letra)) {
        return letra - 'a';
    }
    return -1;
}

// transformar número a letra (0=A, 1=B, ..., 25=Z)
char numeroALetra(int numero, int esMayuscula) {
    if (esMayuscula) {
        return (char)(numero + 'A');
    } else {
        return (char)(numero + 'a');
    }
}

// Función para cifrar el texto usando el cifrado César con desplazamiento variable
void cifrarCesar(char mensaje[], int desplazamiento) {
    for (int i = 0; i < strlen(mensaje); i++) {
        char caracter = mensaje[i];
        
        if (isalpha(caracter)) {
            int esMayuscula = isupper(caracter); // Verifica si es mayúscula
            int numero = letraANumero(caracter);
            
            if (numero != -1) {
                // Aplica f(p) = (p + desplazamiento) mod 26
                int nuevoNumero = (numero + desplazamiento) % 26;
                mensaje[i] = numeroALetra(nuevoNumero, esMayuscula);
            }
        }
    }
}

// Función para descifrar el texto usando el cifrado César con desplazamiento variable
void descifrarCesar(char mensaje[], int desplazamiento) {
    for (int i = 0; i < strlen(mensaje); i++) {
        char caracter = mensaje[i];
        
        if (isalpha(caracter)) {
            int esMayuscula = isupper(caracter);
            int numero = letraANumero(caracter);
            
            if (numero != -1) {
                // Aplica f⁻¹(p) = (p - desplazamiento + 26) % 26
                int nuevoNumero = (numero - desplazamiento + 26) % 26;
                mensaje[i] = numeroALetra(nuevoNumero, esMayuscula);
            }
        }
    }
}

// Función para cifrar con la escítala espartana
void cifrarEscitala(char mensaje[], int numLineas) {
    int len = strlen(mensaje);
    char cifrado[100] = {0};
    int indice = 0;

    for (int col = 0; col < numLineas; col++) {
        for (int fila = col; fila < len; fila += numLineas) {
            cifrado[indice++] = mensaje[fila];
        }
    }
    strcpy(mensaje, cifrado);
}

// Función escítala espartana
void descifrarEscitala(char mensaje[], int numLineas) {
    int len = strlen(mensaje);
    char descifrado[100] = {0};
    int indice = 0;

    int numColumnas = (len + numLineas - 1) / numLineas;

    for (int col = 0; col < numColumnas; col++) {
        for (int fila = col; fila < len; fila += numColumnas) {
            descifrado[indice++] = mensaje[fila];
        }
    }
    strcpy(mensaje, descifrado);
}

// Nueva función para mostrar información de los programadores
void mostrarInfoProgramadores() {
    printf("\n-- ING DE SISTEMAS 5TO SEMESTRE --\n");
    printf("Santiago Martinez Serna - 230222014\n");
    printf("Laura Sofia Toro Garcia - 230222021\n");
    printf("Santiago Alejandro Santacruz - 230222033\n");
    printf("-------------------------------------------\n");
}

int main() {
    int opcion, metodo;
    char mensaje[100];
    int numLineas, desplazamiento;

    do {
        printf("\n----- Menu Principal -----\n");
        printf("1. Cifrado Cesar\n");
        printf("2. Escitala Espartana\n");
        printf("3. Info Programadores\n");
        printf("0. Salir\n");
        printf("\nElige el tipo de cifrado o descifrado: ");
        scanf("%d", &metodo);
        getchar();

        if (metodo == 3) {
            mostrarInfoProgramadores();  // Llamar a la nueva función
        } else if (metodo == 1 || metodo == 2) {
            printf("\n----- Menu Cifrado/Descifrado -----\n");
            printf("1. Cifrar un mensaje\n");
            printf("2. Descifrar un mensaje\n");
            printf("3. Volver al menu anterior\n");
            printf("\nElige una opcion: ");
            scanf("%d", &opcion);
            getchar();

            if (opcion == 1 || opcion == 2) {
                if (metodo == 1) {  // Cifrado Cesar
                    printf("\nIntroduce el desplazamiento para el cifrado Cesar: ");
                    scanf("%d", &desplazamiento);
                    getchar();  // Limpiar el buffer de entrada

                    if (opcion == 1) {
                        printf("\nIntroduce el mensaje a cifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        cifrarCesar(mensaje, desplazamiento);
                        printf("Mensaje cifrado (Cesar): %s\n", mensaje);

                    } else if (opcion == 2) {
                        printf("\nIntroduce el mensaje a descifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        descifrarCesar(mensaje, desplazamiento);
                        printf("Mensaje descifrado (Cesar): %s\n", mensaje);
                    }

                } else if (metodo == 2) {  // Escítala Espartana
                    printf("Introduce el numero de lineas para la vara de la escitala: ");
                    scanf("%d", &numLineas);
                    getchar();

                    if (opcion == 1) {
                        printf("\nIntroduce el mensaje a cifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        cifrarEscitala(mensaje, numLineas);
                        printf("Mensaje cifrado (Escitala): %s\n", mensaje);

                    } else if (opcion == 2) {
                        printf("\nIntroduce el mensaje a descifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        descifrarEscitala(mensaje, numLineas);
                        printf("Mensaje descifrado (Escitala): %s\n", mensaje);
                    }
                }
            } else if (opcion == 3) {
                printf("Volviendo al menú anterior...\n");
            } else {
                printf("Opcion no válida. Intenta de nuevo.\n");
            }
        } else if (metodo == 0) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opcion no válida. Intenta de nuevo.\n");
        }

    } while (metodo != 0);

    return 0;
}
