#include "MenuSalir.h"

enum MenuSalida { Salir = 1, Continuar };

void MenuSalir(MenuActual& menuActual, bool& enJuego)
{
	int input = 0;
	do
	{
		DibujarMenuSalir();
		cin >> input;
	} while (input < Salir || input > Continuar);

	if (input == Salir)
		enJuego = false;
	else if (input == Continuar)
		menuActual = MenuActual::Principal;
}

void DibujarMenuSalir()
{
	system("cls");
	cout << "Menu Salir:" << endl << endl;
	cout << "1- Salir" << endl;
	cout << "2- Continuar Jugando" << endl << endl;
}