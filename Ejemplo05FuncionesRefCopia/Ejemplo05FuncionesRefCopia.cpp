#include <iostream>
using namespace std;


// Los arrays en C++ se pasan SIMEPRE a las funciones por referencia.
// No es necesario utilizar el operador & en el paso de arrays a funciones para indicar que se hace por referencia ya que siempre pasan por referencia.


void CalcularDa�o(int& da�o)
{
	bool da�oCritico = rand() % 2;
	if (da�oCritico == 0)
	{
		da�o *= 2;
		cout << "Critico!! ";
	}
}

void SacarVida(int& vida, int da�o)
{
	CalcularDa�o(da�o);
	vida -= da�o;
	cout << "Has perdido " << da�o << endl;
}

void main()
{
	int vida = 100;
	int da�o = 10;

	do
	{
		cout << "--------------------------------" << endl;
		cout << "La vida es: " << vida << endl;
		SacarVida(vida, da�o);
		system("pause");
		
	} while (vida > 0);

	cout << endl << endl << "Has muerto." << endl << endl;
}