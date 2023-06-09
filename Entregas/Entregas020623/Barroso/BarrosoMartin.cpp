#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//No termine el ejercicio porque falte las ultimas dos clases de fundamentos + el feriado. Con lo cual me perdi bastante info de los structs y arrays bidimensaionales

int main()
{
	std::cout << "Hello World!\n";
}


struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

int board{
	int maxRow = 10;
	int maxCol = 10;
	int  board[maxRow][maxCol] = { {mina, esVisible, estaBloqueada} };

	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			mina = srand / 2
				cout << i << " " << j << board[i][j] << endl;;
		}
	}
}

void mine{

	int colorMine = srand / 9 + 1;
	if (colorMine > 5)
	{
		//se pinta de rojo y el fondo negro
	}
	if (esVisible == false)
	{
		//se dibuja un -
	}
	if (estaBloqueada == true)
	{
		// se dibuja un ¶
	}
}