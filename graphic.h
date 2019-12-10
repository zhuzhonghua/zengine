#pragma once

namespace Zengine{
class Graphic{
public:
	static void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void clearRender();
	static void renderCopy(SDL_Texture* tex, Rect* src, Rect* dst);
	
	static void setRender(SDL_Renderer* renderer);
protected:
	static SDL_Renderer* render;
};
};