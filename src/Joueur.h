#pragma once
#include<string>
//#include "Plateau.h"
using namespace std;

class Joueur
{
	string nom_;
	int num_;
	bool tour_;
	int points_;

public:
	Joueur();
	~Joueur();

	int getPoints() const { return points_; };
	string getNom() const { return nom_; };
	bool getTour() const { return tour_; };
	int getNum() const { return num_; };

	//Plateau action(Plateau);


};

