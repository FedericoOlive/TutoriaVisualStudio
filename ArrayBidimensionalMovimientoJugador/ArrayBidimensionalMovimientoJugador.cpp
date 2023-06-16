#include <iostream>
#include <ctime>

using namespace std;

struct Player
{
	char initial = 'P';
	int colPos = 0;
	int rowPos = 0;
};

const int maxRow = 5;
const int maxCol = 5;

void DrawBoard(char boardToWrite[maxRow][maxCol]);
void SetPlayerPosition(Player& player, char movement, char boardToWrite[maxRow][maxCol]);

void main()
{
	srand(time(NULL));

	char charUserInput = ' ';
	Player player;
	char board[maxCol][maxRow] = {
		{'P','+','+','+','+'},
		{'+','+','+','+','+'},
		{'+','+','+','+','+'},
		{'+','+','+','+','+'},
		{'+','+','+','+','+'}
	};

	do	// Bucle del Juego
	{
		DrawBoard(board);

		cout << "Ingrese WASD para moverse o z para salir\n";
		cout << "Eleccion: ";
		cin >> charUserInput;

		SetPlayerPosition(player, charUserInput, board);

		system("cls");
	} while (charUserInput != 'z');

	cout << "\nCerrado.\n\n";
}


void DrawBoard(char boardToWrite[maxRow][maxCol])
{
	for (int row = 0; row < maxCol; row++)
	{
		for (int col = 0; col < maxRow; col++)
		{
			cout << " " << boardToWrite[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void SetPlayerPosition(Player& player, char movement, char boardToWrite[maxRow][maxCol])
{
	if (movement == 'w')
	{
		boardToWrite[player.rowPos][player.colPos] = '+';
		player.rowPos--;
		boardToWrite[player.rowPos][player.colPos] = player.initial;
	}
	else if (movement == 'a')
	{
		boardToWrite[player.rowPos][player.colPos] = '+';
		player.colPos--;
		boardToWrite[player.rowPos][player.colPos] = player.initial;
	}
	else if (movement == 's')
	{
		boardToWrite[player.rowPos][player.colPos] = '+';
		player.rowPos++;
		boardToWrite[player.rowPos][player.colPos] = player.initial;
	}
	else if (movement == 'd')
	{
		boardToWrite[player.rowPos][player.colPos] = '+';
		player.colPos++;
		boardToWrite[player.rowPos][player.colPos] = player.initial;
	}
}