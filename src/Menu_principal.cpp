#include "Menu_principal.h"



Menu_principal::Menu_principal()
{

}


Menu_principal::~Menu_principal()
{
}

void Menu_principal::nvllePartie() {
	Joueur J1(1);
	Joueur J2(2);
	Plateau awa;
	awa.affichePlateau();

}

bool Menu_principal::quitter() {
	return true;
}
