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

	//PRINTAMOS MAPA Y AYUDA
	a.help();
	system("pause > nul");
	
	system("cls");
	a.printmapa();

	//EMPIEZA EL JUGADOR 1
	
	bool pl1 = true;
	player1.info(player2);
	do
	{
		a.printmapa();
		
		k = enti::getInputKey();
		//player1 starts
		if (pl1) {
			player1.update_player(k,player2);
			if (player1.numacciones <= 0) 
			{
				pl1 = false;
				player1.numacciones = 10;
				
			}
		}
		else 
		{
			player2.update_player(k,player1);
			if (player2.numacciones <= 0)
			{
				pl1 = true;
				player2.numacciones = 10;
			}
		}
		if (pl1 == false)
		{
			player2.info(player1);
		}
		else
		{
			player1.info(player2);
		}
		//enti::cout << enti::cend;

		if (k != enti::InputKey::NONE) {
			system("cls");
		}

	} while (true);
}