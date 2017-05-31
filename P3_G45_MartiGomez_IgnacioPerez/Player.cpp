#include "Player.h"
#include "Input.inl.hh"


Player::Player(Map &mapa, char a, char b, char c, char d, char e, char f) :
	numacciones{ 100 },
	currmap{ mapa },
	wantToPickWeapon {false},
	pickedWeapon{ false },
	arma{enti::InputKey::NONE},
	direction{ enti::InputKey::NONE },
	up{false},
	left{ false },
	down{ false },
	right{ false }

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

	int aux = 1000;//malapraxis
	int count=0;
	Entio* aux2=entios[0];

	for (int i = 0; i < 6; i++)
	{
		if(entios[i]!=nullptr){
			if (aux > entios[i]->fatiga) {
				if (entios[i] != nullptr)
				{
					aux = entios[i]->fatiga;
					aux2 = entios[i];
				}
			}			
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

void Player::info(Player &player)
{
	int i;

	enti::cout << enti::endl;
	enti::cout << enti::Color::LIGHTGREEN << "Remaining movements: ";
	enti::cout << enti::Color::WHITE << numacciones << enti::endl;

	enti::cout << enti::Color::LIGHTGREEN << "Now moves character ";
	enti::cout << enti::Color::WHITE << currentio->entioID << enti::endl;


	if (wantToPickWeapon == true)
	{
		enti::cout << enti::endl;
		enti::cout << enti::Color::WHITE << "Enter the weapon you want to choose:  " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "1 - SWORD " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "2 - BOW" << enti::endl;
		arma = enti::getInputKey();
		if (arma == enti::InputKey::NUM1 || arma == enti::InputKey::NUM2)
		{
			pickedWeapon = true;
		}
	}
	if (pickedWeapon == true)
	{
		wantToPickWeapon = false;
		enti::cout << enti::endl;
		enti::cout << enti::Color::WHITE << "Enter the direction to attack:  " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "1 - UP " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "2 - LEFT" << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "3 - DOWN " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "4 - RIGHT" << enti::endl;
		direction = enti::getInputKey();

		if (direction == enti::InputKey::NUM1)
		{
			up = true;
		}
		else if (direction == enti::InputKey::NUM2)
		{
			left = true;
		}
		else if (direction == enti::InputKey::NUM3)
		{
			down = true;
		}
		else if (direction == enti::InputKey::NUM4)
		{
			right = true;
		}
	}
	//SWORD
	if (up == true)
	{
		Entio* comprobar;
		pickedWeapon = false;
		i = 0;
		comprobar= player.entios[i];
		
		do
		{
			if (i == 5)
			{
				up = false;
				comprobar = nullptr;
				
			}
			else {
				comprobar = player.entios[i];
			
				if ((player.entios[i]->x == currentio->x - 1) && (player.entios[i]->y == currentio->y))
				{
					player.entios[i]->life -= 10;
					currmap.md[player.entios[i]->x][player.entios[i]->y] = player.entios[i]->beforeEntio;
					player.myEntios.erase(player.entios[i]->entioID);
					player.entios[i] = nullptr;		
					
					comprobar = nullptr;
					up = false;
				}
			}

			i++;
		} while (comprobar != nullptr);
		
	}
	if (left == true)
	{
		Entio* comprobar;
		pickedWeapon = false;
		i = 0;
		comprobar = player.entios[i];

		do
		{
			if (i == 5)
			{
				up = false;
				comprobar = nullptr;

			}
			else {
				comprobar = player.entios[i];

				if ((player.entios[i]->x == currentio->x) && (player.entios[i]->y == currentio->y-1))
				{
					player.entios[i]->life -= 10;
					currmap.md[player.entios[i]->x][player.entios[i]->y] = player.entios[i]->beforeEntio;
					player.myEntios.erase(player.entios[i]->entioID);
					player.entios[i] = nullptr;
					
					comprobar = nullptr;
					left = false;
				}
			}
			i++;
		} while (comprobar != nullptr);

	}
	if (down == true)
	{
		Entio* comprobar;
		pickedWeapon = false;
		i = 0;
		comprobar = player.entios[i];

		do
		{
			if (i == 5)
			{
				up = false;
				comprobar = nullptr;

			}
			else {
				comprobar = player.entios[i];

				if ((player.entios[i]->x == currentio->x+1) && (player.entios[i]->y == currentio->y))
				{
					player.entios[i]->life -= 10;
					currmap.md[player.entios[i]->x][player.entios[i]->y] = player.entios[i]->beforeEntio;
					player.myEntios.erase(player.entios[i]->entioID);
					player.entios[i] = nullptr;
					
					comprobar = nullptr;
					down = false;
				}
			}
			i++;
		} while (comprobar != nullptr);

	}
	if (right == true)
	{
		Entio* comprobar;
		pickedWeapon = false;
		i = 0;
		comprobar = player.entios[i];

		do
		{
			if (i == 5)
			{
				up = false;
				comprobar = nullptr;

			}
			else {
				comprobar = player.entios[i];

				if ((player.entios[i]->x == currentio->x) && (player.entios[i]->y == currentio->y+1))
				{
					player.entios[i]->life -= 10;
					currmap.md[player.entios[i]->x][player.entios[i]->y] = player.entios[i]->beforeEntio;
					player.myEntios.erase(player.entios[i]->entioID);
					player.entios[i] = nullptr;
					
					comprobar = nullptr;
					right = false;
					
				}
			}
			i++;
		} while (comprobar != nullptr);

	}
	//BOW
	enti::cout << enti::cend;
}

void Player::update_player(enti::InputKey key, Player &player)
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
				//GUARDAMOS �LTIMO MOVIMIENTO
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
				//GUARDAMOS �LTIMO MOVIMIENTO
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
				//GUARDAMOS �LTIMO MOVIMIENTO
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
				//GUARDAMOS �LTIMO MOVIMIENTO
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
		wantToPickWeapon = true;

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

void Player::selectEntio()
{
	if (currentio == nullptr)
	{
		for (int i = 0; i < 5; i++)
		{
			if (entios[i] != nullptr)
			{
				currentio = entios[i];
			}
		}
	}
}

void Player::ataque(Player &player)
{
	enti::InputKey k;
	enti::InputKey arma;
	Entio* aux;
	aux = nullptr;
	//hacer cout cin para saber espada/arco

	do {
		enti::cout << enti::Color::WHITE << "Enter the weapon you want to choose:  " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "1 - SWORD " << enti::endl;
		enti::cout << enti::Color::LIGHTGREEN << "2 - BOW" << enti::endl;
		arma=enti::getInputKey();
		enti::cout << enti::cend;
	} while (arma !=enti::InputKey::NUM1 || arma != enti::InputKey::NUM2);

	//pedir otro input para saber direccion
	do {
	enti::cout << enti::Color::WHITE << "Enter the direction to attack:  " << enti::endl;
	enti::cout << enti::Color::LIGHTGREEN << "1 - UP " << enti::endl;
	enti::cout << enti::Color::LIGHTGREEN << "2 - LEFT" << enti::endl;
	enti::cout << enti::Color::LIGHTGREEN << "3 - DOWN " << enti::endl;
	enti::cout << enti::Color::LIGHTGREEN << "4 - RIGHT" << enti::endl;
	k = enti::getInputKey();
	//enti::cout << enti::cend;
	} while (k != enti::InputKey::NUM1 || k != enti::InputKey::NUM2 || k != enti::InputKey::NUM3 || k != enti::InputKey::NUM4);
	

	//arco
	if (arma == enti::InputKey::NUM2)
	{
		//derecha
		if (k == enti::InputKey::NUM1)
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
					int proximidad = currentio->x - player.entios[i]->x;
					int proximidadAux = -currentio->x - aux->x;
					if (aux == nullptr || (proximidad < proximidadAux))
					{
						aux = player.entios[i];
					}
				}
			}
		}
		//arriba
		else if (k == enti::InputKey::NUM3)
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
		else if (k == enti::InputKey::NUM4)
		{
			for (int i = 0; i < 6; i++)
			{
				if ((player.entios[i]->y == currentio->y) && (player.entios[i]->x > currentio->x))
				{
					int proximidad = currentio->x - player.entios[i]->x;
					int proximidadAux = -currentio->x - aux->x;
					if (aux == nullptr || (proximidad < proximidadAux))
					{

						aux = player.entios[i];
					}
				}
			}
		}
	}
	
	//Espada
	else if (arma == enti::InputKey::NUM1)
	{
		//derecha
		if (k == enti::InputKey::NUM1)
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
					int proximidad = currentio->x - player.entios[i]->x;
					int proximidadAux = -currentio->x - aux->x;
					if (aux == nullptr || (proximidad < proximidadAux))
					{
						aux = player.entios[i];
					}
				}
			}
		}
		//arriba
		else if (k == enti::InputKey::NUM3)
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
		else if (k == enti::InputKey::NUM4)
		{
			for (int i = 0; i < 6; i++)
			{
				if ((player.entios[i]->y == currentio->y) && (player.entios[i]->x > currentio->x))
				{
					int proximidad = currentio->x - player.entios[i]->x;
					int proximidadAux = -currentio->x - aux->x;
					if (aux == nullptr || (proximidad < proximidadAux))
					{

						aux = player.entios[i];
					}
				}
			}
		}
	}
	//enti::cout << enti::cend;

	//restarle al aux->life deletear en caso de que sea aux-<life<0;

}
