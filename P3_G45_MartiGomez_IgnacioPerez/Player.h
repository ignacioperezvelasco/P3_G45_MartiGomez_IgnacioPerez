#pragma once
#include "entios.h"
#include "Map.h"
#include <map>
#include "Input.inl.hh"

class Player
{
public:
	//ATRIBUTOS
	Map currmap;
	int numacciones;
	std::map<char,Entio> myEntios;
	bool wantToPickWeapon;
	bool pickedWeapon;
	//ataque
	bool up;
	bool left;
	bool down;
	bool right;


	enti::InputKey arma;
	enti::InputKey direction;

	//GUARDAMOS ULTIMOS MOVIMIENTOS
	int l_X;
	int l_Y;
	
	Entio* currentio;
	Entio* entios[6];

	void gastaraccion();
	void entioMenosFatigado();
	void deshacerAccion();
	void rehacerAccion();
	void info(Player &player);
	//void finalizarTurno();

	void update_player(enti::InputKey key, Player &player);			//MOVIMIENTO JUGADOR
	void lastMove();								//DESHACER NOVIMIENTO
	void newMove();									//REHACER MOVIMIENTO
	void ataque(Player &player);

	Player(Map &mapa,char a, char b, char c, char d, char e,char f);
	Player();

	

	~Player();
};

