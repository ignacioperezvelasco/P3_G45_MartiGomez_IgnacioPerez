#pragma once
#include "entios.h"
#include "Map.h"
#include <map>
#include "Input.inl.hh"

class Player
{
public:
	Map currmap;
	int numacciones;
	std::map<char,Entio> myEntios;
	
	Entio* currentio;

	void gastaraccion();
	void empezarTurno();

	void update_player(enti::InputKey key);									//MOVIMIENTO JUGADOR
	void cambiarEntio();
	void deshacerEntio();
	void rehacerEntio();

	int getNumaccions();
	void setNumaccions(int num);
	Player(Map mapa,char a, char b, char c, char d, char e,char f);
	Player();



	~Player();
};

