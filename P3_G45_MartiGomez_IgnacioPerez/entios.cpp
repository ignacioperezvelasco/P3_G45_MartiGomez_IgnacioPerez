#include "entios.h"


entios::entios() {}

entios::entios(char i,Map mapa):
	life{ 10 },
	fatiga{ 0 },
	currMap{ mapa },
	numflechas{ 10 }
{
	setEntioID(i);
	x = findx(i);
	y = findy(i);
}


entios::~entios()
{
}

int entios::getlife()
{
	return life;
}

int entios::getFatiga()
{
	return fatiga;
}

void entios::mfatiga()
{
	fatiga += 1;
}

int entios::getX()
{
	return x;
}

int entios::getY()
{
	return y;
}

void entios::setEntioID(char i)
{
	entioID = i;
}

int entios::findx(char i)
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

int entios::findy(char i)
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