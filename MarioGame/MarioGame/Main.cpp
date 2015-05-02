#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "allegro5/allegro_font.h"
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_acodec.h>
#include "mappy_A5.h"

#include "Game.h"

const int width = 800;
const int length = 500;
enum KEYS{ UP,RIGHT, LEFT };
bool keys[5] = { false, false, false};

int main()
{


	//primitives variables
	bool gameover = false;
	bool redraw = false;
	const int FPS = 60;
	
	int x = 0, y = 0, y1 = 383,x1=20;

	// allegro variables  initailatision

	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	// game class objects

	Game lo;
	//initialisation of allegro
	if (!al_init())
		return -1;
	display = al_create_display(width, length);
	if (!display)
		return -1;

	// addons initialisation
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	
	
	if (MapLoad("MarioMap.fmp", 1))
		return -4;

	al_set_window_title(display, "SUPER MARIO 2D GAME");

	//play sound
	ALLEGRO_SAMPLE*one_up = al_load_sample("1-up.wav");
	ALLEGRO_SAMPLE*song = al_load_sample("orig.mp3");

	al_reserve_samples(2);

	ALLEGRO_SAMPLE_INSTANCE*songinstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songinstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songinstance, al_get_default_mixer());
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	

	al_register_event_source(queue, al_get_keyboard_event_source());
		al_register_event_source(queue, al_get_timer_event_source(timer));

		al_play_sample_instance(songinstance);
	al_start_timer(timer);
	// game loop
	while (!gameover)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				gameover = true;
				break;

			}
		}
		else
			if (event.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (event.keyboard.keycode)
				{
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_ESCAPE:
					gameover = true;
					break;
				}
			}

			else if (event.type == ALLEGRO_EVENT_TIMER)
			{
				x -= keys[LEFT]*10;
				x += keys[RIGHT]*10;
				x1 -= keys[LEFT] * 10;
				x1 += keys[RIGHT] * 10;
				

				
				if (x1>500)
					x1 = 500-10;


				if (x < 0)
					x = 0;
				if (y < 0)
					y = 0;
				if (x>(mapwidth*mapblockwidth) - width)
					x = (mapwidth*mapblockwidth) - width;

				if (y>(mapheight*mapblockheight) - width)
				y = (mapheight*mapblockheight) - length;

				redraw = true;
			}

		if (redraw && al_is_event_queue_empty(queue))
		{

			redraw = false;

			MapDrawBG(x, y, 0, 0, width, length);
	
			lo.drawMario(x1,y1);
			
			
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}



	MapFreeMem();
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_sample(one_up);
	al_destroy_sample(song);
	al_destroy_sample_instance(songinstance);
	al_destroy_event_queue(queue);
	return 0;
}