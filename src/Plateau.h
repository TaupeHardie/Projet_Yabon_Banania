#pragma once
class Plateau
{
	int * plateau_;
	int * plateauAvant_;
	int ** plateauxFuturs_;

	int tour_;
	bool blocage_;
public:
	Plateau();
	~Plateau();
	int * getPlateau() const { return plateau_; };
	int * getAvant() const { return plateauAvant_; };
	Plateau copieplateau(const Plateau & t);

	int getTour() const { return tour_; };
	bool getBlocage() const { return blocage_; };
	int changeTour() { tour_++; }; //Incr�mente le tour
	int* turfu(int) const; //Calcule le futur tableau si la case en argument �tait choisie
	int* difference(Plateau P) const; //Note les diff�rences entre deux plateaux
	bool blocage();

};

