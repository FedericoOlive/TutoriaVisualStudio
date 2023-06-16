#include "Juego.h"

void Juego(MenuActual& menuActual)
{
	bool isPlaying = true;
	int playerInput = 0;

	do
	{
		system("cls");
		cout << "Se esta jugando...(Ingrese 0 para salir)" << endl << endl;
		cin >> playerInput;

		if (playerInput == 0)
			isPlaying = false;

	} while (isPlaying);

	menuActual = MenuActual::Principal;
}
