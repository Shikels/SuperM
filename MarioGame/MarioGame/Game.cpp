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
void Game::drawCoins()
{


	ALLEGRO_BITMAP*mario=al_load_bitmap("mario.png");

	al_draw_bitmap(mario, 30, 383, NULL);
	






}
