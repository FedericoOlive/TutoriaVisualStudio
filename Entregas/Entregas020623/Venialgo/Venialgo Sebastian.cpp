//tengo 5 jugadores y quiero 

#include <iostream>
#include <time.h>

using namespace std;

struct Cell
{
	int mina = 0;
	bool esVisible = false;
	bool estaBloqueada = false;
};

void inicializacion()
{
	srand(time(NULL));
}

void main()
{


	Cell arrayb[9] [9];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arrayb [i][j] .mina = rand()%9;
			int x = rand() % 1;
			int y = rand() % 1;
			
			if (x == 1)
			{
				arrayb[i][j].esVisible == false;
			}
			else { arrayb[i][j].esVisible == true; }
			
			if (y == 1)
			{
				arrayb[i][j].estaBloqueada == true;
			}
			else { arrayb[i][j].estaBloqueada == false; }

			if (arrayb[i][j].esVisible == false)
			{
				cout << "-\t";
			}
			else
			{
				if (arrayb[i][j].estaBloqueada == true)
				{
					cout << "¶\t";
				}
				else
				{
					cout << arrayb[i][j].mina<<"\n";

				}
			}
		}
		cout << "\n";
	}


}