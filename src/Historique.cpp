#include "Historique.h"
using namespace std;



Historique::Historique()
{
	historique_[0][0];
}

void Historique::Sauvegarder(Historique nb, ofstream &ofs)
{
	ofs << historique_.size() << endl; // saving the number of Plateau
	for (int i=0; i< historique_.size(); i++)
		for (int j = 0; j < 12;j++)
		{
			ofs<<historique_[i][j] << endl;
		}
}

void Historique::charger(ifstream &ifs)
{
	int nb;
	ifs >> nb;
	ifs.ignore();
	for (int i = 0;i<nb;i++)
	{
		historique_.push_back(vector<int>(12));
		for (int j = 0; j < 12;j++)
		{
			ifs >> historique_[i][j];
			ifs.ignore();
		}
	}
}



