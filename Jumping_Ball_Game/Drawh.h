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