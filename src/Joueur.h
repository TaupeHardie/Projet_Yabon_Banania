#ifndef JOUEUR_H
#define JOUEUR_H


#include<string>
using namespace std;

/*
Classe: Joueur
Auteurs: Hugo NICOLLE
Description: Correspond au joueur avec ses points et un bool�en tour_ dont la valeur est true si c'est le tour de ce joueur
*/
class Joueur
{
	bool tour_;
	int points_;
	int pointsAvant_;

public:

	/*
	Fonction: Joueur
	Auteur: Hugo NICOLLE
	Description: Constructeur de la classe, les points du joueurs sont par d�faut 
	Param�tre d'entr�e: i l'index de la case choisie
	Param�tres de sortie: plateau_[i] le nombre de graines dans la case
	*/
	Joueur(bool tour);
	~Joueur();

	/*
	Fonction: getPoints
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au nombre de points d'un joueur
	Param�tres de sortie: points_ le nombre de points d'un joueur
	*/
	int getPoints() const { return points_; };

	/*
	Fonction: getPointsAvant
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au nombre de points qu'avait le joueur au tour pr�c�dent
	Param�tres de sortie: pointsAvant_ le nombre de points d'un joueur au tour pr�c�dent
	*/
	int getPointsAvant() const { return pointsAvant_; };
	
	/*
	Fonction: getTour
	Auteur: Hugo NICOLLE
	Description: Permet d'acc�der au membre tour_
	Param�tres de sortie: tour_ un bool�en qui vaut true si c'est au tour du joueur de jouer et false si ce n'est pas le cas
	*/
	bool getTour() const { return tour_; };

	/*
	Fonction: setPoints
	Auteur: Hugo NICOLLE
	Description: Permet de modifier le score d'un joueur
	Param�tres d'entr�e: p le nombre de points auquel on veut mettre le score du joueur
	*/
	void setPoints(int p) { points_ = p; };

	/*
	Fonction: setPoints
	Auteur: Hugo NICOLLE
	Description: Permet de modifier le score du tour pr�c�dent d'un joueur
	Param�tres d'entr�e: p le nombre de points auquel on veut mettre le score du tour pr�c�dent du joueur
	*/
	void setPointsAvant(int p) { pointsAvant_ = p; };

	/*
	Fonction: setTour
	Auteur: Hugo NICOLLE
	Description: Permet de modifier le champ tour_
	Param�tres d'entr�e: b,  true si on veut dire que c'est le tour du joueur
	*/
	void setTour(bool b) { tour_ = b; };

	
	


};

#endif // !JOUEUR_H