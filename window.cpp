#include "stdafx.h"
#include "window.h"

using namespace Zengine;

Window::Window(std::string name, int width, int height)
	:_width(width),_height(height)
{
	init(name, width, height);
}

void Window::init(std::string name, int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
  _window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
														 _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  _renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Window::start()
{
	SDL_StartTextInput();	
}

void Window::end()
{
	SDL_StopTextInput();

  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void Window::renderPresent()
{
	SDL_RenderPresent(_renderer);
}
