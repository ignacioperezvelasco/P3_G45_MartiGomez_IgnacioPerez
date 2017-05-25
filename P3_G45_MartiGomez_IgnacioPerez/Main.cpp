#include <iostream>
#include <map>
#include "Map.h"
#include "entios.h"
#include "Player.h"

void main() 
{
	//INICIAR MAPA
	Map a("default.cfg");
	//INICIAR JUGADORES
	Player player1(a, 'A', 'B', 'C', 'D', 'E', 'F');	

	Player player2(a, '1', '2', '3', '4', '5', '6');

	//VARIABLE DE MOVIMIENTO
	enti::InputKey k;
	a.printmapa();
	do
	{
		k = enti::getInputKey();
		player1.update_player(k);
		if (k != enti::InputKey::NONE) {
			system("cls");
			a.printmapa();
		}
	} while (true);

}