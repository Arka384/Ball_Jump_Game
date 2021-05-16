#pragma once
#include "Depends.h"

//player update
void update_position(void)
{
	//updates for gravity
	for (int i = 0; i < n_tiles; i++)
	{
		float tile_x = tiles[i].getPosition().x;
		float tile_y = tiles[i].getPosition().y;

		if (y + doodle_h >= tile_y && y + doodle_h <= tile_y + tile_height/2 &&
			x + doodle_w >= tile_x && x + 50 <= tile_x + tile_width)
		{
			velocity_x = 0;
			velocity_y = 0;
			if (Keyboard::isKeyPressed(Keyboard::Up))
				velocity_y = -900;
		}
		else
			velocity_y += gravity * dt;
	}

	//updating positions
	velocity_x += accleration_x * dt;
	velocity_y += accleration_y * dt;
	x += velocity_x * dt;
	y += velocity_y * dt;

	//checking for wall-collisions
	if (x < 0)
	{
		x = 0;
		velocity_x = -(velocity_x + 300);
	}
	if (x > W_Width - doodle_w)
	{
		x = W_Width - doodle_w;
		velocity_x = -(velocity_x - 300);
	}
	if (y < 0)
	{
		y = 0;
		velocity_y = -(velocity_y + 100);
	}

	if (y > W_Height)
		game_state = 2;
}

void update_movement(void)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Doodle.setTexture(doodle_2);
		velocity_x = 400;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Doodle.setTexture(doodle);
		velocity_x = -400;
	}

	if (Keyboard::isKeyPressed(Keyboard::Enter))
		if (game_state == 0)
			game_state = 1;
		else if (game_state == 2)
			game_state = 0;

}

void update_tiles(void)
{
	for (int i = 0; i < n_tiles; i++)
		tiles[i].move(0, 100 * dt);

	for (int i = 0; i < n_tiles; i++)
	{
		if (tiles[i].getPosition().y > W_Height)
		{
			score += 2;

			last_tile_y += tile_gap_y;
			float px, py;
			px = rand() % W_Width;
			py = last_tile_y - tile_gap_y;
			last_tile_y = py;
			if (px > W_Width - tile_width)
				px -= tile_width;
			tiles[i].setPosition(px, py);
		}
	}
}
