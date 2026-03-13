#ifndef PIEZAS_H
#define PIEZAS_H

struct Pieza {
    unsigned short forma;
    int x;
    int y;
    int tipo;
};

// --- Prototipos de funciones ---
Pieza* generarPiezaAleatoria(int anchoTablero);
void rotarPieza(Pieza* p);

#endif // PIEZAS_H
