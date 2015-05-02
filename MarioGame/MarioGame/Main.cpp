#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "mappy_A5.h"

#include "Game.h"

const int width = 800;
const int length = 500;
enum KEYS{ UP, DOWN, RIGHT, LEFT, SPACE };
bool keys[5] = { false, false, false, false, false };

int main()
{


	//primitives variables
	bool gameover = false;
	bool redraw = true;
	const int FPS = 60;
	

	// allegro variables  initailatision
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	// game class objects

	Game lo;
	//initialisation of allegro
	if (!al_init())
		return -1;
	display = al_create_display(width, length);
	if (!display)
		return -1;
	// addons init
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	
	if (MapLoad("MarioMap.fmp", 1))
		return -4;



	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	while (1)
	{ 
	
		MapDrawBG(0,76,0,-1, width, length);

		lo.drawCoins();
		al_flip_display();
	
	}



	MapFreeMem();
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	return 0;
}