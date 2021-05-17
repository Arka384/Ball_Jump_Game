
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

		std::stringstream s;
		s << score;
		score_number.setString(s.str());

		if (game_state == 0 && executed == false)
			start();

		if (game_state == 1)
		{
			executed = false;
			update_tiles();
			//update_tile_speed();
			update_position();
			Doodle.setPosition(x, y);
		}
		


		window.clear();

		draw_sprites(window);

		draw_texts(window);
		if (game_state == 2)
		{
			window.draw(next);
			window.draw(over);
		}
		
		draw_player(window);
		draw_tiles(window);
		draw_window(window);

		window.display();
	}
}


