#pragma once

#include "Depends.h"

void set_window(void)
{
	line.setFillColor(Color::White);
	line.setSize(Vector2f(10, W_Height));
	line.setPosition(W_Width, 0);
}

void init_texts(void)
{
	tip_1.setFont(arial);
	tip_1.setCharacterSize(24);
	tip_1.setFillColor(Color::White);
	tip_2.setFont(arial);
	tip_2.setCharacterSize(24);
	tip_2.setFillColor(Color::White);
	tip.setFont(flappy);
	tip.setCharacterSize(35);
	tip.setFillColor(Color::Yellow);
	score_text.setFont(flappy);
	score_text.setCharacterSize(40);
	score_text.setFillColor(Color::Yellow);
	score_number.setFont(flappy);
	score_number.setCharacterSize(40);
	score_number.setFillColor(Color(173, 255, 47, 255));
	score_number.setString("0");

	score_text.setString("SCORE-");
	tip.setString("Tip: ");
	tip_1.setString("Jump first and then");
	tip_2.setString("Change Your Direction");

	tip.setPosition(W_Width + 20, W_Height - 200);
	tip_1.setPosition(W_Width + 20, W_Height - 150);
	tip_2.setPosition(W_Width + 20, W_Height - 120);
	score_text.setPosition(W_Width + 20, 10);
	score_number.setPosition(W_Width + 180, 10);


}

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

void start(void)
{
	last_tile_y = W_Height - 50;
	x = W_Width / 2 - ball_size / 2, y = W_Height / 2 - ball_size / 2;
	velocity_x = 0;
	velocity_y = 0;
	accleration_x = 0;
	accleration_y = 0;
	gravity = 200;
	init_shapes();
	score = 0;
	executed = true;
}

