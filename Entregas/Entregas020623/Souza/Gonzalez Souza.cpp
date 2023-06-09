#include <iostream>
#include <time.h>

using namespace std;

const int SIZE = 10;

void bloques(char tablero[SIZE][SIZE]);

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

int main()
{
	srand(time(0));
	
	char tablero[SIZE][SIZE]; 

	bloques();
}

//void mines(char tablero[SIZE][SIZE])
//{
//	srand(time(0));
//
//	Cell minas;
//
//	minas.mina = rand() % SIZE;
//
//	if (minas.mina > 5)
//	{
//		int valorColor = 1;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) valorColor));
//	}
//}

void bloques(char tablero[SIZE][SIZE])
{
	srand(time(0));

	Cell bloques;

	int block = rand() % SIZE; 

	if (block > 5)
	{
		bloques.esVisible = true;
	}

	for (int i = 0; i < SIZE; i++)
	{
		tablero[i][i] = '-';
	}
}

void blocked(char tablero[SIZE][SIZE])
{
	srand(time(0));

	Cell blocked;

	int bloqueado = rand() % SIZE; 

	if (bloqueado > 5)
	{
		blocked.estaBloqueada = true; 
	}

	
}