#include <iostream>
#include <string>

//No me funciona, lo que queria hacer era crear un "objeto" Cell que se guarde en cada posicion del tablero para luego acceder a ella y poder imprimir lo que corresponde
//pero me saltan un monton de errores por lo que algo de lo que quiero hacer probablemente no funciona asi pero no tuve tiempo de arreglarlo. Esta terrible

using namespace std;

const int maxCant = 10;
Cell tablero[maxCant][maxCant];

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

Cell CrearCelda();
void CompletarArray(Cell tablero[maxCant][maxCant]);

void main()
{
	CompletarArray(tablero);
}

void CompletarArray(Cell tablero[maxCant][maxCant])
{
	for (int i = 0; i < maxCant; i++)
	{
		for (int j = 0; j < maxCant; j++)
		{
			Cell celda = CrearCelda();
			tablero[j][i] = celda;
			
			if (tablero[j][i].esVisible == true)
			{
				cout << tablero[j][i].mina << "\t";
			}
			else
			{
				cout << "-\t";
			}
		}
	}
}

Cell CrearCelda()
{
	int mina = rand() % 10;
	int val1 = (rand() % 2) + 1;
	int val2 = (rand() % 2) + 1;
	bool esVisible = false;
	bool estaBloqueada = false;

	if (val1 == 1)
		esVisible = true;

	if (val2 == 1)
		estaBloqueada = true;

	return { mina, esVisible, estaBloqueada };
}
