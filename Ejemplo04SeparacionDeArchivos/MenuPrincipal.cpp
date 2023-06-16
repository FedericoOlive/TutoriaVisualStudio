#include "MenuPrincipal.h"

void MenuPrincipal(MenuActual& menuActual)
{
	int input = 0;
	do
	{
		DibujarMenuPrincipal();
		cin >> input;
	} while (input < 0 || input > 4);
	
	menuActual = (MenuActual)input;
}

void DibujarMenuPrincipal()
{
	system("cls");
	cout << "Menu Principal: " << endl << endl;
	cout << "1- Jugar." << endl;
	cout << "2- Configuraciones." << endl;
	cout << "3- Creditos" << endl;
	cout << "4- Salir" << endl;
	cout << endl;
}