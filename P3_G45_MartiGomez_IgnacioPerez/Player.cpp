#include "Player.h"


Player::Player(Map mapa, char a, char b, char c, char d, char e, char f):
	numacciones{ 10 },
	currmap{ mapa },
	currentio{&myEntios[a]}

{
	myEntios[a]=Entio(a,currmap);
	myEntios[b] = Entio(b, currmap);
	myEntios[c] = Entio(c, currmap);
	myEntios[d] = Entio(d, currmap);
	myEntios[e] = Entio(e, currmap);
	myEntios[f] = Entio(f, currmap);
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

void Player::empezarTurno()
{
	int aux = currentio->fatiga;
	Entio* aux2=currentio;

	for (int i = 0; i < 10; i++)
	{
		if (aux > myEntios[i].fatiga) {
			aux = myEntios[i].fatiga;
			aux2 = &myEntios[i];
		}
	}
	if (currentio != aux2) 
	{
		currentio = aux2;
		gastaraccion();
	}
}