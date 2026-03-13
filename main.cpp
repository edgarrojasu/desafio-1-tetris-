#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "piezas.h"

using namespace std;

int main() {
    // 1. Inicialización de la semilla para números aleatorios
    srand(time(0));

    int ancho, alto;
    cout << "--- DESAFIO 1: TETRIS BITWISE ---" << endl;
    ancho=anchura();
    alto=altura();

    Tablero* miTablero = crearTablero(ancho, alto);
    Pieza* piezaActual = generarPiezaAleatoria(ancho);

    char entrada = ' ';
    bool jugando = true;

    while (jugando) {
        system("cls");

        imprimirTodo(miTablero, piezaActual);

        cout << "Pieza actual tipo: " << piezaActual->tipo << " en X: " << piezaActual->x << endl;

        cin >> entrada;
        entrada = toupper(entrada);

        switch (entrada) {
        case 'A': piezaActual->x--; break;
        case 'D': piezaActual->x++; break;
        case 'W':
            rotarPieza(piezaActual);
            break;
        case 'S': piezaActual->y++; break;
        case 'Q': jugando = false; break;
        default: break;
        }

    }

    liberarTablero(miTablero);
    delete piezaActual;

    cout << "Gracias por jugar!" << endl;
    return 0;
}
