#include <iostream>
#include "CImg.h"
using namespace std;
using namespace cimg_library;

int main(){
	unsigned char
		grid_color[3] = { 0,0,255 },
		play1_color[3] = { 204,0,0 },
		play2_color[3] = { 0,102,0 };

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
	int liste[13] = { 0, 4, 12 , 0 ,1 ,2 ,3 ,4, 5, 6 ,7 ,8 ,9 };
	// Main loop, exit if the display window is closed or if ESC or Q key is hit
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {

		// Display the scene
		scene.display(disp);

		// Detect mouse click

		disp.wait();
		if (disp.button() & 1) { // Left button clicked.
			int i = 4 * disp.mouse_y() / disp.height();
			int j = 8 * disp.mouse_x() / disp.width();
			cout << i << " " << j << " ";
			if (i > 0 && i < 3 && j>0 && j < 7) { //ne pas attribuer de valeurs aux autres cases 
					// Player 1, draw circle red
				if (player == 1 && table[i][j] == 1) 
				{
					/*for (int k = 1; k < liste[j]; k++) 
					{
						scene.draw_circle(20+ j * (100) + k * 50/liste[i], 50 + i * 100, 100/ liste[j], play1_color, 1, ~0U);

					}*/
					scene.draw_circle(50 + j * 100, 50 + i * 100, 40, play1_color, 2, ~0U);
					player = 3 - player;

				}
				// Player 2, draw circle green
				if (player == 2 && table[i][j] == 2) {
					scene.draw_circle(50 + j * 100, 50 + i * 100, 40, play2_color, 2, ~0U);
					player = 3 - player; // joueur
				}

			}
			//  window resize
			if (disp.is_resized()) disp.resize();
		}
	}

  return 0;
}
