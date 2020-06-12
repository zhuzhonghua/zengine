#include "zengine.h"
#include "texture.h"

#include "util.h"
#include "game.h"

using namespace Zengine;

Texture::Texture()
{
	texSrc = NULL;
	tex = NULL;	
}

Texture::Texture(const std::string& path)
{
	bitmap(path);
}

Texture::Texture(SDL_Surface* img)
{
	bitmap(img);
}

Texture::~Texture()
{
}


void Texture::destroy()
{
	if (tex != NULL)
	{
		SDL_DestroyTexture(tex);
	}
	
	if (texSrc != NULL)
	{
		SDL_FreeSurface(texSrc);
	}
}

void Texture::bitmap(const std::string& bitmap)
{
	SDL_Surface* img = IMG_Load(bitmap.c_str());
	Texture::bitmap(img);
}

void Texture::bitmap(SDL_Surface* img)
{
	width = img->w;
	height = img->h;

	texSrc = img;
	tex = SDL_CreateTextureFromSurface(Game::inst()->getRender(), img);
}

int Texture::getPixel(int x, int y)
{
	int bpp = texSrc->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)texSrc->pixels + y * texSrc->pitch + x * bpp;

	switch (bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}

void Texture::setPixel(int x, int y, int color)
{
	int bpp = texSrc->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)texSrc->pixels + y * texSrc->pitch + x * bpp;

	switch (bpp) {
	case 1:
		*p = color & 0xFF;
		break;

	case 2:
		*(Uint16 *)p = color & 0xFFFF;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			//return p[0] << 16 | p[1] << 8 | p[2];
		{
			p[0] = (color << 16) & 0xFF;
			p[1] = (color << 8) & 0xFF;
			p[2] = color & 0xFF;
		}
		else
			//return p[0] | p[1] << 8 | p[2] << 16;
		{
			p[0] = color & 0xFF; 
			p[1] = (color << 8) & 0xFF;
			p[2] = (color << 16) & 0xFF;
		}
		break;

	case 4:
		*(Uint32 *)p = color;
		break;

	default:
		//return 0;       /* shouldn't happen, but avoids warnings */
		break;
	}

	SDL_UpdateTexture(tex, NULL, texSrc->pixels, texSrc->pitch);
	//if (tex != NULL)
	//{
	//	SDL_DestroyTexture(tex);
	//}
	//
	//tex = SDL_CreateTextureFromSurface(Game::inst()->getRender(), texSrc);
}
