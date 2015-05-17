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

}

void Game::drawEnemys(int x1,int y)
{

	ALLEGRO_BITMAP*enamy = al_load_bitmap("shell1.png");
	ALLEGRO_BITMAP*enamy1 = al_load_bitmap("goomba2.png");
		al_draw_bitmap(enamy, x1+50, y, NULL);
		al_convert_mask_to_alpha(enamy, al_map_rgb(0, 0, 0));
		
		// al_draw_bitmap(enamy1, x + 250, y, NULL);
		
	

	
}

void Game::marioCollideEnemy(int x, int x1,bool mario,bool gameover)
{
	
		if (x == x1)
		{
			mario = false;
			gameover = true;
			
		}
	
}

void Game::mapCollisionDetect(int& x,int& y,int& x1, int& y1,int &score, bool &draw)
{

	ALLEGRO_BITMAP*coin = al_load_bitmap("coin1.png");

	int i=x;

		int in_x = mapblockgapx * 8 - i, in_y = mapblockheight * 12 - y;
		if (x1 >= in_x && y1 >= in_y)
		{
			draw=false;
			if (x1 == in_x)
			score += 5;
			
		}
		else if (draw)
		   		al_draw_bitmap(coin, in_x, in_y, NULL);

		in_x += 50;
			if (x1 >= in_x && y1 >= in_y)
			{
				draw = false;
				if (x1 == in_x)
					score += 5;

			}
			else if (draw)
				al_draw_bitmap(coin, in_x, in_y, NULL);
		
}
int Game:: collided(int x, int y)
 {
	BLKSTR *blockdata;
	blockdata = MapGetBlock(x / mapblockwidth, y / mapblockheight);
	return blockdata->tl;
}