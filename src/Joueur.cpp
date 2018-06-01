#include "Joueur.h"
#include <iostream>
using namespace std;



Joueur::Joueur(int num, bool t)
{
	num_ = num;
	cin >> nom_;
	points_ = 0;
	tour_ = t;


}


Joueur::~Joueur()
{
}
