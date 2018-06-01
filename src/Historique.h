#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Historique {
	vector<vector<int>> historique_;
public: 
	Historique::Historique();
	void Sauvegarder(Historique nb, ofstream &ofs);
	void charger(ifstream &ifs);
};
