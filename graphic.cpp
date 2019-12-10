#include "stdafx.h"

#include "graphic.h"

using namespace Zengine;

SDL_Renderer* Graphic::render = NULL;

void Graphic::setRender(SDL_Renderer* renderer)
{
	render = renderer;
}

void Graphic::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(render, r, g, b, a);
}

void Graphic::clearRender()
{
	SDL_RenderClear(render);
}

void Graphic::renderCopy(SDL_Texture* tex, Rect* src, Rect* dst)
{
	SDL_RenderCopy(render, tex, src, dst);
}
