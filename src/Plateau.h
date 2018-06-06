#pragma once
#include "Joueur.h"
using namespace std;
class Plateau
{
	int * plateau_;
	int * plateauAvant_;
	int tour_;
	bool blocage_;
	Joueur *J1_;
	Joueur *J2_;



public:
	Plateau(Joueur *J1, Joueur *J2);
	
	~Plateau();

	int * getPlateau() const { return plateau_; };
	int * getAvant() const { return plateauAvant_; };
	int getTour() const { return tour_; };
	bool getBlocage() const { return blocage_; };

	//Plateau copieplateau(const Plateau & t); peut être pas nécessaire
	
	void changeTour() { tour_++; }; //Incrémente le tour
	int* turfu( int i); //Calcule le futur tableau si la case en argument était choisie
	int*difference(Plateau P) const; //Note les différences entre deux plateaux
	void blocage(); // verifie si le plateau est bloqué
	void affichePlateau();
	void afficheCase();

};

