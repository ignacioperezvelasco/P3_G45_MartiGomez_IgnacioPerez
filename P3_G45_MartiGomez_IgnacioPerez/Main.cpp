#include <iostream>
#include <map>
#include "Map.h"
#include "entios.h"
#include "Player.h"


void main()
{
	//finaljuego
	bool gameOver = false;
	bool player2Win = false;
	bool player1Win = false;

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


			if (player1.numacciones <= 0)
			{
				if (k == enti::InputKey::ENTER) {
					player2.entioMenosFatigado();
					if (player2.currentio == nullptr)
					{
						gameOver = true;
						break;
					}
					pl1 = false;
					player1.numacciones = 11;
				}
			}
			else
			{
				player1.update_player(k, player2);
			}
		}
		else
		{

			
			if (player2.numacciones <= 0)
			{
				if (k == enti::InputKey::ENTER) {
					player1.entioMenosFatigado();
					if (player2.currentio == nullptr)
					{
						gameOver = true;
						break;
					}
					pl1 = true;
					player2.numacciones = 11;
				}
			}
			else
			{
				player2.update_player(k, player1);
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

	} while (gameOver != true);
	if (player1Win == true) {
	enti::cout << "Player 1 Won!" << enti::endl;
	}
	if (player2Win == true) {
		enti::cout << "Player 2 Won!" << enti::endl;
	}
	enti::cout << enti::cend;
	system("cls");
}