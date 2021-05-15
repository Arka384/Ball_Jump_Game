#pragma once
#include "Depends.h"

//player update
void update_position(void)
{
	//updates for gravity
	for (int i = 0; i < n_tiles; i++)
	{
		if (y + ball_size >= tiles[i].getPosition().y && y + ball_size <= tiles[i].getPosition().y + 5 &&
			x + ball_size >= tiles[i].getPosition().x && x <= tiles[i].getPosition().x + tile_width)
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
	if (x > W_Width-ball_size)
	{
		x = W_Width - ball_size;
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
		velocity_x = 400;
	if (Keyboard::isKeyPressed(Keyboard::Left))
		velocity_x = -400;

	if (Keyboard::isKeyPressed(Keyboard::Enter))
		if (game_state == 0)
			game_state = 1;
		else
			game_state = 0;

}

void update_tiles(void)
{
	for (int i = 0; i < n_tiles; i++)
		tiles[i].move(0, 80 * dt);

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
