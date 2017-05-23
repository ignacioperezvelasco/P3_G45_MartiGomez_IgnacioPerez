#pragma once
#include <string>
#include <iostream>
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

	int numRows;
	int numColumns;
	char **md;
	//
	Map(int dificultat);
	void inicializarmapa();
	void printmapa();
	void cambiarpunto(int x, int y, char nuevoelemento);

	Map();
	~Map();
};

