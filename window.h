#pragma once

namespace Zengine{
class Window{
public:
	Window(std::string name, int width, int height);

	void start();
	void end();
	void renderPresent();
	
	int getWidth() { return _width; }
	int getHeight() { return _height; }

	SDL_Renderer* getRender() { return _renderer; }
protected:
	void init(std::string name, int width, int height);
	
	int _width;
  int _height;
  
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  //InputManager _inputMgr;
};
};
