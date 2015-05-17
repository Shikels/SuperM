#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
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
	BLKSTR* currentblock;
	bool draw = true;
	int mapx = 0, mapy = 0, y= 0,x=20;
	int score=0;
	int velx=0, vely=0;
	const  float gravity = 5;
	bool jump = false;
	float jumpspeed = 10;
	bool active = false;
	int sourceX = 0;
	int x1=650, y1=380;
	// allegro variables  initailatision

	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	
	

	// game class objects

	Game lo;
	//initialisation of allegro
	if (!al_init())
		return -1;
	display = al_create_display(width, length); //creates display object
	if (!display)                               //test display object
		return -1;

	// addons initialisation
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	
	if (MapLoad("MarioMap.fmp", 1))
		return -4;
	
	
	al_set_window_title(display, "SUPER MARIO 2D GAME");

	//play sound
	al_reserve_samples(3);
	ALLEGRO_SAMPLE*one_up = al_load_sample("die.wav");
	ALLEGRO_SAMPLE*song = al_load_sample("orig.wav");
	ALLEGRO_SAMPLE*jumpSound = al_load_sample("jump.wav");
	// font and bitmaps
	ALLEGRO_FONT*font;
	ALLEGRO_BITMAP*mario = al_load_bitmap("mario.png");
	


	
	font = al_load_font("timesnewarial.ttf",18,0);
	
	

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
	//keycode scan and moving based on keyboard input
	while (!gameover)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		//al_play_sample(song);

		al_play_sample(one_up, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);



		if (event.type == ALLEGRO_EVENT_KEY_DOWN) // when key is pushed down
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
			if (event.type == ALLEGRO_EVENT_KEY_UP) // when key is released
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

			
				if (keys[UP] && jump)
				{
				jump = false;
			
				} 
					
				if (!jump)
					y += gravity;
				else
					vely = 0;
				x += velx;
				y += vely;


				jump = (y >= 375);

				if (jump)
					y = 375;
					

					if (keys[UP])
					{

						//al_play_sample(jumpSound, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
						y -= 10;
						if (keys[RIGHT])
							x += 2;
						if (y < 20)
							y += 10; 
					}
					if (keys[LEFT])
					{

						x -= keys[LEFT] * 2;
						if (x < 0)
							x = 0;

					}

					
					//Mario movement above and under the Block
					else if (x >= 175 && x <= 440)
					{
						
						//above the block
					if (y < 205)
					{
						y = 175;
						y -= keys[UP] * 60;
					}

					//under the block
					if (y > 205)
					{
						y = length - 125;
						y -= keys[UP] * 120;
					}
					}
						

			
				if (keys[RIGHT])
				{
					x += keys[RIGHT] * 2;
					sourceX += al_get_bitmap_width(mario) / 3;
					if (sourceX >= al_get_bitmap_width(mario))
						sourceX = 0;
					

				}
			
				lo.marioCollideEnemy(x, x +50,mario,gameover);
				//map boundx and boundy
				
				mapx -= keys[LEFT] * 2;
				mapx += keys[RIGHT] * 2;

				if (mapx < 0)
					mapx = 0;
				if (mapy < 0)
					mapy = 0;
				if (mapx>(mapwidth*mapblockwidth) - width)
					mapx = (mapwidth*mapblockwidth) - width;

				if (mapy>(mapheight*mapblockheight) - width)
				mapy = (mapheight*mapblockheight) - length;

				if (active)

				{
					sourceX += al_get_bitmap_width(mario) / 3;
				}
				else
					sourceX = 36;
				if (sourceX >= al_get_bitmap_width(mario))
					sourceX = 0;


				redraw = true;
			}

		if (redraw && al_is_event_queue_empty(queue))
		{

			redraw = false;

			
		
	
			if (x > 760)
			{
			
				x = 770;
				//al_draw_bitmap(gavor, 0, 0, NULL);
				al_clear_to_color(al_map_rgb(10, 150, 155));
				al_draw_textf(font, al_map_rgb(0, 0, 0), 50, length / 2, 100, " YOU HAVE COMPLETED LEVEL 1");
				al_draw_textf(font, al_map_rgb(0, 0, 0), 50, length / 2+50,100, "SCORE IS   %i", score);

				
			}
			
			else
			{
				x1 -= 3;
				MapDrawBG(mapx, mapy, 0, 0, width, length);

				// collision with the enemy
				if (x == x1 && y == y1)
				{
					gameover = true;
				}

				else
					al_draw_bitmap_region(mario, sourceX, 0, 45, 42, x, y, NULL);
				al_convert_mask_to_alpha(mario, al_map_rgb(0, 0, 0));
				
				al_draw_textf(font, al_map_rgb(0, 255, 150), 5, 5, 0, "Mario Has $%i and %i", x,y);


				lo.mapCollisionDetect(mapx, mapy, x, y, score,draw);

				// draw enemy
				if (x > 200 && x<600)
				{
					
					if (x1 < 0)
					{
						x1 = 650;
					}
					else
					lo.drawEnemys(x1, y1);
				
				}

				al_draw_textf(font, al_map_rgb(0, 255, 150), 5, 5, 0, "Mario Has $%i", score);
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0)); //clears back buffer to the colour black
		}

	}


	// destroy all declared pointer variables
	MapFreeMem();
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_sample(one_up);
	al_destroy_sample(song);
	al_destroy_bitmap(mario);
	al_destroy_sample_instance(songinstance);
	al_destroy_event_queue(queue);
	return 0;
}