#include "tablero.h"
#include <iostream>

Tablero* crearTablero(int ancho, int alto) {
    Tablero* t = new Tablero;
    t->ancho = ancho;
    t->alto = alto;
    t->bytesPorFila = ancho / 8; // Suponiendo que el ancho es múltiplo de 8

    // Reserva de memoria dinámica
    t->matriz = new unsigned char*[alto];
    for (int i = 0; i < alto; i++) {
        t->matriz[i] = new unsigned char[t->bytesPorFila];
        // Inicializar la fila en 0 (vacío)
        for (int j = 0; j < t->bytesPorFila; j++) {
            t->matriz[i][j] = 0;
        }
    }
    return t;
}

void liberarTablero(Tablero* t) {
    for (int i = 0; i < t->alto; i++) {
        delete[] t->matriz[i];
    }
    delete[] t->matriz;
    delete t;
}
