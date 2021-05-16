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

void draw_sprites(RenderWindow &thisWindow)
{
	thisWindow.draw(Background);
	thisWindow.draw(Bottom);
}

void draw_texts(RenderWindow &thisWindow)
{
	thisWindow.draw(tip);
	for (int i = 0; i < 4; i++)
		thisWindow.draw(tips[i]);
	thisWindow.draw(score_text);
	thisWindow.draw(score_number);
}