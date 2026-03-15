#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "piezas.h"

using namespace std;

int main()
{
    srand(time(0));

    int ancho, alto;
    cout << "--- DESAFIO 1: TETRIS BITWISE ---" << endl;
    ancho=anchura();
    alto=altura();

    Tablero* miTablero = crearTablero(ancho, alto);
    Pieza* piezaActual = generarPiezaAleatoria(ancho);
    piezaActual->y = -1;

    char entrada = ' ';
    bool jugando = true;

    while (jugando)
    {
        system("cls");

        imprimirTodo(miTablero, piezaActual);

        cout << "Pieza actual tipo: " << piezaActual->tipo << " en X: " << piezaActual->x << endl;

        cin >> entrada;
        entrada = toupper(entrada);

        switch (entrada)
        {
            case 'A':
            {
                piezaActual->x--;
                if (!validarPosicion(miTablero, piezaActual))
                    piezaActual->x++;
                break;
            }
            case 'D':
            {
                piezaActual->x++;
                if (!validarPosicion(miTablero, piezaActual))
                piezaActual->x--;
                break;
            }
            case 'W':
            {
                unsigned short formaAnterior = piezaActual->forma;
                rotarPieza(piezaActual);
                if (!validarPosicion(miTablero, piezaActual))
                piezaActual->forma = formaAnterior;
                break;
            }
            case 'S':
            {
                piezaActual->y++;
                if (!validarPosicion(miTablero, piezaActual))
                    piezaActual->y--;
                break;
            }
            case 'Q': jugando = false; break;
            default: break;
        }

    }

    liberarTablero(miTablero);
    delete piezaActual;

    cout << "Gracias por jugar!" << endl;
    return 0;
}
