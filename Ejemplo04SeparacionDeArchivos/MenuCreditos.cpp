#include "MenuCreditos.h"

void MenuCreditos(MenuActual& menuActual)
{
	DibujarMenuCreditos();
	system("pause");
	
	menuActual = MenuActual::Principal;
}

void DibujarMenuCreditos()
{
	system("cls");
	cout << "Menu de Creditos" << endl << endl;
	cout << "Hecho por: Alguien" << endl << endl;
}