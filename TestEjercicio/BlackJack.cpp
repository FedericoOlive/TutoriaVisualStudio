#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


struct Cards
{
	int value;
	char number;
	char number2;
	char symbol;
	bool isAnAce = false;
	bool isFigure = false;
};


COORD cursorPosition;
HANDLE hwnd;

int consoleWide = 85;
int consoleHeight = 25;
int playerCardPosX = 1;
int playerHiddenPosX = 1;
int playerCardPosY = 1;
int playerHiddenPosY = 1;
int crupierCardPosX = 1;
int crupierHiddenPosX = 1;
int crupierCardPosY = consoleHeight - 8;
int crupierHiddenPosY = consoleHeight - 8;

bool finishNow = false;

string error = "Opcion incorrecta intentelo nuevamente!";
string clean = "                                       ";
string looseHand = "      *****PERDISTE LA MANO*****      ";
string winHand = "      *****GANASTE LA MANO*****      ";
string replay = "Desea volver a jugar? S/N";
string goodBye1 = "Gracias por elegir Digital-Happines®";
string goodBye2 = "Hasta la proxima...";

void SetConsoleSize();
void DrawFrame(int delay);
void DrawHud(int cash, int playerScore, int crupierScore, int bet, int delay);
void PlantSeed();
void ShowMenu();
void CheckMenuInput(char& key, void ShowMenu());
void ShowRules();
void NewDeck(Cards deck[52]);
void SetBet(int& remainingCash, int& bet);
void NewCard(Cards deck[52], Cards* Cards, int& TotalCards, int& CardPosX, int& CardPosY);
void PrintHiddenCard(int& posX, int& posY, int quantity);
void PrintCard(Cards card, int& posX, int posY);
void PlayerHand(Cards deck[52], Cards* playerCards, int& playerActualScore, int& playerTotalCards, int& cash, int crupierScore, int bet, bool& blackJack);
void CrupierHand(Cards deck[52], Cards* crupierCards, int& playerScore, int& crupierTotalCards, int& cash, int& crupierScore, int bet, bool& blackJack);
void CheckHandScore(Cards* cards, int totalCards, int& actualScore, bool& blackJack);



void main()
{
	bool keepPlaying = true;
	bool blackJack = false;
	char key;
	
	SetConsoleSize();
	
	PlantSeed();
	
	while (keepPlaying)
	{
		int playerActualScore = 0;
		int croupierActualScore = 0;
		int playerTotalCards = 0;
		int crupierTotalCards = 0;
		int remainingCash = 1000;
		int bet = 0;

		int frameDelay = 8;
		int hudDelay = 250;

		playerCardPosX = 1;
		playerHiddenPosX = 1;
		playerCardPosY = 1;
		playerHiddenPosY = 1;
		crupierCardPosX = 1;
		crupierHiddenPosX = 1;
		crupierCardPosY = consoleHeight - 8;
		crupierHiddenPosY = consoleHeight - 8;


		Cards deck[52];
		Cards* playerCards = new Cards[playerTotalCards];
		Cards* crupierCards = new Cards[crupierTotalCards];
		
		ShowMenu();

		CheckMenuInput(key, ShowMenu);

		while (key == '2')
		{
			ShowRules();
			ShowMenu();
			CheckMenuInput(key, ShowMenu);
		}

		if (key == '1')
		{
			while (remainingCash > 0)
			{
				blackJack = false;
				
				DrawFrame(frameDelay);

				NewDeck(deck);

				DrawHud(remainingCash, playerActualScore, croupierActualScore, bet, hudDelay);

				PrintHiddenCard(playerHiddenPosX, playerHiddenPosY, 2);
				PrintHiddenCard(crupierHiddenPosX, crupierHiddenPosY, 2);

				SetBet(remainingCash, bet);

				DrawHud(remainingCash, playerActualScore, croupierActualScore, bet, 0);

				PlayerHand(deck, playerCards, playerActualScore, playerTotalCards, remainingCash, croupierActualScore, bet, blackJack);
				
				if (finishNow)
				{
					break;
				}

				if (blackJack)
				{
					remainingCash += (bet * 2);
				}
				
				else if (playerActualScore > 21)
				{
					cursorPosition.X = (consoleWide / 2) - (looseHand.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << looseHand;

					Sleep(1000);

					cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << clean;

					goto finish;
				}

				else
				{
					CrupierHand(deck, crupierCards, playerActualScore, crupierTotalCards, remainingCash, croupierActualScore, bet, blackJack);
				}

				if (blackJack)
				{
					goto finish;
				}
		
				else if (croupierActualScore > playerActualScore && croupierActualScore <= 21)
				{
					cursorPosition.X = (consoleWide / 2) - (looseHand.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << looseHand;

					Sleep(1000);

					cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << clean;
				}
				

				else
				{
					remainingCash += (bet * 2);

					cursorPosition.X = (consoleWide / 2) - (winHand.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << winHand;

					Sleep(1000);

					cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
					cursorPosition.Y = consoleHeight / 2;
					SetConsoleCursorPosition(hwnd, cursorPosition);
					cout << clean;
				}

			finish:
				{

				}

				playerCardPosX = 1;
				playerHiddenPosX = 1;
				crupierCardPosX = 1;
				crupierHiddenPosX = 1;
				playerActualScore = 0;
				playerActualScore = 0;
				croupierActualScore = 0;
				playerTotalCards = 0;
				crupierTotalCards = 0;
				bet = 0;
				frameDelay = 0;
				hudDelay = 0;
			}

			system("cls");

			DrawFrame(0);

			cursorPosition.X = (consoleWide / 2) - (replay.length() / 2);
			cursorPosition.Y = consoleHeight / 2;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << replay;

			char input = toupper(_getch());

			while (input != 'S' && input != 'N')
			{
				cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);

				cout << clean;

				cursorPosition.X = (consoleWide / 2) - (error.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);

				cout << error;
				Sleep(1000);

				cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);

				cout << clean;

				cursorPosition.X = (consoleWide / 2) - (replay.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);

				cout << replay;

				input = toupper(_getch());
			}

			if (input == 'N')
			{
				keepPlaying = false;
				break;
			}

			else
			{
				finishNow = false;
			}
		}

		if (key == '3')
		{
			break;
		}
	}
	
	DrawFrame(0);

	cursorPosition.X = (consoleWide / 2) - (goodBye1.length() / 2);
	cursorPosition.Y = consoleHeight / 2;
	SetConsoleCursorPosition(hwnd, cursorPosition);
	cout << goodBye1;

	cursorPosition.X = (consoleWide / 2) - (goodBye2.length() / 2);
	cursorPosition.Y = (consoleHeight / 2) + 1;
	SetConsoleCursorPosition(hwnd, cursorPosition);
	cout << goodBye2;
	
	cursorPosition.Y = consoleHeight - 2;
	SetConsoleCursorPosition(hwnd, cursorPosition);
}

void SetConsoleSize()
{
	//Setear el tamanio de la consola
	SMALL_RECT rect;
	COORD coord;
	
	coord.X = consoleWide;
	coord.Y = consoleHeight;

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1;
	rect.Right = coord.X - 1;

	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);
	SetConsoleWindowInfo(hwnd, TRUE, &rect);

	// Ocultar cursor
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void DrawFrame(int delay)
{
	system("cls");

	//Dibujamos el marco de la consola
	cout << (char)201;

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		cout << (char)205;
		
		Sleep(delay);
	}

	cout << (char)187;

	cursorPosition.X = consoleWide - 1;
	cursorPosition.Y = 1;

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		SetConsoleCursorPosition(hwnd, cursorPosition);
		cout << (char)186;
		cursorPosition.Y++;
		if (delay > 0)
		{
			Sleep(delay + 20);
		}
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << (char)188;

	cursorPosition.X--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleWide - 2); i++)
	{
		cout << (char)205;
		cursorPosition.X--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		Sleep(delay);
	}

	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << (char)200;

	cursorPosition.Y--;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < (consoleHeight - 2); i++)
	{
		cout << (char)186 << endl;
		cursorPosition.Y--;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		if (delay > 0)
		{
			Sleep(delay+20);
		}
	}

	

	

	string imageCampus = "Digital Happines";

	cursorPosition.X = (consoleWide / 2) - (imageCampus.length() / 2) - 1;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < imageCampus.length(); i++)
	{
		cout << imageCampus[i];
		if (delay > 0)
		{
			Sleep(100);
		}
	}
	cout << (char)169;
}

void DrawHud(int cash, int playerScore, int crupierScore, int bet, int delay)
{
	string oneMore = "1-Pedir carta";
	string stop = "2-Plantarse";
	string exitNow = "3-Salir";

	const int arrayDimensionHeight = 3;
	const int arrayDimensionWide = 7;
	char cashBox[arrayDimensionHeight][arrayDimensionWide] = {
		{201,205,205,205,205,205,187},
		{186,'$',' ',' ',' ',' ',186},
		{200,205,205,205,205,205,188}
	};

	const int scoreDimensionHeight = 3;
	const int scoreDimensionWide = 5;
	char scoreBox[scoreDimensionHeight][scoreDimensionWide] = {
		{201,205,205,205,187},
		{186,'#',' ',' ',186},
		{200,205,205,205,188}
	};

	const int betDimensionHeight = 3;
	const int betDimensionWide = 9;
	char betBox[betDimensionHeight][betDimensionWide] = {
		{201,205,205,205,205,205,205,205,187},
		{186,'B','E','T','$',' ',' ',' ',186},
		{200,205,205,205,205,205,205,205,188}
	};

	cursorPosition.X = 2;
	cursorPosition.Y = 8;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	for (int i = 0; i < scoreDimensionHeight; i++)
	{
		for (int j = 0; j < scoreDimensionWide; j++)
		{
			cout << scoreBox[i][j];
		}
		cursorPosition.X = 2;
		cursorPosition.Y++;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	cursorPosition.X = 4;
	cursorPosition.Y = 9;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << playerScore;

	cursorPosition.X = 2;
	cursorPosition.Y = 11;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	for (int i = 0; i < betDimensionHeight; i++)
	{
		for (int j = 0; j < betDimensionWide; j++)
		{
			cout << betBox[i][j];
		}
		cursorPosition.X = 2;
		cursorPosition.Y++;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	cursorPosition.X = 7;
	cursorPosition.Y = 12;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << bet;

	cursorPosition.X = 2;
	cursorPosition.Y = consoleHeight - 11;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	for (int i = 0; i < scoreDimensionHeight; i++)
	{
		for (int j = 0; j < scoreDimensionWide; j++)
		{
			cout << scoreBox[i][j];
		}
		cursorPosition.X = 2;
		cursorPosition.Y++;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	cursorPosition.X = 4;
	cursorPosition.Y = consoleHeight - 10;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << crupierScore;

	

	cursorPosition.X = consoleWide - 10;
	cursorPosition.Y = 1;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	for (int i = 0; i < arrayDimensionHeight; i++)
	{
		for (int j = 0; j < arrayDimensionWide; j++)
		{
			cout << cashBox[i][j];
		}
		cursorPosition.X = consoleWide - 10;
		cursorPosition.Y++;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	cursorPosition.X = consoleWide - 8;
	cursorPosition.Y = 2;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << cash;

	cursorPosition.X = consoleWide - 14;
	cursorPosition.Y += 2;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << oneMore;

	cursorPosition.X = consoleWide - 14;
	cursorPosition.Y++;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << stop;

	cursorPosition.X = consoleWide - 14;
	cursorPosition.Y++;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	Sleep(delay);

	cout << exitNow;
}

void PlantSeed()
{
	srand(time(0));
}

void ShowMenu()
{
	string menu = "**MENU PRINCIPAL**";
	string newGame = "1-Jugar";
	string rules = "2-Reglas de juego";
	string exit = "3-Finalizar";

	DrawFrame(0);

	cursorPosition.X = (consoleWide / 2) - (menu.length() / 2);
	cursorPosition.Y = consoleHeight / 3;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << menu;

	cursorPosition.X = (consoleWide / 2) - (newGame.length() / 2)-1;
	cursorPosition.Y = (consoleHeight / 10) * 6;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << newGame;

	cursorPosition.X = (consoleWide / 2) - (rules.length() / 2)-1;
	cursorPosition.Y = (consoleHeight / 10) * 7;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rules;

	cursorPosition.X = (consoleWide / 2) - (exit.length() / 2)-1;
	cursorPosition.Y = (consoleHeight / 10) * 8;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << exit;
}

void CheckMenuInput(char& key, void ShowMenu())
{
	key = toupper(_getch());

	while (key != '1' && key != '2' && key != '3')
	{
		system("cls");

		DrawFrame(0);

		cursorPosition.X = (consoleWide / 2) - (error.length() / 2);
		cursorPosition.Y = consoleHeight / 2;
		SetConsoleCursorPosition(hwnd, cursorPosition);

		cout << error;

		Sleep(700);
		system("cls");

		DrawFrame(0);
		ShowMenu();

		key = _getch();
	}
}

void ShowRules()
{
	string menu = "**REGLAS DE JUEGO**";
	
	string rule1 = "-El jugador elije cuanto apostar";
	string rule2 = "-Una vez repartidas las cartas no se puede modificar la apuesta";
	string rule3 = "-El jugador puede pedir de a una carta tantas veces como quiera";
	string rule4 = "-El objetivo es llegar a 21 puntos, si se pasa pierde la mano";
	string rule5 = "-Si saca un As y una figura gana la mano";
	string rule6 = "-El As puede valer 1 o 11 dependiendo la conveniencia";
	string rule7 = "-Uva vez finalizada la mano del jugador le toca al crupier";
	string rule8 = "-En caso de empate gana el jugador";
	string rule9 = "-Si el jugador gana duplica lo que aposto";
	string rule10 = "-Si el jugador se queda sin dinero se acaba el juego";
	
	string exit = "Presione cualquier tecla para volver al menu principal";

	system("cls");

	DrawFrame(0);

	cursorPosition.X = (consoleWide / 2) - (menu.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 2;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << menu << endl;

	cursorPosition.X = (consoleWide / 2) - (rule1.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 4;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule1;

	cursorPosition.X = (consoleWide / 2) - (rule2.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 5;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule2;

	cursorPosition.X = (consoleWide / 2) - (rule3.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 6;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule3;

	cursorPosition.X = (consoleWide / 2) - (rule4.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 7;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule4;

	cursorPosition.X = (consoleWide / 2) - (rule5.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 8;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule5;

	cursorPosition.X = (consoleWide / 2) - (rule6.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 9;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule6;

	cursorPosition.X = (consoleWide / 2) - (rule7.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 10;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule7;

	cursorPosition.X = (consoleWide / 2) - (rule8.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 11;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule8;

	cursorPosition.X = (consoleWide / 2) - (rule9.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 12;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule9;

	cursorPosition.X = (consoleWide / 2) - (rule10.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 13;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << rule10;

	cursorPosition.X = (consoleWide / 2) - (exit.length() / 2);
	cursorPosition.Y = (consoleHeight / 15) * 16;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << exit;

	cin.get();
}

void NewDeck(Cards deck[52])
{
	////////////Diamantes
	////////////Diamantes
	Cards diamond1;
	diamond1.value = 11;
	diamond1.number = '1';
	diamond1.number2 = ' ';
	diamond1.symbol = 04;
	diamond1.isAnAce = true;
	deck[0] = diamond1;


	Cards diamond2;
	diamond2.value = 2;
	diamond2.number = '2';
	diamond2.number2 = ' ';
	diamond2.symbol = 04;
	deck[1] = diamond2;

	Cards diamond3;
	diamond3.value = 3;
	diamond3.number = '3';
	diamond3.number2 = ' ';
	diamond3.symbol = 04;
	deck[2] = diamond3;

	Cards diamond4;
	diamond4.value = 4;
	diamond4.number = '4';
	diamond4.number2 = ' ';
	diamond4.symbol = 04;
	deck[3] = diamond4;

	Cards diamond5;
	diamond5.value = 5;
	diamond5.number = '5';
	diamond5.number2 = ' ';
	diamond5.symbol = 04;
	deck[4] = diamond5;

	Cards diamond6;
	diamond6.value = 6;
	diamond6.number = '6';
	diamond6.number2 = ' ';
	diamond6.symbol = 04;
	deck[5] = diamond6;

	Cards diamond7;
	diamond7.value = 7;
	diamond7.number = '7';
	diamond7.number2 = ' ';
	diamond7.symbol = 04;
	deck[6] = diamond7;

	Cards diamond8;
	diamond8.value = 8;
	diamond8.number = '8';
	diamond8.number2 = ' ';
	diamond8.symbol = 04;
	deck[7] = diamond8;

	Cards diamond9;
	diamond9.value = 9;
	diamond9.number = '9';
	diamond9.number2 = ' ';
	diamond9.symbol = 04;
	deck[8] = diamond9;

	Cards diamond10;
	diamond10.value = 10;
	diamond10.number = '1';
	diamond10.number2 = '0';
	diamond10.symbol = 04;
	deck[9] = diamond10;

	Cards diamondJ;
	diamondJ.value = 10;
	diamondJ.number = 'J';
	diamondJ.number2 = ' ';
	diamondJ.symbol = 04;
	diamondJ.isFigure = true;
	deck[10] = diamondJ;

	Cards diamondQ;
	diamondQ.value = 10;
	diamondQ.number = 'Q';
	diamondQ.number2 = ' ';
	diamondQ.symbol = 04;
	diamondQ.isFigure = true;
	deck[11] = diamondQ;

	Cards diamondK;
	diamondK.value = 10;
	diamondK.number = 'K';
	diamondK.number2 = ' ';
	diamondK.symbol = 04;
	diamondK.isFigure = true;
	deck[12] = diamondK;


	////////////Corazones
	////////////Corazones
	Cards hearts1;
	hearts1.value = 11;
	hearts1.number = '1';
	hearts1.number2 = ' ';
	hearts1.symbol = 03;
	hearts1.isAnAce = true;
	deck[13] = hearts1;

	Cards hearts2;
	hearts2.value = 2;
	hearts2.number = '2';
	hearts2.number2 = ' ';
	hearts2.symbol = 03;
	deck[14] = hearts2;

	Cards hearts3;
	hearts3.value = 3;
	hearts3.number = '3';
	hearts3.number2 = ' ';
	hearts3.symbol = 03;
	deck[15] = hearts3;

	Cards hearts4;
	hearts4.value = 4;
	hearts4.number = '4';
	hearts4.number2 = ' ';
	hearts4.symbol = 03;
	deck[16] = hearts4;

	Cards hearts5;
	hearts5.value = 5;
	hearts5.number = '5';
	hearts5.number2 = ' ';
	hearts5.symbol = 03;
	deck[17] = hearts5;

	Cards hearts6;
	hearts6.value = 6;
	hearts6.number = '6';
	hearts6.number2 = ' ';
	hearts6.symbol = 03;
	deck[18] = hearts6;

	Cards hearts7;
	hearts7.value = 7;
	hearts7.number = '7';
	hearts7.number2 = ' ';
	hearts7.symbol = 03;
	deck[19] = hearts7;

	Cards hearts8;
	hearts8.value = 8;
	hearts8.number = '8';
	hearts8.number2 = ' ';
	hearts8.symbol = 03;
	deck[20] = hearts8;

	Cards hearts9;
	hearts9.value = 9;
	hearts9.number = '9';
	hearts9.number2 = ' ';
	hearts9.symbol = 03;
	deck[21] = hearts9;

	Cards hearts10;
	hearts10.value = 10;
	hearts10.number = '1';
	hearts10.number2 = '0';
	hearts10.symbol = 03;
	deck[22] = hearts10;

	Cards heartsJ;
	heartsJ.value = 10;
	heartsJ.number = 'J';
	heartsJ.number2 = ' ';
	heartsJ.symbol = 03;
	heartsJ.isFigure = true;
	deck[23] = heartsJ;

	Cards heartsQ;
	heartsQ.value = 10;
	heartsQ.number = 'Q';
	heartsQ.number2 = ' ';
	heartsQ.symbol = 03;
	heartsQ.isFigure = true;
	deck[24] = heartsQ;

	Cards heartsK;
	heartsK.value = 10;
	heartsK.number = 'K';
	heartsK.number2 = ' ';
	heartsK.symbol = 03;
	heartsK.isFigure = true;
	deck[25] = heartsK;


	////////////Trebol
	////////////Trebol
	Cards clover1;
	clover1.value = 11;
	clover1.number = '1';
	clover1.number2 = ' ';
	clover1.symbol = 05;
	clover1.isAnAce = true;
	deck[26] = clover1;

	Cards clover2;
	clover2.value = 2;
	clover2.number = '2';
	clover2.number2 = ' ';
	clover2.symbol = 05;
	deck[27] = clover2;

	Cards clover3;
	clover3.value = 3;
	clover3.number = '3';
	clover3.number2 = ' ';
	clover3.symbol = 05;
	deck[28] = clover3;

	Cards clover4;
	clover4.value = 4;
	clover4.number = '4';
	clover4.number2 = ' ';
	clover4.symbol = 05;
	deck[29] = clover4;

	Cards clover5;
	clover5.value = 5;
	clover5.number = '5';
	clover5.number2 = ' ';
	clover5.symbol = 05;
	deck[30] = clover5;

	Cards clover6;
	clover6.value = 6;
	clover6.number = '6';
	clover6.number2 = ' ';
	clover6.symbol = 05;
	deck[31] = clover6;

	Cards clover7;
	clover7.value = 7;
	clover7.number = '7';
	clover7.number2 = ' ';
	clover7.symbol = 05;
	deck[32] = clover7;

	Cards clover8;
	clover8.value = 8;
	clover8.number = '8';
	clover8.number2 = ' ';
	clover8.symbol = 05;
	deck[33] = clover8;

	Cards clover9;
	clover9.value = 9;
	clover9.number = '9';
	clover9.number2 = ' ';
	clover9.symbol = 05;
	deck[34] = clover9;

	Cards clover10;
	clover10.value = 10;
	clover10.number = '1';
	clover10.number2 = '0';
	clover10.symbol = 05;
	deck[35] = clover10;

	Cards cloverJ;
	cloverJ.value = 10;
	cloverJ.number = 'J';
	cloverJ.number2 = ' ';
	cloverJ.symbol = 05;
	cloverJ.isFigure = true;
	deck[36] = cloverJ;

	Cards cloverQ;
	cloverQ.value = 10;
	cloverQ.number = 'Q';
	cloverQ.number2 = ' ';
	cloverQ.symbol = 05;
	cloverQ.isFigure = true;
	deck[37] = cloverQ;

	Cards cloverK;
	cloverK.value = 10;
	cloverK.number = 'K';
	cloverK.number2 = ' ';
	cloverK.symbol = 05;
	cloverK.isFigure = true;
	deck[38] = cloverK;


	////////////Picas
	////////////Picas
	Cards spades1;
	spades1.value = 11;
	spades1.number = '1';
	spades1.number2 = ' ';
	spades1.symbol = 06;
	spades1.isAnAce = true;
	deck[39] = spades1;

	Cards spades2;
	spades2.value = 2;
	spades2.number = '2';
	spades2.number2 = ' ';
	spades2.symbol = 06;
	deck[40] = spades2;

	Cards spades3;
	spades3.value = 3;
	spades3.number = '3';
	spades3.number2 = ' ';
	spades3.symbol = 06;
	deck[41] = spades3;

	Cards spades4;
	spades4.value = 4;
	spades4.number = '4';
	spades4.number2 = ' ';
	spades4.symbol = 06;
	deck[42] = spades4;

	Cards spades5;
	spades5.value = 5;
	spades5.number = '5';
	spades5.number2 = ' ';
	spades5.symbol = 06;
	deck[43] = spades5;

	Cards spades6;
	spades6.value = 6;
	spades6.number = '6';
	spades6.number2 = ' ';
	spades6.symbol = 06;
	deck[44] = spades6;

	Cards spades7;
	spades7.value = 7;
	spades7.number = '7';
	spades7.number2 = ' ';
	spades7.symbol = 06;
	deck[45] = spades7;

	Cards spades8;
	spades8.value = 8;
	spades8.number = '8';
	spades8.number2 = ' ';
	spades8.symbol = 06;
	deck[46] = spades8;

	Cards spades9;
	spades9.value = 9;
	spades9.number = '9';
	spades9.number2 = ' ';
	spades9.symbol = 06;
	deck[47] = spades9;

	Cards spades10;
	spades10.value = 10;
	spades10.number = '1';
	spades10.number2 = '0';
	spades10.symbol = 06;
	deck[48] = spades10;

	Cards spadesJ;
	spadesJ.value = 10;
	spadesJ.number = 'J';
	spadesJ.number2 = ' ';
	spadesJ.symbol = 06;
	spadesJ.isFigure = true;
	deck[49] = spadesJ;

	Cards spadesQ;
	spadesQ.value = 10;
	spadesQ.number = 'Q';
	spadesQ.number2 = ' ';
	spadesQ.symbol = 06;
	spadesQ.isFigure = true;
	deck[50] = spadesQ;

	Cards spadesK;
	spadesK.value = 10;
	spadesK.number = 'K';
	spadesK.number2 = ' ';
	spadesK.symbol = 06;
	spadesK.isFigure = true;
	deck[51] = spadesK;
}

void SetBet(int& remainingCash, int& bet)
{
	string question = "           Ingrese su apuesta:           ";
	string insuficient = "        ***Fondos insuficentes***        ";
	string minimumBet = "***La apuesta minima para entrar es $1***";
	string clean = "                                         ";

	cursorPosition.X = (consoleWide / 2) - (question.length() / 2) - 2;
	cursorPosition.Y = (consoleHeight / 10) * 5;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << question;

	cursorPosition.X = (consoleWide / 2) + (question.length() / 2) -11;
	SetConsoleCursorPosition(hwnd, cursorPosition);
	cin >> bet;

	Sleep(300);
	//Corroboramos que la apuesta sea mayor 0 pero no mayor que nuestro dinero disponible
	
	while (bet < 1 || bet > remainingCash)
	{
		if (bet < 1)
		{
			cursorPosition.X = (consoleWide / 2) - (minimumBet.length() / 2) - 2;
			cursorPosition.Y = (consoleHeight / 10) * 5;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << minimumBet;

			cursorPosition.X = (consoleWide / 2) - (minimumBet.length() / 2) - 2;
			cursorPosition.Y = ((consoleHeight / 10) * 5) + 1;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << question;

			cursorPosition.X = (consoleWide / 2) + (question.length() / 2) -11;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cin >> bet;

		}

		if (bet > remainingCash)
		{
			cursorPosition.X = (consoleWide / 2) - (minimumBet.length() / 2) - 2;
			cursorPosition.Y = (consoleHeight / 10) * 5;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << insuficient;

			cursorPosition.X = (consoleWide / 2) - (minimumBet.length() / 2) - 2;
			cursorPosition.Y = ((consoleHeight / 10) * 5) + 1;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cout << question;

			cursorPosition.X = (consoleWide / 2) + (question.length() / 2) -11;
			SetConsoleCursorPosition(hwnd, cursorPosition);

			cin >> bet;

		}
	}

	cursorPosition.X = (consoleWide / 2) - (clean.length() / 2) - 2;
	cursorPosition.Y = (consoleHeight / 10) * 5;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << clean;

	cursorPosition.X = (consoleWide / 2) - (clean.length() / 2) - 2;
	cursorPosition.Y = ((consoleHeight / 10) * 5) + 1;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	cout << clean;

	remainingCash -= bet;
}

void NewCard(Cards deck[52], Cards* Cards, int& TotalCards, int& CardPosX, int& CardPosY)
{
	int random = rand() % 52;

	while (deck[random].value == 0)
	{
		random = rand() % 52;
	}

	Cards[TotalCards] = deck[random];
	deck[random].value = 0;

	PrintCard(Cards[TotalCards], CardPosX, CardPosY);

	TotalCards++;
}

void PlayerHand(Cards deck[52], Cards* playerCards, int& playerActualScore, int& playerTotalCards, int& cash, int crupierScore, int bet, bool& blackJack)
{	
	char key;

	string clean = "                                       ";
	string BlackJack = "         *****BLACK JACK*****         ";
	string overPassed = "         *****TE PASASTE*****         ";

	for (int i = 0; i < 2; i++)
	{
		NewCard(deck, playerCards, playerTotalCards, playerCardPosX, playerCardPosY);
	}

	CheckHandScore(playerCards, playerTotalCards, playerActualScore, blackJack);

	DrawHud(cash, playerActualScore, crupierScore, bet, 0);

	if (blackJack)
	{
		for (int i = 0; i < 8; i++)
		{
			cursorPosition.X = (consoleWide / 2) - (BlackJack.length() / 2);
			cursorPosition.Y = consoleHeight / 2;
			SetConsoleCursorPosition(hwnd, cursorPosition);
			cout << BlackJack;

			Sleep(80);

			cursorPosition.X = (consoleWide / 2) - (BlackJack.length() / 2);
			cursorPosition.Y = consoleHeight / 2;
			SetConsoleCursorPosition(hwnd, cursorPosition);
			cout << clean;

			Sleep(20);
		}
	}

	else if (playerActualScore < 21)
	{
		while (playerActualScore < 21)
		{
			PrintHiddenCard(playerHiddenPosX, playerHiddenPosY, 1);
		
			key = _getch();

			while (key != '1' && key != '2' && key != '3')
			{
				cursorPosition.X = (consoleWide / 2) - (error.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);
				cout << error;

				Sleep(800);

				cursorPosition.X = (consoleWide / 2) - (clean.length() / 2);
				cursorPosition.Y = consoleHeight / 2;
				SetConsoleCursorPosition(hwnd, cursorPosition);
				cout << clean;

				key = _getch();
			}

			if (key == '1')
			{
				NewCard(deck, playerCards, playerTotalCards, playerCardPosX, playerCardPosY);

				CheckHandScore(playerCards, playerTotalCards, playerActualScore, blackJack);

				DrawHud(cash, playerActualScore, crupierScore, bet, 0);
			}

			if (key == '3')
			{
				finishNow = true;
				break;
			}

			if (key == '2')
			{
				break;
			}
		}
	}

	else
	{
		cursorPosition.X = (consoleWide / 2) - (overPassed.length() / 2);
		cursorPosition.Y = consoleHeight / 2;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		cout << overPassed;

		Sleep(1000);

		cursorPosition.X = (consoleWide / 2) - (BlackJack.length() / 2);
		cursorPosition.Y = consoleHeight / 2;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		cout << clean;
	}
}

void CrupierHand(Cards deck[52], Cards* crupierCards, int& playerScore, int& crupierTotalCards, int& cash, int& crupierScore, int bet, bool& blackJack)
{
	string clean = "                                       ";
	string BlackJack = "     *****CRUPIER BLACK JACK*****     ";
	
	for (int i = 0; i < 2; i++)
	{
		NewCard(deck, crupierCards, crupierTotalCards, crupierCardPosX, crupierCardPosY);
	}

	CheckHandScore(crupierCards, crupierTotalCards, crupierScore, blackJack);

	DrawHud(cash, playerScore, crupierScore, bet, 0);

	if (blackJack)
	{
		for (int i = 0; i < 5; i++)
		{
			cursorPosition.X = (consoleWide / 2) + (BlackJack.length() / 2);
			cursorPosition.Y = consoleHeight / 2;
			SetConsoleCursorPosition(hwnd, cursorPosition);
			cout << BlackJack;

			Sleep(1000);

			cursorPosition.X = (consoleWide / 2) + (BlackJack.length() / 2);
			cursorPosition.Y = consoleHeight / 2;
			SetConsoleCursorPosition(hwnd, cursorPosition);
			cout << clean;
		}
	}
	
	else
	{
		while (crupierScore <= 15)
		{
			PrintHiddenCard(crupierHiddenPosX, crupierHiddenPosY, 1);
	
			NewCard(deck, crupierCards, crupierTotalCards, crupierCardPosX, crupierCardPosY);

			CheckHandScore(crupierCards, crupierTotalCards, crupierScore, blackJack);

			DrawHud(cash, playerScore, crupierScore, bet, 0);
		}
	}
}

void CheckHandScore(Cards* cards, int totalCards, int& actualScore, bool& blackJack)
{
	bool ace = false;
	bool figure = false;

	actualScore = 0;

	if (totalCards == 2)
	{
		for (int i = 0; i < totalCards; i++)
		{
			if (cards[i].isAnAce == true)
			{
				ace = true;
			}

			if (cards[i].isFigure == true)
			{
				figure = true;
			}
		}

	}
	
	if (!ace || !figure)
	{
		for (int i = 0; i < totalCards; i++)
		{	////////sumamos el score total de las cartas actuales con el as en valor 11
			actualScore += cards[i].value;
		}
	
		if (actualScore > 21)
		{			/////////si se pasa recorreomes el arreglo buscando las que tengan el numero 1 (as)
			for (int i = 0; i < totalCards; i++)
			{
				if (cards[i].value == 11)
				{	////////al encontar dicha carta le cambiamos el valor 1
					cards[i].value = 1;
					actualScore = 0;
			
					for (int j = 0; j < totalCards; j++)
					{/////volvemos a calcular el score
						actualScore += cards[j].value;
					}
					///le decimos que si el score ya es menor o igual a 21 deje de buscar 
					if (actualScore <= 21)
					{
						break;
					}
				}
			}
		}

	}

	else
	{
		blackJack = true;
	}
}

void PrintHiddenCard(int& hiddenPosX, int& hiddenPosY, int quantity)
{	
	const int arrayDimensionHeight = 7;
	const int arrayDimensionWide = 9;
	char baseCard[arrayDimensionHeight][arrayDimensionWide] = {
		{201,205,205,205,205,205,205,205,187},
		{186,177,177,177,177,177,177,177,186},
		{186,177,177,177,177,177,177,177,186},
		{186,177,'I','M','A','G','E',177,186},
		{186,'C','A','M','P','U','S',169,186},
		{186,177,177,177,177,177,177,177,186},
		{200,205,205,205,205,205,205,205,188}
	};

	for (int i = 0; i < quantity; i++)
	{
		cursorPosition.X = hiddenPosX;
		cursorPosition.Y = hiddenPosY;
		SetConsoleCursorPosition(hwnd, cursorPosition);
		int localPosX = hiddenPosX;
		int localPosY = hiddenPosY;

		for (int j = 0; j < arrayDimensionHeight; j++)
		{
			for (int k = 0; k < arrayDimensionWide; k++)
			{
				cout << baseCard[j][k];
				Sleep(1);
			}

			localPosY++;

			cursorPosition.X = localPosX;
			cursorPosition.Y = localPosY;
			SetConsoleCursorPosition(hwnd, cursorPosition);
		}
		hiddenPosX += 10;
		Sleep(200);
	}
}

void PrintCard(Cards card, int& posX, int posY)
{
	const int arrayDimensionHeight = 7;
	const int arrayDimensionWide = 9;
	char baseCard[arrayDimensionHeight][arrayDimensionWide] = {
		{201,205,205,205,205,205,205,205,187},
		{186,' ',' ',' ',' ',' ',' ',' ',186},
		{186,' ',' ',' ',' ',' ',' ',' ',186},
		{186,' ',' ',' ',' ',' ',' ',' ',186},
		{186,' ',' ',' ',' ',' ',' ',' ',186},
		{186,' ',' ',' ',' ',' ',' ',' ',186},
		{200,205,205,205,205,205,205,205,188}
	};

	baseCard[1][1] = card.number;
	baseCard[1][2] = card.number2;
	baseCard[5][6] = card.number;
	baseCard[5][7] = card.number2;
	baseCard[3][4] = card.symbol;

	cursorPosition.X = posX;
	cursorPosition.Y = posY;
	SetConsoleCursorPosition(hwnd, cursorPosition);

	for (int i = 0; i < arrayDimensionHeight; i++)
	{
		for (int j = 0; j < arrayDimensionWide; j++)
		{
			cout << baseCard[i][j];
			Sleep(30);
		}
		
		posY++;

		cursorPosition.X = posX;
		cursorPosition.Y = posY;
		SetConsoleCursorPosition(hwnd, cursorPosition);
	}

	posX += 10;
}