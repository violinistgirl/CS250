#include "Application.hpp"
#include "TicTacToe.hpp"

int main(int argc, char* args[])
{
	int width = 300;
	int height = 300;

	Application graphicalApp;
	graphicalApp.Start( "TicTacToe", width, height );

	TicTacToe tictactoe(&graphicalApp, width, height);
	tictactoe.Main();

	graphicalApp.End();

	return 0;
}