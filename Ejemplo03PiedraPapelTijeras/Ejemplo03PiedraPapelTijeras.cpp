// ReSharper disable CppCStyleCast
#include <iostream>
#include <ctime>
using namespace std;

enum class Weapons { None, Sword, Knife, Axe, Bow, Last };

struct Player
{
	Weapons weapon = Weapons::None;
	int life = 10;
};

const int maxPlayers = 5;

Weapons PlayerWeaponSelect();
string GetWeaponName(Weapons weapon);
void Combat(Player players[]);
void CheckPlayerDie(Player player, bool& isPlaying);

void main()
{
	srand(time(NULL));
	bool isPlaying = true;

	Player players[maxPlayers]{}; // 0 = Player, Los Otros = bots

	do
	{
		players[0].weapon = PlayerWeaponSelect();
		if (players[0].weapon == Weapons::None)
		{
			isPlaying = false;
		}
		else
		{
			Combat(players);
		}
		
		CheckPlayerDie(players[0], isPlaying);
		
	} while (isPlaying);
}

void CheckPlayerDie(Player player, bool& isPlaying)
{
	if (player.life < 1)
	{
		cout << "Perdiste Todo. Te vas del juego.\n\n";
		isPlaying = false;
	}
}

void Combat(Player players[])
{
	for (int i = 1; i < maxPlayers; ++i)
	{
		players[i].weapon = (Weapons)(rand() % ((int)Weapons::Last - 1) + 1);
	}

	cout << "\n\nHas elejido: " << GetWeaponName(players[0].weapon) << ".";
	for (int i = 1; i < maxPlayers; ++i)
	{
		cout << "\nCPU" << i << "ha elejido: " << GetWeaponName(players[i].weapon) << ".";
	}
	cout << "\n";
	// Chequeo de Victoria:
	bool playerLose = false;
	
	for (int i = 1; i < maxPlayers; ++i)
	{
		if ((int)players[0].weapon < (int)players[i].weapon)
		{
			playerLose = true;
			break;
		}
	}

	if (playerLose)
	{
		cout << "\n\nHas Perdido!";
		players[0].life--;
	}
	else
	{
		cout << "\n\nHas Ganado!";

		for (int i = 1; i < maxPlayers; ++i)
		{
			players[i].life--;
		}
	}

	cout << "\n\n";
	system("pause");
	system("cls");
}

Weapons PlayerWeaponSelect()
{
	int intUserInput = 0;
	bool correctInput = true;
	
	do
	{
		cout << "Elija un Arma o 0 para salir:\n";
		cout << "1- Sword\n";
		cout << "2- Knife\n";
		cout << "3- Axe\n";
		cout << "4- Bow\n\n";
		cout << "Elija: ";
		cin >> intUserInput;

		correctInput = (intUserInput > (int)Weapons::None && intUserInput < (int)Weapons::Last) || intUserInput == 0;

		if (!correctInput)
		{
			cout << "\nInput Incorrecto!!\n\n";
			system("pause");
			system("cls");
		}

	} while (!correctInput);

	return (Weapons)intUserInput;
}

string GetWeaponName(Weapons weapon)
{
	string weaponName;

	switch (weapon)
	{
	case Weapons::None:
		weaponName = "*WARNING*: Nunca fue seteada el arma!!!";
		break;
	case Weapons::Sword:
		weaponName = "Sword";
		break;
	case Weapons::Knife:
		weaponName = "Knife";
		break;
	case Weapons::Axe:
		weaponName = "Axe";
		break;
	case Weapons::Bow:
		weaponName = "Bow";
		break;
	case Weapons::Last:
		weaponName = "*WARNING*: Es LAST: El arma esta fuera de Rango!!!";
		break;
	default:
		weaponName = "*WARNING*: el arma esta fuera de Rango!!!";
		break;
	}
	
	return weaponName;
}