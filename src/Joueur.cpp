#include "Joueur.h"
#include <iostream>
using namespace std;



Joueur::Joueur(bool tour)
{
	tour_ = tour;
	points_ = 0;
	pointsAvant_ = 0;


}


Joueur::~Joueur()
{
}
