/*
Ejercicio 01:
● Simular un estante de regalos en donde cada una de las persona solo puede tomar una cantidad
random de 5 a 8 objetos.
● Una vez que junta su cantidad de objetos, se va por donde vino.
● Al volver, empieza otra persona y sigue recogiendo objetos hasta juntar todos los objetos que puede
llevar. Repetir esto hasta que se vacíe el estante.
● Replicar el ejecutable: de este Link
● En total son 10 lugares. Cada lugar puede tener de 0 a 4 objetos (siendo 0 que no hay objetos en ese
lugar del estante).
● La persona está representada con ‘ß’.
● Se contabilizan los objetos de la persona y los objetos en total y las personas que se retiraron con
objetos.
*/






#include <iostream>
#include <ctime>
using namespace std;


void main()
{
	srand(time(NULL));

	const int wallBL = 200;//	╚
	const int wallV = 186;//	║
	const int wallH = 205;//	═ 
	const int wallBR = 188;//	╝
	const int wallTR = 187;//	╗
	const int wallTL = 201;//	╔

	const char customer = 225;
	const char empty = 32;
	const int MIN_INVENTORY = 5;
	const int MAX_INVENTORY = 8;
	const int MAX_SHELF_CONTENTS = 4;
	const int MAX_LENGTH = 10;
	int totalContents = 0;
	int gifts[MAX_LENGTH] = { 0 };
	int aisle[MAX_LENGTH] = { 0 };
	int customerPos = 0;
	int giftSlots = rand() % (MAX_INVENTORY - MIN_INVENTORY) + MIN_INVENTORY + 1; // 5 - 8
	int giftsTaken = 0;
	int giftsAtCounter = 0;
	int clientCount = 0;
	bool isEmpty = false;
	bool playing = true;
	int gridPlus = 2;

	//INIT
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		gifts[i] = rand() % (MAX_SHELF_CONTENTS + 1); // 0-5
		totalContents += gifts[i];
	}
	//DRAW
	for (int i = 0; i < MAX_LENGTH + gridPlus; i++)
	{
		if (i == 0)
			cout << (char)wallTL;
		else if (i == 11)
			cout << (char)wallTR;
		else
			cout << (char)wallH;
	}
	cout << endl;
	cout << (char)wallV;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (gifts[i] > 0)
			cout << gifts[i];
		else
			cout << 0;
	}
	cout << (char)wallV;
	cout << endl;
	cout << (char)wallV;

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (i == customerPos)
			cout << customer;
		else
			cout << empty;
	}
	cout << (char)wallV;

	cout << endl;
	for (int i = 0; i < MAX_LENGTH + gridPlus; i++)
	{
		if (i == 0)
			cout << (char)wallBL;
		else if (i == 11)
			cout << (char)wallBR;
		else
			cout << (char)wallH;
	}
	cout << endl;
	cout << "La persona tiene " << giftsTaken << " de " << giftSlots << endl;
	cout << "Los items dejados son: " << giftsAtCounter << endl;
	cout << "Personas en total: " << clientCount << endl;
	system("pause");
	while (playing)
	{
		//UPDATE
		isEmpty = gifts[customerPos] <= 0;

		if (giftsTaken < giftSlots && totalContents > 0)
		{
			customerPos++;
			
			if (giftsTaken + gifts[customerPos - 1] <= giftSlots)
			{
				giftsTaken += gifts[customerPos - 1];
				totalContents -= gifts[customerPos - 1];
				gifts[customerPos - 1] = 0;
			}
			else
			{
				int dif = giftSlots - giftsTaken;

				giftsTaken += dif;
				totalContents -= dif;
				gifts[customerPos - 1] -= dif;
			}
		}
		else
		{
			customerPos--;
			cout << "T";
		}

		if (customerPos < 0)
			customerPos = 0;
		if (customerPos == 0 && (giftsTaken == giftSlots || totalContents == 0))
		{
			//new customer
			clientCount++;
			giftsAtCounter += giftsTaken;
			giftSlots = rand() % (MAX_INVENTORY - MIN_INVENTORY) + MIN_INVENTORY + 1; // 5 - 8
			giftsTaken = 0;
		}
		system("cls");
		//DRAW
		for (int i = 0; i < MAX_LENGTH + gridPlus; i++)
		{
			if (i == 0)
				cout << (char)wallTL;
			else if (i == 11)
				cout << (char)wallTR;
			else
				cout << (char)wallH;
		}
		cout << endl;
		cout << (char)wallV;
		for (int i = 0; i < MAX_LENGTH; i++)
		{
			if (gifts[i] > 0)
				cout << gifts[i];
			else
				cout << 0;
		}
		cout << (char)wallV;
		cout << endl;
		cout << (char)wallV;

		for (int i = 0; i < MAX_LENGTH; i++)
		{
			if (i == customerPos)
				cout << customer;
			else
				cout << empty;
		}
		cout << (char)wallV;

		cout << endl;
		for (int i = 0; i < MAX_LENGTH + gridPlus; i++)
		{
			if (i == 0)
				cout << (char)wallBL;
			else if (i == 11)
				cout << (char)wallBR;
			else
				cout << (char)wallH;
		}
		cout << endl;
		cout << "La persona tiene " << giftsTaken << " de " << giftSlots << " items." << endl;
		cout << "Los items dejados son: " << giftsAtCounter << endl;
		cout << "Personas en total: " << clientCount << endl;
		system("pause");
		//Game over
		playing = (totalContents > 0 || giftsTaken != 0);
	}
}