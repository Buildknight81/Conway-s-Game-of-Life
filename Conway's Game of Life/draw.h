#ifndef DRAW_H
#define DRAW_H
#include "tile.h"

extern int speed;
extern bool paused;


void Draw(std::vector<Tile> T)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	//draw the tiles only if they are alive. otherwise you cant tell the difference
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i].alive == true)
		{
			T[i].Draw();
		}
	}

	//draw border lines so it looks cleaner and you can click nicely
	for (int i = 0; i < 31; i++)
	{
		
		DrawLine(0, i * 30, GetScreenWidth(), i * 30, BLACK);
	}

	for (int i = 0; i < 40; i++)
	{
		DrawLine(i * 30, 0, i * 30, GetScreenHeight() - 60, BLACK);
	}

	//draw text for the end user
	DrawText("Press Space to pause/resume",20, GetScreenHeight() - 40, 20, BLUE);
	DrawText("Use < and > keys to adjust speed", 400, GetScreenHeight() - 40, 20, BLUE);
	DrawText(TextFormat("Speed = %i", speed), 800, GetScreenHeight() - 40, 20, BLUE);
	if (paused)
	{
		DrawText("Paused", 1050, GetScreenHeight() - 40, 20, RED);
	}
	EndDrawing();
}
#endif
