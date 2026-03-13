#include "piezas.h"
#include <cstdlib>
#include <ctime>
using namespace std;


const unsigned short FORMAS[7] =
    {
    0x0F00, // I: 0000 1111 0000 0000 (Fila 1 completa)
    0xCC00, // O: 1100 1100 0000 0000 (Cuadrado 2x2 arriba)
    0x4E00, // T: 0100 1110 0000 0000
    0x4460, // J: 0100 0100 0110 0000 (L invertida)
    0x2260  // L: 0010 0010 0110 0000 (L estándar)
};

Pieza* generarPiezaAleatoria(int anchoTablero)
{
    Pieza* p = new Pieza;

    p->tipo = rand() % 5;
    p->forma = FORMAS[p->tipo];

    p->x = (anchoTablero / 2) - 2;
    p->y = 0;

    return p;
}

void rotarPieza(Pieza* p)
{
    unsigned short nuevaForma = 0;
    for (int f = 0; f < 4; f++)
    {
        for (int c = 0; c < 4; c++)
        {
            int posOriginal = 15 - (f * 4 + c);
            if ((p->forma >> posOriginal) & 1)
            {
                int f_new = c;
                int c_new = 3 - f;
                int posNueva = 15 - (f_new * 4 + c_new);
                nuevaForma |= (1 << posNueva);
            }
        }
    }
    p->forma = nuevaForma;
}
