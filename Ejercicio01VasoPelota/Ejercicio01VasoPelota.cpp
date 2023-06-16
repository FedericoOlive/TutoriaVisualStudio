// ReSharper disable CppTooWideScope
// ReSharper disable CppClangTidyReadabilityRedundantStringInit
// ReSharper disable CppClangTidyClangDiagnosticImplicitIntConversion

#include <iostream>		// Para usar cout y cin.
#include <time.h>		// Para el random basado en el tiempo.
#include <windows.h>	// Para los colores.
using namespace std;

/// El juego consiste en adivinar en cual vaso está la pelotita.
/// Al iniciar la partida ya estarán los 4 vasos y debemos adivinar en cual está la pelota.
/// La posición pelota deberá cancularse mediante random.
/// Hay 4 vasos: Rojo, Azul, Amarillo, Verde.

/// Consignas:
/// Usar Enums.
/// Usar Random.
/// Al ingresar una opcion la consola deberá decirte si ganaste o perdiste y en caso de perder, y poder setear la cantidad de intentos.
/// Cuando la consola te diga el vaso que elegiste debemos pintar con el color correspondiente esa linea y luego restaurarla.
/// Al terminar, preguntar si quiero volver a jugar.

void main()
{
	srand(time(NULL));

	// Variables que nunca cambian
	enum Vasos { Inicio, Rojo, Azul, Amarillo, Verde, FinVasos };
	int colorNormal = 7;
	int colorRojo = 12;
	int colorAzul = 9;
	int colorAmarillo = 14;
	int colorVerde = 10;

	// Variables del juego
	bool isWin = false;
	int intentosActuales = 0;

	// Variables Extras
	int input = 0;
	bool isPlaying = true;
	int maxIntentos = 2;
	string nombreVasoElegido = "";

	do // Bucle de reinicio de Juego
	{
		isWin = false;
		intentosActuales = 0;
		int vasoRandom = rand() % (FinVasos - 1) + 1;

		do // Bucle de Intentos
		{
			do
			{
				system("cls");
				cout << "Elija 1 de los " << FinVasos - 1 << " Vasos.\nEleccion: ";
				cin >> input;

			} while (input <= Inicio || input >= FinVasos);

			switch (input)
			{
			case Rojo:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorRojo);
				nombreVasoElegido = "Rojo";
				break;
			case Azul:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAzul);
				nombreVasoElegido = "Azul";
				break;
			case Amarillo:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAmarillo);
				nombreVasoElegido = "Amarillo";
				break;
			case Verde:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorVerde);
				nombreVasoElegido = "Verde";
				break;
			default:
				cout << "En vaso ingresado no es valido." << endl;
				break;
			}

			cout << endl << "Usted ha elegido el vaso " << nombreVasoElegido << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNormal);

			if (input == vasoRandom)
			{
				cout << "Has acertado!" << endl;
				isWin = true;
			}
			else
			{
				intentosActuales++;
				cout << "No es el vaso correcto. Te quedan " << maxIntentos - intentosActuales << " intentos." << endl;
			}

			cout << endl << endl;
			system("pause");

		} while (intentosActuales < maxIntentos && !isWin);

		do
		{
			system("cls");

			cout << "Desea Jugar Nuevamente?" << endl << endl;
			cout << "1- No, Salir." << endl;
			cout << "2- Si, Jugar Nuevamente." << endl << endl;
			cout << "Eleccion: ";
			cin >> input;
		} while (input < 1 || input > 2);

		if (input == 1)
		{
			isPlaying = false;
		}
	} while (isPlaying);
}