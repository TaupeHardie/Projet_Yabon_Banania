#include "stdafx.h"
#include "Plateau.h"



Plateau::Plateau()
{

	plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
	{
		plateau_[i] = 4;
	}
	plateauAvant_ = new int[12];
	tour_ = 1;
	blocage_ = false;
	
}


Plateau::~Plateau()
{

}

Plateau Plateau::copieplateau(const Plateau & t) {
	Plateau copie;
	copie.plateauAvant_ = t.plateauAvant_;
	copie.plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
		copie.plateau_[i] = t.plateau_[i];
	return copie;

}
;

int* Plateau  :: turfu(int a, Joueur J) const 
{
	int cpt = a; //compteur
	int* t; // copie du plateau 
	int nbgraines = plateau_[a];
	t = new int[12]; 
	for (int i = 0; i < 12; i++) {
		t[i]= plateau_[i];
	}
	t[a] = 0; 

	while (nbgraines != 0)
		{
		if (cpt = 12) 
		{cpt = 0;}
		t[cpt++] ++;
		nbgraines--;
		}

	if (cpt = 0)
	{
		cpt = 11;
	}

	if (J.getNum == 1)
	{
		while (cpt <= 11 && cpt>=6) 
		{
			if (t[cpt] == 2 || t[cpt] == 3)
			{
				J.setPoints(J.getPoints+t[cpt]);
				t[cpt] = 0;
				cpt--;
			}
		}
	}
	return t;

}


int*  Plateau::difference(Plateau P) const
{
	int* dif; // tableau des différences
	dif = new int[12];
	for (int i = 0; i < 12; i++)
	{
		dif[i] = P.plateau_[i] - plateau_[i];
	}
	return dif;
}


void Plateau::blocage()
{
	if (tour_ % 2 == 1)
	{
		int i = 0;
		while ((plateau_[i] == 0)||(i!=5)) { i++; } // parcours du début de la première moitiétableau
		if ((i == 5) && (plateau_[5] == 0))	//verifie si on a parcouru jusqu'au bout et si le dernier élément est zéro
		{
			blocage_ = true;
		}
	}
	if (tour_ % 2 == 0)
	{
		int i = 0;
		while ((plateau_[i] == 0) || (i != 5)) { i++; }
		if ((i == 5) && (plateau_[5] == 0))
		{
			blocage_ = true;
		}
	}
}

