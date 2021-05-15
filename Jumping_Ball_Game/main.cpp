
#include "Depends.h"
#include "Init.h"
#include "Updates.h"
#include "Drawh.h"

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(W_Width, W_Height), "test", Style::Close);
	init_shapes();

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

		if (game_state == 1)
		{
			update_tiles();
			update_position();
			ball.setPosition(x, y);
		}
		


		window.clear();
		if (game_state != 2)
		{
			draw_player(window);
			draw_tiles(window);
		}
		if (game_state == 2)
		{
			init_shapes();
			window.clear();
		}
		window.display();
	}
}


