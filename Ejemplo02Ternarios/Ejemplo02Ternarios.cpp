#include <iostream>
#include <windows.h>
using namespace std;

///	Expresión ? ValorVerdader : ValorFalso;
///	Identificar los casos en los cuales se podría usar ternarios.

void main()
{
	int inputUser;

	cout << "Ingrese dos numeros que no sean iguales: " << endl;

	cout << "Primer Numero: ";
	cin >> inputUser;
	int primerNumero = inputUser;

	cout << "\nSegundo Numero: ";
	cin >> inputUser;
	int segundoNumero = inputUser;

	//Ternario
	int mayorNumero = (primerNumero > segundoNumero) ? primerNumero : segundoNumero;
	//                          Expresión            ? ValorVerdader : ValorFalso;

	cout << "\n\nEl mayor numero es: " << mayorNumero;
	cout << endl << endl;

	system("pause");
	system("cls");

	// ----------------------------------------------------------------------------------------------------------------------------------------

	cout << "Que dia es hoy?" << endl << endl;
	cout << "1- Lunes" << endl;
	cout << "2- Martes" << endl;
	cout << "3- Miercoles" << endl;
	cout << "4- Jueves" << endl;
	cout << "5- Viernes" << endl;
	cout << "6- Sabado" << endl;
	cout << "7- Domingo" << endl;

	cout << "Ingrese el numero: ";
	cin >> inputUser;
	cout << endl << endl;

	bool esFinDeSemana = (inputUser >= 6);
	cout << "Valor de la variable: " << esFinDeSemana;
	cout << endl << endl;

	system("pause");
	system("cls");

	// ----------------------------------------------------------------------------------------------------------------------------------------

	int adultAge = 18;
	string textResult = "No asignado";

	cout << "Ingrese su edad: ";
	cin >> inputUser;

	if (inputUser >= adultAge)
	{
		textResult = "Sos mayor de edad.";
	}
	else
	{
		textResult = "Sos menor de edad.";
	}

	// Opcion 1:
	textResult = (inputUser >= adultAge) ? "Sos mayor de edad." : "Sos menor de edad.";
	cout << textResult;

	// Opcion 2:
	cout << ((inputUser >= adultAge) ? "Sos mayor de edad." : "Sos menor de edad.");
}