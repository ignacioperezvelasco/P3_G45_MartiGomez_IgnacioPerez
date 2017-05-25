#include <iostream>
#include <map>
#include "Map.h"
#include "entios.h"
#include "Player.h"
#include <windows.h>

void main() 
{
	//INICIAR MAPA
	Map a("default.cfg");
	//INICIAR JUGADORES
	Player player2(a, '1', '2', '3', '4', '5', '6');
	Player player1(a, 'A', 'B', 'C', 'D', 'E', 'F');	
	

	a.printmapa();
	player1.currentio->atacar();
}