#include "tile.h"
#include "input.h"
#include "draw.h"
#include "logic.h"


std::vector<Tile> Tiles;

int speed = 10;
float timer = 0.0f;
bool paused = true;

int main()
{
	//set up the window
	InitWindow(1200, 960, "Conway's Game of Life");
	SetWindowState(FLAG_VSYNC_HINT);

	//set up the grid
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			Tiles.push_back(Tile(i,j));
		}
	}

	while (!WindowShouldClose())
	{
		
		//input
		Input();

		//logic
		if (paused == false)
		{
			timer = timer + GetFrameTime();
		}

		if (timer > (5.0f / (speed + 0.0f)))
		{
			timer = timer - (5.0f / (speed + 0.0f));
			Tiles = Logic(Tiles);
		}

		Draw(Tiles);

	}

	//end the program
	CloseWindow();
	return 0;
}