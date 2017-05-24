#pragma once
#include "Input.inl.hh"
#include "Map.h"
class entios
{
public:
	//atributos

	Map currMap;

	int life;
	int fatiga;
	int x, y;
	char beforeEntio;
	int numflechas;
	char entioID;

	int getlife();
	int getFatiga();
	void mfatiga();
	int getX();
	int getY();
	void setEntioID(char i);
	
	int findx(char i);
	int findy(char i);

	void mover(char a);

	void atacar(char a);

	entios::entios(char i, Map mapa);
	entios();
	~entios();
};

