#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
class Map
{
public:
	//atributos
	enum class terreno
	{
		WATER = 'O',
		MOUNTAIN = 'X',
		FOREST = ':',
		GROUND = '.',
		MAX			
	};

	int NUMROWS;
	int NUMCOLUMNS;
	char **md;

	//
	void printmapa();
	void leerfichero(std::string URL);
	void cambiarpunto(int x, int y, char nuevoelemento);

	Map();
	Map::Map(std::string URL);
	~Map();
};

