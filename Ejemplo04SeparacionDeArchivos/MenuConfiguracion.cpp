#include "MenuConfiguracion.h"

void MenuConfiguracion(MenuActual& menuActual)
{
	int input = 0;
	do
	{
		DibujarMenuConfiguraciones();
		cin >> input;
	} while (input != 4);
	
	menuActual = MenuActual::Principal;
}

void DibujarMenuConfiguraciones()
{
	system("cls");
	cout << "Menu de Configuraciones." << endl << endl;
	cout << "1- Opcion 1." << endl;
	cout << "2- Opcion 2." << endl;
	cout << "3- Opcion 3." << endl;
	cout << "4- Volver." << endl;
}