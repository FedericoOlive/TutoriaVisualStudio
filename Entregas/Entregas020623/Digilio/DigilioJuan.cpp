#include <iostream>
#include <ctime>
#include <Windows.h>


using namespace std;


const int maxRows = 10;

struct Cell
{
	int mine = 0;
	bool isVisible = false;
	bool isFlagged = false;
};


void SetConsoleSize();
void PlantSeed();
void RandCells(Cell cells[10][10]);
void PrintBoard(Cell cells[10][10]);

COORD cursorPosition;
HANDLE hwnd;
int consoleWide = 70;
int consoleHeight = 25;
const int boardLenght = 10;




void main()
{
	Cell cells[boardLenght][boardLenght];
	SetConsoleSize();
	PlantSeed();
	RandCells(cells);
	PrintBoard(cells);

	cout << endl << endl << endl;

	system("pause");
}



void SetConsoleSize()
{
	SMALL_RECT rect;
	COORD coord;
	coord.X = consoleWide;
	coord.Y = consoleHeight;

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1;
	rect.Right = coord.X - 1;

	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);
	SetConsoleWindowInfo(hwnd, TRUE, &rect);


	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void PlantSeed()
{
	srand(time(0));
}

void DrawFrame(int delay)
{
	system("cls");

	cout << (char)201;

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		cout << (char)205;

		Sleep(delay);
	}

	cout << (char)187;

	cursorPosition.X = consoleWide - 1;
	cursorPosition.Y = 1;

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		SetConsoleCursorPosition(hwnd, cursorPosition);
		cout << (char)186;
		cursorPosition.Y++;
		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << (char)188;

	cursorPosition.X--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		cout << (char)205;
		cursorPosition.X--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		Sleep(delay);
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << (char)200;

	cursorPosition.Y--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		cout << (char)186 << endl;
		cursorPosition.Y--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	string imageCampus = "Fund Technology Inc";

	cursorPosition.X = (consoleWide / 2) - (imageCampus.length() / 2);
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < imageCampus.length(); i++)
	{
		cout << imageCampus[i];
		if (delay > 0)
		{
			Sleep(100);
		}
	}
	cout << (char)169;
}

void RandCells(Cell cells[10][10])
{
	int mineRandom;
	int boolRandom;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mineRandom = rand() % 10;
			boolRandom = rand() % 2;
			cells[i][j].mine = mineRandom;
			
			if (boolRandom == 0)
			{
				cells[i][j].isVisible = true;
			}

			else
			{
				boolRandom = rand() % 2;

				if (boolRandom == 0)
				{
					cells[i][j].isFlagged = true;
				}
			}
		}

	}
}

void PrintBoard(Cell cells[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (cells[i][j].isVisible)
			{
				if (cells[i][j].mine > 5)
				{
					
					SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				
				}
			
				cout << cells[i][j].mine << " ";

				cout << "\033[0m";
			}

			else if (cells[i][j].isFlagged)
			{
				cout << (char)244 << " ";
			}

			else
			{
				cout << "- ";
			}
		}

		cout << endl;
	}
}

void BoardFrame()
{
	cursorPosition.X = (consoleWide/2) - 30;
	cursorPosition.Y = (consoleHeight / 2) - 30;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << (char)201;
			}

			else if (i == 0 && j == 9)
			{
				cout << (char)200;
			}

			else
			{

			}
		}
	}
}