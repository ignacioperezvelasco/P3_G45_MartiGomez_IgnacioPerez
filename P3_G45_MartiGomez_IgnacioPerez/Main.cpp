#include <iostream>
#include <map>
#include "Map.h"
#include "entios.h"
#include "Player.h"
#include <windows.h>

void main() 
{

	Map a("default.cfg");

	Player numeros(a,'1','2','3','4','5','6');
	
	

	a.printmapa();

}