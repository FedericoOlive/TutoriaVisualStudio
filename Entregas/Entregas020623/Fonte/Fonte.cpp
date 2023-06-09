#include <iostream>

using namespace std;

int main()
{

	int nivel, minas, dimension;
	int cercano = 0, perdido = 1;
	int coordenadas_X, coordenadas_Y;

	srand(time(NULL));

	cout << setw(50) << "BUSCAMINAS" << endl;
	do {
		system("cls");
		cout << "SELECCIONE NIVEL DE DIFICULTAD" << endl;
		cout << "1.FACIL" << endl;
		cout << "2.INTERMEDIO" << endl;
		cout << "3.EXPERTO" << endl;
		cin >> nivel;

		switch (nivel)
		{
		case 1:
		{
			minas = 8;
			dimension = 10;
			break;
		}

		case 2:
		{
			minas = 15;
			dimension = 15;
			break;
		}

		case 3:
		{
			minas = 30;
			dimension = 20;
			break;
		}

		default:
			cout << "OPCION INVALIDA" << endl;
			break;
		}

	} while (nivel < 1 || nivel>3);

	int tablero[dimension][dimension];
	int jugada[dimension][dimension];

	for (int x = 0; x < minas; x++)
	{
		tablero[0 + rand() % dimension][0 + rand() % dimension] = 8;
	}

	for (int x = 0; x < dimension; x++)
	{
		for (int y = 0; y < dimension; y++)
		{
			jugada[x][y] = 0;
		}
	}

}