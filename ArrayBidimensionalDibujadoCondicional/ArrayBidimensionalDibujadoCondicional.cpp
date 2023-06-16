#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

const int maxMatriz = 20;
int matriz[maxMatriz][maxMatriz];

void ResetBoard(int maxCol, int maxFil);
void DrawTop(int maxCol, char esqSupIzq, char barrHor, char esqSupDer, char barrSupUni);
void DrawBoard(int maxCol, int maxFil);

int main()
{
	srand(time(NULL));

	int board[10][20];
	int board2[10][20] = { 0 };

	int i = 0;
	
	int maxMinas = 10;
	
	for (int i = 0; i < maxMinas; ++i)
	{		
		int minax = rand() % 20;
		int minaY = rand() % 20;

		minaY *= 2;
	}

	system("pause");
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // Maximiza la consola
	srand(time(nullptr));
	int maxCol = 10;
	int maxFil = 5;
	
	ResetBoard(maxCol, maxFil);	
	DrawBoard(maxCol, maxFil);	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	return 0;
}

void ResetBoard(int maxCol, int maxFil)
{
	for (int i = 0; i < maxFil; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			matriz[i][j] = 0;
		}
	}
}

void DrawTop(int maxCol, char esqSupIzq, char barrHor, char esqSupDer, char barrSupUni)
{
	cout << esqSupIzq;

	for (int i = 0; i < maxCol * 3 + maxCol; i++)
	{
		cout << (i % 4 == 3 ? barrSupUni : barrHor);
	}
	cout << "\b" << esqSupDer << "\n";
}

void DrawBoard(int maxCol, int maxFil)
{
	char ESI = 201;		// Esquina superior Izquierda: ╔
	char LBH = 205;		// Barra Horizontal: ═
	char ESD = 187;		// Esquina superior Derecha: ╗
	char LBV = 186;		// Barra Lateral: ║
	char TBS = 203;		// Barra Superior union: ╦
	char TBUJ = 202;	// Barra Inferior union: ╩
	char UNI = 206;		// Union ╬
	char TBD = 204;		// Union ╠
	char TBI = 185;		// Union ╣
	char EID = 200;		// Esquina Inferior Derecha: ╚
	char EII = 188;		// Esquina Inferior Izquierda: ╝

	DrawTop(maxCol, ESI, LBH, ESD, TBS);

	for (int i = 0; i < maxFil; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			cout << LBV;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80 + matriz[i][j] * 16);
			cout << " " << matriz[i][j] << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		cout << LBV;
		cout << "\n";

		if (i < maxFil - 1)
		{
			cout << TBD;
			for (int j = 0; j < maxCol; j++)
			{
				cout << LBH << LBH << LBH << UNI;
			}
			cout << "\b" << TBI << "\n";
		}
		else
		{
			cout << EID;
			for (int j = 0; j < maxCol; j++)
			{
				cout << LBH << LBH << LBH << TBUJ;
			}
			cout << "\b" << EII << "\n";
		}
	}
}