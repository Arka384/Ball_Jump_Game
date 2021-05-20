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
constexpr int n_tiles = 12;
RectangleShape tiles[n_tiles];
RectangleShape line, line_2;
float tile_gap_y = 60;
float tile_gap_x = 500;
float last_tile_y = W_Height - 50;
float last_tile_x;
float jet_time_counter;
int move_speed = 120;
bool executed = false;
bool spawner = false;
bool spawnd = false;
bool collided = false;
bool draw_menu = false;
bool draw_replay = false;
bool draw_help = false;
bool paused = false;
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
float dt, timer = 0, spawn_time = 10;
Text score_text, score_number;
Text tip, tips[4];
Text over, next, help;
RectangleShape help_back;
Text menu[4];
Font flappy, arial, comic_sans;
float mx, my;

//textrures
Texture background, doodle, doodle_2, bottom, platform, main_menu;
Texture play_b, play_b_on, over_score_img, jet_off, jet_on, jet_new, over_screen;
Texture menu_on, replay, help_1, help_2;

Sprite Background, Bottom, Doodle, Menu, Play, score_bck, Jet_on, Jet_off, Jet_new, Over;
Sprite Menu_on, Replay, Help_1, Help_2;

//sounds
SoundBuffer jump_sound, fall_sound, start_sound ,jetpack, collect, pause;
Sound jump, fall, s_start, JetPack, Collect, Pause;


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
void spwan_pickups(void);
void update_pickups(void);
void update_mouse_over(void);

void draw_tiles(RenderWindow &);
void draw_player(RenderWindow &);
void draw_window(RenderWindow &);
void draw_texts(RenderWindow &);
void draw_sprites(RenderWindow &);
void draw_menu_screen(RenderWindow &);
void draw_over_screen(RenderWindow &);