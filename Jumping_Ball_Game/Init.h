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
	for (int i = 0; i < 4; i++)
	{
		tips[i].setFont(arial);
		tips[i].setCharacterSize(20);
		tips[i].setFillColor(Color::White);
	}
	tip.setFont(flappy);
	tip.setCharacterSize(35);
	tip.setFillColor(Color::Yellow);

	score_text.setFont(flappy);
	score_text.setCharacterSize(40);
	score_text.setFillColor(Color::Yellow);
	score_number.setFont(flappy);
	score_number.setCharacterSize(40);
	score_number.setFillColor(Color::White);
	score_number.setString("0");

	over.setFont(flappy);
	over.setCharacterSize(50);
	over.setFillColor(Color(255, 228, 196, 255));
	next.setFont(flappy);
	next.setCharacterSize(35);
	next.setFillColor(Color(255, 228, 196, 255));

	score_text.setString("SCORE-");
	over.setString("Game Over!");
	next.setString("Press Return");
	tip.setString("Tip: ");
	tips[0].setString("Jump first and then");
	tips[1].setString("change your direction");
	tips[2].setString("Pressing arrow keys");
	tips[3].setString("multiple times will help");

	tip.setPosition(W_Width + 20, W_Height - 200);
	tips[0].setPosition(W_Width + 20, W_Height - 150);
	tips[1].setPosition(W_Width + 30, W_Height - 130);
	tips[2].setPosition(W_Width + 20, W_Height - 90);
	tips[3].setPosition(W_Width + 30, W_Height - 70);
	score_text.setPosition(W_Width + 20, 10);
	score_number.setPosition(W_Width + 180, 10);
	over.setPosition(W_Width + 20, W_Height / 2 - 100);
	next.setPosition(W_Width + 40, W_Height / 2 - 30);

}

void init_sprites(void)
{
	background.loadFromFile("Images/bck.png");
	Background.setTexture(background);
	Background.setScale(Vector2f(1.03, 1));

	bottom.loadFromFile("Images/bottom.png");
	Bottom.setTexture(bottom);
	Bottom.setScale(Vector2f(2.03, 1));
	Bottom.setPosition(0, W_Height - 30);

	doodle.loadFromFile("Images/doodle_left.png");
	Doodle.setTexture(doodle);
	doodle_2.loadFromFile("Images/doodle_right.png");
	platform.loadFromFile("Images/platform.png");
}

void init_shapes(void)
{
	//this will init shapes for the first time only

	doodle_w = Doodle.getGlobalBounds().width;
	doodle_h = Doodle.getGlobalBounds().height;
	x = W_Width / 2 - doodle_w / 2;
	y = W_Height / 2 - doodle_h / 2;
	Doodle.setPosition(x, y);

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
		tiles[i].setSize(Vector2f(tile_width, tile_height));
		//tiles[i].setFillColor(Color::Green);
		tiles[i].setTexture(&platform);
		tiles[i].setPosition(px, py);
	}
}

void start(void)
{
	last_tile_y = W_Height - 50;
	x = W_Width / 2 - doodle_w / 2, y = W_Height / 2 - doodle_h / 2;
	velocity_x = 0;
	velocity_y = 0;
	accleration_x = 0;
	accleration_y = 0;
	gravity = 200;
	init_shapes();
	score = 0;
	executed = true;
}

