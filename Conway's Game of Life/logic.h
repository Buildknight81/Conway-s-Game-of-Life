#ifndef LOGIC_H
#define LOGIC_H
#include "tile.h"

//yes i know this is bad code but i dont know a better way
Tile NCheck(Tile T, int x, int y, std::vector<Tile> Tiles)
{
	for (int i = 0; i < Tiles.size(); i++)
	{
		if (Tiles[i].x == (T.x + 40 + x) % 40 && Tiles[i].y == (T.y + 30 + y) % 30)
		{
			if (Tiles[i].alive == true)
			{
				T.aliveN = T.aliveN + 1;
			}
		}
	}
	return T;
}

std::vector<Tile> Logic(std::vector<Tile> T)
{
	for (int i = 0; i < T.size(); i++)
	{
		T[i].aliveN = 0;
		T[i] = NCheck(T[i], 1, 1, T);
		T[i] = NCheck(T[i], 0, 1, T);
		T[i] = NCheck(T[i], -1, 1, T);
		T[i] = NCheck(T[i], 1, 0, T);
		T[i] = NCheck(T[i], -1, 0, T);
		T[i] = NCheck(T[i], 1, -1, T);
		T[i] = NCheck(T[i], 0, -1, T);
		T[i] = NCheck(T[i], -1, -1, T);
	}

	for (int i = 0; i < T.size(); i++)
	{
		if (T[i].alive == true)
		{
			if (T[i].aliveN < 2 || T[i].aliveN > 3)
			{
				T[i].alive = false;
			}
		}

		else
		{
			if (T[i].aliveN == 3)
			{
				T[i].alive = true;
			}
		}
	}
	return T;
}
#endif
