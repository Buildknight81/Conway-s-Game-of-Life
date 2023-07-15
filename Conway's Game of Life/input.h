#ifndef INPUT_H
#define INPUT_H
#include "raylib.h"

extern int speed;
extern bool paused;
extern std::vector<Tile> Tiles;

void Input()
{
	
	if (IsKeyPressed(KEY_SPACE))
	{
		if (paused == true)
		{
			paused = false;
		}
		else
		{
			paused = true;
		}
	}

	if (IsKeyPressed(KEY_RIGHT) && speed < 30)
	{
		speed = speed + 1;
	}

	if (IsKeyPressed(KEY_LEFT) && speed > 1)
	{
		speed = speed - 1;
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < Tiles.size(); i++)
		{
			if (CheckCollisionPointRec(Vector2{ GetMouseX() + 0.0f, GetMouseY() + 0.0f}, Tiles[i].GetRec()))
			{
				Tiles[i].alive = !Tiles[i].alive;
			}
		}
	}
}
#endif
