#include "stdafx.h"
#include "Plateau.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace cimg_library;


Plateau::Plateau(Joueur *J1, Joueur *J2 )
{
	plateau_ = new int[12];
	for (int i = 0; i < 12; i++)
	{
		plateau_[i] = 4;
	}
	plateauAvant_ = new int[12];
	for (int i = 0; i < 12; i++)
	{
		plateauAvant_[i] = 4;
	}
	tour_ = 1;
	J1_ = J1;
	J2_ = J2;
	caseAvant_ = 0;
	
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
void Plateau::changeTour()
{
	tour_++;
	J1_->setTour(! J1_->getTour());
	J2_->setTour(! J2_->getTour());
}


void Plateau  :: action(int a,CImg<unsigned char> &grid, CImgDisplay &disp)
{
		caseAvant_ = a;
		int cpt = a; //compteur
		int nbgraines = plateau_[a];

		for (int i = 0; i < 12; i++)
		{
			plateauAvant_[i] = plateau_[i];
		}
		J1_->setPointsAvant(J1_->getPoints());
		J2_->setPointsAvant(J2_->getPoints());
		plateau_[a] = 0;
		std::this_thread::sleep_for(0.2s);
		afficheCase(a, grid, disp);


		while (nbgraines != 0)
		{
			if (cpt == 11)
			{
				cpt = -1;
			}
			cpt++;
			plateau_[cpt] ++;
			
			std::this_thread::sleep_for(0.2s);
			afficheCase(cpt, grid, disp);
			nbgraines--;
		}


		if (J1_->getTour() == true)
		{
			
			
			while (plateau_[cpt] == 2 && cpt<=11 && cpt>=6 || plateau_[cpt] == 3 && cpt<=11 && cpt >=6)
			{
			
					J1_->setPoints(J1_->getPoints() + plateau_[cpt]);
					plateau_[cpt] = 0;
					std::this_thread::sleep_for(0.2s);
					afficheCase(cpt, grid, disp);
					cpt--;
	
			}
			
		}
		if (J2_->getTour() == true)
		{
			while (plateau_[cpt] == 2 && cpt <= 5 && cpt >= 0 || plateau_[cpt] == 3 && cpt <= 5 && cpt >= 0)
			{
				J2_->setPoints(J2_->getPoints() + plateau_[cpt]);
				plateau_[cpt] = 0;
				std::this_thread::sleep_for(0.2s);
				afficheCase(cpt, grid, disp);
				cpt--;
			}
		}
	


}




int Plateau::finPartie() 
{
	
	if (J1_->getPoints() > 24 || J2_->getPoints()>24)
	{
		if (J1_->getPoints() > J2_->getPoints())
		{
			return 1;
		}
		else if (J1_->getPoints() < J2_->getPoints())
		{
			return 2;
		}

	}
	return 0;
}

void Plateau::afficheCase(int position, CImg<unsigned char> &grid, CImgDisplay &disp)
{
	CImg<float> image;
	switch (plateau_[position]) { // On détermine le noombre de graine dans la case à une position
	case 0:
		image.load("0_.PPM");
		break;
	case 1:
		image.load("1_.PPM");
		break;
	case 2:
		image.load("2_.PPM");

		break;
	case 3:
		image.load("3_.PPM");

		break;
	case 4:
		image.load("4_.PPM");
		break;
	case 5:
		image.load("5_.PPM");
		break;
	case 6:
		image.load("6_.PPM");
		break;
	case 7:
		image.load("7_.PPM");

		break;
	case 8:
		image.load("8_.PPM");
		break;
	case 9:
		image.load("9_.PPM");

		break;
	case 10:
		image.load("10_.PPM");

		break;
	case 11:
		image.load("11_.PPM");

		break;
	case 12:
		image.load("12_.PPM");

		break;
	case 13:
		image.load("13_.PPM");

		break;
	case 14:
		image.load("14_.PPM");

		break;
	case 15:
		image.load("15_.PPM");

		break;
	case 16:
		image.load("16_.PPM");

	case 17:
		image.load("17_.PPM");

		break;
	case 18:
		image.load("18_.PPM");

		break;
	case 19:
		image.load("19_.PPM");

		break;
	case 20:
		image.load("20_.PPM");
		break;
		/*default:
		image.draw_text(100 , 100, liste[position]);*/
	}
	int i = position % 6 + 1;
	int j = floor(position / 6)+1;
	if (j == 2)
	{
		i = 7 - i;
	}
	grid.draw_image(i * 100, j * 100, image);
	grid.display(disp);


}

void Plateau::affichePlateau(CImg<unsigned char> &grid, CImgDisplay &disp)
{
	for (int i = 0; i < 12; i++)
	{
		afficheCase(i, grid,disp);
	}
}


void Plateau::affichePlateauConsole()
{
	for (int i = 0; i < 6; i++)
	{
		cout << plateau_[i];
	}
	cout << endl;
	for (int i = 11; i >5; i--)
	{
		cout << plateau_[i];
	}
	cout << endl;
	cout << endl;
}

void Plateau::sauver()
{
	ofstream  ofs("save.txt");
	ofs << J1_->getTour() << " " << J1_->getPoints() << " " << J1_->getPointsAvant() <<  endl;
	ofs << J2_->getTour() << " " << J2_->getPoints() << " " << J2_->getPointsAvant() << endl;
	ofs << tour_ << endl;
	ofs << caseAvant_ << endl;
		for (int i = 0; i < 12; i++) 
		{
			ofs << plateau_[i] << " ";
		}
		ofs << endl;

		for (int i = 0; i < 12; i++)
		{
			ofs << plateauAvant_[i] << " ";
		}
		ofs << endl;
		
}

void Plateau::charger()
{
	ifstream ifs("save.txt");
	ifs.ignore();
	int n;
	ifs >> n;
	J1_->setTour(n);
	ifs >> n;
	J1_->setPoints(n);
	ifs >> n;
	J1_->setPointsAvant(n);
	ifs >> n;
	J2_->setTour(n);
	ifs >> n;
	J2_->setPoints(n);
	ifs >> n;
	J2_->setPointsAvant(n);
	ifs >> n;
	tour_ = n;
	ifs >> n;
	caseAvant_ = n;
	for (int i = 0; i < 12; i++)
	{
		ifs >> n;
		plateau_[i] = n;
	}
	for (int i = 0; i < 12; i++)
	{
		ifs >> n;
		plateauAvant_[i] = n;
	}

}

void Plateau::rewind(CImg<unsigned char> &grid, CImgDisplay &disp)
{
	if (tour_ > 1)
	{
		for (int i = 0; i < 12; i++)
		{
			plateau_[i] = plateauAvant_[i];
		}
		J1_->setTour(not J1_->getTour());
		J2_->setTour(not J2_->getTour());
		J1_->setPoints(J1_->getPointsAvant());
		J2_->setPoints(J2_->getPointsAvant());
		affichePlateau(grid, disp);
		action(caseAvant_, grid, disp);
		J1_->setTour(not J1_->getTour());
		J2_->setTour(not J2_->getTour());
	}
}

void Plateau::capituler(CImg<unsigned char> &grid, CImgDisplay &disp)
{
	CImg<float> image;
	if (J1_->getTour() == true)
	{
		image.load("Gagnant2.PPM");
	}
	if (J2_->getTour() == true)
	{
		image.load("Gagnant1.PPM");
	}
	grid.draw_image(0 * 100, 0 * 100, image);
	grid.display(disp);
}

