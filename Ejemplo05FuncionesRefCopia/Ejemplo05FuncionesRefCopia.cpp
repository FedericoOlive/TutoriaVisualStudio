#include <iostream>
using namespace std;


// Los arrays en C++ se pasan SIMEPRE a las funciones por referencia.
// No es necesario utilizar el operador & en el paso de arrays a funciones para indicar que se hace por referencia ya que siempre pasan por referencia.


void CalcularDaño(int& daño)
{
	bool dañoCritico = rand() % 2;
	if (dañoCritico == 0)
	{
		daño *= 2;
		cout << "Critico!! ";
	}
}

void SacarVida(int& vida, int daño)
{
	CalcularDaño(daño);
	vida -= daño;
	cout << "Has perdido " << daño << endl;
}

void main()
{
	int vida = 100;
	int daño = 10;

	do
	{
		cout << "--------------------------------" << endl;
		cout << "La vida es: " << vida << endl;
		SacarVida(vida, daño);
		system("pause");
		
	} while (vida > 0);

	cout << endl << endl << "Has muerto." << endl << endl;
}