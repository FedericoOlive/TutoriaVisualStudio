#include "MenuManager.h"

void MenuManager()
{
	bool enJuego = true;
	MenuActual menuActual = MenuActual::Principal;
	do
	{
		switch (menuActual)
		{
		case MenuActual::Principal:
			MenuPrincipal(menuActual);
			break;
		case MenuActual::Juego:
			Juego(menuActual);
			break;
		case MenuActual::Configuracion:
			MenuConfiguracion(menuActual);
			break;
		case MenuActual::Creditos:
			MenuCreditos(menuActual);
			break;
		case MenuActual::Salir:
			MenuSalir(menuActual, enJuego);
			break;
		default:
			menuActual = MenuActual::Principal;
			break;
		}
	} while (enJuego);
}