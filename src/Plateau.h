#ifndef PLATEAU_H
#define PLATEAU_H


#include "Joueur.h"
#include "CImg.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace cimg_library;

/*
Classe: Plateau
Auteurs: Hugo NICOLLE & Jocelyn DROUET
Description:	G�re le plateau de jeu au niveau logique et graphique. Du point de vue logique, elle controle le nombre de graine dans chaque case, 
				garde en m�moire l'�tat du plateau au tour pr�c�dent et la case qui a �t� jou�e, le num�ro du tour. Elle consid�re deux Joueurs. 
				Au niveau graphique, elle g�re l'affichage des cases du plateau dans le displayer


*/
class Plateau
{
	int * plateau_;
	int * plateauAvant_;
	int caseAvant_;
	int tour_;
	Joueur *J1_;
	Joueur *J2_;



public:
	/*
	Fonction: Plateau
	Auteur: Hugo NICOLLE
	Description: Constructeur d'un plateau, il initie toutes les cases du plateau � 4 graines
	Param�tre d'entr�e: J1,J2 Les deux joueurs
	*/
	Plateau(Joueur *J1, Joueur *J2);
	
	/*
	Fonction: Plateau
	Auteur: Hugo NICOLLE
	Description: Destructeur de la classe
	*/
	~Plateau();

	/*
		Fonction: getPlateau  
		Auteur: Hugo NICOLLE
		Description: Permet d'acc�der au tableau correspondant au plateau de jeu
		Param�tres de sortie: plateau_ Le plateau de jeu
	*/
	int * getPlateau() const { return plateau_; };

	/*
	Fonction: getCase
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au nombre de graines d'une case du plateau
	Param�tre d'entr�e: i l'index de la case choisie
	Param�tres de sortie: plateau_[i] le nombre de graines dans la case
	*/
	int getCase(int i) const { return plateau_[i]; };

	/*
	Fonction: getAvant
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au plateau tel qu'il �tait au tour pr�c�dent
	Param�tres de sortie: plateauAvant_ le plateau du tour pr�c�dent
	*/
	int * getAvant() const { return plateauAvant_; };

	/*
	Fonction: getCaseAvant
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der � l'index de la derni�re case jou�e
	Param�tres de sortie: caseAvant_ l'index de la derni�re case jou�e 
	*/
	int getCaseAvant() const { return caseAvant_; };

	/*
	Fonction: getTour
	Auteur: Hugo NICOLLE
	Description: Donne le nombre du tour
	Param�tres de sortie: tour_ le tour actuel
	*/
	int getTour() const { return tour_; };

	/*
	Fonction: getJ1
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au Joueur 1
	Param�tres de sortie: J1_ le joueur 1 (voir classe Joueur)
	*/
	Joueur* getJ1() const { return J1_; };

	/*
	Fonction: getJ2
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au Joueur 2
	Param�tres de sortie: J2_ le joueur 2 (voir classe Joueur)
	*/
	Joueur* getJ2() const { return J2_; }

	

	/*
	Fonction: affichePlateauConsole
	Auteur: Hugo NICOLLE
	Description: Affiche le plateau de Awale sur la console pour tester sans avoir l'interface graphique
	*/
	void affichePlateauConsole(); 

	/*
	Fonction: changeTour()
	Auteur: Hugo NICOLLE
	Description: Modifie le tour et indique qui a le droit de jouer en inversant le champ tour_ (pas celui de l'objet plateau) de chaque joueur
	*/
	void changeTour() ; //Incr�mente le tour

	/*
	Fonction: action
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Modifie les valeurs du plateau selon les r�gles du Awale et affiche ces changements
	Param�tre d'entr�e: i l'index de la case choisie
						grid l'image dans la fen�tre ghraphique
						disp la fen�tre graphique
	*/
	void action(int i, CImg<unsigned char> &grid, CImgDisplay &disp); 

	/*
	Fonction: rewind
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Permet d'afficher le coup pr�c�dent en mode pas � pas 
	Param�tre d'entr�e: grid l'image dans la fen�tre ghraphique
						disp la fen�tre graphique
	*/
	void rewind(CImg<unsigned char> &grid, CImgDisplay &disp);

	/*
	Fonction: getCase
	Auteur: Hugo NICOLLE
	Description: Arr�te la partie si il est impossible pour un joueur de jouer ou si un joueur d�passe un score de 24 (moiti� des points).
	Si la fin est du � une impossibilit� de jouer distribue les derni�res graines selon les r�gles.
	*/
	int finPartie();

	/*
	Fonction: affichePlateau
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Affiche le plateau dans la fen�tre graphique
	Param�tre d'entr�e: grid l'image dans la fen�tre graphique
						disp la fen�tre
	*/
	void affichePlateau(CImg<unsigned char> &grid, CImgDisplay &disp);
	
	/*
	Fonction: 
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Affiche une case du plateau dans la fen�tre graphique
	Param�tre d'entr�e: position la position de la case � afficher
						grid l'image dans la fen�tre d'affichage
						disp la fen�tre d'affichage
	*/
	void afficheCase(int position, CImg<unsigned char> &grid, CImgDisplay &disp);

	/*
	Fonction: sauver
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Sauvegarde les diff�rents �l�ments d'un objet Plateau dans le fichier "save.text"
	*/
	void  sauver();

	/*
	Fonction: capituler
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Permet � un joueur d'abandonner la partie
	Param�tre d'entr�e: grid image dans la fen�tre
						disp fen�tre d'affichage
	*/
	void capituler(CImg<unsigned char> &grid, CImgDisplay &disp);

	/*
	Fonction: charger
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: charge le contenu du fichier "save.text" dans un plateau
	*/
	void charger();

};


#endif // !PLATEAU_H
