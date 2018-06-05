#pragma once
#include "c:\Users\hugon\source\repos\Projet_Yabon_Banania\src\Menu.h"
#include "Plateau.h"
class Menu_principal :
	public Menu
{

public:
	Menu_principal();
	~Menu_principal();

	void nvllePartie();
	void chargerPartie(ifstream &ifs);
	bool quitter();
	void affiche();

	
};

