#include <iostream>
#include <map>
#include "Map.h"
#include "entios.h"
#include <windows.h>

void main() 
{

	Map a("default.cfg");


	entios uno('1', a);

	

	a.printmapa();

}