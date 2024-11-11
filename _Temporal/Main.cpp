/*#include <iostream>
#include <time.h>
using namespace std;

const int sizeArray = 10;
struct Circle
{
	float radio = 0;
	float area = 0;
	float perim = 0;
};

void TP03_EJ02_C();
void Temp1();
void Temp2();
void Temp3();
void Temp4();
void Temp5();
void Temp5A(int arrayToFix[sizeArray]);
Circle Temp4A(Circle& circle);

void main()
{
	TP03_EJ02_C();
}


void Temp5()
{
	int myArr[sizeArray] = { 0 };
	Temp5A(myArr);

}

void Temp5A(int arrayToFix[sizeArray])
{
	
}

void Temp4()
{
	Circle myCircle;
	myCircle.radio = 10;
	Temp4A(myCircle);

	cout << "";
}


Circle Temp4A(Circle& circle)
{
	circle.area = 3.14f * circle.radio * circle.radio;
	circle.perim = 3.14f * (circle.radio * 2);

	return circle;
}

void Temp3()
{
	struct Slot
	{
		int cellType = 0;
		char letter = 'O';
	};

	const int sizeX = 8;
	const int sizeY = 8;
	Slot tableboard[sizeY][sizeX];

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			cout << tableboard[i][j].letter;
		}
		cout << "\n";
	}
}

void Temp2()
{
	srand(time(nullptr));
	const int sizeArr = 30;
	int numbers[sizeArr] = { 0 };

	for (int i = 0; i < sizeArr; i++)
	{
		bool isWrongValue;
		int number;
		do
		{
			isWrongValue = false;
			number = rand() % 91 + 10;
			for (int j = 0; j < sizeArr; j++)
			{
				if (number == numbers[j])
				{
					isWrongValue = true;
					break;
				}
			}
		}
		while (isWrongValue);

		numbers[i] = number;
		cout << numbers[i] << " ";
	}

	cout << "\n";
	int minPrinted = 0;
	for (int i = 0; i < sizeArr; i++)
	{
		int min = 999;
		for (int j = 0; j < sizeArr; j++)
		{
			if (numbers[j] < min && numbers[j] > minPrinted)
				min = numbers[j];
		}

		minPrinted = min;
		cout << min << " ";
	}
}

void Temp1()
{
	const int sizeX = 30;
	const int sizeY = 20;
	char tableboard[sizeY][sizeX] = {};

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if(i== sizeY/2 -1&& j == sizeX / 2-1)
				tableboard[i][j] = 'X';
			else if (i == 0 && j == 0)
				tableboard[i][j] = 201;
			else if (i == 0 && j == sizeX - 1)
				tableboard[i][j] = 187;
			else if (i == sizeY - 1 && j == 0)
				tableboard[i][j] = 200;
			else if (i == sizeY - 1 && j == sizeX - 1)
				tableboard[i][j] = 188;
			else if (i == 0 || i == sizeY - 1)
				tableboard[i][j] = 205;
			else if (j == 0 || j == sizeX - 1)
				tableboard[i][j] = 186;
			else
				tableboard[i][j] = '_';
		}
	}

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			cout << tableboard[i][j];
		}
		cout << "\n";
	}

	cin.get();
}





void TP03_EJ02_C()
{
	const int maxArr = 5;
	int myArr[maxArr] = { 3, 2, 1, 5, 0 };


	for (int i = 0; i < maxArr; i++)
	{
		cout << myArr[i] << ", ";
	}
	cout << "\n\n";

	int lastMin = INT_MIN;

	for (int i = 0; i < maxArr; ++i)
	{
		int min = INT_MAX;
		for (int j = 0; j < maxArr; j++)
			if (myArr[j] > lastMin && myArr[j] < min)
				min = myArr[j];

		lastMin = min;
		cout << min << ", ";
	}

	/// Buscar el menor
	/// Imprimirlo
	/// Buscar el menor y mayor al ultimo encontrado
	///	Imprimirlo
}*/