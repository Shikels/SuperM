#include "Game.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include "mappy_A5.h"


Game::Game()
{
}


Game::~Game()
{
}
void Game::drawMario()
{


	ALLEGRO_BITMAP*mario=al_load_bitmap("mario.png");

	al_draw_bitmap(mario, 30, 383, NULL);
	

}

void Game::drawCoins()
{


	ALLEGRO_BITMAP*mario = al_load_bitmap("coin1.png");
	int in_x =380;
	
	
	for (int i = 0; i < 5; i++)
	{      
		
		in_x += 40;
		al_draw_bitmap(mario, in_x, 350, NULL);
	}

	in_x = 340;

	for (int i = 0; i < 7; i++)
	{      
		
		in_x += 40;
		al_draw_bitmap(mario, in_x, 100, NULL);
	}

	


}

void Game::moveMario()
{



}
