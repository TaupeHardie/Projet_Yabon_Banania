#include "Joueur.h"
#include <iostream>
using namespace std;



Joueur::Joueur(bool tour)
{
	tour_ = tour;
	cout << "Entrez le nom du joueur" << endl;
	cin >> nom_;
	points_ = 0;


}


Joueur::~Joueur()
{
}
