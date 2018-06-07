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
Description:	Gère le plateau de jeu au niveau logique et graphique. Du point de vue logique, elle controle le nombre de graine dans chaque case, 
				garde en mémoire l'état du plateau au tour précédent et la case qui a été jouée, le numéro du tour. Elle considère deux Joueurs. 
				Au niveau graphique, elle gère l'affichage des cases du plateau dans le displayer


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
	Description: Constructeur d'un plateau, il initie toutes les cases du plateau à 4 graines
	Paramètre d'entrée: J1,J2 Les deux joueurs
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
		Description: Permet d'accéder au tableau correspondant au plateau de jeu
		Paramètres de sortie: plateau_ Le plateau de jeu
	*/
	int * getPlateau() const { return plateau_; };

	/*
	Fonction: getCase
	Auteur: Hugo NICOLLE
	Description: Permet d'accéder au nombre de graines d'une case du plateau
	Paramètre d'entrée: i l'index de la case choisie
	Paramètres de sortie: plateau_[i] le nombre de graines dans la case
	*/
	int getCase(int i) const { return plateau_[i]; };

	/*
	Fonction: getAvant
	Auteur: Hugo NICOLLE
	Description: Permet d'accéder au plateau tel qu'il était au tour précédent
	Paramètres de sortie: plateauAvant_ le plateau du tour précédent
	*/
	int * getAvant() const { return plateauAvant_; };

	/*
	Fonction: getCaseAvant
	Auteur: Hugo NICOLLE
	Description: Permet d'accéder à l'index de la dernière case jouée
	Paramètres de sortie: caseAvant_ l'index de la dernière case jouée 
	*/
	int getCaseAvant() const { return caseAvant_; };

	/*
	Fonction: getTour
	Auteur: Hugo NICOLLE
	Description: Donne le nombre du tour
	Paramètres de sortie: tour_ le tour actuel
	*/
	int getTour() const { return tour_; };

	/*
	Fonction: getJ1
	Auteur: Hugo NICOLLE
	Description: Permet d'accéder au Joueur 1
	Paramètres de sortie: J1_ le joueur 1 (voir classe Joueur)
	*/
	Joueur* getJ1() const { return J1_; };

	/*
	Fonction: getJ2
	Auteur: Hugo NICOLLE
	Description: Permet d'accéder au Joueur 2
	Paramètres de sortie: J2_ le joueur 2 (voir classe Joueur)
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
	void changeTour() ; //Incrémente le tour

	/*
	Fonction: action
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Modifie les valeurs du plateau selon les règles du Awale et affiche ces changements
	Paramètre d'entrée: i l'index de la case choisie
						grid l'image dans la fenêtre ghraphique
						disp la fenêtre graphique
	*/
	void action(int i, CImg<unsigned char> &grid, CImgDisplay &disp); 

	/*
	Fonction: rewind
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Permet d'afficher le coup précédent en mode pas à pas 
	Paramètre d'entrée: grid l'image dans la fenêtre ghraphique
						disp la fenêtre graphique
	*/
	void rewind(CImg<unsigned char> &grid, CImgDisplay &disp);

	/*
	Fonction: getCase
	Auteur: Hugo NICOLLE
	Description: Arrête la partie si il est impossible pour un joueur de jouer ou si un joueur dépasse un score de 24 (moitié des points).
	Si la fin est du à une impossibilité de jouer distribue les dernières graines selon les règles.
	*/
	int finPartie();

	/*
	Fonction: affichePlateau
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Affiche le plateau dans la fenêtre graphique
	Paramètre d'entrée: grid l'image dans la fenêtre graphique
						disp la fenêtre
	*/
	void affichePlateau(CImg<unsigned char> &grid, CImgDisplay &disp);
	
	/*
	Fonction: 
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Affiche une case du plateau dans la fenêtre graphique
	Paramètre d'entrée: position la position de la case à afficher
						grid l'image dans la fenêtre d'affichage
						disp la fenêtre d'affichage
	*/
	void afficheCase(int position, CImg<unsigned char> &grid, CImgDisplay &disp);

	/*
	Fonction: sauver
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Sauvegarde les différents éléments d'un objet Plateau dans le fichier "save.text"
	*/
	void  sauver();

	/*
	Fonction: capituler
	Auteur: Hugo NICOLLE & Jocelyn DROUET
	Description: Permet à un joueur d'abandonner la partie
	Paramètre d'entrée: grid image dans la fenêtre
						disp fenêtre d'affichage
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
