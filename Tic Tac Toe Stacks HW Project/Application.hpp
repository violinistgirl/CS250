#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SDL.h>

#include <string>

struct Timer
{
	int fps;
	int ticksPerFrame;
	int startTicks;
	void Setup(int fps);
	void Start();
	void Update();
};

class Application
{
public:
	bool Start(const std::string& winTitle, int screenWidth = 480, int screenHeight = 480);
	void End();

	int GetScreenWidth();
	int GetScreenHeight();

	int GetDefaultWidth();
	int GetDefaultHeight();

	float GetWidthRatio();
	float GetHeightRatio();

	void SetDefaultResolution(int width, int height);

	SDL_Renderer* GetRenderer();
	void BeginDraw();
	void EndDraw();

	void TimerStart();
	void TimerUpdate();

private:
	int m_screenWidth;
	int m_screenHeight;

	int m_defaultWidth;
	int m_defaultHeight;

	float m_widthRatio;
	float m_heightRatio;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Timer m_timer;
};

#endif
