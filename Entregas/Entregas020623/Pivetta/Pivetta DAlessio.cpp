#include <iostream>
#include <cmath>

using namespace std;

const int rowTabla = 10;
const int columnTabla = 10;
void GameLogic();
void tableMaker(char table[rowTabla][columnTabla]);

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

void main()
{
	GameLogic();
}

void GameLogic()
{
	char tabla[rowTabla][columnTabla] = {};

	tableMaker(tabla);
}

void tableMaker(char table[rowTabla][columnTabla])
{
	for (int i = 0; i < rowTabla; i++)
	{
		cout << i + 1;
	}
}
