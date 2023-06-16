// ReSharper disable CppCStyleCast
#include <iostream>
#include <Windows.h>
using namespace std;
const int filas = 28;
const int columnas = 28;

char dibujado[] = { 201, 205, 203, 187, 186, 250, 157, 32, 200, 188, 196, 202 };

enum TipoDeCasilla
{
	EsquinaSuperiorIzquierda,
	DobleLineaHorintal,
	DobleTSuperior,
	EsquinaSuperiorDerecha,
	DobleLineaVertical,
	Comida,
	Objeto,
	Vacio,
	EsquinaInferiorIzquierda,
	EsquinaInferiorDerecha,
	Entrada,
	DobleTInferior
};

int tableroDibujado[filas][columnas] =
{
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
	{4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4},
	{4, 5, 0, 1, 1, 3, 5, 0, 1, 1, 1, 3, 5, 4, 4, 5, 0, 1, 1, 1, 3, 5, 0, 1, 1, 3, 5, 4},
	{4, 6, 4, 7, 7, 4, 5, 4, 7, 7, 7, 4, 5, 4, 4, 5, 4, 7, 7, 7, 4, 5, 4, 7, 7, 4, 6, 4},
	{4, 5, 8, 1, 1, 9, 5, 8, 1, 1, 1, 9, 5, 8, 9, 5, 8, 1, 1, 1, 9, 5, 8, 1, 1, 9, 5, 4},
	{4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4},
	{4, 5, 0, 1, 1, 3, 5, 0, 3, 5, 0, 1, 1, 1, 1, 1, 1, 3, 5, 0, 3, 5, 0, 1, 1, 3, 5, 4},
	{4, 5, 8, 1, 1, 9, 5, 4, 4, 5, 8, 1, 1, 3, 0, 1, 1, 9, 5, 4, 4, 5, 8, 1, 1, 9, 5, 4},
	{4, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5, 4},
	{8, 1, 1, 1, 1, 3, 5, 4, 8, 1, 1, 3, 7, 4, 4, 7, 0, 1, 1, 9, 4, 5, 0, 1, 1, 1, 1, 9},
	{7, 7, 7, 7, 7, 4, 5, 4, 0, 1, 1, 9, 7, 8, 9, 7, 8, 1, 1, 3, 4, 5, 4, 7, 7, 7, 7, 7},
	{7, 7, 7, 7, 7, 4, 5, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 5, 4, 7, 7, 7, 7, 7},
	{1, 1, 1, 1, 1, 9, 5, 8, 9, 7, 0, 1, 1,10,10, 1, 1, 3, 7, 8, 9, 5, 8, 1, 1, 1, 1, 1},
	{7, 7, 7, 7, 7, 7, 5, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 5, 7, 7, 7, 7, 7, 7},
	{1, 1, 1, 1, 1, 3, 5, 0, 3, 7, 8, 1, 1, 1, 1, 1, 1, 9, 7, 0, 3, 5, 0, 1, 1, 1, 1, 1},
	{7, 7, 7, 7, 7, 4, 5, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 5, 4, 7, 7, 7, 7, 7},
	{0, 1, 1, 1, 1, 9, 5, 8, 9, 7, 0, 1, 1, 1, 1, 1, 1, 3, 7, 8, 9, 5, 8, 1, 1, 1, 1, 3},
	{4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 8, 1, 1, 3, 0, 1, 1, 9, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4},
	{4, 5, 0, 1, 1, 1, 1, 1, 3, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 0, 1, 1, 1, 1, 1, 3, 5, 4},
	{4, 5, 8, 1, 3, 7, 7, 7, 8, 1, 1, 3, 5, 4, 4, 5, 0, 1, 1, 9, 7, 7, 7, 0, 1, 9, 5, 4},
	{4, 6, 5, 5, 8, 1, 1, 1, 1, 1, 1, 9, 5, 8, 9, 5, 8, 1, 1, 1, 1, 1, 1, 9, 5, 5, 6, 4},
	{8, 1, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 1, 9},
	{0, 1, 9, 5, 0, 1, 1, 1, 3, 5, 0, 1, 1, 1, 1, 1, 1, 3, 5, 0, 1, 1, 1, 3, 5, 8, 1, 3},
	{4, 5, 5, 5, 4, 7, 7, 7, 4, 5, 8, 1, 1, 3, 0, 1, 1, 9, 5, 4, 7, 7, 7, 4, 5, 5, 5, 4},
	{4, 5, 0, 1, 9, 7, 7, 7, 4, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 4, 7, 7, 7, 8, 1, 3, 5, 4},
	{4, 5, 8, 1, 1, 1, 1, 1, 9, 5, 0, 3, 5, 8, 9, 5, 0, 3, 5, 8, 1, 1, 1, 1, 1, 9, 5, 4},
	{4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4},
	{8, 1, 1, 1, 1, 1, 1, 1, 1, 1,11,11, 1, 1, 1, 1,11,11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9}
};

void CambiarColorSegunTipoDeCasilla(int tipoCasilla)
{
	switch (tipoCasilla)
	{
	case EsquinaSuperiorIzquierda:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case DobleLineaHorintal:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		break;
	case DobleTSuperior:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case EsquinaSuperiorDerecha:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case DobleLineaVertical:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		break;
	case Comida:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		break;
	case Objeto:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		break;
	case Vacio:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case EsquinaInferiorIzquierda:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case EsquinaInferiorDerecha:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case Entrada:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case DobleTInferior:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	default: ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

void main()
{
	bool isPlaying = true;
	
	//while (isPlaying)
	{
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
				CambiarColorSegunTipoDeCasilla(tableroDibujado[i][j]);
				cout << dibujado[tableroDibujado[i][j]];
			}
			cout << "\n";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		//system("cls");
	}
}