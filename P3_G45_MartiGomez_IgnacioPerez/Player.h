#pragma once
#include "entios.h"
#include "Map.h"
#include <map>
class Player
{
public:
	Map currmap;
	int numacciones;
	std::map<char,Entio> myEntios;
	
	Entio* currentio;

	void gastaraccion();
	void empezarTurno();


	Player(Map mapa,char a, char b, char c, char d, char e,char f);
	Player();

	~Player();
};

