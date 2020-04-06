#pragma once
#include "util.h"

namespace Zengine{
class Image;

class ImageManager{
public:
	static ImageManager* inst();
  Image* getSolid(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	
	void setRender(SDL_Renderer* renderer);	
protected:
	static ImageManager* _inst;
	
	ImageManager();

	SDL_Renderer* render;
};
};
