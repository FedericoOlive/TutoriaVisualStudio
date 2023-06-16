#include <iostream>
using namespace std;

void main()
{
	srand(time(NULL));
	enum class ATAQUES
	{
		INICIO = -1, ESPADA, ARCO, MAGIA, FIN	// Espada le gana a Arco. Arco le gana a Magia. Magia le gana a Espada.
	};

	// Seteo de variable mínimo y máximo, esto permite, en caso de agregar un ataque mas,
	// solo introducirlo en el enum y agregar su comportamiento en los switchs.
	const int minAtaques = (int)ATAQUES::INICIO;
	const int maxAtaques = (int)ATAQUES::FIN;

	ATAQUES ataquePlayer = ATAQUES::INICIO;
	ATAQUES ataqueIa = ATAQUES::INICIO;
	int inputUser = 0;
	bool correctInput = false;

	do
	{
		system("cls");
		cout << "Indique su ataque:\n\n";
		cout << "1- Ataque con Espada.\n";
		cout << "2- Ataque con Arco.\n";
		cout << "3- Ataque con Magia.\n";
		cout << "Ingrese su ataque: ";

		cin >> inputUser;

		correctInput = ((inputUser > minAtaques) && (inputUser < maxAtaques));	// Extracción la condición del while para mejor lectura y comprensión.
	} while (!correctInput);
	ataquePlayer = (ATAQUES)inputUser;

	cout << "\n\n Has elegido: ";
	switch (ataquePlayer)
	{
	case ATAQUES::ESPADA:
		cout << "Espada.";
		break;
	case ATAQUES::ARCO:
		cout << "Arco.";
		break;
	case ATAQUES::MAGIA:
		cout << "Magia.";
		break;
	default:
		cout << "\n\nError en la asignacion del ataque del player!!!!!\n\n";
		system("pause");
		break;
	}

	cout << "\n\n La maquina ha elegido: ";
	{
		int randomAtaqueIA = rand() % maxAtaques;	// Mejor manera y expandible | Eliminación de Magic Number
		ataqueIa = (ATAQUES)randomAtaqueIA;
		switch (ataqueIa)
		{
		case ATAQUES::ESPADA:
			cout << "Espada.";
			break;
		case ATAQUES::ARCO:
			cout << "Arco.";
			break;
		case ATAQUES::MAGIA:
			cout << "Magia.";
			break;
		}
	}

	int ataqueJugador = (int)ataquePlayer;
	int ataqueIA = (int)ataqueIa;

	// En caso de Empate
	if (ataqueJugador == ataqueIA)
		cout << "\n\nEmpate!\n\n";

	system("pause");	// Se debe pausar la consola al terminar sino nunca se va a poder ver la ultima linea al terminar
	return;	// El main debe salir acá. Evitar cerrar en la mitad del código.
}