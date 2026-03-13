#ifndef TABLERO_H
#define TABLERO_H

struct Pieza;

struct Tablero {
    int ancho;
    int alto;
    int bytesPorFila;
    unsigned char** matriz;
};

// --- Prototipos ---
Tablero* crearTablero(int ancho, int alto);
void liberarTablero(Tablero* t);
void imprimirTodo(Tablero* t, Pieza* p);
int anchura();
int altura();


#endif
