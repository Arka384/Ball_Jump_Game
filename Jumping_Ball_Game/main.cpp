
#include "Depends.h"
#include "Init.h"
#include "Updates.h"
#include "Drawh.h"

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(Window_Width, W_Height), "test", Style::Close);
	flappy.loadFromFile("Fonts/flappy.ttf");
	arial.loadFromFile("Fonts/font.ttf");
	comic_sans.loadFromFile("Fonts/comic-sans.ttf");

	set_window();
	init_sprites();
	init_texts();
	init_sounds();

	while (window.isOpen())
	{
		t = cl.restart();
		dt = t.asSeconds();

		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
			case Event::KeyPressed:
				update_movement();
			default:
				break;
			}
		}

		//updates 
		std::stringstream s;
		s << score;
		score_number.setString(s.str());

		mx = Mouse::getPosition(window).x;
		my = Mouse::getPosition(window).y;
		//std::cout << mx << " " << my << std::endl;

		if (game_state == 0 && executed == false)
			start();

		if (game_state == 3)
			update_mouse_menu();
		else if (game_state == 1)
		{
			executed = false;
			update_tiles();
			update_position();
			Doodle.setPosition(x, y);
			spwan_pickups();
			if (spawner == true)
				update_pickups();
		}
		else if (game_state == 2)
			update_mouse_over();
		


		//draw functions
		window.clear();

		draw_sprites(window);

		draw_texts(window);
		
		if (game_state == 0)
			window.draw(next);
		
		draw_tiles(window);
		draw_window(window);
		draw_player(window);
		
		if (game_state == 1 && spawner == true && collided == false)
			window.draw(Jet_new);
		else if (game_state == 1 && spawner == true && collided == true && jet_time_counter < 5)
			window.draw(Jet_on);
		else if (game_state == 1 && spawner == true && collided == true && jet_time_counter < 7)
			window.draw(Jet_off);

		if (game_state == 2)
		{
			window.draw(next);
			window.draw(over);
			draw_over_screen(window);
		}

		//the menu screen on top
		if (game_state == 3)
			draw_menu_screen(window);



		window.display();
	}
}


