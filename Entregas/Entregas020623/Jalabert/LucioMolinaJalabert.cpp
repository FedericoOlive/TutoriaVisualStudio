#include<iostream>
#include <cstdlib>

using namespace std;

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

const int row = 10;
const int column = 10;

int board[row][column];

void drawHorizontalSeparater();
void drawSeparatedValues(int row);
void printboard();
void gameplay();

void main()
{
	gameplay();
}

void drawHorizontalSeparater() 
{
	for (int i = 0; i < 10; i++) 
	{
		cout << " ---";
	}
	cout << endl;
}

void drawSeparatedValues(int row) 
{
	cout << "|";

	for (int col = 0; col < 10; col++) 
	{
		board[row][col] = ' ';

		cout << " " << board[row][col] << " |";
	}
	cout << endl;
}

void printboard()
{
	drawHorizontalSeparater();
	for (int row = 0; row < 10; row++) 
	{
		drawSeparatedValues(row);
		drawHorizontalSeparater();
	}
}

void gameplay()
{
	srand(time(NULL));
	int i = 0;

	printboard();



}