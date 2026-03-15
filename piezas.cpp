#include "piezas.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const unsigned short FORMAS[5] =
{
    0x0F00, // Tipo 0 (I)
    0x0660, // Tipo 1 (O)
    0xE400, // Tipo 2 (T)
    0x8E00, // Tipo 3 (J)
    0x2E00  // Tipo 4 (L)
};

Pieza* generarPiezaAleatoria(int anchoTablero)
{
    Pieza* p = new Pieza;
    p->tipo = rand() % 5;
    p->forma = FORMAS[p->tipo];
    p->x = (anchoTablero / 2) - 2;
    p->y = -1;
    return p;
}

void rotarPieza(Pieza* p)
{
    unsigned short nuevaForma = 0;

    if (p->tipo == 1) return;

    if (p->tipo == 0)
    {
        if (p->forma == 0x0F00) nuevaForma = 0x4444;
        else nuevaForma = 0x0F00;
    }
    else
    {
        for (int f = 0; f < 3; f++)
        {
            for (int c = 0; c < 3; c++)
            {
                if ((p->forma >> (15 - (f * 4 + c))) & 1)
                {
                    int nF = c;
                    int nC = 2 - f;
                    nuevaForma |= (1 << (15 - (nF * 4 + nC)));
                }
            }
        }
    }

    p->forma = nuevaForma;
}
