#pragma once
#include<string>
#include "Plateau.h"
#include "Menu.h"
#include "Menu_pause.h"
#include "Menu_fin.h"
#include "Menu_principal.h"
using namespace std;

class Joueur
{
	string nom_;
	int num_;
	int points_;

public:
	Joueur(int num);
	~Joueur();

	int getPoints() const { return points_; };
	string getNom() const { return nom_; };
	int getNum() const { return num_; };
	void setPoints(int p) { points_ = p; };

	//Plateau action(Plateau);
	//Menu_pause pause();
	//Menu finPartie(Plateau);
	//affiche action
	//Menu capituler();

	


};

