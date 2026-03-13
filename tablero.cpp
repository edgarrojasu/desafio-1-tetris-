#include <iostream>
#include "tablero.h"
#include "piezas.h"
using namespace std;

int altura()
{
    int alto;
    while(true)
    {
        cout << "Alto: ";
        cin >> alto;
        if (alto>=8)
        {
            return alto;
        }
        else
        {
            cout<<endl<<"El numero debe ser mayor o igual a 8"<<endl;
        }
    }
}

int anchura()
{
    int ancho;
    while(true)
    {
        cout << "Ancho (multiplo de 8): ";
        cin >> ancho;
        if (ancho%8==0)
        {
            return ancho;
        }
        else
        {
            cout<<endl<<"El numero debe ser multiplo de 8"<<endl;
        }
    }
}

Tablero* crearTablero(int ancho, int alto)
{
    Tablero* t = new Tablero;
    t->ancho = ancho;
    t->alto = alto;
    t->bytesPorFila = ancho / 8;

    t->matriz = new unsigned char*[alto];
    for (int i = 0; i < alto; i++)
    {
        t->matriz[i] = new unsigned char[t->bytesPorFila];

        for (int j = 0; j < t->bytesPorFila; j++)
        {
            t->matriz[i][j] = 0;
        }
    }
    return t;
}

void liberarTablero(Tablero* t)
{
    for (int i = 0; i < t->alto; i++)
    {
        delete[] t->matriz[i];
    }
    delete[] t->matriz;
    delete t;
}

void imprimirTablero(Tablero* t)
{

    for (int i = 0; i < t->alto; i++)
    {
        cout << "|";
        for (int j = 0; j < t->bytesPorFila; j++)
        {
            unsigned char byteActual = t->matriz[i][j];

            for (int bit = 7; bit >= 0; bit--)
            {

                if ((byteActual >> bit) & 1)
                {
                    cout << "#";
                } else
                {
                    cout << ".";
                }
            }
        }
        cout << "|" << endl;
    }

    for (int k = 0; k < t->ancho + 2; k++) cout << "-";
    cout << endl;
}


void imprimirTodo(Tablero* t, Pieza* p) {
    system("cls");
        cout << "Controles: [A] Izq, [D] Der, [S] Bajar, [W] Rotar, [Q] Salir" << endl;

    for (int i = 0; i < t->alto; i++)
    {
        cout << "|";
        for (int j = 0; j < t->bytesPorFila; j++)
        {
            unsigned char byteTablero = t->matriz[i][j];
            unsigned char byteParaImprimir = byteTablero;

            if (i >= p->y && i < p->y + 4)
            {
                int filaRelativaPieza = i - p->y;

                unsigned short mascaraFila = (p->forma >> (12 - (filaRelativaPieza * 4))) & 0xF;

                for (int bitPieza = 0; bitPieza < 4; bitPieza++)
                {
                    int colGlobalPieza = p->x + bitPieza;
                    if (colGlobalPieza >= j * 8 && colGlobalPieza < (j + 1) * 8)
                    {
                        if ((mascaraFila >> (3 - bitPieza)) & 1)
                        {
                            int bitEnByte = 7 - (colGlobalPieza % 8);
                            byteParaImprimir |= (1 << bitEnByte);
                        }
                    }
                }
            }

            for (int bit = 7; bit >= 0; bit--)
            {
                if ((byteParaImprimir >> bit) & 1) cout << "#";
                else cout << ".";
            }
        }
        cout << "|" << endl;
    }
    for (int k = 0; k < t->ancho + 2; k++) cout << "-";
    cout << endl;
}
