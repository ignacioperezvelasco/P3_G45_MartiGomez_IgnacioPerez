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
			std::cout << md[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::cambiarpunto(int x, int y, char a) 
{
	md[x][y] = a;
}