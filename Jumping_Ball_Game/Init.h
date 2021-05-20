#pragma once

#include "Depends.h"

void set_window(void)
{
	line.setFillColor(Color(139, 69, 19, 255));
	line.setSize(Vector2f(10, W_Height));
	line.setPosition(W_Width, 0);

	line_2.setFillColor(Color::Black);
	line_2.setSize(Vector2f(10, W_Height));
	line_2.setPosition(Window_Width/2 - 5, 0);
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
	tips[0].setString("Use the momentum for");
	tips[1].setString("higher jumps");
	tips[2].setString("Try not to stop");
	//tips[3].setString("multiple times will help");

	tip.setPosition(W_Width + 20, W_Height - 200);
	tips[0].setPosition(W_Width + 20, W_Height - 150);
	tips[1].setPosition(W_Width + 30, W_Height - 130);
	tips[2].setPosition(W_Width + 20, W_Height - 90);
	//tips[3].setPosition(W_Width + 30, W_Height - 70);
	score_text.setPosition(W_Width + 20, 10);
	score_number.setPosition(W_Width + 180, 10);
	over.setPosition(W_Width + 20, W_Height / 2 - 100);
	next.setPosition(W_Width + 40, W_Height / 2 - 30);

	help.setFont(comic_sans);
	help.setCharacterSize(40);
	help.setFillColor(Color::Black);
	help.setString("Help");
	help.setPosition(650, 500);
	help_back.setSize(Vector2f(100, 50));
	help_back.setFillColor(Color(0,0,0,0));
	help_back.setPosition(640, 505);

}

void init_sprites(void)
{
	background.loadFromFile("Images/bck_white.png");
	Background.setTexture(background);
	Background.setScale(Vector2f(0.79, 1));

	bottom.loadFromFile("Images/bottom.png");
	Bottom.setTexture(bottom);
	Bottom.setScale(Vector2f(1.58, 1));
	Bottom.setPosition(0, W_Height - 30);

	doodle.loadFromFile("Images/doodle_left.png");
	Doodle.setTexture(doodle);
	doodle_2.loadFromFile("Images/doodle_right.png");
	platform.loadFromFile("Images/platform.png");

	//main menu sprites
	main_menu.loadFromFile("Images/menu.jpg");
	Menu.setTexture(main_menu);
	play_b.loadFromFile("Images/play.png");
	play_b.setSmooth(true);
	Play.setTexture(play_b);
	play_b_on.loadFromFile("Images/play-on.png");
	play_b_on.setSmooth(true);
	Play.setScale(Vector2f(1.5, 1.5));
	Play.setPosition(W_Width/2 + 100, W_Height/2 - 80);

	//jetpack sprites
	jet_off.loadFromFile("Images/jetpack_off.png");
	jet_on.loadFromFile("Images/jetpack_on.png");
	jet_new.loadFromFile("Images/jet.png");
	Jet_new.setTexture(jet_new);
	Jet_off.setTexture(jet_off);
	Jet_on.setTexture(jet_on);
	Jet_off.setScale(Vector2f(0.8, 0.8));
	Jet_on.setScale(Vector2f(0.8, 0.8));

	//over screen 
	over_screen.loadFromFile("Images/game-over.jpg");
	Over.setTexture(over_screen);
	Over.setScale(Vector2f(1.45, 0.8));

	menu_on.loadFromFile("Images/menu-on.png");
	Menu_on.setTexture(menu_on);
	Menu_on.setScale(Vector2f(1.3, 0.7));
	Menu_on.setPosition(264, 544);

	replay.loadFromFile("Images/replay.png");
	Replay.setTexture(replay);
	Replay.setScale(Vector2f(1.5, 0.8));
	Replay.setPosition(260, 453);

	//help images
	help_1.loadFromFile("Images/help_1.jpg");
	help_2.loadFromFile("Images/help_2.jpg");
	Help_1.setTexture(help_1);
	Help_2.setTexture(help_2);
	Help_1.setScale(Vector2f(1.12, 1.12));
	Help_2.setScale(Vector2f(1.12, 1.12));
	Help_2.setPosition(Window_Width/2, 0);
}

void init_sounds(void)
{
	jump_sound.loadFromFile("Sounds/jump.wav");
	jump.setBuffer(jump_sound);
	jump.setVolume(100.f);

	start_sound.loadFromFile("Sounds/start.wav");
	s_start.setBuffer(start_sound);
	s_start.setVolume(100.f);

	fall_sound.loadFromFile("Sounds/pada.wav");
	fall.setBuffer(fall_sound);
	fall.setVolume(50.f);

	jetpack.loadFromFile("Sounds/Jetpack.wav");
	JetPack.setBuffer(jetpack);

	collect.loadFromFile("Sounds/collect.wav");
	Collect.setBuffer(collect);

	pause.loadFromFile("Sounds/pause.wav");
	Pause.setBuffer(pause);
}

void init_shapes(void)
{
	int i;
	//this will init shapes for the first time only
	Doodle.setScale(Vector2f(0.8, 0.8));
	doodle_w = Doodle.getGlobalBounds().width;
	doodle_h = Doodle.getGlobalBounds().height;
	x = W_Width / 2 - doodle_w / 2;
	y = W_Height / 2 - doodle_h / 2;
	Doodle.setPosition(x, y);

	for (i = 0; i < n_tiles; i++)
	{
		int px, py;
		
		if (i == 0)
		{
			px = W_Width / 2 - tile_width / 2;
			py = W_Height - 150;
			last_tile_y = py;
			last_tile_x = px;
			tiles[i].setSize(Vector2f(tile_width, tile_height));
			tiles[i].setTexture(&platform);
			tiles[i].setPosition(px, py);
			continue;
		}

		int low = last_tile_x - tile_gap_x - tile_width;
		int high = last_tile_x + tile_gap_x;

		px = (rand() % (high - low + 1) + low);
		py = last_tile_y - tile_gap_y;
	
		if (px > W_Width - tile_width)
		{
			px = 0;
			px -= tile_width;
		}
		else if (px < 0)
		{
			px = 0;
			px = rand() % W_Width / 2;
		}

		last_tile_y = py;
		last_tile_x = px;

		tiles[i].setSize(Vector2f(tile_width, tile_height));
		tiles[i].setTexture(&platform);
		tiles[i].setPosition(px, py);
	}
	last_tile_x = tiles[i - 1].getPosition().x;
}

void start(void)
{
	last_tile_y = W_Height - 50;
	score_number.setPosition(W_Width + 180, 10);
	score_number.setFont(flappy);
	score_number.setFillColor(Color::White);
	x = W_Width / 2 - doodle_w / 2, y = W_Height / 2 - doodle_h / 2;
	velocity_x = 0;
	velocity_y = 0;
	accleration_x = 0;
	accleration_y = 0;
	gravity = 200;
	init_shapes();
	score = 0;
	timer = 0;
	move_speed = 120;
	spawn_time = 10;
	spawner = false;
	draw_help = false;
	executed = true;
}

