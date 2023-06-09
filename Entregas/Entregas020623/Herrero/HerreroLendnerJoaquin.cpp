#include <iostream>

using namespace std;

struct Celda
{
	int mina{};
	bool esVisible = false;
	bool estaBloqueada = false;
};

void main()
{
	srand(time(NULL));

	Celda celda;

	const int FILAS = 10;
	const int COLUMNAS = 10;
	int tablero[FILAS][COLUMNAS] = {};
	
	char bandera = 244; // ¶
	int num = 0;

	int celdaDibujada = 0;

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			celda.mina = rand() % 10;
			celda.esVisible = rand() % 2;
			celda.estaBloqueada = rand() % 2;

			celdaDibujada = rand() % 3;

			switch (celdaDibujada)
			{
			case 0:

				if (celda.mina < 5)
				{
					system("color 04");
				}

				cout << 'X';

				system("color 0f");

				break;

			case 1:

				if (celda.esVisible == false)
				{
					cout << '-';
				}
				else
				{
					num = rand() % 3 + 1;
					cout << num;
				}

				break;

			case 2:
				if (celda.estaBloqueada == true)
				{
					cout << bandera;
				}
				break;

				if (tablero[i][j] == 0)
				{
					break;
				}
			}			
		}
		cout << endl;
	}

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			cout << tablero[i][j];
		}
	}
}