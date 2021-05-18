#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace sf;

//game variables
constexpr int Window_Width = 800;
constexpr int W_Width = 500;
constexpr int W_Height = 700;
constexpr int tile_width = 80;
constexpr int tile_height = 20;
constexpr int n_tiles = 15;
RectangleShape tiles[n_tiles];
RectangleShape line;
float tile_gap_y = 60;
float tile_gap_x = 300;
float last_tile_y = W_Height - 50;
float last_tile_x;
int move_speed = 120;
bool executed = false;
int score = 0;
int game_state = 3;
	//0 - start
	//1 - running
	//2 - over
	//3 - main screen

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
float mx, my;

//textrures
Texture background, doodle, doodle_2, bottom, platform, main_menu;
Texture play_b, play_b_on, over_score_img;
Sprite Background, Bottom, Doodle, Menu, Play, score_bck;

//sounds
SoundBuffer jump_sound, fall_sound, start_sound;
Sound jump, fall, s_start;


void init_shapes(void);
void start(void);
void set_window(void);
void init_texts(void);
void init_sprites(void);
void init_sounds(void);

void update_position(void);
void update_movement(void);
void update_tiles(void);
void update_mouse_menu(void);

void draw_tiles(RenderWindow &);
void draw_player(RenderWindow &);
void draw_window(RenderWindow &);
void draw_texts(RenderWindow &);
void draw_sprites(RenderWindow &);
void draw_menu_screen(RenderWindow &);