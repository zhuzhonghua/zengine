#pragma once
#include "util.h"

namespace Zengine{
class Image;

class ImageManager{
public:
	ImageManager();
	
  Image* getSolid(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	
	void setRender(SDL_Renderer* renderer);	
protected:
	SDL_Renderer* render;
};
};
