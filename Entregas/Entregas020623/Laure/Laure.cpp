#include <iostream>
#include <Windows.h>
using namespace std;



struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

const int SIDE_SIZE = 10;
int GetRandomNumber(int base, int max);

void main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	srand(time(0));

	Cell board[SIDE_SIZE][SIDE_SIZE];

	for (int i = 0; i < SIDE_SIZE; i++)
	{
		for (int j = 0; j < SIDE_SIZE; j++)
		{
			board[i][j].mina = GetRandomNumber(0, 9);
			board[i][j].esVisible = static_cast<bool>(GetRandomNumber(0, 1));
			board[i][j].estaBloqueada = static_cast<bool>(GetRandomNumber(0, 1));

			if (board[i][j].esVisible && !board[i][j].estaBloqueada)
			{
				if (board[i][j].mina > 5)
				{
					SetConsoleTextAttribute(handle, 4);
					cout << board[i][j].mina;
					SetConsoleTextAttribute(handle, 7);
				}
				else
				{
					cout << board[i][j].mina;
				}
			}
			else if (!board[i][j].esVisible)
			{
				cout << "-";
			}
			else if (board[i][j].estaBloqueada)
			{
				char flag = 244;
				cout << flag;
			}
			cout << "\t";
		}
		cout << "\n\n\n";
	}
}

int GetRandomNumber(int base, int max)
{
	if (base == 0)
		return rand() % (max + 1);
	else
		return rand() % max + base;
}