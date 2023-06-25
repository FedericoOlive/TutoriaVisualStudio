#include <iostream>
//#include <Windows.h> No incluir porque choca con la funcion max()

void main()
{
	char input = ' ';

	while (true)
	{
		std::cout << "\n\n";
		std::cin >> input;

		bool isAlpha = isalpha(input);
		bool isDigit = isdigit(input);

		if (isAlpha)
			std::cout << "Es alpha\n";
		else
			std::cout << "NO Es alpha\n";

		if (isDigit)
			std::cout << "Es digit\n";
		else
			std::cout << "NO digit\n";
	}


	// Clear de bufer de teclado (cin)
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}