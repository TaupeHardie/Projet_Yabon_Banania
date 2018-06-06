#pragma once
#include<string>
using namespace std;

class Joueur
{
	string nom_;
	bool tour_;
	int points_;

public:
	Joueur(bool tour);
	~Joueur();

	int getPoints() const { return points_; };
	string getNom() const { return nom_; };
	bool getTour() const { return tour_; };
	void setPoints(int p) { points_ = p; };

	//Plateau action(Plateau);
	//Menu_pause pause();
	//Menu finPartie(Plateau);
	//affiche action
	//Menu capituler();

	


};

