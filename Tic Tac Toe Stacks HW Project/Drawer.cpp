#include "Drawer.hpp"

#include <iostream>
using namespace std;

Drawer::Drawer()
{
}

Drawer::~Drawer()
{
}

void Drawer::SetScreenDimensions(int w, int h)
{
	m_screenWidth = w;
	m_screenHeight = h;
}

void Drawer::SetApp(Application* ptrApp)
{
	m_ptrApp = ptrApp;
}

void Drawer::DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Rect background = { x, y, width, height };
	SDL_SetRenderDrawColor(m_ptrApp->GetRenderer(), r, g, b, 0xFF);
	SDL_RenderFillRect(m_ptrApp->GetRenderer(), &background);
}

void Drawer::DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(m_ptrApp->GetRenderer(), r, g, b, 0xFF);
	SDL_RenderDrawLine(m_ptrApp->GetRenderer(), x1, y1, x2, y2);
}
