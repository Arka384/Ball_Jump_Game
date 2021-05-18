
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
		}
		


		//draw functions
		window.clear();

		draw_sprites(window);

		draw_texts(window);
		if (game_state == 2)
		{
			window.draw(next);
			window.draw(over);
		}
		else if (game_state == 0)
			window.draw(next);
		
		draw_player(window);
		draw_tiles(window);
		draw_window(window);

		//the menu screen on top
		if (game_state == 3)
			draw_menu_screen(window);


		window.display();
	}
}


