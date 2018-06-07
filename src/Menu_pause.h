#ifndef MENU_PAUSE_H
#define MENU_PAUSE_H


#include "Plateau.h"
class Menu_pause 
	
{
	Plateau *jeu_;

public:
	Menu_pause(Plateau *P);
	~Menu_pause();

	void continuer();
	void capituler();
	void sauver(ofstream &ofs);
	void affiche();


};

#endif // !MENU_PAUSE_H