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


void Game::DrawCoins_enemys_box(int x, int y,int x1,int y1)
{
	int xoff = x;
	
	ALLEGRO_BITMAP*coins = al_load_bitmap("coin1.png");
	ALLEGRO_BITMAP*box = al_load_bitmap("box.png");
	ALLEGRO_BITMAP*blume = al_load_bitmap("blume.png");
	
	// first coin group
	
	    
		al_draw_bitmap(coins, mapblockgapx * 8 - xoff, mapblockheight * 12 - y, NULL);
		xoff += 50;
		
		al_draw_bitmap(coins, mapblockgapx * 8 - xoff, mapblockheight * 12 - y, NULL);
		xoff += 50;
		al_draw_bitmap(coins, mapblockgapx * 8 - xoff, mapblockheight * 12 - y, NULL);
		xoff += 50;
		al_draw_bitmap(coins, mapblockgapx * 8 - xoff, mapblockheight * 12 - y, NULL);
	
	// second coin group

	xoff =x ;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 12 - y, NULL);

	// third coin group

	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 35 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 35 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 35 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 35 - xoff, mapblockheight * 12 - y, NULL);


	// fourth group

	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 6 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 6- y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 6 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 15 - xoff, mapblockheight * 6 - y, NULL);

	// next group

	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 30 - xoff, mapblockheight * 6 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 30 - xoff, mapblockheight * 6 - y, NULL);

	// next group
	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 40 - xoff, mapblockheight * 3 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 40 - xoff, mapblockheight * 3 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 40 - xoff, mapblockheight * 3 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 40 - xoff, mapblockheight * 3 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 40 - xoff, mapblockheight * 3 - y, NULL);

	//next coins 


	xoff =x;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 7 - y, NULL);
	

	// last conis
	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	xoff = x;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 12 - y, NULL);
	xoff += 50;
	al_draw_bitmap(coins, mapblockgapx * 70 - xoff, mapblockheight * 12 - y, NULL);


// draw box and blume

	al_draw_bitmap(blume, mapblockgapx * 59 - xoff, mapblockheight * 9 - y, NULL);
	al_draw_bitmap(box, mapblockgapx * 22 - xoff, mapblockheight * 4 - y, NULL);






	//destroy allegro variables
	al_destroy_bitmap(coins);
	al_destroy_bitmap(box);
	al_destroy_bitmap(blume);

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