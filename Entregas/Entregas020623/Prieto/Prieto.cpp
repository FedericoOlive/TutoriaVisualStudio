#include <iostream>

using namespace std;

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

void printBoard();

const int rows = 10;
const int columns = 10;
int board[rows][columns];

int main()
{
	srand(time(0));
	printBoard();
}

void createMine(Cell mine)
{
	int valorMina = rand() % 10;
	mine.mina = valorMina;
}

void printBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "\t" << board[i][j];
		}
		cout << endl;
	}
}