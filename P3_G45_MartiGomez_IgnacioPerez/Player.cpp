#include "Player.h"
#include "Input.inl.hh"


Player::Player(Map &mapa, char a, char b, char c, char d, char e, char f):
	numacciones{ 10 },
	currmap{ mapa }
{
	myEntios[a]=Entio(a,currmap);
	entios[0] = &myEntios[a];
	myEntios[b] = Entio(b, currmap);
	entios[1] = &myEntios[b];
	myEntios[c] = Entio(c, currmap);
	entios[2] = &myEntios[c];
	myEntios[d] = Entio(d, currmap);
	entios[3] = &myEntios[d];
	myEntios[e] = Entio(e, currmap);
	entios[4] = &myEntios[e];
	myEntios[f] = Entio(f, currmap);
	entios[5] = &myEntios[f];
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

void Player::entioMenosFatigado()
{
	int aux = currentio->fatiga;
	int count=0;
	Entio* aux2=entios[0];

	for (int i = 0; i < 6; i++)
	{
		if (aux > entios[i]->fatiga) {
			aux = entios[i]->fatiga;
			aux2 = entios[i];
			count++;
		}
	}
	if ((currentio != aux2) && (count !=0))
	{
		currentio = aux2;
		gastaraccion();
	}
	
}

void Player::deshacerAccion()
{
	if ((l_X >= -1) && (l_Y >=-1)) {
		char next = currentio->beforeEntio;

		int aux_x = currentio->x;
		int aux_y = currentio->y;

		currentio->x = l_X;
		currentio->y = l_Y;

		l_X = aux_x;
		l_Y = aux_y;

		//UPDATEAMOS LA POSICION DEL JUGADOR
		currmap.cambiarpunto(aux_x, aux_y, next);
		currmap.cambiarpunto(l_X, l_Y, currentio->entioID);
		
	}
	
}

void Player::rehacerAccion()
{
}

void Player::update_player(enti::InputKey key)
{
	int previous_x = currentio->x;
	int previous_y = currentio->y;
	char next=currentio->beforeEntio;
	int count = 0;

	switch (key)
	{
	case enti::InputKey::W:
		if (currentio->x  > 0)
		{
			if ((currmap.md[currentio->x - 1][currentio->y] == 'X') || (currmap.md[currentio->x - 1][currentio->y] == 'O')|| (currmap.md[currentio->x - 1][currentio->y] == 'F') || (currmap.md[currentio->x - 1][currentio->y] == 'E') || (currmap.md[currentio->x - 1][currentio->y] == 'D')|| (currmap.md[currentio->x - 1][currentio->y] == 'C') || (currmap.md[currentio->x - 1][currentio->y] == 'B') || (currmap.md[currentio->x - 1][currentio->y] == 'A') || (currmap.md[currentio->x - 1][currentio->y] == '1') || (currmap.md[currentio->x - 1][currentio->y] == '2') || (currmap.md[currentio->x - 1][currentio->y] == '3') || (currmap.md[currentio->x - 1][currentio->y] == '4') || (currmap.md[currentio->x - 1][currentio->y] == '5') || (currmap.md[currentio->x - 1][currentio->y] == '6'))
			{
				break;
			}
			else {
				//GUARDAMOS ÚLTIMO MOVIMIENTO
				l_X = currentio->x;
				l_Y = currentio->y;

				currentio->beforeEntio = currmap.md[currentio->x - 1][currentio->y];
				currentio->x = currentio->x - 1;				
				currentio->mfatiga();
				gastaraccion();
				count++;
			}
		}
		break;
	case enti::InputKey::A:
		if (currentio->y > 0)
		{
			if ((currmap.md[currentio->x ][currentio->y-1] == 'X')|| (currmap.md[currentio->x ][currentio->y-1] == 'O')|| (currmap.md[currentio->x][currentio->y - 1] == 'F') || (currmap.md[currentio->x][currentio->y - 1] == 'E') || (currmap.md[currentio->x][currentio->y - 1] == 'D') || (currmap.md[currentio->x][currentio->y - 1] == 'C') || (currmap.md[currentio->x][currentio->y - 1] == 'B') || (currmap.md[currentio->x][currentio->y - 1] == 'A') || (currmap.md[currentio->x][currentio->y - 1] == '1') || (currmap.md[currentio->x][currentio->y - 1] == '2') || (currmap.md[currentio->x][currentio->y - 1] == '3') || (currmap.md[currentio->x][currentio->y - 1] == '4') || (currmap.md[currentio->x][currentio->y - 1] == '5') || (currmap.md[currentio->x][currentio->y - 1] == '6'))
			{
				break;
			}
			else {
				//GUARDAMOS ÚLTIMO MOVIMIENTO
				l_X = currentio->x;
				l_Y = currentio->y;

				currentio->beforeEntio = currmap.md[currentio->x][currentio->y - 1];
				currentio->y = currentio->y - 1;
				currmap.md[currentio->x][currentio->y] = currentio->entioID;
				currentio->mfatiga();
				gastaraccion();
				count++;
			}
		}
		break;
	case enti::InputKey::S:
		if (currentio->x < currmap.NUMROWS - 1)
		{
			if ((currmap.md[currentio->x + 1][currentio->y] == 'X') || (currmap.md[currentio->x + 1][currentio->y] == 'O') || (currmap.md[currentio->x + 1][currentio->y] == 'F') || (currmap.md[currentio->x + 1][currentio->y] == 'E') || (currmap.md[currentio->x + 1][currentio->y] == 'D') || (currmap.md[currentio->x + 1][currentio->y] == 'C') || (currmap.md[currentio->x + 1][currentio->y] == 'B') || (currmap.md[currentio->x + 1][currentio->y] == 'A') || (currmap.md[currentio->x + 1][currentio->y] == '1') || (currmap.md[currentio->x + 1][currentio->y] == '2') || (currmap.md[currentio->x + 1][currentio->y] == '3') || (currmap.md[currentio->x + 1][currentio->y] == '4') || (currmap.md[currentio->x + 1][currentio->y] == '5') || (currmap.md[currentio->x + 1][currentio->y] == '6'))
			{
				break;
			}
			else {
				//GUARDAMOS ÚLTIMO MOVIMIENTO
				l_X = currentio->x;
				l_Y = currentio->y;

				currentio->beforeEntio = currmap.md[currentio->x + 1][currentio->y];
				currentio->x = currentio->x + 1;
				currmap.md[currentio->x][currentio->y] = currentio->entioID;
				currentio->mfatiga();
				gastaraccion();
				count++;
			}
		}
		break;
	case enti::InputKey::D:
		if (currentio->y < currmap.NUMCOLUMNS - 1)
		{
			if ((currmap.md[currentio->x ][currentio->y+1] == 'X') || (currmap.md[currentio->x ][currentio->y+1] == 'O') || (currmap.md[currentio->x][currentio->y + 1] == 'O') || (currmap.md[currentio->x][currentio->y + 1] == 'F') || (currmap.md[currentio->x][currentio->y + 1] == 'E') || (currmap.md[currentio->x][currentio->y + 1] == 'D') || (currmap.md[currentio->x][currentio->y + 1] == 'C') || (currmap.md[currentio->x][currentio->y + 1] == 'B') || (currmap.md[currentio->x][currentio->y + 1] == 'A') || (currmap.md[currentio->x][currentio->y + 1] == '1') || (currmap.md[currentio->x][currentio->y + 1] == '2') || (currmap.md[currentio->x][currentio->y + 1] == '3') || (currmap.md[currentio->x][currentio->y + 1] == '4') || (currmap.md[currentio->x][currentio->y + 1] == '5') || (currmap.md[currentio->x][currentio->y + 1] == '6'))
			{
				break;
			}
			else {
				//GUARDAMOS ÚLTIMO MOVIMIENTO
				l_X = currentio->x;
				l_Y = currentio->y;


				currentio->beforeEntio = currmap.md[currentio->x][currentio->y + 1];
				currentio->y = currentio->y + 1;
				currmap.md[currentio->x][currentio->y] = currentio->entioID;

				currentio->mfatiga();
				gastaraccion();
				count++;
			}
		}
		break;
	case enti::InputKey::z:
		deshacerAccion();
		break;
	case enti::InputKey::SPACEBAR:

		break;
	case enti::InputKey::ENTER:
		entioMenosFatigado();
		break;
	}
	

	//UPDATEAMOS LA POSICION DEL JUGADOR
	if (count !=0){
		currmap.cambiarpunto(previous_x, previous_y, next);
		currmap.cambiarpunto(currentio->x, currentio->y, currentio->entioID);
	}
}

void Player::lastMove()
{
}

void Player::newMove()
{
}

void Player::ataque(Player &player, enti::InputKey k)
{
	Entio* aux;
	//hacer cout cin para saber espada/arco

	//pedir otro input para saber direccion
	
	//arco
	//derecha
	if (k==enti::InputKey::NUM1)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((player.entios[i]->y == currentio->y) && (player.entios[i]->x > currentio->x))
			{
				int proximidad = player.entios[i]->x - currentio->x;
				int proximidadAux = aux->x - currentio->x;
				if (aux == nullptr || (proximidad < proximidadAux))
				{

					aux = player.entios[i];
				}
			}
		}
	}
	//izquierda
	else if (k == enti::InputKey::NUM2)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((player.entios[i]->y == currentio->y) && (player.entios[i]->x < currentio->x))
			{
				int proximidad = currentio->x-player.entios[i]->x ;
				int proximidadAux = -currentio->x-aux->x;
				if (aux == nullptr || (proximidad < proximidadAux))
				{
					aux = player.entios[i];
				}
			}
		}
	}
	//arriba
	else if(k == enti::InputKey::NUM3)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((player.entios[i]->y == currentio->y) && (player.entios[i]->x > currentio->x))
			{
				int proximidad = player.entios[i]->x - currentio->x;
				int proximidadAux = aux->x - currentio->x;
				if (aux == nullptr || (proximidad < proximidadAux))
				{

					aux = player.entios[i];
				}
			}
		}
	}
	//abajo
	else if(k == enti::InputKey::NUM4)
	{

	}

	//restarle al aux->life deletear en caso de que sea aux-<life<0;
}
