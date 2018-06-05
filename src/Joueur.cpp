#include "Joueur.h"
#include <iostream>
using namespace std;



Joueur::Joueur(int num)
{
	num_ = num;
	cout << "Entrez le nom du joueur" << endl;
	cin >> nom_;
	points_ = 0;


}


Joueur::~Joueur()
{
}
