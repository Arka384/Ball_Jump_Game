#pragma once

#include "Depends.h"

void init_shapes(void)
{
	//this will init shapes for the first time only
	ball.setRadius(ball_size/2);
	ball.setFillColor(Color::Red);
	ball.setPosition(x, y);

	for (int i = 0; i < n_tiles; i++)
	{
		float px, py;
		px = rand() % W_Width;
		py = last_tile_y - tile_gap_y;
		if (i == 0)
		{
			px = W_Width / 2 - tile_width / 2;
			py = W_Height - 150;
		}
		last_tile_y = py;
		if (px > W_Width - tile_width)
			px -= tile_width;
		tiles[i].setSize(Vector2f(tile_width, 10));
		tiles[i].setFillColor(Color::White);
		tiles[i].setPosition(px, py);
	}
}

