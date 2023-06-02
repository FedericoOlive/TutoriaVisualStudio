// 19 / 06 / 2020 - Olive Federico - TrabajoPráctico_06 - BuscaMinas

/*
		Condicinoes mínimas:
COMPLETADAS:
	**	La minas, las banderas, las celdas 'inexploradas' y las descubiertas (vacías o con números) poseen caracteres que las diferencien entre ellas de forma fácil y efectiva .
	**	Cada vez que se empieza una partida nueva, el tablero es randomizado.
	**	La cantidad mínima de minas es de 10.
	**	El tamaño del tablero debe ser mínimo de 8x8.


		Condiciones avanzadas:

	**	Hacer que el juego tenga, por lo menos, tres dificultades: Fácil, Normal y Difícil. A medida que aumenta la dificultad aumenta el tamaño del tablero y la cantidad de minas.
	**	El jugador puede optar por terminar el juego en mitad de la partida.
	**	Hacer que haya un contador que muestre la cantidad de minas restantes.


		"Ultimate Conditions" :

	**	Hacer que el tablero se genere a partir de la primera selección del jugador, y por ende, el primer intento nunca es una mina.
	**	Hacer un cronómetro que al final el juego indique el tiempo transcurrido. NO tiene que mostrarse en pantalla ni actualizarse. *mirar ejemplo provisto*

		Enviar un archivo .ZIP
		ANALISIS_TM_TP6_OliveFederico.zip.
*/

#include <iostream>		
#include <time.h>		
#include <conio.h>		
#include <Windows.h>	
// #include<string>		

using namespace std;

enum class TECLAS { ENTER = 13, ESPACIO = 32, CERO = 48, A = 65, E = 69, S = 83, W = 87, D = 68, a = 97, d = 100, e = 101, s = 115, w = 119 };
TECLAS tecla = TECLAS::ENTER;
const int tam = 20;
const int top = 5;
const string title = "---- Juego BuscaMinas FIX 2K20 Personalizable ----\t\t By: Federico Olive.\n\n";
struct CONFIGURACIONES
{
	int minasTotales = 10;
	int filasTotales = 8;
	int columnasTotales = 8;
	char banderinChar = 244;
	bool xRay = false;

	struct DIFICULTADFACIL
	{
		int minas = 5;
		int tamaño = 8;
	};
	struct DIFICULTADMEDIO
	{
		int minas = 10;
		int tamaño = 10;
	}; 
	struct DIFICULTADDIFICIL
	{
		int minas = 30;
		int tamaño = 12;
	};
	struct DIFICULTADPERZONALIZADO
	{
		int minas = 10;
		int filas = 10;
		int columnas = 10;
	};
	DIFICULTADFACIL dificultadFacil;
	DIFICULTADMEDIO	dificultadMedio;
	DIFICULTADDIFICIL dificultadDificil;
	DIFICULTADPERZONALIZADO dificultadPerzonalizado;
};
CONFIGURACIONES configuraciones;

struct TOPPLAYERS
{
	char caracter01 = 'A';
	char caracter02 = 'A';
	char caracter03 = 'A';
	int segundos = 0;
};
TOPPLAYERS topPlayers[top];

struct CELDA
{
	int mina = 0;
	bool visibilidad = false;
	bool bloqueo = false;
};
CELDA celda[tam][tam] = { 0 };

#pragma region Funciones

	bool CeldaValida(int, int);			// Chequea si la celda pertenece a los límites del array
	void SwitchColores(int, int);		// Switch de colores para pintar los números
	void ResetearTablero();				// reseteo el tablero
	void CrearTableroMinas(int, int);	// Crea por única vez el tablero (En cada nivel)
	void MostrarTablero(int, int);		// Muestra el tablero y los índices
	void MostrarCelda(int, int);		// Algoritmo de expansion: Recursivo
	void MoverMira(int&, int&);			// Movimiento wasd
	bool ChequeoVictoria();				// Chequeo 
	void MostrarCronometro(int);		// Calculo y cout de timer
	void MostrarTop();					// TOP de x players
	void OrdenarTopPlayers();			// Ordena el top
	void GuardarPuntuacion(int);		// Guarda la puntuacion del player (si ganó)
	int MenuSalir();					// Muestra el menú e input del mismo

#pragma endregion

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i < top; i++)
	{
		topPlayers[i].caracter01 = rand() % 26 + 65;
		topPlayers[i].caracter02 = rand() % 26 + 65;
		topPlayers[i].caracter03 = rand() % 26 + 65;
		topPlayers[i].segundos = rand() % 150 + 25;
	}

	enum class TIPOMENU { MENUPRINCIPAL, JUGAR, REGLAS, CONFIGURACIONES, TOP, SALIR };
	TIPOMENU tipomenu = TIPOMENU::MENUPRINCIPAL;
	TIPOMENU juegoElegido = TIPOMENU::MENUPRINCIPAL;

	int cantidadMinas = 10;
	int minas = cantidadMinas;
	
	int filaActual = 0;
	int columnaActual = 0;

	int input = 0;

	int seleccionador = 1;
	bool continuarJugando = true;
	bool noCerrar = true;
	int tiempo1 = 0;
	int tiempo2 = 0;
	bool crearTablero = true;
	char muestrachar = 'A';

	int dificultad = 0;
	int banderines = 0;

	do
	{
		
		switch (tipomenu)
		{
		case TIPOMENU::MENUPRINCIPAL:

			//Reinicio de CFG
			tiempo1 = 0;
			tiempo2 = 0;
			continuarJugando = true;
			columnaActual = 0, filaActual = 0;
			crearTablero = true;
			configuraciones.xRay = false;

			system("cls");
			cout << title;
			cout << "Instrucciones de uso:\n\nENTER: Seleccionar\nWASD: Mover el cursor\n\n";

			cout << "Menu Principal:\n\n";

			if (seleccionador == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			cout << "   1- Jugar             \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (seleccionador == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			cout << "   2- Reglas            \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (seleccionador == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			cout << "   3- Configuraciones   \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (seleccionador == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			cout << "   4- TOP Jugadores     \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (seleccionador == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			cout << "   5- Salir             \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			input = _getch();
			tecla = (TECLAS)input;

			switch (tecla)
			{
			case TECLAS::ENTER:
			case TECLAS::ESPACIO:

				if (seleccionador == 1)
				{
					do
					{
						system("cls");
						cout << title;
						cout << "Instrucciones de uso:\n\nENTER: Seleccionar - ESPACIO: Volver\nWASD: Mover el cursor\n\n";
						cout << "Seleccionar dificultad:\n";
						if (seleccionador == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
						cout << "   1- Facil                \n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						if (seleccionador == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
						cout << "   2- Medio                \n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						if (seleccionador == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
						cout << "   3- Dificil              \n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						if (seleccionador == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
						cout << "   4- Usar Personalizado   \n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						input = _getch();
						tecla = (TECLAS)input;

						switch (tecla)
						{
						case TECLAS::ENTER:
							tipomenu = (TIPOMENU)seleccionador;

							switch (seleccionador)
							{
							case 1:

								configuraciones.minasTotales = configuraciones.dificultadFacil.minas;
								configuraciones.columnasTotales = configuraciones.dificultadFacil.tamaño;
								configuraciones.filasTotales = configuraciones.dificultadFacil.tamaño;
								dificultad = 1;
								break;

							case 2:

								configuraciones.minasTotales = configuraciones.dificultadMedio.minas;
								configuraciones.columnasTotales = configuraciones.dificultadMedio.tamaño;
								configuraciones.filasTotales = configuraciones.dificultadMedio.tamaño;
								dificultad = 2;
								break;

							case 3:

								configuraciones.minasTotales = configuraciones.dificultadDificil.minas;
								configuraciones.columnasTotales = configuraciones.dificultadDificil.tamaño;
								configuraciones.filasTotales = configuraciones.dificultadDificil.tamaño;
								dificultad = 3;
								break;

							case 4:

								configuraciones.minasTotales = configuraciones.dificultadPerzonalizado.minas;
								configuraciones.columnasTotales = configuraciones.dificultadPerzonalizado.columnas;
								configuraciones.filasTotales = configuraciones.dificultadPerzonalizado.filas;
								dificultad = 0;
								break;

							default:
								break;
							}
							seleccionador = 1;
							tipomenu = TIPOMENU::JUGAR;
							continuarJugando = false;

							break;
						
						case TECLAS::ESPACIO:
							seleccionador = 1;
							continuarJugando = false;
							tipomenu = TIPOMENU::MENUPRINCIPAL;
							break;
						case TECLAS::W:
						case TECLAS::w:

							seleccionador--;
							if (seleccionador < 1)seleccionador = 1;	// LIMITO EL MINIMO

							break;
						case TECLAS::S:
						case TECLAS::s:

							seleccionador++;
							if (seleccionador > 4)seleccionador = 4;	// LIMITO EL MAXIMO

							break;
						default:
							break;
						}
					} while (continuarJugando);
					continuarJugando = true;
				}
				else
					tipomenu = (TIPOMENU)seleccionador;

				break;

			case TECLAS::W:	// PARA CUALQUIERA DE ESTAS TECLAS, SE MUEVE HACIA ARRIBA
			case TECLAS::w:

				seleccionador--;
				if (seleccionador < 1)seleccionador = 1;	// LIMITO EL MINIMO

				break;

			case TECLAS::S:	// PARA CUALQUIERA DE ESTAS TECLAS, SE MUEVE HACIA ABAJO
			case TECLAS::s:

				seleccionador++;
				if (seleccionador > (int)TIPOMENU::SALIR)seleccionador = (int)TIPOMENU::SALIR;	// LIMITO EL MAXIMO
				break;

			default:
				cout << "Tecla no valida:\n\nENTER: Seleccionar/Accion \nWASD: Mover el cursor\n\n";
				system("pause");
				break;
			}

			break;
		case TIPOMENU::JUGAR:

			do
			{
				system("cls");
				cout << title;

				cout << "Muevase con WASD.\n";
				cout << "Con Enter: Muestra la celda.\n";
				cout << "Con E: Bloquear celda (Banderita).\n";
				cout << "Con Espacio: Salir al Menu Principal.";
				cout << "\t\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				cout << "0: xRay (alterna)";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				cout << "\n\n";

				// MUESTRO EL TIEMPO DE LA PARTIDA
				cout << "\t\t\tTiempo de Partida: ";
				MostrarCronometro(tiempo2 - tiempo1);	// Timer: 00:00
				cout << "\n";

				MostrarTablero(filaActual, columnaActual);

				cout << "\n\n";

				cout << "Minas totales: " << configuraciones.minasTotales - banderines;
				MoverMira(filaActual, columnaActual); // WASD

				switch (tecla)	// Para los que no son de movimiento (WASD)
				{
				case TECLAS::CERO:

					configuraciones.xRay = !configuraciones.xRay;

					break;

				case TECLAS::ENTER:	// ABRE CELDA

					if (crearTablero)
					{
						tiempo1 = time(0);
						CrearTableroMinas(columnaActual, filaActual);
						crearTablero = false;
						banderines = 0;
					}
					
					if (!celda[columnaActual][filaActual].bloqueo)
					{
						MostrarCelda(columnaActual, filaActual);
						if (celda[columnaActual][filaActual].mina == 9)
						{
							continuarJugando = false;
							cout << "\a";
						}
					}

					break;
				case TECLAS::ESPACIO:	// SALE AL MENU PRINCIPAL

					continuarJugando = false;

					break;
				case TECLAS::E:	// PONE BANDERITA
				case TECLAS::e:

					if (!celda[columnaActual][filaActual].visibilidad && !crearTablero)
					{
						celda[columnaActual][filaActual].bloqueo = !celda[columnaActual][filaActual].bloqueo;
						(celda[columnaActual][filaActual].bloqueo) ? banderines++ : banderines--;
						
					}

					break;
				default:
					break;
				}

				if (continuarJugando)
					continuarJugando = ChequeoVictoria();

				if (crearTablero)
					tiempo1 = time(0);

				tiempo2 = time(0);

			} while (continuarJugando);
			
			if (tecla != TECLAS::ESPACIO)
			{
				system("cls");

				cout << title;

				cout << "Muevase con WASD.\n";
				cout << "Con Enter: Muestra la celda.\n";
				cout << "Con Espacio: Salir al Menu Principal.\n\n";

				// MUESTRO EL TIEMPO DE LA PARTIDA
				cout << "\t\t\tTiempo de Partida: ";
				MostrarCronometro(tiempo2 - tiempo1);
				cout << "\n";

				MostrarTablero(filaActual, columnaActual);

				cout << "\n\n";

				if (celda[columnaActual][filaActual].mina == 9)	// PERDIDA
				{
					cout << "Has perdido! F\n\n\n";
				}
				else if (!ChequeoVictoria())	//  VICTORIA
				{
					cout << "Has Ganado!\n";
					
					cout << "\n\n";
					cout << "Tiempo tomado: ";
					MostrarCronometro(tiempo2 - tiempo1);
					if (tiempo2 - tiempo1 < topPlayers[top - 1].segundos)	// SI ENTRA EN EL TOP, GUARDA PUNTUACION
					{
						cout << "\nHas entrado en el TOP!";
						if (dificultad == 3)
						{
							GuardarPuntuacion(tiempo2 - tiempo1);
							OrdenarTopPlayers();
						}
						else
						{
							cout << " Pero tu dificultad no cumple los requisitos. Jugar en Dificil para competir.";
						}
					}
					cout << "\n\n";
				}
			}

			system("pause");
			tipomenu = TIPOMENU::MENUPRINCIPAL;
			ResetearTablero();
			break;
		case TIPOMENU::REGLAS:

			system("cls");
			cout << title;
			cout << "Instrucciones de uso:\n\nENTER: Seleccionar\nWASD: Mover el cursor\n\n";

			cout << "El objetivo es descubrir todas las posiciones vacias, sin minas.\n";
			cout << "En caso de pisar una mina, pierdes.\n";
			cout << "En caso de que la casilla no sea mina, te va a mostrar la cantidad de minas que hay alrededor.\n";
			cout << "Si no hay ninguna, te mostrara las adyacentes, y asi suscesivamente hasta que haya alguna mina cerca alrededor.\n\n\n";

			system("pause");
			tipomenu = TIPOMENU::MENUPRINCIPAL;

			break;
		case TIPOMENU::CONFIGURACIONES:
			seleccionador = 1;
			do
			{
				if (configuraciones.minasTotales >= configuraciones.filasTotales * configuraciones.columnasTotales - 1)
					configuraciones.minasTotales = configuraciones.filasTotales * configuraciones.columnasTotales - 1;
				system("cls");
				cout << title;	//----------- MENU CONFIG ----------

				if (seleccionador == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << "Filas actuales: " << configuraciones.filasTotales << " (2 - " << tam << ").\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				if (seleccionador == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << "Columnas actuales: " << configuraciones.columnasTotales << " (2 - " << tam << ").\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				if (seleccionador == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << "Minas actuales: " << configuraciones.minasTotales << " (1 - " << configuraciones.filasTotales * configuraciones.columnasTotales - 1 << ").\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				if (seleccionador == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << "Ingreso manual de minas\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				if (seleccionador == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << "Volver al menu principal\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						//----------- FIN MENU CONFIG ----------
				
				input = _getch();
				tecla = (TECLAS)input;

				switch (tecla)
				{
				case TECLAS::ENTER:
					if (seleccionador == 4)
					{
						cout << "Cantidad de minas: ";
						cin >> input;

						configuraciones.minasTotales = input;
						if (configuraciones.minasTotales >= configuraciones.filasTotales * configuraciones.columnasTotales)
							configuraciones.minasTotales = configuraciones.filasTotales * configuraciones.columnasTotales - 1;
						else if (configuraciones.minasTotales < 1)
							configuraciones.minasTotales = 1;
					}
					else if (seleccionador == 5)
						tipomenu = TIPOMENU::MENUPRINCIPAL;

					break;

				case TECLAS::W:	// MUEVE HACIA ARRIBA
				case TECLAS::w:
					seleccionador--;
					if (seleccionador < 1) seleccionador = 1;
					break;

				case TECLAS::A:	// DISMINUYE CANTIDAD (DEL SELECCIONADO)
				case TECLAS::a:
					if (seleccionador == 1)
					{
						configuraciones.filasTotales--;
						if (configuraciones.filasTotales < 2)configuraciones.filasTotales = 2;
					}
					else if (seleccionador == 2)
					{
						configuraciones.columnasTotales--;
						if (configuraciones.columnasTotales < 2)configuraciones.columnasTotales = 2;
					}
					else if (seleccionador == 3)
					{
						configuraciones.minasTotales--;
						if (configuraciones.minasTotales < 1)configuraciones.minasTotales = 1;
					}
					break;

				case TECLAS::S:	// MUEVE HACIA ABAJO
				case TECLAS::s:
					seleccionador++;
					if (seleccionador > 5) seleccionador = 5;
					break;

				case TECLAS::D:	// AUMENTA CONTIDAD (DEL SELECCIONADO)
				case TECLAS::d:

					if (seleccionador == 1)
					{
						configuraciones.filasTotales++;
						if (configuraciones.filasTotales > tam - 1)configuraciones.filasTotales = tam;
					}
					else if (seleccionador == 2)
					{
						configuraciones.columnasTotales++;
						if (configuraciones.columnasTotales > tam - 1)configuraciones.columnasTotales = tam;
					}
					else if (seleccionador == 3)
					{
						configuraciones.minasTotales++;
						if (configuraciones.minasTotales > (configuraciones.filasTotales * configuraciones.columnasTotales - 1))configuraciones.minasTotales = configuraciones.filasTotales * configuraciones.columnasTotales - 1;
					}

					break;

				default:
					break;
				}

			} while (tipomenu != TIPOMENU::MENUPRINCIPAL);
			seleccionador = 1;

			configuraciones.dificultadPerzonalizado.minas = configuraciones.minasTotales;
			configuraciones.dificultadPerzonalizado.columnas = configuraciones.columnasTotales;
			configuraciones.dificultadPerzonalizado.filas = configuraciones.filasTotales;

			break;
		case TIPOMENU::TOP:

			system("cls");
			cout << title;
			cout << "TOP " << top << " JUGADORES:";
			OrdenarTopPlayers();
			MostrarTop();

			cout << "\n\n";
			system("pause");
			tipomenu = TIPOMENU::MENUPRINCIPAL;

			break;
		case TIPOMENU::SALIR:
			
			input = MenuSalir();
			if (input == 1)
				noCerrar = false;
			else
				tipomenu = TIPOMENU::MENUPRINCIPAL;

		default:
			break;
		}

	} while (noCerrar);
}

// MENU INTERACTIVO DE SALIDA
int MenuSalir()
{
	int input = 0;
	int seleccionador = 1;
	do
	{
		system("cls");
		cout << "---- Buscaminas FIX 2K20 Personalizable ----\t\t By: Fede O.\n\n";

		if (seleccionador == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		cout << "   1- Salir del juego         \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		if (seleccionador == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		cout << "   2- Continuar Jugando      \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		input = _getch();
		tecla = (TECLAS)input;

		switch (tecla)
		{
		case TECLAS::W:	// MUEVE A SALIR
		case TECLAS::w:

			seleccionador--;
			if (seleccionador < 1) seleccionador = 1;
			break;

		case TECLAS::S:	// MUEVE A CONTINUAR JUGANDO
		case TECLAS::s:

			seleccionador++;
			if (seleccionador > 2) seleccionador = 2;
			break;

		default:
			break;
		}
	} while (tecla != TECLAS::ENTER);
	return seleccionador;
}

//	Chequea si la celda pertenece a los límites del array
bool CeldaValida(int fil, int col)
{
	bool retorno = false;

	if (fil >= 0 && fil < configuraciones.filasTotales && col >= 0 && col < configuraciones.columnasTotales)
		retorno = true;

	return retorno;
}

//	Switch de colores para pintar los números
void SwitchColores(int celda, int visibilidad)
{
	bool visibilidadCelda = (configuraciones.xRay) ? true : visibilidad;

	if (visibilidadCelda)
		switch (celda)	// SEGUN EL VALOR DE LA CELDA (CANTIDAD DE MINAS CERCA 0-9)	// 48 cian - 64 rojo - 
		{
		case 0:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
			break;
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
			break;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			break;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
			break;
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
			break;
		case 6:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
			break;
		case 7:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
			break;
		case 8:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			break;
		case 9:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 192);
			break;
		default:
			break;
		}
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

void ResetearTablero()
{
	for (int i = 0; i < configuraciones.filasTotales; i++)
	{
		for (int z = 0; z < configuraciones.columnasTotales; z++)
		{
			celda[i][z].mina = 0;
			celda[i][z].visibilidad = 0;
			celda[i][z].bloqueo = false;
		}
	}
}

//	Crea por única vez el tablero (En cada nivel)
void CrearTableroMinas(int filaActual, int columnaActual)
{
	//Reseteo de valores
	int minas = configuraciones.minasTotales;
	
	ResetearTablero();

	//Asignacion de minas
	do
	{
		int col = rand() % configuraciones.columnasTotales;
		int fil = rand() % configuraciones.filasTotales;
				//	Que no sea mina   y       Que no sea la celda precionada
		if (celda[fil][col].mina != 9 && !(fil == filaActual && col == columnaActual))
		{
			celda[fil][col].mina = 9;

			//----- Sumo 1 a cada una de las circundantes -----
			for (int i = -1; i <= 1; i++)
			{
				for (int z = -1; z <= 1; z++)
				{
					if (CeldaValida(fil + i, col + z))
					{
						if (celda[fil + i][col + z].mina != 9)
						{
							celda[fil + i][col + z].mina++;
						}
					}
				}
			}

			minas--;
		}
	} while (minas != 0);
}

//	Muestra el tablero y los índices
void MostrarTablero(int filaActual, int columnaActual)
{
	char _185 = 185;  //  ╣
	char _186 = 186;  //  ║
	char _187 = 187;  //  ╗
	char _188 = 188;  //  ╝
	char _200 = 200;  //  ╚
	char _201 = 201;  //  ╔
	char _202 = 202;  //  ╩
	char _203 = 203;  //  ╦
	char _204 = 204;  //  ╠	
	char _205 = 205;  //  ═ 	
	char _206 = 206;  //  ╬	

	// INDICES SUPERIORES:
	cout << "    ";
	for (int i = 1; i < configuraciones.columnasTotales + 1; i++)
	{
		if (i < 10)
			cout << " ";
		cout << i << " " << " ";
	}
	cout << "\n";

	//DIBUJO TECHO
	cout << "   " << _201;
	for (int i = 0; i < configuraciones.columnasTotales; i++)
		cout << _205 << _205 << _205 << _203;
	cout << "\b" << _187;

	//DIBUJO MATRIZ
	for (int i = 0; i < configuraciones.filasTotales; i++)
	{
		cout << "\n";

		//INDICES LATERALES
		if (i + 1 < 10)
			cout << " ";
		cout << i + 1 << " ";

		//MATRIZ
		for (int z = 0; z < configuraciones.columnasTotales; z++)
		{
			cout << _186;
			if (columnaActual == i && filaActual == z)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 203);
				cout << "-";
				SwitchColores(celda[i][z].mina, celda[i][z].visibilidad);
				if (celda[i][z].bloqueo)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
					cout << configuraciones.banderinChar;
				}
				else
					cout << celda[i][z].mina;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 203);
				cout << "-";
			}
			else
			{
				SwitchColores(celda[i][z].mina, celda[i][z].visibilidad);
				if (celda[i][z].bloqueo)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
					cout << " " << configuraciones.banderinChar << " ";
				}
				else
					cout << " " << celda[i][z].mina << " ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		cout << _186;


		//ENTREPISOS
		cout << "\n" << "   " << _204;
		for (int i = 0; i < configuraciones.columnasTotales; i++)
			cout << _205 << _205 << _205 << _206;
		cout << "\b" << _185;
	}
	//DIBUJO PISO
	cout << "\r" << "   " << _200;
	for (int i = 0; i < configuraciones.columnasTotales; i++)
		cout << _205 << _205 << _205 << _202;
	cout << "\b" << _188;
}

//	Algoritmo de expansion: Recursivo
void MostrarCelda(int filaActual, int columnaActual)
{
	if (!celda[filaActual][columnaActual].visibilidad && CeldaValida(filaActual, columnaActual))
	{
		celda[filaActual][columnaActual].bloqueo = false;
		celda[filaActual][columnaActual].visibilidad = true;

		if (celda[filaActual][columnaActual].mina == 0)
		{										//								Algoritmo:
			for (int i = -1; i <= 1; i++)		// Chequea de Izq a Derecha		1	2	3
			{									//								4	x	6
				for (int z = -1; z <= 1; z++)	// Chequea de Arriba a Abajo	7	8	9
				{
					MostrarCelda(filaActual + z, columnaActual + i);
				}
			}
		}
	}
}

//	Mueve el "cursor"
void MoverMira(int& punteroX, int& punteroY)
{
	tecla = (TECLAS)_getch();

	switch (tecla)
	{
	case TECLAS::W:
	case TECLAS::w:
		//cout << "Hacia Arriba";
		punteroY--;
		if (punteroY < 0) punteroY = 0;
		break;

	case TECLAS::A:
	case TECLAS::a:

		//cout << "A la izquierda";
		punteroX--;
		if (punteroX < 0) punteroX = 0;

		break;

	case TECLAS::S:
	case TECLAS::s:
		//cout << "Hacia Abajo";
		punteroY++;
		if (punteroY > configuraciones.filasTotales - 1) punteroY = configuraciones.filasTotales - 1;
		break;

	case TECLAS::D:
	case TECLAS::d:

		//cout << "A la Derecha";
		punteroX++;
		if (punteroX > configuraciones.columnasTotales - 1) punteroX = configuraciones.columnasTotales - 1;

		break;

	default:
		//cout << "No corresponde.";
		break;
	}

}

//  Chequea si quedan posiciones libres
bool ChequeoVictoria()
{
	int contador = 0;
	for (int i = 0; i < configuraciones.filasTotales; i++)
	{
		for (int z = 0; z < configuraciones.columnasTotales; z++)
		{
			contador += celda[i][z].visibilidad;	// CUENTO LAS CELDAS VACIAS
		}
	}
	if (contador + configuraciones.minasTotales == configuraciones.filasTotales * configuraciones.columnasTotales)	// SI LAS CELDAS VACIAS + LAS MINAS ES IGUAL AL TOTAL DE CELDAS, ES PORQUE SE GANÓ
		return 0;	// PARA GANAR
	else
		return 1;	// CONTINUA JUGANDO
}

void MostrarCronometro(int segundos)
{
	int minutos = 0;
	if (segundos < 0)segundos = 0;
	minutos = 0;
	while (segundos >= 60)
	{
		segundos -= 60;
		minutos++;
	}
	if (minutos < 10) cout << "0";
	cout << minutos << ":";
	if (segundos < 10)cout << "0";
	cout << segundos;
}

void MostrarTop()
{
	for (int i = 0; i < top; i++)	// MUESTRO CADA UNO DE LOS TOP CON LAS 3 LETRAS Y EL TIEMPO
	{
		cout << "\nJugador: " << topPlayers[i].caracter01 << topPlayers[i].caracter02 << topPlayers[i].caracter03 << " Tiempo: ";
		MostrarCronometro(topPlayers[i].segundos);
	}
}

void OrdenarTopPlayers()
{
	for (int i = 0; i < top; i++)
	{
		for (int z = 0; z < top; z++)
		{
			if (topPlayers[i].segundos < topPlayers[z].segundos)	// BUBBLE SORT DE SEGUNDOS - PARA LAS 4 VARIABLES DEL STRUCT
			{
				char chAux = topPlayers[z].caracter01;
				topPlayers[z].caracter01 = topPlayers[i].caracter01;
				topPlayers[i].caracter01 = chAux;

				chAux = topPlayers[z].caracter02;
				topPlayers[z].caracter02 = topPlayers[i].caracter02;
				topPlayers[i].caracter02 = chAux;

				chAux = topPlayers[z].caracter03;
				topPlayers[z].caracter03 = topPlayers[i].caracter03;
				topPlayers[i].caracter03 = chAux;

				short intAux = topPlayers[z].segundos;
				topPlayers[z].segundos = topPlayers[i].segundos;
				topPlayers[i].segundos = intAux;
			}
		}
	}


}

void GuardarPuntuacion(int segundos)
{
	char char01letra = 'A';
	char char02letra = 'A';
	char char03letra = 'A';

	int seleccionador = 1;
	int input = 0;
	do
	{
		system("cls");
		cout << title;
		cout << "Muevase con WASD.\n";
		cout << "Enter: Terminar.\n\n";
		cout << "Guarde su tiempo: ";
		MostrarCronometro(segundos);
		cout << "\n\n\t\t";

		if (seleccionador == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		cout << char01letra;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		if (seleccionador == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		cout << char02letra;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		if (seleccionador == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		cout << char03letra;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		input = _getch();
		tecla = (TECLAS)input;

		switch (tecla)
		{
		case TECLAS::ENTER:	// FINALIZA EL GUARDADO
			seleccionador = 0;

			break;

		case TECLAS::W:	// VA A LETRA ANTERIOR
		case TECLAS::w:

			if (seleccionador == 1)
			{
				char01letra--;
				if (char01letra < 65) char01letra = 65;
			}
			else if (seleccionador == 2)
			{
				char02letra--;
				if (char02letra < 65) char02letra = 65;
			}
			else if (seleccionador == 3)
			{
				char03letra--;
				if (char03letra < 65) char03letra = 65;
			}
			break;

		case TECLAS::A:	// CAMBIA HACIA LA PRIMER LETRA
		case TECLAS::a:

			seleccionador--;
			if (seleccionador < 1) seleccionador = 1;
			break;

		case TECLAS::S:	// VA A LETRA INFERIOR
		case TECLAS::s:

			if (seleccionador == 1)
			{
				char01letra++;
				if (char01letra > 90) char01letra = 90;
			}
			else if (seleccionador == 2)
			{
				char02letra++;
				if (char02letra > 90) char02letra = 90;
			}
			else if (seleccionador == 3)
			{
				char03letra++;
				if (char03letra > 90) char03letra = 90;
			}
			break;

		case TECLAS::D:	// CAMBIA HACIA LA ULTIMA LETRA
		case TECLAS::d:

			seleccionador++;
			if (seleccionador > 3) seleccionador = 3;
			break;

		default:
			break;
		}
		cout << "\n";
	} while (seleccionador != 0);
	//GUARDA LAS VARIABLES AL STRUCT
	topPlayers[top - 1].caracter01 = char01letra;
	topPlayers[top - 1].caracter02 = char02letra;
	topPlayers[top - 1].caracter03 = char03letra;
	topPlayers[top - 1].segundos = segundos;
}