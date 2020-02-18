#pragma once

namespace Zengine{
class Image;

class Graphic{
public:
	static void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void clearRender();
	static void renderCopy(Image* img, SDL_Rect* src, SDL_Rect* dst);
	
	static void setRender(SDL_Renderer* renderer);
	static SDL_Renderer* getRender();
protected:
	static SDL_Renderer* render;
};
};
