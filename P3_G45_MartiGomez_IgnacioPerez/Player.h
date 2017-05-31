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
	//ataque SWORD
	bool up_S;
	bool left_S;
	bool down_S;
	bool right_S;

	//ataque BOW
	bool up_B;
	bool left_B;
	bool down_B;
	bool right_B;

	//arma
	bool sword;
	bool bow;

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
	void selectEntio();

	Player(Map &mapa,char a, char b, char c, char d, char e,char f);
	Player();

	

	~Player();
};

