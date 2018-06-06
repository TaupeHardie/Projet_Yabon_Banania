#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main() {
	


	int table[7][4] = { 0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,3,3,0,0,0,0,0 };
	CImg<float> image;
	image.load("Test_png.PPM");
	CImg<unsigned char> Menu(400, 700, 1, 3, 255);
	CImgDisplay Menudisp(Menu, "Menu", 0, false, false);
	Menudisp.move((CImgDisplay::screen_width() - Menudisp.width()) / 2,
		(CImgDisplay::screen_height() - Menudisp.height()) / 2);
	CImg<float> Bouton1;
	CImg<float> Bouton2;
	CImg<float> Bouton3;
	Bouton1.load("Nvlle.PPM");
	Bouton2.load("Save.PPM");
	Bouton3.load("Charger.PPM");
	Menu.draw_image(1 * 100, 1 * 100, Bouton1);
	Menu.draw_image(1 * 100, 3 * 100, Bouton2);
	Menu.draw_image(1 * 100, 5 * 100, Bouton3);
	while (!Menudisp.is_closed() && !Menudisp.is_keyESC() && !Menudisp.is_keyQ()) {

		// Display the scene
		Menu.display(Menudisp);
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



/*unsigned char
		grid_color[3] = { 0,0,255 },
		play1_color[3] = { 204,0,0 },
		play2_color[3] = { 0,102,0 };
	CImg<float> image;
	image.load("Test_png.PPM");
	// Declare an image to draw the grid
	CImg<unsigned char> grid(800, 400, 1, 3, 255);
	for (int j = 1; j < 4; j++) grid.draw_line(100, j * 100, 700, j * 100, grid_color);
	for (int j = 1; j < 8; j++) grid.draw_line(100 * j, 100, 100 * j, 300, grid_color);

	// Declare a display to draw the scene
	CImgDisplay disp(grid, "Awale", 0, false, false);
	// Center the window on the screen
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);

	// Declare an image to display the scene
	CImg<unsigned char> scene = grid;
	// Usefull variables
	int player = 1;
	int table[4][8] = { 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0 }; // cadriage de l'espace 
	// Main loop, exit if the display window is closed or if ESC or Q key is hit
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {

		// Display the scene
		scene.display(disp);

		// Detect mouse click
		

	/*	disp.wait();
		if (disp.button() & 1) { // Left button clicked.
			int i = 4 * disp.mouse_y() / disp.height();
			int j = 8 * disp.mouse_x() / disp.width();
			cout << i << " " << j << " ";
			if (i > 0 && i < 3 && j>0 && j < 7) { //ne pas attribuer de valeurs aux autres cases 
					// Player 1, draw circle red
				if (player == 1 && table[i][j] == 1) {
					scene.draw_image(j * 100, i * 100,image);
					scene.draw_circle(50 + j * 100, 50 + i * 100, 40, play1_color, 1, ~0U);
					player = 3 - player;
				}
				// Player 2, draw circle green
				if (player == 2 && table[i][j] == 2) {
					scene.draw_image(j * 100, i * 100, image);
					scene.draw_circle(50 + j * 100, 50 + i * 100, 40, play2_color, 2, ~0U);
					player = 3 - player;
				}
			}

			//  window resize
			if (disp.is_resized()) disp.resize();
		}
	}
  return 0;
}*/




void display_grid() {
	int player =1; // Peux être changé pour l'appel du numéro du tour
	int table[4][8] = { 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0 };
	unsigned char
		grid_color[3] = { 0,0,255 },
		play1_color[3] = { 204,0,0 },
		play2_color[3] = { 0,102,0 };
	CImg<unsigned char> grid(800, 400, 1, 3, 255);
	for (int j = 1; j < 4; j++) grid.draw_line(100, j * 100, 700, j * 100, grid_color);
	for (int j = 1; j < 8; j++) grid.draw_line(100 * j, 100, 100 * j, 300, grid_color);
	CImg<float> image;
	CImg<unsigned char> scene = grid;
	CImgDisplay disp(grid, "Awale", 0, false, false);
	image.load("Test_png.PPM");
	for (int i = 1; i < 7; i++) {
		scene.draw_image(i * 100, 1 * 100, image);
		scene.draw_image(i * 100, 2 * 100, image);
	}

	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {

		// Display the scene
		scene.display(disp);
		disp.wait();
		if (disp.button() & 1) { 
			int i = 4 * disp.mouse_y() / disp.height();
			int j = 8 * disp.mouse_x() / disp.width();
			if (i > 0 && i < 3 && j>0 && j < 7) { //ne pas attribuer de valeurs aux autres cases

				if (player == 1 && table[i][j] == 1) {
					
					//  Appel de l'action , on prendra ici comme valeur du tableau i -1 

					player = 3 - player;
				}

				if (player == 2 && table[i][j] == 2) {
					
					// Appel de l'action  on prendra ici comme valeur du tableau i +5

					player = 3 - player;
				}
			}
		}
	}
}

void displayMenu() {
	int table[5][4] = { 0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,0,0,0,0,0 };
	CImg<float> image;
	image.load("Test_png.PPM");
	CImg<unsigned char> Menu(400, 500, 1, 3, 255);
	CImgDisplay Menudisp(Menu, "Menu", 0, false, false);
	Menudisp.move((CImgDisplay::screen_width() - Menudisp.width()) / 2,
		(CImgDisplay::screen_height() - Menudisp.height()) / 2);
	CImg<float> Bouton1;
	CImg<float> Bouton2;
	Bouton1.load("Nvlle.PPM");
	Bouton2.load("Save.PPM");
	Menu.draw_image(1 * 100, 1 * 100, Bouton1);
	Menu.draw_image(1 * 100, 3 * 100, Bouton2);
	while (!Menudisp.is_closed() && !Menudisp.is_keyESC() && !Menudisp.is_keyQ()) {

		// Display the scene
		Menu.display(Menudisp);
		Menudisp.wait();
		if (Menudisp.button() & 1)
		{ 
			int i = 4 * Menudisp.mouse_y() / Menudisp.height();
			int j = 5 * Menudisp.mouse_x() / Menudisp.width();
			if (table[i][j] == 1)
			{
				// Nouvelle partie 
			}
			if (table[i][j] == 2)
			{
				// Déclencher la sauvegarde 
			}
		}
	}
}


void displayMenu2() {
	int table[7][4] = { 0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,3,3,0,0,0,0,0 };
	CImg<float> image;
	image.load("Test_png.PPM");
	CImg<unsigned char> Menu(400, 700, 1, 3, 255);
	CImgDisplay Menudisp(Menu, "Menu", 0, false, false);
	Menudisp.move((CImgDisplay::screen_width() - Menudisp.width()) / 2,
		(CImgDisplay::screen_height() - Menudisp.height()) / 2);
	CImg<float> Bouton1;
	CImg<float> Bouton2;
	CImg<float> Bouton3;
	Bouton1.load("Nvlle.PPM");
	Bouton2.load("Save.PPM");
	Bouton2.load("Charger.PPM");
	Menu.draw_image(1 * 100, 1 * 100, Bouton1);
	Menu.draw_image(1 * 100, 3 * 100, Bouton2);
	while (!Menudisp.is_closed() && !Menudisp.is_keyESC() && !Menudisp.is_keyQ()) {

		// Display the scene
		Menu.display(Menudisp);
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