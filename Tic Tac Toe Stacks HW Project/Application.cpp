// Kuko Framework - https://github.com/Rejcx/Kuko - Rachel J. Morris - MIT License
#include "Application.hpp"

#include <SDL.h>

void Timer::Setup(int fps)
{
	this->fps = fps;
	this->startTicks = 0;
	this->ticksPerFrame = 1000 / this->fps;
}

void Timer::Start()
{
	startTicks = SDL_GetTicks();
}

void Timer::Update()
{
	int frameTicks = SDL_GetTicks();
	if (frameTicks < ticksPerFrame)
	{
		SDL_Delay(ticksPerFrame - frameTicks);
	}
}

void Application::TimerStart()
{
	m_timer.Start();
}

void Application::TimerUpdate()
{
	m_timer.Update();
}

void Application::SetDefaultResolution(int width, int height)
{
	m_defaultWidth = width;
	m_defaultHeight = height;
}

bool Application::Start(const std::string& winTitle, int screenWidth /* = 480 */, int screenHeight /* = 480 */)
{
	// Screen scaling is based on the default width/height
	SetDefaultResolution(screenWidth, screenHeight);

	m_timer.Setup(60);

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		std::string error(SDL_GetError());
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
	}

	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_window = SDL_CreateWindow(winTitle.c_str(),
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);

	if (m_window == NULL)
	{
		std::string error(SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL)
	{
		std::string error(SDL_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	m_widthRatio = float(m_screenWidth) / float(m_defaultWidth);
	m_heightRatio = float(m_screenHeight) / float(m_defaultHeight);

	//SDL_RenderSetScale( m_renderer, 0.5, 0.5 );
	SDL_RenderSetScale(m_renderer, m_widthRatio, m_heightRatio);

	return true;
}

void Application::End()
{
	if (m_renderer != NULL)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = NULL;
	}

	if (m_window != NULL)
	{
		SDL_DestroyWindow(m_window);
		m_window = NULL;
	}

	SDL_Quit();
}

int Application::GetScreenWidth()
{
	return m_screenWidth;
}

int Application::GetScreenHeight()
{
	return m_screenHeight;
}

int Application::GetDefaultWidth()
{
	return m_defaultWidth;
}

int Application::GetDefaultHeight()
{
	return m_defaultHeight;
}

float Application::GetWidthRatio()
{
	return m_widthRatio;
}

float Application::GetHeightRatio()
{
	return m_heightRatio;
}

SDL_Renderer* Application::GetRenderer()
{
	return m_renderer;
}

void Application::BeginDraw()
{
	SDL_SetRenderDrawColor(m_renderer, 0x99, 0x99, 0xFF, 0xFF);
	SDL_RenderClear(m_renderer);
}

void Application::EndDraw()
{
	SDL_RenderPresent(m_renderer);
}

