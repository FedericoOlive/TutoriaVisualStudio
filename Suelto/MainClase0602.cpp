/// Tengo 5 Jugadores y quiero guardar sus stats cada 1ro de cada mes
/// Sus Stats consisten en: "HorasJugadas", "ClicksEnPantalla", "
/// Tengo una base de datos "Database" en la que quiero guardar los 

#include <iostream>
#include <ctime>
using namespace std;

const int maxRows = 5;
const int maxCols = 12;

struct Database
{
	float horasJugadas = 0;
	int clicksEnPantalla = 0;
};

void main()
{
	srand(time(NULL));
	Database database[maxRows][maxCols];
	int userInput = 0;

	// Seteo El Array
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			database[i][j].horasJugadas = (rand() % 100) / 10.0f;
			database[i][j].clicksEnPantalla = rand() % 100;
		}
	}

	// Bucle
	do
	{
		system("cls");
		cout << "0- Salir\n";
		cout << "1- Mostrar Horas\n";
		cout << "2- Mostrar Clicks\n\n";
		cout << "Eleccion: ";
		cin >> userInput;		

		if (userInput == 1)
		{
			cout << "Jug/Mes";
			for (int j = 0; j < maxCols; j++)
			{
				cout << "\t" << j + 1;
			}
			cout << "\n";

			for (int i = 0; i < maxRows; i++)
			{
				cout << i;
				for (int j = 0; j < maxCols; j++)
				{
					cout << "\t" << database[i][j].horasJugadas;
				}
				cout << "\n";
			}
		}
		else if (userInput == 2)
		{
			cout << "Jug/Mes";
			for (int j = 0; j < maxCols; j++)
			{
				cout << "\t" << j + 1;
			}
			cout << "\n";

			for (int i = 0; i < maxRows; i++)
			{
				cout << i;
				for (int j = 0; j < maxCols; j++)
				{
					cout << "\t" << database[i][j].clicksEnPantalla;
				}
				cout << "\n";
			}
		}

		cout << "\n\n\n";
		system("pause");
	} while (userInput != 0);
}