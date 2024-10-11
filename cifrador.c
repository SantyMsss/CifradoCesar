#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Función para descifrar el texto usando f a la -1 (p) = (p - 3) mod 26
void descifrarCesar(char mensaje[]) {
    for (int i = 0; i < strlen(mensaje); i++) {
        char caracter = mensaje[i];
        
        if (isalpha(caracter)) {
            int esMayuscula = isupper(caracter); 
            int numero = letraANumero(caracter);
            
            if (numero != -1) {
                // Aplica f⁻¹(p) = (p - 3 + 26) % 26
                int nuevoNumero = (numero - 3 + 26) % 26; 
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

int main() {
    int opcion, metodo;
    char mensaje[100];
    int numLineas; 

    do {

        printf("\n----- Menu Principal -----\n");
        printf("1. Cifrado Cesar\n");
        printf("2. Escitala Espartana\n");
        printf("3. Salir\n");
        printf("\nElige el tipo de cifrado o descifrado: ");
        scanf("%d", &metodo);
        getchar(); 

        if (metodo == 1 || metodo == 2) {

            printf("\n----- Menu Cifrado/Descifrado -----\n");
            printf("1. Cifrar un mensaje\n");
            printf("2. Descifrar un mensaje\n");
            printf("3. Volver al menu anterior\n");
            printf("\nElige una opcion: ");
            scanf("%d", &opcion);
            getchar();  

            if (opcion == 1 || opcion == 2) {
             
                if (metodo == 1) {
                    if (opcion == 1) {
                       
                        printf("\nIntroduce el mensaje a cifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        cifrarCesar(mensaje);
                        printf("Mensaje cifrado (Cesar): %s\n", mensaje);

                    } else if (opcion == 2) {
                     
                        printf("\nIntroduce el mensaje a descifrar: ");
                        fgets(mensaje, sizeof(mensaje), stdin);
                        mensaje[strcspn(mensaje, "\n")] = 0;

                        descifrarCesar(mensaje);
                        printf("Mensaje descifrado (Cesar): %s\n", mensaje);
                    }

                } else if (metodo == 2) { 
                  
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
        } else if (metodo == 3) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opcion no válida. Intenta de nuevo.\n");
        }

    } while (metodo != 3);  

    return 0;
}
