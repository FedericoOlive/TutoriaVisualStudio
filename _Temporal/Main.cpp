#include <iostream>
using namespace std;


void main3() // Piramide de Arrar de String
{
	string names[6] = {
		"0Nombre0",
		"1Nombre1",
		"2Nombre2",
		"3Nombre3",
		"4Nombre4",
		"5Nombre5",
	};
	string spacingX5 = "     ";
	string spacingX4 = "    ";

	cout << "LvL 1: \t";
	cout << names[0][0] << names[0][1] << names[0][2] << spacingX5 << names[1][0] << names[1][1] << names[1][2] << spacingX5 << names[2][0] << names[2][1] << names[2][2] << "\n\n";
	cout << "LvL 2: \t";
	cout << spacingX4 << names[3][0] << names[1][1] << names[1][2] << spacingX5 << names[4][0] << names[4][1] << names[4][2] << "\n\n";
	cout << "LvL 3: \t";
	cout << spacingX4 << spacingX4 << names[5][0] << names[5][1] << names[5][2] << "\n\n";
}