#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace sf;

//game variables
constexpr int Window_Width = 950;
constexpr int W_Width = 650;
constexpr int W_Height = 900;
constexpr int tile_width = 150;
constexpr int tile_height = 20;
constexpr int n_tiles = 10;
RectangleShape tiles[n_tiles];
RectangleShape line;
float tile_gap_y = 200;
float last_tile_y = W_Height - 50;
bool executed = false;
int score = 0;
int game_state = 0;
	//0 - start
	//1 - running
	//2 - over
	//then again 0

//Player variables
float doodle_w, doodle_h;
float x, y;
float velocity_x = 0;
float velocity_y = 0;
float accleration_x = 0;
float accleration_y = 0;
float gravity = 200;

//other 
Clock cl;
Time t;
float dt;
Text score_text, score_number;
Text tip, tips[4];
Text over, next;
Text menu[4];
Font flappy, arial;

//textrures
Texture background, doodle, doodle_2, bottom, platform;
Sprite Background, Bottom, Doodle;


void init_shapes(void);
void start(void);
void set_window(void);
void init_texts(void);
void init_sprites(void);

void update_position(void);
void update_movement(void);
void update_tiles(void);

void draw_tiles(RenderWindow &);
void draw_player(RenderWindow &);
void draw_window(RenderWindow &);
void draw_texts(RenderWindow &);
void draw_sprites(RenderWindow &);