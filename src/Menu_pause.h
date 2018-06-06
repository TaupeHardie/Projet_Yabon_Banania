#pragma once
#include "Plateau.h"
class Menu_pause 
	
{

public:
	Menu_pause();
	~Menu_pause();

	void continuer();
	void capituler();
	void sauver(ofstream &ofs);
	void affiche();


};

