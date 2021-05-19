#pragma once
#include "Depends.h"

void draw_tiles(RenderWindow &thisWindow)
{
	for (int i = 0; i < n_tiles; i++)
		thisWindow.draw(tiles[i]);
}

void draw_player(RenderWindow &thisWindow)
{
	thisWindow.draw(Doodle);
}

void draw_window(RenderWindow &thisWindow)
{
	thisWindow.draw(line);
}

void draw_sprites(RenderWindow &thisWindow)
{
	thisWindow.draw(Background);
	thisWindow.draw(Bottom);
	thisWindow.draw(Doodle);
}

void draw_menu_screen(RenderWindow &thisWindow)
{
	thisWindow.draw(Menu);
	thisWindow.draw(Play);
	thisWindow.draw(help_back);
	thisWindow.draw(help);

	if (draw_help)
	{
		thisWindow.draw(Help_1);
		thisWindow.draw(Help_2);
		thisWindow.draw(line_2);
	}
}

void draw_over_screen(RenderWindow &thisWindow)
{
	thisWindow.draw(Over);
	thisWindow.draw(score_number);
	if (draw_menu)
	{
		thisWindow.draw(Menu_on);
		draw_menu = false;
	}
	if (draw_replay)
	{
		thisWindow.draw(Replay);
		draw_replay = false;
	}
}

void draw_texts(RenderWindow &thisWindow)
{
	thisWindow.draw(tip);
	for (int i = 0; i < 3; i++)
		thisWindow.draw(tips[i]);
	thisWindow.draw(score_text);
	thisWindow.draw(score_number);
}