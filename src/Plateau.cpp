#include "stdafx.h"
#include "Plateau.h"


Plateau::Plateau()
{
}


Plateau::~Plateau()
{
}

Plateau Plateau::copieplateau(const Plateau & t) {
	plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
		plateau_[i] = t.plateau_[i];
}
;

int* Plateau  :: turfu(int a) const 
{
	int cpt = a; //index lecture
	int* t; // copie du plateau 
	int nbgraines = plateau_[a];
		t = new int[12]; 
	for (int i = 0; i < 12; i++)
		plateau_[i] = t[i];
	
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