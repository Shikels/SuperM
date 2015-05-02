#include "Game.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include "allegro5/allegro_font.h"
#include "mappy_A5.h"


Game::Game()
{
	in_x = 0;
	in_y = 0;
}


Game::~Game()
{
}
void Game::drawMario(int x,int y)
{

	
	
	ALLEGRO_BITMAP*mario=al_load_bitmap("SuperM.png");

	al_draw_bitmap(mario, x,y, NULL);
	
	
}


