/// Tengo 5 Jugadores y quiero guardar sus Stats de cada Mes
/// Sus Stats consisten en: "HorasJugadas" y "ClicksEnPantalla"
/// Tengo un Array "Stats" en la que quiero guardar estos datos:
#include <iostream>
#include <ctime>
using namespace std;
const int maxRows = 5;
const int maxCols = 12;
struct Stats
{
	float horasJugadas = 0;
	int clicksEnPantalla = 0;
};
void main()
{
	srand(time(NULL));
	Stats stats[maxRows][maxCols];
	int userInput = 0;
	// Seteo El Array
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			stats[i][j].horasJugadas = (rand() % 100) / 10.0f;
			stats[i][j].clicksEnPantalla = rand() % 100;
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
		cout << "\n\n";
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
					cout << "\t" << stats[i][j].horasJugadas;
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
					cout << "\t" << stats[i][j].clicksEnPantalla;
				}
				cout << "\n";
			}
		}
		cout << "\n\n\n";
		system("pause");
	} while (userInput != 0);
}
/// Ejercicio de 30m:
/// Hacer lo mismo pero con los valores de una celda del buscaminas.
/// Los valores de las celtas tendràn que ser los siguientes:
struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};
/// Objetivo: 
/// Array bidimensional de 10x10.
/// Que se randomice las 3 variables.
/// Mostrar el tablero separando de la misma manera en la que fue explicado.
/// Las condiciones de dibujado son:
///		mina: de 0 a 9. Si mina es mayor a 5, se pinta la letra de rojo y el fondo negro.
///		esVisible: Si es falso dibujo "-" en vez del valor.
///		estaBloqueada: Se dibuja un "¶" en vez del valor. 244 = ¶