#include "stdafx.h"
#include "imagemanager.h"

using namespace Zengine;

ImageManager::ImageManager()
{
}

void ImageManager::setRender(SDL_Renderer* renderer)
{
	render = renderer;
}

// TODO: cache
SDL_Texture* ImageManager::getSolid(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  SDL_Surface* img = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = width;
  rect.h = height;  
  SDL_FillRect(img, &rect, SDL_MapRGBA(img->format, r, g, b, a));  
  SDL_Texture* tex = SDL_CreateTextureFromSurface(render, img);
  
  SDL_FreeSurface(img);

  return tex;
}
