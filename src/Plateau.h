#pragma once
#include "Joueur.h"
class Plateau
{
	int * plateau_;
	int * plateauAvant_;


	int tour_;
	bool blocage_;
public:
	Plateau();
	~Plateau();

	int * getPlateau() const { return plateau_; };
	int * getAvant() const { return plateauAvant_; };
	int getTour() const { return tour_; };

	Plateau copieplateau(const Plateau & t);
	bool getBlocage() const { return blocage_; };
	void changeTour() { tour_++; }; //Incr�mente le tour
	int* turfu(int, Joueur) const; //Calcule le futur tableau si la case en argument �tait choisie
	int* difference(Plateau P) const; //Note les diff�rences entre deux plateaux
	void blocage(); // verifie si le plateau est bloqu�
	void affichePlateau();
	void afficheCase()

};

