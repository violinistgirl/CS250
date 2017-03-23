#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Application.hpp"
#include "Drawer.hpp"
#include "GameBoard.hpp"

#include "Stack.hpp"
using namespace std;

class TicTacToe
{
public:
	TicTacToe(Application* ptrApp, int width, int height);
	~TicTacToe();

	void Main();
	void Draw();

	void UndoLastMove();
	void PushHistory();
	void HandleClick(int x, int y);

private:
	Application* m_ptrApp;
	Drawer m_drawer;
	int m_screenWidth;
	int m_screenHeight;

	GameBoard m_board;
	int m_turn;

	Stack<GameBoard> m_gameHistory;
};

#endif