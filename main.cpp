/*
 * Universidad de las Fuerzas Armadas "ESPE"
 * Enunciado: Suma de matrices-Memoria Dinamica
 * Autor: Leandro Mendoza
 * Fecha de Creacion: 14 de Noviembre del 2024
 * Fecha de Modificacion: 15 de Noviembre del 2024
 * NRC: 1978
 * Curso: Estructura de Datos
 * Docente: Edgar Fernando Solis Acosta
 */

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX = 3; // Tamaño de las matrices (constante para el programa).

// Función recursiva para sumar los elementos de dos matrices.
int sumaRecursivaMatrices(int**, int**, int, int);

int sumaRecursivaMatrices(int** mat1, int** mat2, int f, int c) {
    // Caso base: si estamos en la posición (0, 0), sumamos los elementos de ambas matrices.
    if ((f == 0) && (c == 0))
        return mat1[f][c] + mat2[f][c];
    else {
        // Mientras haya filas y columnas por recorrer.
        if (f > -1) {
            c--; // Moverse a la columna anterior.
            if (c >= -1)
                // Sumar los elementos de la posición actual y avanzar en la recursión.
                return mat1[f][c + 1] + mat2[f][c + 1] + sumaRecursivaMatrices(mat1, mat2, f, c);
            else
                // Cuando se llega al final de una fila, pasar a la fila anterior y la última columna.
                return sumaRecursivaMatrices(mat1, mat2, f - 1, MAX - 1);
        }
    }
    return 0; // Valor de retorno para evitar advertencias.
}

int main(int argc, char** argv) {
    // Asignación dinámica para las matrices.
    int** mat1 = (int**)malloc(MAX * sizeof(int*)); // Reservar memoria para las filas de la primera matriz.
    int** mat2 = (int**)malloc(MAX * sizeof(int*)); // Reservar memoria para las filas de la segunda matriz.
    for (int i = 0; i < MAX; i++) {
        mat1[i] = (int*)malloc(MAX * sizeof(int)); // Reservar memoria para las columnas de la primera matriz.
        mat2[i] = (int*)malloc(MAX * sizeof(int)); // Reservar memoria para las columnas de la segunda matriz.
    }

    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual.
    // Llenar ambas matrices con números aleatorios entre 0 y 999.
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat1[i][j] = (int)((rand() / 32768.1) * 1000); // Número aleatorio para mat1.
            mat2[i][j] = (int)((rand() / 32768.1) * 1000); // Número aleatorio para mat2.
        }
    }

    // Mostrar la primera matriz.
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat1[i][j] << "\t"; // Imprimir cada elemento de la fila.
        }
        cout << endl; // Cambiar a la siguiente fila.
    }
    cout << endl;

    // Mostrar la segunda matriz.
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat2[i][j] << "\t"; // Imprimir cada elemento de la fila.
        }
        cout << endl; // Cambiar a la siguiente fila.
    }

    // Calcular y mostrar la suma de las dos matrices utilizando la función recursiva.
    cout << "Suma de Matrices es: " << sumaRecursivaMatrices(mat1, mat2, MAX - 1, MAX - 1) << endl;

    // Liberar la memoria dinámica asignada para ambas matrices.
    for (int i = 0; i < MAX; i++) {
        free(mat1[i]); // Liberar cada fila de la primera matriz.
        free(mat2[i]); // Liberar cada fila de la segunda matriz.
    }
    free(mat1); // Liberar la memoria para las filas de la primera matriz.
    free(mat2); // Liberar la memoria para las filas de la segunda matriz.

    return 0; // Finalizar el programa.
}
//Realizar en clases este codigo, Estatica a dinamica, prueba de escritorio, prueba del deber
