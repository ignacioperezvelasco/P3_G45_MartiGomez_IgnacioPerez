#include "Map.h"

Map::Map() {};

Map::Map(std::string URL):
	NUMCOLUMNS(73),
	NUMROWS(36)
{

	md = new char *[NUMROWS];
	for (int i = 0; i < NUMROWS; i++) {
		md[i] = new char[NUMCOLUMNS+1];
	}
	leerfichero(URL);
}

Map::~Map()
{
}

void Map::leerfichero(std::string URL)
{	
	std::ifstream fichero;
	std::string aux;
	//char casilla;
	int j = 0;
	
	fichero.open(URL);

	if (fichero.fail())
	{
		system("pause");
	}
	else {
		while (std::getline(fichero, aux))
		{

			for (int i = 0; i < NUMCOLUMNS; i++)
			{
				md[j][i] = aux[i];
			}

			j++;

		}
	}

	fichero.close();
}

void Map::printmapa()
{
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOLUMNS; j++)
		{
			if (md[i][j] == 'O')
			{
				enti::cout << enti::Color::LIGHTCYAN << md[i][j] << " ";
			}
			else if (md[i][j] == 'X')
			{
				enti::cout << enti::Color::LIGHTRED << md[i][j] << " ";
			}
			else if (md[i][j] == ':')
			{
				enti::cout << enti::Color::LIGHTGREEN << md[i][j] << " ";
			}
			else if (md[i][j] == '.')
			{
				enti::cout << enti::Color::WHITE << md[i][j] << " ";
			}
			else if (md[i][j] == 'A' || md[i][j] == 'B' || md[i][j] == 'C' || md[i][j] == 'D' || md[i][j] == 'E' || md[i][j] == 'F')
			{
				enti::cout << md[i][j] << " ";
			}
			else if (md[i][j] == '1' || md[i][j] == '2' || md[i][j] == '3' || md[i][j] == '4' || md[i][j] == '5' || md[i][j] == '6')
			{
				enti::cout << md[i][j] << " ";
			}
		}
		enti::cout << enti::endl;
	}
	//enti::cout << enti::cend;
}

void Map::help()
{
	enti::cout << enti::Color::LIGHTGREEN << "CLASH OF ENTIOS" << enti::endl;
	enti::cout << enti::endl;

	enti::cout << enti::Color::WHITE << "- Each player has 6 entios." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use WASD to move each entio."  << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use Z to undo a movement."  << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each entio has 2 weapons: 1 sword and 1 bow."  << enti::endl;
	enti::cout << enti::Color::WHITE << "- Press the SPACEBAR to use a weapon."  << enti::endl;
	enti::cout << enti::Color::WHITE << "- The sword can instantly kill an enemy if it is place in a cell next door."<< enti::endl;
	enti::cout << enti::Color::WHITE << "- The bow can damage an enemy within a maxium distance of a 10 cells." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each character has oly 10 arrows."<< enti::endl;
	enti::cout << enti::Color::WHITE << "- Each turn the less fatigued entio will play first."<< enti::endl;
	enti::cout << enti::Color::WHITE << "- To play with the next entio press ENTER." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each player can do 10 of these actions" << enti::endl;
	enti::cout << enti::endl;

	enti::cout << enti::Color::BLUE << "Press any key to begin the game!" << enti::endl;
	enti::cout << enti::cend;
}



void Map::cambiarpunto(int x, int y, char a) 
{
	md[x][y] = a;
}