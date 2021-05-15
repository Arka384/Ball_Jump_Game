#pragma once
#include "Depends.h"

void draw_tiles(RenderWindow &thisWindow)
{
	for (int i = 0; i < n_tiles; i++)
		thisWindow.draw(tiles[i]);
}

void draw_player(RenderWindow &thisWindow)
{
	thisWindow.draw(ball);
}

void draw_window(RenderWindow &thisWindow)
{
	thisWindow.draw(line);
}

void draw_texts(RenderWindow &thisWindow)
{
	thisWindow.draw(tip);
	thisWindow.draw(tip_1);
	thisWindow.draw(tip_2);
	thisWindow.draw(score_text);
	thisWindow.draw(score_number);
}