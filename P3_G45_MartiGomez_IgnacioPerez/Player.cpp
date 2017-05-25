#include "Player.h"
#include "Input.inl.hh"


Player::Player(Map mapa, char a, char b, char c, char d, char e, char f):
	numacciones{ 10 },
	currmap{ mapa }
	

{
	myEntios[a]=Entio(a,currmap);
	myEntios[b] = Entio(b, currmap);
	myEntios[c] = Entio(c, currmap);
	myEntios[d] = Entio(d, currmap);
	myEntios[e] = Entio(e, currmap);
	myEntios[f] = Entio(f, currmap);
	currentio = &myEntios[a];
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

void Player::update_player(enti::InputKey key)
{
	int previous_x = currentio->x;
	int previous_y = currentio->y;
	char next=currentio->beforeEntio;

	switch (key)
	{
	case enti::InputKey::W:
		if (currentio->x  > 0)
		{
			if ((currmap.md[currentio->x - 1][currentio->y] == 'X') || (currmap.md[currentio->x - 1][currentio->y] == 'O'))
			{
				break;
			}
			else {
				currentio->beforeEntio = currmap.md[currentio->x - 1][currentio->y];
				currentio->x = currentio->x - 1;
			}
		}
		break;
	case enti::InputKey::A:
		if (currentio->y > 0)
		{
			if ((currmap.md[currentio->x ][currentio->y-1] == 'X')|| (currmap.md[currentio->x ][currentio->y-1] == 'O'))
			{
				break;
			}
			else {
				currentio->beforeEntio = currmap.md[currentio->x][currentio->y - 1];
				currentio->y = currentio->y - 1;
			}
		}
		break;
	case enti::InputKey::S:
		if (currentio->x < currmap.NUMROWS - 1)
		{
			if ((currmap.md[currentio->x + 1][currentio->y] == 'X') || (currmap.md[currentio->x + 1][currentio->y] == 'O'))
			{
				break;
			}
			else {
				currentio->beforeEntio = currmap.md[currentio->x + 1][currentio->y];
				currentio->x = currentio->x + 1;
			}
		}
		break;
	case enti::InputKey::D:
		if (currentio->y < currmap.NUMCOLUMNS - 1)
		{
			if ((currmap.md[currentio->x ][currentio->y+1] == 'X') || (currmap.md[currentio->x ][currentio->y+1] == 'O'))
			{
				break;
			}
			else {
				currentio->beforeEntio = currmap.md[currentio->x][currentio->y + 1];
				currentio->y = currentio->y + 1;
			}
		}
		break;
	}
	

	//UPDATEAMOS LA POSICION DEL JUGADOR
	currmap.cambiarpunto(previous_x, previous_y, next);
	currmap.cambiarpunto( currentio->x, currentio->y, currentio->entioID);
}