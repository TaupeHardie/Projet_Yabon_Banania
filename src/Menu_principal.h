#pragma once

#include "Plateau.h"
#include "CImg.h"
#include <iostream>

class Menu_principal 

{

public:
	Menu_principal();
	~Menu_principal();

	void nvllePartie();
	void chargerPartie(ifstream &ifs);
	bool quitter();
	void affiche();

	
};

