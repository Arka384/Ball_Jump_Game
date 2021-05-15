#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <list>
using namespace sf;

//game variables
constexpr int W_Width = 650;
constexpr int W_Height = 900;
constexpr int tile_width = 150;
constexpr int n_tiles = 10;
RectangleShape tiles[n_tiles];
float tile_gap_y = 150;
float last_tile_y = W_Height - 50;
int game_state = 0;
	//0 - start
	//1 - running
	//2 - over
	//then again 0

//Player variables
float ball_size = 40.f;
float x = W_Width / 2 - ball_size / 2, y = W_Height / 2 - ball_size / 2;
float velocity_x = 0;
float velocity_y = 0;
float accleration_x = 0;
float accleration_y = 0;
float gravity = 200;
CircleShape ball;

//other 
Clock cl;
Time t;
float dt;


void init_shapes(void);
void restart(void);

void update_position(void);
void update_movement(void);
void update_tiles(void);

void draw_tiles(RenderWindow &);
void draw_player(RenderWindow &);