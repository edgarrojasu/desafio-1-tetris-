#ifndef TABLERO_H
#define TABLERO_H

struct Tablero {
    int ancho;
    int alto;
    int bytesPorFila;
    unsigned char** matriz; // Puntero a punteros para memoria dinámica
};

// Prototipos de funciones
Tablero* crearTablero(int ancho, int alto);
void imprimirTablero(Tablero* t);
void liberarTablero(Tablero* t);

#endif
