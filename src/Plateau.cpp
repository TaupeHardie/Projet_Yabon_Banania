#include "stdafx.h"
#include "Plateau.h"


Plateau::Plateau()
{

	plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
	{
		plateau_[i] = 4;
	}
	plateauAvant_ = new int[0];
	plateauxFuturs_ = new int*[0];
	blocage_ = false;
}


Plateau::~Plateau()
{

}

Plateau Plateau::copieplateau(const Plateau & t) {
	Plateau copie;
	copie.plateauAvant_ = t.plateauAvant_;
	copie.plateauxFuturs_ = t.plateauxFuturs_;
	copie.plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
		copie.plateau_[i] = t.plateau_[i];
	return copie;

}
;

int* Plateau  :: turfu(int a) const 
{
	int cpt = a; //compteur
	int* t; // copie du plateau 
	int nbgraines = plateau_[a];
	t = new int[12]; 
	for (int i = 0; i < 12; i++) {
		plateau_[i] = t[i];
	}
	t[a] = 0; 

	while (nbgraines != 0)
		{
		if (cpt = 12) 
		{cpt = 0;}
		t[cpt++] ++;
		nbgraines--;
		}
	return t;

}


int*  Plateau::difference(Plateau P) const
{
	int* dif; // tableau des diff�rences
	dif = new int[12];
	for (int i = 0; i < 12; i++)
	{
		dif[i] = P.plateau_[i] - plateau_[i];
	}
	return dif;
}

