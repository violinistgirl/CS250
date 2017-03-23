#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <iostream>
using namespace std;

struct GameBoard
{
	char grid[3][3];

	GameBoard()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				grid[x][y] = ' ';
			}
		}
	}

	void Display()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (x != 0) { cout << " |"; }
				cout << " " << grid[x][y];
			}
			if (y != 2)
			{
				cout << endl << "---|---|---" << endl;
			}
		}
		cout << endl; 
	}
};

#endif