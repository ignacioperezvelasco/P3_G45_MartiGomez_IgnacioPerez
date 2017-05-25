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