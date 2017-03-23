#ifndef DRAW_HPP
#define DRAW_HPP

#include <SDL.h>

#include "Application.hpp"

#include <string>
using namespace std;

// Functions to draw with SDL
class Drawer
{
public:
	Drawer();
	~Drawer();
	void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	void DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);

	void SetScreenDimensions(int w, int h);

	void SetApp(Application* ptrApp);

private:
	Application* m_ptrApp;

	int m_screenWidth;
	int m_screenHeight;
};

#endif
