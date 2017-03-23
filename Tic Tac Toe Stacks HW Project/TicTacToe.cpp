#include "TicTacToe.hpp"

#include <iostream>
using namespace std;

TicTacToe::TicTacToe(Application* ptrApp, int width, int height)
{
	m_ptrApp = ptrApp;
	m_screenWidth = width;
	m_screenHeight = height;
	m_drawer.SetApp(m_ptrApp);
	m_drawer.SetScreenDimensions(width, height);
	m_turn = 0;
	m_gameHistory.Push(m_board);
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::Main()
{
	bool done = false;
	while (!done)
	{
		m_ptrApp->TimerStart();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				done = true;
			}

			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);

				cout << "Mouse click @ position: (" << x << "," << y << ")" << endl;

				if (event.button.button == SDL_BUTTON_LEFT)
				{
					HandleClick(x, y);
				}
				else if (event.button.button == SDL_BUTTON_RIGHT)
				{
					UndoLastMove();
				}
			}
		}

		m_ptrApp->BeginDraw();
		Draw();
		m_ptrApp->EndDraw();
		m_ptrApp->TimerUpdate();
	}
}

void TicTacToe::HandleClick(int x, int y)
{
	int gridWH = 100;

	int clickedGridX = x / gridWH;
	int clickedGridY = y / gridWH;

	cout << "Clicked grid position (" << clickedGridX << "," << clickedGridY << ")" << endl;

	if (m_board.grid[clickedGridX][clickedGridY] == ' ')
	{
		if (m_turn % 2 == 0)
		{
			m_board.grid[clickedGridX][clickedGridY] = 'x';
		}
		else
		{
			m_board.grid[clickedGridX][clickedGridY] = 'o';
		}

		// Save history
		PushHistory();

		m_turn++;
		cout << (m_turn % 2) << "'s turn" << endl;
	}
}

void TicTacToe::Draw()
{
	// Background
	m_drawer.DrawRectangle(0, 0, m_screenWidth, 300, 200, 200, 255);

	// Draw grid
	m_drawer.DrawRectangle(0, 100, m_screenWidth, 5, 0, 0, 0);
	m_drawer.DrawRectangle(0, 200, m_screenWidth, 5, 0, 0, 0);
	m_drawer.DrawRectangle(100, 0, 5, 300, 0, 0, 0);
	m_drawer.DrawRectangle(200, 0, 5, 300, 0, 0, 0);

	// Draw grid
	int tileX, tileY;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			tileX = x * 100;
			tileY = y * 100;
			if (m_board.grid[x][y] == 'x')
			{
				m_drawer.DrawLine(tileX, tileY, tileX + 100, tileY + 100, 255, 0, 0);
				m_drawer.DrawLine(tileX, tileY +100, tileX + 100, tileY, 255, 0, 0);
			}
			else if (m_board.grid[x][y] == 'o')
			{
				m_drawer.DrawLine(tileX + 50, tileY, tileX + 0, tileY + 50, 0, 0, 255);
				m_drawer.DrawLine(tileX  + 50, tileY, tileX + 100, tileY + 50, 0, 0, 255);
				m_drawer.DrawLine(tileX + 50, tileY +100, tileX + 0, tileY + 50, 0, 0, 255);
				m_drawer.DrawLine(tileX + 50, tileY +100, tileX + 100, tileY + 50, 0, 0, 255);
			}
		}
	}
}

void TicTacToe::PushHistory()
{
	try {
		m_gameHistory.Push(m_board);
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
	cout << m_gameHistory.GetSize()-1 << " moves" << endl;
	m_board.Display();
}

void TicTacToe::UndoLastMove()
{
	try {
		if (m_gameHistory.GetSize()-1 <= 0)
		{
			throw out_of_range("Nothing to undo!");
		}
		cout << "Undo last move, stack size: " << m_gameHistory.GetSize()-1 << endl;
	}
	catch (out_of_range x) {
		cout << "Nothing to undo.";
	}

	
	if (m_gameHistory.GetSize() >= 1)
	{
		// The top-most item is the current state,
		// so actually need to pop this and then get top.
		try {
			m_gameHistory.Pop();
		}
		catch (out_of_range x) {
			cout << "Nothing to undo.";
		}
		if (m_gameHistory.GetSize() > 0) {
			m_board = m_gameHistory.Top();
			m_turn--;
		}
			
		
	}
	m_board.Display();
}