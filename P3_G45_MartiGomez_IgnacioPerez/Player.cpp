#include "Player.h"

Player::Player(Map mapa, char a, char b, char c, char d, char e, char f):
	numacciones{ 10 },
	currmap{ mapa },
	currentio{&myEntios[0]}

{
	myEntios[0] = Entio(a, currmap);
	myEntios[1] = Entio(b, currmap);
	myEntios[2] = Entio(c, currmap);
	myEntios[3] = Entio(d, currmap);
	myEntios[4] = Entio(e, currmap);
	myEntios[5] = Entio(f, currmap);
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::gastaraccion()
{
	numacciones--;
}

void Player::cambiarentio(int i)
{
	currentio = &myEntios[i];
}