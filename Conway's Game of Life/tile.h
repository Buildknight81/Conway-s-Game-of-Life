#ifndef TILE_H
#define TILE_H
#include <vector>
#include "raylib.h"

//this is a tile class in the game. it can be alive or dead.
class Tile
{
public:
	int x, y;
	bool alive = false;
	int aliveN = 0;
	


	Tile(int X, int Y)
	{
		x = X;
		y = Y;
	}

	Rectangle GetRec()
	{
		return Rectangle{ x * 30.0f,y * 30.0f,30,30 };
	}

	void Draw()
	{
		DrawRectangle(x * 30, y * 30, 30, 30, RED);
	}

	
};
#endif
