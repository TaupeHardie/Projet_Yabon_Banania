// Projet_Yabon_Banania.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Joueur.h"
#include "Plateau.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace cimg_library;



int main()
{

	//test fonction afficheCase
	Joueur Joueur1(true);
	Joueur Joueur2(false);
	Joueur* J1 = &Joueur1;
	Joueur* J2 = &Joueur2;
	Plateau P(J1, J2);
	int pos;
	int gagnant;
	
	
	
	bool fin = FALSE;
	int position = 0;
	int table[8][4] = { 1,0,0,3,1,8,9,3,0,8,9,0,5,8,9,0,5,8,9,0,0,8,9,0,2,8,9,4,2,0,0,4 };
	unsigned char
		grid_color[3] = { 0,0,255 };
	CImg<unsigned char> grid(800, 400, 1, 3, 255);
	for (int j = 1; j < 4; j++) grid.draw_line(100, j * 100, 700, j * 100, grid_color);
	for (int j = 1; j < 8; j++) grid.draw_line(100 * j, 100, 100 * j, 300, grid_color);
	CImg<float> image;
	CImg<float> Bouton1;
	CImg<float> Bouton2;
	CImg<float> Bouton3;
	CImg<float> Bouton4;
	CImg<float> Bouton5;
	Bouton1.load("Capituler.PPM");
	Bouton2.load("Save.PPM");
	Bouton3.load("Charger.PPM");
	Bouton4.load("Quitter.PPM");
	Bouton5.load("Rewind.PPM");
	CImg<unsigned char> scene = grid;
	scene.draw_image(0 * 100, 0 * 100, Bouton1);
	scene.draw_image(0 * 100, 3 * 100, Bouton2);
	scene.draw_image(6 * 100, 0 * 100, Bouton3);
	scene.draw_image(6 * 100, 3 * 100, Bouton4);
	scene.draw_image(3 * 100, 0 * 100, Bouton5);
	CImgDisplay disp(grid, "Awale", 0, false, false);
	
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ() && fin == FALSE) {
		scene.display(disp);
		
		P.affichePlateau(scene, disp);
		disp.wait();
		if (disp.button() & 1)
		{
			int j = 4 * disp.mouse_y() / disp.height();
			int i = 8 * disp.mouse_x() / disp.width();
			switch (table[i][j])
			{
			case 1:
				P.capituler(scene,disp);
				
				std::this_thread::sleep_for(5s);
				fin = TRUE;
				break;

			case 3:
				
				P.sauver();
				cout << "sauvegarde" << endl;
				break;
			case 2:
				P.charger();
				cout << "chargement" << endl;
				cout << P.getCase(3);
				P.affichePlateau(scene,disp);
				break;
			case 4:
				fin = TRUE;
				return 0;
				break;
			case 5:
				cout << 1;
				P.rewind(scene, disp);

				break;
				
			case 8:
				cout <<endl << P.getJ1()->getTour()<< endl;
				if (P.getJ1()->getTour()==true)
				{
					pos=i-1;
					j = 1;
					if (P.getCase(pos) != 0)
					{
						P.action(pos, scene, disp);
						//P.blocage();
						P.changeTour();
						gagnant = P.finPartie();
						if (gagnant == 1)
						{
							image.load("Gagnant1");
							scene.draw_image(0, 0, image);
							std::this_thread::sleep_for(5s);
							fin = TRUE;
						}
						if (gagnant == 2)
						{
							image.load("Gagnant2");
							scene.draw_image(0, 0, image);
							std::this_thread::sleep_for(5s);
							fin = TRUE;
						}
					}
				}
				break;
			case 9: 
				cout << endl << P.getJ2()->getTour() << endl;
				if (P.getJ2()->getTour()==true)
				{
					pos = i - 1;
					pos = (j - 1) * 12 - pos-1;
					j = 2;
		
					if (P.getCase(pos) != 0)
					{
						P.action(pos, scene, disp);
						//P.blocage();
						P.changeTour();
						
						gagnant = P.finPartie();
						if (gagnant == 1)
						{
							image.load("Gagnant1.ppm");
							scene.draw_image(0, 0, image);
							std::this_thread::sleep_for(5s);
							fin = TRUE;
						}
						if (gagnant == 2)
						{
							image.load("Gagnant2.ppm");
							scene.draw_image(0, 0, image);
							std::this_thread::sleep_for(5s);
							fin = TRUE;
						}
					}
				}
				break;
			}
		}
		


		
		
	}


	//test action
	/*P.affichePlateauConsole();
	int c = 1;
	while (c != 0)
	{
		int position;
		cin >> position;
		P.action(position);
		P.affichePlateauConsole();
		int a;
		cin >> a;
	}*/
    return 0;
}

