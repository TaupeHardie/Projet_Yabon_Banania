#include "Menu_principal.h"
using namespace std;
using namespace cimg_library;



Menu_principal::Menu_principal()
{

}


Menu_principal::~Menu_principal()
{
}

void Menu_principal::nvllePartie() {
	Joueur J1(true);
	Joueur J2(false);
	Plateau awa (&J1,&J2);
	//awa.affichePlateau();

}

bool Menu_principal::quitter() {
	return true;
}

void Menu_principal::affiche()
{
	int table[7][4] = { 0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,3,3,0,0,0,0,0 };
	CImg<float> image;
	image.load("Test_png.PPM");
	CImg<unsigned char> Menu_p(400, 700, 1, 3, 255);
	CImgDisplay Menudisp(Menu_p, "Menu", 0, false, false);
	Menudisp.move((CImgDisplay::screen_width() - Menudisp.width()) / 2, (CImgDisplay::screen_height() - Menudisp.height()) / 2);
	CImg<float> Bouton1;
	CImg<float> Bouton2;
	CImg<float> Bouton3;
	Bouton1.load("Nvlle.PPM");
	Bouton2.load("Save.PPM");
	Bouton3.load("Charger.PPM");
	Menu_p.draw_image(1 * 100, 1 * 100, Bouton1);
	Menu_p.draw_image(1 * 100, 3 * 100, Bouton2);
	Menu_p.draw_image(1 * 100, 5 * 100, Bouton3);
	while (!Menudisp.is_closed() && !Menudisp.is_keyESC() && !Menudisp.is_keyQ()) {

		// Display the scene
		Menu_p.display(Menudisp);
		Menudisp.wait();
		if (Menudisp.button() & 1)
		{
			int i = 4 * Menudisp.mouse_y() / Menudisp.height();
			int j = 7 * Menudisp.mouse_x() / Menudisp.width();
			if (table[i][j] == 1)
			{
				// Nouvelle partie 
			}
			if (table[i][j] == 2)
			{
				// Déclencher la sauvegarde 
			}
			if (table[i][j] == 3)
			{
				// Déclencher le chargement
			}
		}
	}
}
