#include "Game.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include "allegro5/allegro_font.h"
#include "mappy_A5.h"


Game::Game()
{

}

Game::~Game()
{
}
void Game::drawMario(int x,int y)
{

	
	
	ALLEGRO_BITMAP*mario=al_load_bitmap("player1r.png");

	al_draw_bitmap(mario, x,y, NULL);
	
	
}

void Game::drawEnemys(int x,int y)
{



	ALLEGRO_BITMAP*enamy = al_load_bitmap("turtler1.png");

	
			al_draw_bitmap(enamy, mapblockgapx * 65 - x, mapblockheight * 12 - y, NULL);


	
}





void Game::mapCollisionDetect(int x,int y,int x1, int y1,int *score)
{

	ALLEGRO_BITMAP*clear = al_load_bitmap("coin1.png");
	int i=x;

		int in_x = mapblockgapx * 8 - i, in_y = mapblockheight * 12 - y;

		if (x1 = in_x)
		{
			al_draw_bitmap(clear, in_x, in_y, NULL);
		
			score += 1;
		}
		score += 1;
}