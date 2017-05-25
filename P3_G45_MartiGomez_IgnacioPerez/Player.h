#pragma once
#include "entios.h"
#include "Map.h"
class Player
{
public:
	Map currmap;
	int numacciones;
	Entio myEntios[6];
	Entio* currentio;

	void gastaraccion();

	void cambiarentio(int i);

	Player(Map mapa,char a, char b, char c, char d, char e,char f);
	Player();

	~Player();
};

