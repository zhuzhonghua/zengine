#include "stdafx.h"
#include "game.h"
#include "timing.h"
#include "touchscreen.h"

using namespace Zengine;

int Game::width = 640;
int Game::height = 960;

float Game::timeScale = 1.0f;
float Game::elapsed = 0.0f;

Game* Game::instance = NULL;

float Game::density = 1;

GameState Game::state = GameState::PLAY;

Game::Game()
{
	instance = this;

	_scene = NULL;
	_requestedScene = NULL;
	_requestedReset = true;

	_now = 0;
	_step = 0;
}

Game::~Game()
{

}

void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Zengine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
														 width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  _renderer = SDL_CreateRenderer(_window, -1, 0);
		
	TTF_Init();

	// setup sould
	int flag = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG;
	if (Mix_Init(flag) & flag != flag)
	{
		std::string err = Mix_GetError();
		fatalError("Mix_Init error "+err);
	}

	// 44100 cd rate, more cpu power
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		std::string err = Mix_GetError();
		fatalError("Mix_OpenAudio error " + err);
	}
}

void Game::run()
{
	FPSLimiter fps;
	fps.setMaxFPS(60.0f);

	SDL_StartTextInput();
	
	while (state == GameState::PLAY)
	{
		fps.begin();

		long rightNowTick = SDL_GetTicks();
		_step = (_now == 0 ? 0 : rightNowTick - _now);
		_now = rightNowTick;

		processInput();

		step();

		draw();

		SDL_RenderPresent(_renderer);

		_fps = fps.end();
	}

	SDL_StopTextInput();
}

void Game::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			state = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			_motionEvents.push_back(e);
			break;
		case SDL_KEYDOWN:
			
			break;
		case SDL_KEYUP:
			
			break;
		case SDL_MOUSEBUTTONDOWN:
			_motionEvents.push_back(e);
			break;
		case SDL_MOUSEBUTTONUP:
			_motionEvents.push_back(e);
			break;
		}
	}

	TouchScreen::processTouchEvents(_motionEvents);
	_motionEvents.clear();
}

void Game::switchScene(Scene* sce)
{
	instance->_requestedScene = sce;
	instance->_requestedReset = true;
}

void Game::vibrate(int milliseconds)
{
	// vibrate
}

void Game::switchScene()
{
	Camera::reset();

	if (_scene != NULL)
	{
		_scene->destroy();
		delete _scene;
	}

	_scene = _requestedScene;
	_scene->init();

	Game::elapsed = 0.0f;
	Game::timeScale = 1.0f;
}

void Game::step()
{
	if (_requestedReset)
	{
		_requestedReset = false;
		switchScene();
	}

	update();
}

void Game::update()
{
	Game::elapsed = Game::timeScale * _step * 0.001f;

	if (_scene != NULL)
	{
		_scene->update();
	}

	Camera::updateAll();
}

void Game::draw()
{
	if (_scene != NULL)
	{
		_scene->draw();
	}
}

void Game::finish()
{
	SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
	SDL_Quit();
	
	exit(0);
}
