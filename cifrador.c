#include "ejemplojni_lib_JavaCifrador.h"
#include <string.h>
#include <stdlib.h>

// Método para cifrar usando el cifrado César
JNIEXPORT jstring JNICALL Java_ejemplojni_lib_JavaCifrador_cifrarCesar
  (JNIEnv *env, jobject obj, jstring mensaje, jint desplazamiento) {
    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);
    int len = strlen(str);
    char *result = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        result[i] = str[i] + desplazamiento;
    }
    result[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    jstring encrypted = (*env)->NewStringUTF(env, result);
    free(result);

    return encrypted;
}

// Método para descifrar usando el cifrado César
JNIEXPORT jstring JNICALL Java_ejemplojni_lib_JavaCifrador_descifrarCesar
  (JNIEnv *env, jobject obj, jstring mensaje, jint desplazamiento) {
    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);
    int len = strlen(str);
    char *result = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        result[i] = str[i] - desplazamiento;
    }
    result[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    jstring decrypted = (*env)->NewStringUTF(env, result);
    free(result);

    return decrypted;
}

// Método para cifrar usando Escítala Espartana
JNIEXPORT jstring JNICALL Java_ejemplojni_lib_JavaCifrador_cifrarEscitala
  (JNIEnv *env, jobject obj, jstring mensaje, jint numLineas) {
    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);
    int len = strlen(str);
    int numColumnas = (len + numLineas - 1) / numLineas;  // Calcula el número de columnas necesario
    char *result = (char *)malloc(len + 1);

    // Rellena la matriz por filas
    int k = 0;
    for (int col = 0; col < numColumnas; col++) {
        for (int row = 0; row < numLineas; row++) {
            if (col + row * numColumnas < len) {
                result[k++] = str[col + row * numColumnas];
            }
        }
    }
    result[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    jstring encrypted = (*env)->NewStringUTF(env, result);
    free(result);

    return encrypted;
}

// Método para descifrar usando Escítala Espartana
JNIEXPORT jstring JNICALL Java_ejemplojni_lib_JavaCifrador_descifrarEscitala
  (JNIEnv *env, jobject obj, jstring mensaje, jint numLineas) {
    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);
    int len = strlen(str);
    int numColumnas = (len + numLineas - 1) / numLineas;  // Calcula el número de columnas necesario
    char *result = (char *)malloc(len + 1);

    // Rellena la matriz por columnas
    int k = 0;
    for (int row = 0; row < numLineas; row++) {
        for (int col = 0; col < numColumnas; col++) {
            if (col * numLineas + row < len) {
                result[col * numLineas + row] = str[k++];
            }
        }
    }
    result[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    jstring decrypted = (*env)->NewStringUTF(env, result);
    free(result);

    return decrypted;
}

