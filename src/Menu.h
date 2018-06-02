#pragma once
#include <string>
using namespace std;

class Menu
{
	string texte_;

public:
	Menu(string txt="Bonjour");
	~Menu();

	string getTexte() const { return texte_; };
	void setTexte(string t) { texte_ = t; };
	void affiche();
};

