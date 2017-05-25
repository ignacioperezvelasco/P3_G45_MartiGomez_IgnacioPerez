#include "entios.h"



Entio::Entio() {}

Entio::Entio(char i,Map mapa):
	life{ 10 },
	fatiga{ 0 },
	currMap{ mapa },
	numflechas{ 10 }
{
	setEntioID(i);
	x = findx(i);
	y = findy(i);
}

Entio::~Entio()
{
}

int Entio::getlife()
{
	return life;
}

int Entio::getFatiga()
{
	return fatiga;
}

void Entio::mfatiga()
{
	fatiga += 1;
}

int Entio::getX()
{
	return x;
}

int Entio::getY()
{
	return y;
}

void Entio::setEntioID(char i)
{
	entioID = i;
}

int Entio::findx(char i)
{
	char aux;
	int x;
	for (int c = 0; c <= currMap.NUMROWS; c++) 
	{
		for (int j = 0; j <= currMap.NUMCOLUMNS; j++)
		{
			aux = currMap.md[c][j];
			x = j;
			if (aux == i) 
			{
				return x;
			}
		}
	}
}

int Entio::findy(char i)
{
	char aux;
	int y;
	for (int c = 0; c <= currMap.NUMROWS; c++)
	{
		for (int j = 0; j <= currMap.NUMCOLUMNS; j++)
		{
			aux = currMap.md[c][j];
			y = c;
			if (aux == i)
			{
				return y;
			}
		}
	
	}
}

void Entio::mover(char a)
{

}

void Entio::atacar()
{
	int arma;
	std::cout << std::endl;
	std::cout << "Que arma quieres usar?  1: Espada  2: Arco" << std::endl;
	std::cin >> arma ;
	if (arma == 1)
	{
		std::cout << "has escojido: Espada" << std::endl;
		/*switch (Input) {
		case W:
			cur;
			break; //optional
		case constant - expression:
			statement(s);
			break; //optional
		}*/
		
	}
	if (arma == 2)
	{
		std::cout << "has escojido: Arco" << std::endl;
	}

}