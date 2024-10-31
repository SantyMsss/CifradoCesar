#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cifrador.h"

// transformar letra a número (A=0, B=1, ..., Z=25)
int letraANumero(char letra) {
    return isupper(letra) ? letra - 'A' : letra - 'a';
}

// transformar número a letra (0=A, 1=B, ..., 25=Z)
char numeroALetra(int numero, int esMayuscula) {
    return (char)(numero + (esMayuscula ? 'A' : 'a'));
}

// Función para cifrar el texto usando el cifrado César
JNIEXPORT jstring JNICALL Java_CifradorJNI_cifrarCesar(JNIEnv *env, jobject thisObj, jstring mensaje, jint desplazamiento) {
    const char *inputMensaje = (*env)->GetStringUTFChars(env, mensaje, NULL);
    char cifrado[strlen(inputMensaje) + 1];
    strcpy(cifrado, inputMensaje);

    for (int i = 0; i < strlen(cifrado); i++) {
        if (isalpha(cifrado[i])) {
            int esMayuscula = isupper(cifrado[i]);
            int nuevoNumero = (letraANumero(cifrado[i]) + desplazamiento) % 26;
            cifrado[i] = numeroALetra(nuevoNumero, esMayuscula);
        }
    }
    (*env)->ReleaseStringUTFChars(env, mensaje, inputMensaje);
    return (*env)->NewStringUTF(env, cifrado);
}

// Función para descifrar el texto usando el cifrado César
JNIEXPORT jstring JNICALL Java_CifradorJNI_descifrarCesar(JNIEnv *env, jobject thisObj, jstring mensaje, jint desplazamiento) {
    const char *inputMensaje = (*env)->GetStringUTFChars(env, mensaje, NULL);
    char descifrado[strlen(inputMensaje) + 1];
    strcpy(descifrado, inputMensaje);

    for (int i = 0; i < strlen(descifrado); i++) {
        if (isalpha(descifrado[i])) {
            int esMayuscula = isupper(descifrado[i]);
            int nuevoNumero = (letraANumero(descifrado[i]) - desplazamiento + 26) % 26;
            descifrado[i] = numeroALetra(nuevoNumero, esMayuscula);
        }
    }
    (*env)->ReleaseStringUTFChars(env, mensaje, inputMensaje);
    return (*env)->NewStringUTF(env, descifrado);
}

// Función para cifrar con la escítala espartana
JNIEXPORT jstring JNICALL Java_CifradorJNI_cifrarEscitala(JNIEnv *env, jobject thisObj, jstring mensaje, jint numLineas) {
    const char *inputMensaje = (*env)->GetStringUTFChars(env, mensaje, NULL);
    int len = strlen(inputMensaje);
    char cifrado[100] = {0};  // Ajustar tamaño si es necesario
    int indice = 0;

    for (int col = 0; col < numLineas; col++) {
        for (int fila = col; fila < len; fila += numLineas) {
            cifrado[indice++] = inputMensaje[fila];
        }
    }
    (*env)->ReleaseStringUTFChars(env, mensaje, inputMensaje);
    return (*env)->NewStringUTF(env, cifrado);
}

// Función para descifrar con la escítala espartana
JNIEXPORT jstring JNICALL Java_CifradorJNI_descifrarEscitala(JNIEnv *env, jobject thisObj, jstring mensaje, jint numLineas) {
    const char *inputMensaje = (*env)->GetStringUTFChars(env, mensaje, NULL);
    int len = strlen(inputMensaje);
    char descifrado[100] = {0};  // Ajustar tamaño si es necesario
    int indice = 0;

    int numColumnas = (len + numLineas - 1) / numLineas;

    for (int col = 0; col < numColumnas; col++) {
        for (int fila = col; fila < len; fila += numColumnas) {
            descifrado[indice++] = inputMensaje[fila];
        }
    }
    (*env)->ReleaseStringUTFChars(env, mensaje, inputMensaje);
    return (*env)->NewStringUTF(env, descifrado);
}

