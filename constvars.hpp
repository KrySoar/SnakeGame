#pragma once
const float WIN_HEIGHT = 1000.0f;//pixels
const float WIN_WIDTH = WIN_HEIGHT;

const float CELL_SIZE = WIN_HEIGHT * (1/50.0f);// 1 CELL == 1/50 window size

enum Direction {Up, Down, Left, Right, NO_DIRECTION};

const float FRAMERATE = 18;//default 18 // define the speed of the game
const float SNAKE_SPEED = CELL_SIZE;
