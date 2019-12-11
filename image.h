#pragma once

namespace Zengine{
class Image{
public:
	Image(SDL_Texture* tex);
	SDL_Texture* getTex() { return _tex; }
protected:
	SDL_Texture* _tex;
};
};
