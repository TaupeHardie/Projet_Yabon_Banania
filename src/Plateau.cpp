#include "stdafx.h"
#include "Plateau.h"
using namespace std;


Plateau::Plateau(Joueur *J1, Joueur *J2 )
{
	plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
	{
		plateau_[i] = 4;
	}
	plateauAvant_ = new int[12];
	tour_ = 1;
	blocage_ = false;
	*J1_ = J1;
	*J2_ = J1;
	
}


Plateau::~Plateau()
{

}

//Plateau Plateau::copieplateau(const Plateau & t) {
//	Plateau copie;
//	copie.plateauAvant_ = t.plateauAvant_;
//	copie.plateau_ = new int[12];
//	for (int i = 0; i < 12; i++)
//		copie.plateau_[i] = t.plateau_[i];
//	return copie;
//
////
////}
//;
//
int* Plateau  :: turfu(int a)
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

	if ( J1_->getTour() == true)
	{
		while (cpt <= 11 && cpt>=6) 
		{
			if (t[cpt] == 2 || t[cpt] == 3)
			{
				J1_->setPoints(J1_->getPoints() + t[cpt]);
				t[cpt] = 0;
				cpt--;
			}
		}
	}
	if (J2_->getTour() == true)
	{
		while (cpt <= 5 && cpt >= 0)
		{
			if (t[cpt] == 2 || t[cpt] == 3)
			{
				J2_->setPoints(J2_->getPoints() + t[cpt]);
				t[cpt] = 0;
				cpt--;
			}
		}
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


void Plateau::blocage()
{
	if (J1_->getTour() == true)
	{
		int i = 0;
		while ((plateau_[i] == 0)||(i!=5)) { i++; } // parcours du d�but de la premi�re moiti�tableau
		if ((i == 5) && (plateau_[5] == 0))	//verifie si on a parcouru jusqu'au bout et si le dernier �l�ment est z�ro
		{
			blocage_ = true;
		}
	}
	if (J2_->getTour() == true)
	{
		int i = 0;
		while ((plateau_[i] == 0) || (i != 5)) { i++; }
		if ((i == 5) && (plateau_[5] == 0))
		{
			blocage_ = true;
		}
	}
}

